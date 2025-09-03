SIGUSR1 AND `SIGUSR2` are signal already defined by the system, we cannot redefine them  because they are already defined by the system headers. This causes  a redefinition error. 


# to test independently signals without server
we can test our signal handler without depending on the server by sending a signal to our client process manually from another terminal.
for example :
1. Run our client:
```bash
./client <any_pid> <any_message>
```
it will wait in a loop
2. In another terminal, find the PID using grep or `prgep`
3. send a signal to it
```bash
kill -SIGUSR1 <client_pid>
# or
kill -SIGUSR2 <client_pid>
```
the handler will print the message when it receives the signal. This way we can test the handler independently of the server

```bash
Client PID: 2170794
Sent SIGUSR2(12) for bit 7 of character 'c'
Sent SIGUSR1(10) for bit 6 of character 'c'
Sent SIGUSR1(10) for bit 5 of character 'c'
Sent SIGUSR2(12) for bit 4 of character 'c'
Sent SIGUSR2(12) for bit 3 of character 'c'
Sent SIGUSR2(12) for bit 2 of character 'c'
Sent SIGUSR1(10) for bit 1 of character 'c'
Sent SIGUSR1(10) for bit 0 of character 'c'
Sent SIGUSR2(12) for bit 7 of character 'l'
Sent SIGUSR1(10) for bit 6 of character 'l'
Sent SIGUSR1(10) for bit 5 of character 'l'
Sent SIGUSR2(12) for bit 4 of character 'l'
Sent SIGUSR1(10) for bit 3 of character 'l'
Sent SIGUSR1(10) for bit 2 of character 'l'
Sent SIGUSR2(12) for bit 1 of character 'l'
Sent SIGUSR2(12) for bit 0 of character 'l'
Sent SIGUSR2(12) for bit 7 of character 'i'
Sent SIGUSR1(10) for bit 6 of character 'i'
Sent SIGUSR1(10) for bit 5 of character 'i'
Sent SIGUSR2(12) for bit 4 of character 'i'
Sent SIGUSR1(10) for bit 3 of character 'i'
Sent SIGUSR2(12) for bit 2 of character 'i'
Sent SIGUSR2(12) for bit 1 of character 'i'
Sent SIGUSR1(10) for bit 0 of character 'i'
Sent SIGUSR2(12) for bit 7 of character 'e'
Sent SIGUSR1(10) for bit 6 of character 'e'
Sent SIGUSR1(10) for bit 5 of character 'e'
Sent SIGUSR2(12) for bit 4 of character 'e'
Sent SIGUSR2(12) for bit 3 of character 'e'
Sent SIGUSR1(10) for bit 2 of character 'e'
Sent SIGUSR2(12) for bit 1 of character 'e'
Sent SIGUSR1(10) for bit 0 of character 'e'
Sent SIGUSR2(12) for bit 7 of character 'n'
Sent SIGUSR1(10) for bit 6 of character 'n'
Sent SIGUSR1(10) for bit 5 of character 'n'
Sent SIGUSR2(12) for bit 4 of character 'n'
Sent SIGUSR1(10) for bit 3 of character 'n'
Sent SIGUSR1(10) for bit 2 of character 'n'
Sent SIGUSR1(10) for bit 1 of character 'n'
Sent SIGUSR2(12) for bit 0 of character 'n'
Sent SIGUSR2(12) for bit 7 of character 't'
Sent SIGUSR1(10) for bit 6 of character 't'
Sent SIGUSR1(10) for bit 5 of character 't'
Sent SIGUSR1(10) for bit 4 of character 't'
Sent SIGUSR2(12) for bit 3 of character 't'
Sent SIGUSR1(10) for bit 2 of character 't'
Sent SIGUSR2(12) for bit 1 of character 't'
Sent SIGUSR2(12) for bit 0 of character 't'
Sent SIGUSR2(12) for bit 7 of character ''
Sent SIGUSR2(12) for bit 6 of character ''
Sent SIGUSR2(12) for bit 5 of character ''
Sent SIGUSR2(12) for bit 4 of character ''
Sent SIGUSR2(12) for bit 3 of character ''
Sent SIGUSR2(12) for bit 2 of character ''
Sent SIGUSR2(12) for bit 1 of character ''
Sent SIGUSR2(12) for bit 0 of character ''

```

## Racing conditions
The kind of intermittent "stuck" or "hang" in our minitalk tesster is a classic symptom of `race conditions` or `synchronization issues` in handling signal protocol

## Why does this happen
- signal loss or missed ACK:
- The client sends a bit, waits for an ACK from the server. It the ACK signal is missud due to OS scheduling, signal queue overflow, or a bug in our handler. The client will wait forever.
- if the client is not ready to preocesss the incoming signal correclty, leading to deadlock.
- Signal handler reentrancy
- if our signal handler is not reentrant-safe or if you do too much worki inside the handler, signals cna be lost or mishandled
- if the client signals sends signals too fast (not enough `usleep`) teh server may not keep up, and signals can be lost.
- Zombie/defunct processes:
- if the server of client crashes or exits unexpectedly, the testre may hand for a response that won't come.
## Why is it random ?
- non-determinitic scheduling:
	The OS schedules processes and delivers signals in a non-determinitic way. Sometimes everything lines up, sometimes a signal is missed. 
- signal queu limit
		if too many signals are sent quickly, the kernel may drop some, especially if we don't wait for an ACK properly
## How to fix or debug ?
- add timeouts:
	-in our client, after waiting for ACK, add a timeout. If the timeout expires, print anerror and exit.
- Increaeses `usleep`
- Check signal handler logic
- add debug logs
- tests with simple message

# Signal handlers
in C, signal handlers (functions called when a signal like `SIGUSR1` or  `SIGUSR2` is received) must have  aspecific function signature, such as :

```c
void handler(int signum, siginfo_t *info, void *context);
```
in this case we cannot pass custom parameters (like a pointer to our data structure) directly to a signal hanlder, because the operating system calls this function and only provides the signal number and some system info

if we want our signal handler to acces our program's  data, we have two main options:
1. **Global variable**:
2. [[singleton]]:
	Instead of a global variable, we can use the singleton accessor function.
	This is function that stores a static pointer to our data structure
	When we initialize our program, we call this function with our structure address
	in our signal handler, we call the same function with `NULL` to retrieve the stored pointer