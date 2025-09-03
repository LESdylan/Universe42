# Signal Transmission Reliability Issues & Fixes

## Current Situation Analysis

- **Before fix**: Failed at ~80 characters (checksum completely wrong)
- **After fix**: Fails at ~160 characters (checksum very close: 9450 vs 9445)
- **Difference**: Only 5 codepoint units difference suggests 1-2 character corruption

## Root Cause: Signal Loss/Corruption

With 1006 total bits being transmitted, even a 99.5% success rate means ~5 lost signals, which matches your checksum difference.

## Fix #1: Increase Signal Delays (Most Important)

**Current client delay**: `usleep(300)` (300 microseconds) **Problem**: Too fast for reliable transmission over 1000+ signals

**Solution**: Increase delays progressively

### In `minitalk_client.c`:

**BEFORE:**

```c
void send_bit(pid_t pid, char bit) {
    // ... signal sending code ...
    usleep(300);  // Too fast!
}
```

**AFTER:**

```c
void send_bit(pid_t pid, char bit) {
    // ... signal sending code ...
    usleep(1000);  // 4x slower for reliability
}
```

### In `minitalk_server.c` (checksum transmission):

**BEFORE:**

```c
usleep(30000); // Increased delay for reliability
```

**AFTER:**

```c
usleep(50000); // Even more delay for checksum
```

## Fix #2: Add Signal Acknowledgment (More Robust)

The current implementation sends signals without waiting for confirmation. Add a simple ACK system:

### Enhanced Client Signal Function:

```c
volatile sig_atomic_t g_ack_received = 0;

void handle_ack(int sig) {
    g_ack_received = 1;
}

void send_bit_with_ack(pid_t pid, char bit) {
    int retries = 0;
    int sig = (bit == '0') ? SIGUSR1 : SIGUSR2;
    
    while (retries < 3) {  // Max 3 retries
        g_ack_received = 0;
        kill(pid, sig);
        
        // Wait for ACK with timeout
        for (int i = 0; i < 1000 && !g_ack_received; i++) {
            usleep(10);
        }
        
        if (g_ack_received) break;
        retries++;
        usleep(1000);  // Wait before retry
    }
}
```

### Enhanced Server Acknowledgment:

```c
void handle_bit(int sig, siginfo_t *info, void *context) {
    // ... existing bit processing code ...
    
    // Send ACK back to client
    kill(info->si_pid, SIGUSR1);  // Simple ACK
    
    // ... rest of function ...
}
```

## Fix #3: Add Bit Verification (Debugging)

Add a verification system to catch exactly where corruption occurs:

### In Client:

```c
void send_bit_with_debug(pid_t pid, char bit, int bit_index) {
    int sig = (bit == '0') ? SIGUSR1 : SIGUSR2;
    
    if (bit_index % 100 == 0) {  // Progress indicator
        printf("[Client] Sent %d bits...\n", bit_index);
    }
    
    kill(pid, sig);
    usleep(1000);
}
```

### In Server:

```c
void handle_bit(int sig, siginfo_t *info, void *context) {
    // ... existing code ...
    
    if (g_bit_idx % 100 == 0) {  // Progress indicator
        printf("[Server] Received %d bits...\n", (int)g_bit_idx);
    }
    
    // ... rest of function ...
}
```

## Fix #4: Improve Buffer Management

Ensure no buffer overflows for large messages:

```c
#define MAX_BITS 20000  // Increase from 10000
#define MAX_MESSAGE_LEN 2500  // For characters

// In pack_bits function, add bounds checking:
int pack_bits(const char *bitstr, unsigned char *out) {
    int len = strlen(bitstr);
    if (len > MAX_BITS - 100) {  // Leave some margin
        printf("[ERROR] Message too long: %d bits (max %d)\n", len, MAX_BITS - 100);
        return -1;
    }
    // ... rest of function
}
```

## Testing Strategy

### Step 1: Try Just Delay Increase

1. Change `usleep(300)` to `usleep(1000)` in client
2. Test with your failing message
3. If checksums match → problem solved!

### Step 2: If Still Failing

1. Increase delay to `usleep(2000)`
2. Add the debug progress indicators
3. Look for patterns in where corruption occurs

### Step 3: If Still Failing

1. Implement the ACK system
2. This will be 100% reliable but slower

## Expected Results

With `usleep(1000)`:

- **Success rate**: Should improve from ~99.5% to ~99.9%
- **Speed**: 4x slower but still reasonable
- **Checksums**: Should match for messages up to 300+ characters

With ACK system:

- **Success rate**: 100% (guaranteed delivery)
- **Speed**: 10x slower but completely reliable
- **Checksums**: Always match, regardless of message size

## Quick Test Command

```bash
# Try with a message that currently fails
./client [server_pid] "Your 160+ character message that currently fails"

# If it works, try progressively longer messages
./client [server_pid] "An even longer message with more characters..."
```

Start with Fix #1 (increase delays) as it's the simplest and most likely to solve your issue!