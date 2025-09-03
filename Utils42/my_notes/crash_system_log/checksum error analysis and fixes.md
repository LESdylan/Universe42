# Checksum Error Analysis & Root Cause

## What's Happening

From your debug output:

```
[Client DEBUG] Total bits sent: 8 + 10*37 + 8 + 272 = 658
[Client] Expected checksum: 4200
[Client] Received checksum: 198
```

**The Problem**: Your encoded message is **272 bits long**, but you're only using **8 bits** to transmit the length.

## Step-by-Step Breakdown

### 1. **Client Side (Sending)**

- Real encoded message length: **272 bits**
- Sent as 8 bits: `272 & 0xFF = 16` (272 in binary = 100010000, only last 8 bits = 00010000 = 16)
- Client sends: Header + 272 actual bits
- Client calculates checksum from full original message = **4200**

### 2. **Server Side (Receiving)**

- Receives length as: **16 bits** (truncated from 272)
- Server expects: `8 + 10*37 + 8 + 16 = 402 total bits`
- Server actually receives: `8 + 10*37 + 8 + 272 = 658 bits`
- Server stops reading after 402 bits, ignoring the remaining 256 bits
- Server decodes incomplete message → checksum = **198**

## The Fix

You need to change the message length encoding from **8 bits to 16 bits** in both files.

### Client Changes (minitalk_client.c)

**BEFORE:**

```c
// Send encoded message length (8 bits) - WRONG!
int msg_len = strlen(ctx.encoded);
for (int bit = 7; bit >= 0; bit--) {
    char bit_char = ((msg_len >> bit) & 1) ? '1' : '0';
    send_bit(server_pid, bit_char);
}
```

**AFTER:**

```c
// Send encoded message length (16 bits) - FIXED!
int msg_len = strlen(ctx.encoded);
printf("[Client DEBUG] Sending encoded message length: %d\n", msg_len);
for (int bit = 15; bit >= 0; bit--) {  // Changed from 7 to 15
    char bit_char = ((msg_len >> bit) & 1) ? '1' : '0';
    send_bit(server_pid, bit_char);
}
```

**Also update the debug output:**

```c
printf("[Client DEBUG] Total bits sent: 8 + %d*37 + 16 + %zu = %zu\n", 
    ctx.n, strlen(ctx.encoded), 24 + ctx.n*37 + strlen(ctx.encoded));
    // Changed from 16 to 24 (8 + 37*n + 16)
```

### Server Changes (minitalk_server.c)

**BEFORE:**

```c
} else if (g_bit_idx == 8 + num_chars * 37 + 8) {
    // Extract encoded message length from 8 bits - WRONG!
    for (int i = 8 + num_chars * 37; i < 8 + num_chars * 37 + 8; i++) {
        enc_len = (enc_len << 1) | (g_bits[i] - '0');
    }
    expected_total_bits = 8 + num_chars * 37 + 8 + enc_len;
```

**AFTER:**

```c
} else if (g_bit_idx == 8 + num_chars * 37 + 16) {  // Changed +8 to +16
    // Extract encoded message length from 16 bits - FIXED!
    for (int i = 8 + num_chars * 37; i < 8 + num_chars * 37 + 16; i++) {  // Changed +8 to +16
        enc_len = (enc_len << 1) | (g_bits[i] - '0');
    }
    expected_total_bits = 8 + num_chars * 37 + 16 + enc_len;  // Changed +8 to +16
```

**Also update the bit extraction:**

```c
// Extract encoded message length (16 bits instead of 8)
int enc_len = 0;
for (int i = 0; i < 16; i++) {  // Changed from 8 to 16
    enc_len = (enc_len << 1) | (g_bits[bit_pos++] - '0');
}
```

## Why This Fixes the Checksum Error

1. **Before**: Server only reads first 16 bits of your 272-bit message
2. **After**: Server correctly reads all 272 bits of your message
3. **Result**: Server decodes the complete message and calculates the correct checksum (4200)

## Test Results Expected

After the fix, you should see:

```
[Client DEBUG] Total bits sent: 8 + 10*37 + 16 + 272 = 666
[Client] Expected checksum: 4200
[Client] Received checksum: 4200
[Client] ✓ SUCCESS: Checksums match!
```

## Additional Recommendations

1. **Increase MAX_BITS** if you plan to send very large messages:
    
    ```c
    #define MAX_BITS 50000  // Instead of 10000
    ```
    
2. **Add validation** in pack_bits():
    
    ```c
    if (len > MAX_BITS) {
        printf("Error: Message too long!\n");
        return -1;
    }
    ```
    

This fix should resolve your checksum mismatch error completely!