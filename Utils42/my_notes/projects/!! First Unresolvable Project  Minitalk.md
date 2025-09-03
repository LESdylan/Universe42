---
aliases:
  - "!! First Unresolvable Project : Minitalk"
---
[SIGNAL]
https://en.wikipedia.org/wiki/Volatile_(computer_programming)
https://dev.to/pauljlucas/what-volatile-does-in-c-and-c-5147
---
Just when we start to get used to give our maximum to get our program errors free with 42 school project. I discovered throughout a lot of trial and failure that this problem is impossible because of the requirements of the school.
The core problem I primarily identified in this project is this kind of pattern
```c
//this sequence ALWAYS has a race condition:
volatile sig_atomic_t signal_received = 0;

void handler(int sig) {
    signal_received = 1;
    printf("Signal received at time T2\n");
}

// Main code:
signal(SIGUSR1, handler);

if (!signal_received) {              // T1: Check (returns false)
    // Server sends SIGUSR1 HERE     // T2: Signal arrives, handler runs
    pause();                         // T3: pause() waits for NEXT signal
}

## // my solution
while (!server->ready_to_proceed) { usleep(100); // Even if signal is "lost", we check again in 100μs }

//if signal arrive between step 1 and step2, pause hangs() forever
// since pause() only wakeds up on new signals that arrive after it starts, and our signal can arrive before, it will wait forever for another signal

//and as we ask the signal to be received the condition can never be accomplished
```

Why our requirements are problematic ?
The restriction to only use `signal()`/ `sigaction` without proper signal `masking primitives`makes reliable singla hanlding impossible. This is exactly why POSIX introduced `sigprocmask()` , `sigusped()` and `signalfd()`
As all project we can do in our life, a difficulty of the project can reflect the mind spirit of the developer that codes it. This project is one of them because a we see too much from my grade for example that people do the easiest choice possible 

## Concepts to see in the nutshell
### identifying each role between server and client
#### Client
#### Server
### Signals
unix give a safe 
Primarily the signal was created to 

> Portability
       The only portable use of signal() is to set a signal's disposition to SIG_DFL or SIG_IGN.  The semantics when using signal() to establish a signal handler vary across systems (and POSIX.1 explicitly
       permits this variation); do not use it for this purpose.
       POSIX.1 solved the portability mess by specifying sigaction(2), which provides explicit control of the semantics when a signal handler is invoked; use that interface instead of signal().
       In  the original UNIX systems, when a handler that was established using signal() was invoked by the delivery of a signal, the disposition of the signal would be reset to SIG_DFL, and the system did
       not block delivery of further instances of the signal.  This is equivalent to calling sigaction(2) with the following flags:
           sa.sa_flags = SA_RESETHAND | SA_NODEFER;
       System V also provides these semantics for signal().  This was bad because the signal might be delivered again before the handler had a chance to reestablish itself.  Furthermore,  rapid  deliveries
       of the same signal could result in recursive invocations of the handler.
       BSD  improved  on this situation, but unfortunately also changed the semantics of the existing signal() interface while doing so.  On BSD, when a signal handler is invoked, the signal disposition is
       not reset, and further instances of the signal are blocked from being delivered while the handler is executing.  Furthermore, certain blocking system calls are automatically restarted if interrupted
       by a signal handler (see signal(7)).  The BSD semantics are equivalent to calling sigaction(2) with the following flags:
           sa.sa_flags = SA_RESTART;
       The situation on Linux is as follows:
       * The kernel's signal() system call provides System V semantics.
 
| command | summary                                                                                                                                                                | page         |                                                                                                                       |                                                                                          |
| ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | --------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| kill    |                                                                                                                                                                        | man 7 signal |                                                                                                                       |                                                                                          |
| pause   | cause the calling process (`or thread`) t sleep until a signal is delivered that either terminates the process or causes teh invocation of a signal-catching function. | man 2 pause  | return only when signal was caught and the signal-catching funtion returned  otherwise (-1) and errno is set to EINTR | may be handled into the handler_funciton to be seu that the signal is received each time |
| signal  |                                                                                                                                                                        | man 7 signal |                                                                                                                       |                                                                                          |
#### SIGSET 
#### SIGACTION
#### SIGNAL
Let's imagine we're writing to a file, updating a pointer, or halfway through some malloc.
A signal handler can suddenly JUMP IN like:
`I'M SIGUSR1`
but the program lost why it needed this

signal handler, we cannot malloc, we can't use mutexes, we can't print safely
we can only set a volative sig_atomic_t flag and run
### ICP

### Limits of signals

the signal rely on `async interruptions`
we can have `race condition` issues, `override values` because `not queued` 
insie

---
## inline Vocabulary
### volatile
`volatile sig_atomic_t`  : volatile is a keywork that modifies a variable indicating that its value may change at any time by external factors (like hardware or other threads), and therefore the compiler should not make assumptions about its value. Writing this `indicator`make the compiler reading directly into the `memory` rather than reling on `cached values` this ensures that all threas onprocesses see the most up-to-date value. The memory is the most update value from the system can get because the cache `can't notice teh environment/headers change, compiler flags change, when timestamp are messy, randomness or harware..` --> this explain why we need to use volatile
volatile is a `type qualifier` like `const` 
- `volatile` access to `memory-mapped` I/O devices.
- allow preserving value across a `longjump` 
- allow sharing values between signal handlers and the rest of the program in `volatile`

## Race condition in the signal handling pattern

    ```C
    volatile sig_atomic_t signal_received = 0;
    void handler(int sig)
    {
	    signal_received = 1;
	    printf("Signal received at time T2\n");
	}

	// Main code:
	signal(SIGUSR1, handler);

	if (!signal_received)
	{
	// T1: Check (returns false)
    // Server sends SIGUSR1 HERE
    // T2: Signal arrives, handler runs
    pause();                         // T3: pause() waits for NEXT signal
	}
    ```
- **Issue**: The sequence you described has a race condition. If the signal (SIGUSR1) arrives between the check (if (!signal_received)) and the pause() call, the program will hang indefinitely because pause() only wakes up on signals delivered _after_ it starts. This is a classic problem with the signal() interface and pause().
- **Why**: The signal() function does not block or queue signals reliably, and pause() does not account for signals that have already been handled. This makes the pattern unreliable without additional synchronization mechanisms.
- **Your Solution**: Using a while (!server->ready_to_proceed) { usleep(100); } loop to periodically check a flag is a practical workaround to avoid relying on pause(). This approach mitigates the race condition by repeatedly checking the flag, ensuring the program doesn't hang if a signal is "missed." However, it introduces a small delay (100μs) and consumes CPU cycles, which may not be ideal for performance-critical applications.
#### 2. School Requirements and Signal Handling Limitations

Your claim that the school's restriction to use only signal() or sigaction without proper signal masking primitives (e.g., sigprocmask(), sigsuspend(), or signalfd()) makes reliable signal handling impossible is **mostly correct**:

- **Why the Restriction is Problematic**: The signal() function, as noted in the POSIX documentation, is not portable for establishing signal handlers due to varying semantics across systems (e.g., System V vs. BSD). POSIX recommends sigaction() for reliable signal handling because it allows explicit control over signal behavior, such as blocking signals during handler execution or restarting interrupted system calls.
- **POSIX Solutions**: You correctly mention that POSIX introduced sigprocmask(), sigsuspend(), and signalfd() to address these issues:
    - **sigprocmask()**: Allows blocking/unblocking signals to prevent them from interrupting critical sections of code, avoiding race conditions.
    - **sigsuspend()**: Atomically sets a signal mask and suspends the process until a signal is received, avoiding the race condition in the if (!signal_received) { pause(); } pattern.
    - **signalfd()**: Provides a file descriptor-based interface for handling signals, which is more robust for modern applications but not available in all environments (and likely not allowed in 42 projects).
- **School Constraints**: If the project restricts you to signal() or sigaction without these primitives, it forces you to work with inherently unreliable mechanisms. This aligns with your observation that the project requirements make reliable signal handling "impossible" in some cases, as you cannot fully eliminate race conditions without masking or atomic operations.42
#### 3. Signal Handler Limitations

Your statement about signal handler constraints is **correct**:

- **Async-Safe Functions**: Signal handlers must be async-signal-safe, meaning they can only call a limited set of functions (e.g., setting a volatile sig_atomic_t variable, as you noted). Functions like printf(), malloc(), or mutex operations are not safe because they may be interrupted in an inconsistent state (e.g., during memory allocation or I/O).
- **Race Conditions and Non-Queued Signals**: Signals are not queued in most UNIX systems (except for real-time signals like SIGRTMIN to SIGRTMAX). If multiple instances of the same signal are delivered while a handler is running, they may be merged into a single invocation, leading to potential signal loss.
- **Volatile Keyword**: Your explanation of volatile and sig_atomic_t is accurate:
    - **volatile**: Ensures the compiler does not optimize away reads/writes to the variable by forcing memory access instead of using cached values. This is critical in signal handlers where the variable may be modified by an external event (the signal).
    - **sig_atomic_t**: A type guaranteed to be atomically read/written, even in the presence of asynchronous signals, making it safe for communication between the handler and the main program.
    - **Use Cases**: You correctly note that volatile is used for memory-mapped I/O, longjmp, and sharing values between signal handlers and the main program.
    
 #### 4. Portability and Signal Semantics

Your summary of signal portability and semantics is **accurate**:

- **Portability Issues**: The POSIX man page for signal() (man 7 signal) confirms that signal() is only portable for setting a signal's disposition to SIG_DFL (default action) or SIG_IGN (ignore). Using it to establish a handler is non-portable due to varying semantics (e.g., System V resets the handler to SIG_DFL and does not block further signals, while BSD blocks signals and does not reset the handler).
- **BSD vs. System V**: Your description of the differences is correct:
    - **System V**: Resets the signal disposition to SIG_DFL and does not block further signals, risking recursive handler invocations or missed signals.
    - **BSD**: Blocks further instances of the signal during handler execution and does not reset the disposition, which is safer but still not ideal without explicit control.
    - **Linux**: Uses System V semantics for signal(), making sigaction() the preferred choice for reliable handling.
- **POSIX Recommendation**: You correctly state that sigaction() is the POSIX-recommended interface because it allows fine-grained control over signal behavior (e.g., SA_RESTART, SA_NODEFER, SA_RESETHAND).

#### 5. Other Concepts

- **Client and Server Roles**: Your mention of identifying roles between client and server is relevant but incomplete in the provided text. In signal-based communication, the server typically sends signals (e.g., via kill()) to the client, which handles them. Clarifying these roles is crucial for designing the project’s architecture.
- **Limits of Signals**: Your points about async interruptions, race conditions, and non-queued signals are accurate. Signals are inherently asynchronous and can interrupt the program at unpredictable times, leading to issues like corrupted data structures or missed signals.
- **Table of Commands**: Your table summarizing kill, pause, and signal is partially correct but incomplete:
    - **kill**: Sends a signal to a process (man 2 kill). Your table lacks a summary, but it’s implied as a signal-sending mechanism.
    - **pause**: Correctly described as suspending the process until a signal is delivered (man 2 pause). It returns -1 with errno set to EINTR when interrupted by a signal handler.
    - **signal**: Correctly referenced as part of man 7 signal, but the summary is missing in your text.
#### 6. Inline Vocabulary

Your explanation of volatile and related concepts is **accurate**:

- **volatile sig_atomic_t**: Ensures atomic updates and prevents compiler optimizations that could lead to stale values.
- **Memory-Mapped I/O**: volatile is indeed used for memory-mapped I/O, where hardware can change values outside the program’s control.
- **Longjmp and Signal Handlers**: Correctly noted that volatile preserves values across longjmp and ensures reliable communication in signal handlers.

### Clarifications and Corrections

1. **Race Condition Workaround**: While your usleep(100) solution avoids the pause() issue, it’s a busy-waiting approach, which may not be acceptable in 42 projects due to performance concerns. A better approach (if allowed) would be to use sigaction() with proper signal masking or sigsuspend() to atomically handle signals.
2. **School Restrictions**: You claim the requirements make reliable signal handling "impossible," which is an exaggeration. It’s challenging but not impossible if you carefully design around the limitations (e.g., using sigaction() with a minimal handler and polling a flag).
3. **Signal Queuing**: You mention signals are not queued, which is true for standard signals but not for real-time signals (SIGRTMIN to SIGRTMAX), which are queued in POSIX systems. However, 42 projects likely don’t allow real-time signals.
4. **Table Completeness**: The table is incomplete (e.g., missing summaries for kill and signal). Additionally, sigset and sigaction are mentioned but not fully explained in your text.

### Tricks and Tips for Handling Signals in 42 School Projects

Given the constraints (e.g., limited to signal() or sigaction, no sigprocmask or sigsuspend), here are key strategies to succeed in your project:

#### 1. Use sigaction() Instead of signal()

- **Why**: sigaction() is more reliable and portable. It allows you to:
    - Prevent signal handler reset (SA_RESETHAND).
    - Block other signals during handler execution (sa_mask).
    - Control whether system calls are restarted (SA_RESTART).
```c
#include <signal.h>

#include <stdio.h>

#include <unistd.h>

volatile sig_atomic_t signal_received = 0;

void handler(int sig) {

signal_received = 1;

}

int main() {

struct sigaction sa = {0};

sa.sa_handler = handler;

sa.sa_flags = SA_RESTART; // Restart interrupted system calls

sigemptyset(&sa.sa_mask); // Don't block additional signals (adjust as needed)

sigaction(SIGUSR1, &sa, NULL);

while (!signal_received) {

usleep(100); // Poll flag periodically

}

printf("Signal received\n");

return 0;

}
```

- **Tip**: Always use sigaction() unless explicitly required to use signal(). Set sa_flags and sa_mask appropriately to avoid race conditions.

#### 2. Minimize Signal Handler Code

- Keep handlers minimal and async-signal-safe. Only set a volatile sig_atomic_t flag or perform simple operations listed in POSIX’s async-safe functions (man 7 signal).
- Avoid printf(), malloc(), or other non-safe functions in handlers.
- **Example**:
```c
volatile sig_atomic_t signal_received = 0;

void handler(int sig) {

signal_received = 1; // Safe

}
```

#### 3. Avoid pause() for Synchronization

- As you noted, pause() is problematic due to race conditions. Instead, use a polling loop with usleep() or sleep() to check a flag, as you did:
```c
while (!signal_received) {

usleep(100); // Short sleep to avoid busy-waiting

}
```

Trade-off: This consumes CPU cycles. Minimize the sleep duration (e.g., 10-100μs) to balance responsiveness and efficiency.

#### 4. Use volatile sig_atomic_t Correctly

- Always use volatile sig_atomic_t for flags shared between signal handlers and the main program.
- Ensure atomic operations (e.g., single read/write) to avoid data corruption.
- **Example**:
```c
volatile sig_atomic_t signal_received = 0;

void handler(int sig) {

signal_received = 1; // Atomic write

}

int main() {

if (signal_received) { // Atomic read

// Handle signal

}

}
```

#### 5. Handle Signal Delivery Timing

- Signals can arrive at any time, so design your program to tolerate missed or early signals:
    - Use a flag to track signal receipt and poll it periodically.
    - If multiple signals are expected, consider a counter:
```c

volatile sig_atomic_t signal_count = 0;

void handler(int sig) {

signal_count++;

}
```


#### 6. Client-Server Signal Communication

- **Roles**:
    - **Server**: Sends signals to the client using kill(pid, SIGUSR1). Must know the client’s PID (e.g., passed via command-line arguments or a file).
    - **Client**: Sets up a signal handler and waits for signals from the server.
- **Example Workflow**:
    - Client registers a handler for SIGUSR1 and sets a flag.
    - Server sends SIGUSR1 to the client’s PID.
    - Client polls the flag and proceeds when set.
- **Tip**: Use getpid() in the client to print its PID for the server to use. Ensure the server has the correct PID to avoid signaling the wrong process.

#### 7. Debugging Signal Issues

- **Log Signal Receipt**: Use async-safe methods to log signals (e.g., write to a file descriptor instead of printf()):
```c
#include <unistd.h>

void handler(int sig) {

signal_received = 1;

write(STDERR_FILENO, "Signal received\n", 16); // Async-safe

}
```


- **Test Signal Delivery**: Use kill -USR1 from the command line to simulate server signals.
- **Check errno**: If pause() or other system calls fail, check errno for EINTR to handle interrupted calls.

### 8. Work Around School Restrictions

- If sigprocmask() or sigsuspend() are not allowed, rely on polling with usleep() or redesign the project to minimize signal dependency.
- If allowed, use sigaction() with a blocked signal mask to prevent signals from interrupting critical sections:

#### 9. Understand Signal Semantics

- **System V vs. BSD**: On Linux, signal() uses System V semantics (resets handler to SIG_DFL, does not block signals). Always use sigaction() to avoid surprises.
- **Interrupted System Calls**: If SA_RESTART is not set, system calls like read() or write() may return -1 with errno set to EINTR. Handle this explicitly:

#### 10. Project-Specific Tips

- **Mindset**: As you noted, the project’s difficulty reflects the developer’s problem-solving skills. Embrace the challenge by breaking it into smaller problems (e.g., signal setup, communication protocol, error handling).
- **Avoid Easy Choices**: Instead of hacks like long sleep() calls, design robust solutions within the constraints (e.g., polling with short sleeps or restructuring the program flow).
- **Test Edge Cases**: Test scenarios where signals arrive early, late, or multiple times to ensure your program doesn’t hang or crash.

#### 11. Inter-Process Communication (IPC)

- Signals are a basic form of IPC but are unreliable for complex communication. If the project allows, consider alternatives like pipes, FIFOs, or shared memory (if permitted by 42 rules).
- For signal-based IPC:
    - Use distinct signals (e.g., SIGUSR1 for one message, SIGUSR2 for another) to differentiate actions.
    - Ensure the client and server agree on the signal protocol (e.g., SIGUSR1 means "proceed").

#### 12. Common Pitfalls

- **Signal Loss**: If multiple signals arrive before the handler processes them, only one may be delivered. Use a counter or redesign to tolerate this.
- **Handler Reentrancy**: Avoid complex logic in handlers to prevent reentrancy issues.
- **Race Conditions**: Always assume signals can arrive at any time and design your logic to handle this (e.g., check flags before and after critical sections).

---

### Expanded Explanation of Key Concepts

#### Signals

- **Purpose**: Signals are asynchronous notifications sent to a process to indicate events (e.g., SIGUSR1 for user-defined events, SIGINT for Ctrl+C). They were designed for simple communication but are not robust for complex synchronization.
- **Limitations**:
    - Not queued (except real-time signals).
    - Can interrupt system calls, requiring SA_RESTART or EINTR handling.
    - Handlers must be async-safe, limiting their functionality.

#### sigaction vs. signal

- **signal()**: Simple but unreliable due to non-portable semantics.
- **sigaction()**: Preferred for its explicit control over:
    - Signal disposition (handler, ignore, default).
    - Signal masking (sa_mask).
    - Flags like SA_RESTART, SA_NODEFER, SA_RESETHAND.

#### volatile and sig_atomic_t

- **volatile**: Prevents compiler optimizations that assume a variable’s value doesn’t change unexpectedly. Essential for variables modified by signal handlers or hardware.
- **sig_atomic_t**: Ensures atomic reads/writes, even in asynchronous contexts. Always use with volatile for signal handler flags.

#### Client-Server Architecture

- **Client**: Typically waits for signals and responds (e.g., by setting a flag or performing an action).
- **Server**: Sends signals to trigger client actions. Must know the client’s PID.
- **Protocol**: Define a clear signal-based protocol (e.g., SIGUSR1 means "data ready," SIGUSR2 means "shutdown").

#### POSIX Signal Primitives

- If allowed, these would solve many issues:
    - **sigprocmask()**: Blocks/unblocks signals to protect critical sections.
    - **sigsuspend()**: Atomically sets a signal mask and waits for a signal, avoiding race conditions.
    - **signalfd()**: Modern way to handle signals via file descriptors (unlikely allowed in 42 projects).

Sample robut signal handling

```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t signal_received = 0;

void handler(int sig) {
    signal_received = 1;
    write(STDERR_FILENO, "Signal received\n", 16); // Async-safe
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1); // Block SIGUSR1 during handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Client PID: %d\n", getpid()); // For server to send signal

    while (!signal_received) {
        usleep(100); // Poll flag
    }

    printf("Proceeding after signal\n");
    return 0;
}
```

- Run the server
```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <client_pid>\n", argv[0]);
        return 1;
    }

    pid_t client_pid = atoi(argv[1]);
    if (kill(client_pid, SIGUSR1) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGUSR1 to %d\n", client_pid);
    return 0;
}
```

	Summary  

Your analysis of the signal handling issues and the limitations imposed by the 42 school project requirements is accurate. The restrictions (e.g., no sigprocmask or sigsuspend) make reliable signal handling challenging, but not impossible with careful design. By using sigaction(), minimal handlers, volatile sig_atomic_t flags, and polling loops, you can mitigate race conditions and build a robust solution. The key is to understand the asynchronous nature of signals, avoid unsafe functions in handlers, and test edge cases thoroughly.

If you have specific details about the project (e.g., allowed functions, exact requirements), I can tailor the advice further. Let me know if you want help with a particular aspect or more code examples!


### Overview of interactions signals

The sigaction function is a  POSIX-compliant interface for managing singal handling in C programs, offering more control and reliability than the older `signal` function. It allows us to specifiy how a  process handles specific sinals, including setting custom handlers, controlling signal maskign and configuration behavior like system call restarting. Below, I'll provide a detailed explanation of how `sigaction` works, the associated structure s ( `struct sigaction, sigset_t, and related types`)
and their interactions in signal handling. 


we are going to cover some considerations before diving more into this deeply.
Understand how sigaction work and expect us to configure

prototype of a handler :
When the `SA_RESTART` flag is specified it is equivalently to set it to `0` the signal handler address is passed via the act.sigaction field. This handler takes one argument as follows:
This signal is meaningful when we want only to treat the signal as it is.
`void handler(int sig)`
or
When the `SA_SIGINFO` flag is specified in `act.sa_flags` the signal handler addres is passed via the act.sigaction field. This handler takes three arguments as follows:
`void handler(int sig, siginfo_t *info, void *ucontext);`

- SA_RESTART flag restarts interrupted system calls
- `SA_SIGINFO` flag provides sender PID
those three arguments are : 
**sig** -> The number of signal that caused invocation of the handler
**info** -> a pointer to struct siginfo, which is a convenient structure containing further information about the signal describe as below :LiAArrowDown:
`ucontext` we don't use it into this project but it is good to know that this variable contain the signal content that was saved on the space of the user space stack by the kernel itself.
```c
//The siginfo_t data type is a structure with the following fields:

    siginfo_t 
	{
		   int      si_signo;     /* Signal number */
		   int      si_errno;     /* An errno value */
		   int      si_code;      /* Signal code */
		   int      si_trapno;    /* Trap number that caused
                                         hardware-generated signal
                                         (unused on most architectures) */
		   pid_t    si_pid;       /* Sending process ID */
		   uid_t    si_uid;       /* Real user ID of sending process */
		   int      si_status;    /* Exit value or signal */
		   clock_t  si_utime;     /* User time consumed */
		   clock_t  si_stime;     /* System time consumed */
		   union sigval si_value; /* Signal value */
		   int      si_int;       /* POSIX.1b signal */
		   void    *si_ptr;       /* POSIX.1b signal */
		   int      si_overrun;   /* Timer overrun count;
										 POSIX.1b timers */
		   int      si_timerid;   /* Timer ID; POSIX.1b timers */
		   void    *si_addr;      /* Memory location which caused fault */
		   long     si_band;      /* Band event (was int in
									 glibc 2.3.2 and earlier) */
		   int      si_fd;        /* File descriptor */
		   short    si_addr_lsb;  /* Least significant bit of address
									 (since Linux 2.6.32) */
		   void    *si_lower;     /* Lower bound when address violation
									 occurred (since Linux 3.19) */
		   void    *si_upper;     /* Upper bound when address violation
									 occurred (since Linux 3.19) */
		   int      si_pkey;      /* Protection key on PTE that caused
								 fault (since Linux 4.6) */
		   void    *si_call_addr; /* Address of system call instruction
									 (since Linux 3.5) */
		   int      si_syscall;   /* Number of attempted system call
                                         (since Linux 3.5) */
		   unsigned int si_arch;  /* Architecture of attempted system call
                                         (since Linux 3.5) */
    }

```


```c
//The sigaction structure is defined as something like:

	   struct sigaction
	   {
		   void     (*sa_handler)(int);
		   void     (*sa_sigaction)(int, siginfo_t *, void *);
		   sigset_t   sa_mask;
		   int        sa_flags;
		   void     (*sa_restorer)(void);
	   };


```


## kill
` kill [options] <pid> [...]`
kill command as a default behavior and gained its name for that primar behavior which is `TERM` alias terminating a process

but kill what it does is to communicate with process id to do something
for instance in our project we have to use `SIGUSR1` or `SIGUSR2` 
which is one of the primor difficulty and we'll see it later.

first we must know how to use it 
here is a logical use of discovering from the minishell

```c
kill -l // we akcnowledge all teh SIGINT we can use by name
--signal 
```

### Some rules about signal safety
### What is a function unsafe ?
When performing buffered I/O on a file, the `stdio` functions (such as `printf(3)`) maintain an internal, statically allocated buffer along with associated counters and pointers. These track both how much data is in the buffer and the current position within it.

If the main program is interrupted by a signal **while inside a `stdio` function** like `printf(3)`, and the signal handler itself calls another `stdio` function (such as `printf(3)` again), both calls will operate on this **shared, inconsistent internal state**. This can lead to **corrupt buffers, lost output, undefined behavior, or deadlocks.**

to avoid these problems, signal handlers should **only call functions that are explcitly mares as async-signal-safe** by POSIX (like `write`) and never use buffered output I/O functions like `printf()` inside a signal handler. 

## so using singleton is really a good idea ?

let's unpack this carefully because we need to nuance the vocabulary here.
> The problem isn't the singleton itself  because it acts like a global pointer, the danger is `how functions behave when interrupted`

Example where singleton is fine
```c
// singleton to store a global flag
typedef struct {
    sig_atomic_t got_signal;
} global_state_t;

global_state_t *get_state(void) {
    static global_state_t state = { 0 };
    return &state;
}

```

> [!NOTE]
we can't safely use dynamic array, vectors, lists...
  
  

## SUMMARY
The code of minitalk is about making the exchange of signal betweeen a server and a client the more reliable we can get but for truly mission-critical applications, we would need to consider using other IPC mechanisms like `pipes, messages queues, or sockets`
### COMMON ISSUES
- unsafe function due to async issues created by buffe I/O, BUFFERING, LOCKING, MUTATING SHARED STATE IN A NON-REENTRANT WAY
- volatile state is not enough it just help out the program to get access to the more recent value avoiding letting the compiler just decide to take from the cache.
- `signal coalescing` standard singal (SIGUSR1, SIGUSR2) are not queued they can be lost
- `race conditions` signals can arrive between checking and waiting
- `timing issues` : fast senders can overwhel show receivers
- `system overload` : heavy system load can introduce delays or also crash
- `process scheduling`: OS scheduling can introduce scheduling and cause the signal loss
- `signal loss` : signal can still be lost in extreme conditions, no matter what we intend to do it's impossible to get 100% reliablility.
- `limit capacity size of arguments` arguments can barely hold 150000 bytes of characters in its content. we would need more to redirect into the stdin and read it but the subject force us to use the command line arguments so we are limited here.
### COMMON SOLUTIONS OF OPTIMIZATIONS

using `volatile sig_atomic_t` for the signal flag
##### 1. Using `sigaction()` instead of `signal()`
- `SA_SIGINFO` flag provides sender PID
- `SA_RESTART` flag restarts interrupted system calls
##### 2. Acknowledgment system:
- server send ACK back to client for each bit
- Clients wait for ACK before sending next bit
- Timeout and retry mechanism
- Ownership is a synchronization mechanism that ensures only one client at a time can send data to the server, preventing race conditions and data corruption.
##### 3. Signal-safe functions only:
`man signal-safety`
##### 4. Proper signal blocking

##### 5. (forbidden) best practice use mask, real-time signals, exponential backoff, sequence numbers, shared  memory, pipes, sockets...
### Representation bit terminal

The terminal is act like a state machine to represent a n-byte character representation.

![[representation byte terminal]]

Let's break down how this state machine work

- 0xxxxxxx -> Stays  in SingleByte state (ASCII character)
- `110xxxxx` -> Enters twoBytes state (expect one more byte)
- `1110xxxx` ->Enter three bytes state (expect two more bytes)
- `11110xxx` -> Enter fourbytes state (expect three more bytes)

3. Continuation bytes:
	- Must start with 10 followed by 6 data bits
	- Terminal verifies each continuation byte matches this pattern
	- Invalid patterns trigger ErrorState and reset

### let's take for example '€'

`first byte: 11100010 (€ symbol)` 
`Second byte: 10100000 (€ symbol)
Third byte: `10101110` 
Unused reserved for future

The key to prevent conflict with the ASCII table  is the stricti validation process shown in the diagram:
	1. sequential validation:
		1. terminal never interprets bytes until the entire sequence is validated
		2. each byte must match its expected pattern exactly
		3. invalid bytes trigger immedaite reset to SingleByte state
	2. Why ASCII can't conflict:
		1. ASCII bytes (0xxxxxxx) never appears as `continuation bytes` (10xxxxxxx)
		2. unicode multi-byte sequences never starts with valid ASCII patterns
		3. Once in a multi-byte, singl ASCIII byte would cause validation failure
	3. Practical protection
		1. Terminal buffer incoming bytes until sequence completion
		2. Partial sequences trigger reset rather than display
		3. Invalid sequences trigger rester rather than display
		4. This ensures consistent interpolation regardless of transmission order.
The strict state-based approach guarantess that terminals can reliably distinguish between ASCII and UNICODE sequences, even when receiving bytes bit-by-bit, preventing any potential confusion between different encoding types

![[minitalk project idea]]![[minitalk state machine]]
### UNDERSTANDING THE COMMUNICATION FLOW

##### 1. PID registration phase:
- Each client registers its PID with the server using `sigaction` 
- Server stores PIDs in a map structure for tracking multiple clients
- Registration ensures proper signal routing and client identification
#### 2. Signal processing
- Server uses `sigaction` with `SA_SIGINFO` flag to access `siginfo_t` structure
- `si_pid` field in  `siginfo_t` identifies the sending client
- Server maintains separate character buffers for each client
####  3. Timeout & Retry Mechanism
- Client waits for Ack within tiemout period
- if no ACK received, client retries the signal
- Server maintains signal sequence tracking per client

![[server state]]
Thes server state machine is really simple to understand
1. server receives either `SIGUSR1` or `SIGUSR2` 
2. usr `siginfo_t` to identify client and update their buffer
3. verifies if 8 bits have been received
4. Processes full character and send `ACKS`
asyncrhonly active the clients, currently processing, generate the queue of clients waiting to send 
server switches between clients based on signal receipt
Each client's state is maintained indenpenedently


### let's look at the structure of sigaction
- `sa_handler` : basic signal handler (not used in Minitalk)
- `sa_sigaction` : Advanced handler used in Minitalk for PID tracking
- `sa_mask` : Signal mask to prevent `race conditions` 
- `sa_flags` : enables SA_SIGINFO for `siginfo_t` access

### Let's take a look at siginfo_t structure
- `si_pid` : Identifies sending client's process ID
- `si_signo` : indicates signal type (SIGUSR1/SIGUSR2)
- `si_code`: Provides additional signal context
- `si_uid` : User ID of sending process

### Sigset_t structure:
- Manage signal blocking during critical operations
- prevint signal racing conditions
- Ensure atomic oeprations in signal handlers

### Checksum
1. The server expects a checksum bits after message
2. Compares received vs calcualted checksum
3. message integrity verified
4. integrity check failed

5. Client status management
		- Successful checksum -> Client marked as reliable
		- Failed checksum ->client marked as errored
		- Error clients remain in system but with lower priority
		- System maintains separate checksum status per client

All of that ensure reliable message transmission while maintaining the system's ability to handle multiple clients and recover from errors. 

this complete system enables reliable communication between multiple clients and teh server, with proper signal hanlding, client management, and error recovery mechanisms.


### Relationships between sigaction and sigset_t
![[relationship sigaction, sigset]]

`sa_mask` benefits is to blocks signals during handler execution
it has not need for explit blocking/unblocking calls
and ensure hadnler complete wihtout interruption

### Race condition
- Signal delivery is atomic - either fully delivered or not at all
- blocked signals become `pending` rather than beign lost
- handler execution is guaranteed to complete wihout interruption
### Practical advantages
- simpler code with fewr potential race conditions
- Automatic signal blocking during crtitical operations
- no need to manage signal masks manually


![[server state machine]]

## client owns the transmission slot of it
the ownership is needed to prevent multiplle clients from sending data at the same time, which woud corrupt the communication. 
To ensure only one client can send its message, and others must wait until  the slot is free.

to check the ownership we compare the client's pid to current_client_pid and check the `transmission active`
if a client does not own the slot, it must wait until the slot if free.

![[send bit server]]

![[huffman algo]]

 The PID (process ID) is shared between the client and server using UNIX signals and teh siginfo_t structure
how it works: 
- clien knows server PID:
	- the client is started with the server's PID as a command-line argument
	- this client uses this PID to send signals to the server using `kill(server_pid, SIGNAL)`
	- `siginfo-t`contains teh sender's PID in the `si_pid` fielld
	- The server saves teh client's PID in its state (`actual_pid` , `client_pid`)
	- The cliennt gets the server's  PID from  the user and send signals to it
	- The server get the client's PID from the signal handler and can reply using signals

### transmission active if  anew client tries to connect 
while another is active the server rejects the connection (sends a busy signal)
There s no queuing acive or storing the waiting list clients. only one cient can transmit, and others must retry or wait externally


![[machine communication]]