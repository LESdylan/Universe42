# Minitalk Large Message Issues Analysis

## Primary Issues Identified

### 1. **Buffer Overflow in Bit Packing**

**Location**: `minitalk_client.c` - `pack_bits()` function **Problem**:

- The `packed` array is declared as `unsigned char packed[1250]`
- This can only handle `1250 * 8 = 10,000` bits maximum
- But your `MAX_BITS` is also 10,000, and with large messages, you could exceed this

**Fix**: Increase buffer size or add bounds checking:

```c
unsigned char packed[2000]; // Increase buffer size
// OR add bounds checking in pack_bits()
```

### 2. **Integer Overflow in Message Metadata**

**Location**: Both client and server **Problem**:

- Encoded message length is sent as only 8 bits (`msg_len` limited to 0-255)
- For large messages, the encoded length can easily exceed 255 characters
- This causes truncation and desynchronization

**Current Code**:

```c
// Sends only 8 bits for message length - MAX 255!
for (int bit = 7; bit >= 0; bit--) {
    char bit_char = ((msg_len >> bit) & 1) ? '1' : '0';
    send_bit(server_pid, bit_char);
}
```

**Fix**: Use 16 bits for message length:

```c
// Send 16 bits instead of 8
for (int bit = 15; bit >= 0; bit--) {
    char bit_char = ((msg_len >> bit) & 1) ? '1' : '0';
    send_bit(server_pid, bit_char);
}
```

### 3. **Server Bit Calculation Logic Error**

**Location**: `minitalk_server.c` - `handle_bit()` function **Problem**:

```c
} else if (g_bit_idx == 8 + num_chars * 37 + 8) {
    // Extract encoded message length (expecting 8 more bits)
    for (int i = 8 + num_chars * 37; i < 8 + num_chars * 37 + 8; i++) {
```

This hardcodes 8 bits for message length, but needs to match client's bit width.

### 4. **Potential Race Conditions**

**Location**: Signal handling in both files **Problem**:

- With large messages, rapid signal sending might cause signals to be lost
- `usleep(300)` in client might be too fast for reliable transmission
- Server's static variables in `handle_bit()` could get corrupted

### 5. **Memory Management Issues**

**Location**: Various locations **Problem**:

- Potential memory leaks with large messages
- Fixed-size arrays might overflow
- Hash table size (4096) might be insufficient for very large, diverse messages

## Recommended Fixes (Priority Order)

### **CRITICAL FIX #1: Message Length Encoding**

Change both client and server to use 16-bit message length:

**Client**:

```c
// Send 16 bits for message length
for (int bit = 15; bit >= 0; bit--) {
    char bit_char = ((msg_len >> bit) & 1) ? '1' : '0';
    send_bit(server_pid, bit_char);
}
```

**Server**:

```c
} else if (g_bit_idx == 8 + num_chars * 37 + 16) { // Changed from +8 to +16
    // Extract 16 bits for message length
    for (int i = 8 + num_chars * 37; i < 8 + num_chars * 37 + 16; i++) {
        enc_len = (enc_len << 1) | (g_bits[i] - '0');
    }
    expected_total_bits = 8 + num_chars * 37 + 16 + enc_len; // Updated calculation
}
```

### **CRITICAL FIX #2: Increase Buffer Sizes**

```c
#define MAX_BITS 50000  // Increase from 10000
unsigned char packed[6250]; // Increase accordingly (50000/8 + margin)
```

### **FIX #3: Add Bounds Checking**

```c
int pack_bits(const char *bitstr, unsigned char *out) {
    int len = strlen(bitstr);
    if (len > MAX_BITS) {
        printf("Error: Message too long (%d bits, max %d)\n", len, MAX_BITS);
        return -1;
    }
    // ... rest of function
}
```

### **FIX #4: Increase Signal Delays**

For large messages, increase the delay between signals:

```c
usleep(1000);  // Increase from 300 to 1000 microseconds
```

## Testing Strategy

1. **Test with incrementally larger messages**:
    
    - 100 characters
    - 500 characters
    - 1000 characters
    - 2000+ characters
2. **Monitor for specific error patterns**:
    
    - Checksum mismatches
    - Incomplete message reception
    - Segmentation faults
    - Infinite loops in signal handling
3. **Add debugging output** to track:
    
    - Actual vs expected bit counts
    - Message length encoding/decoding
    - Buffer usage statistics