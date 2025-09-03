The ACK protocol is called `reliable` in theory because:
- The client send one bit, then waits for an explicit acknowledgement from the server before sending teh next bit
- if the client does not receive teh ACK, it does not proceed so in principle, no data sould be lost
However in practice with UNIX signals (SIGUSR1/SIGUSR2):
- Standard signals are not `queued` : if a signal arrives while another of the same type is pending, it is lost.
- if the client or server is too fast, or the OS Is busy, signals can be missed.
- the protocol is only as reliable as the underlying mechanism (here UNIX-signals) which is not designed for high-reliability data transfer

for true reliability we need mechanisms that guarantees delivery and queuing `like sockets, pipes, or real-time signals`
in [[READMES/minitalk]] make the signals exchange utterly reliable is impossible based on UNIX system and 42 school requirements. we have to make it as best as we can. that's it

[[like sockets]]
[[pipes PROTOCOL]]
[[REAL TIME SIGNALS]]
[[queued signals]]
[[sockets signals]]

to minimize signal loss:
- we use only one signal at a time ( wait for ack for each signal)
- add a small usleep in the busy-wait loop
- on the server, send the ACK as the last action in the signal handler
- avoid any heavyprocessing in the signal handler
- if possible use real-time signals (SIGRTMIN +N) which are queued, bi
The best we can do is for minitalk to : 
from the client:

```c
while (!ack)
	usleep(N);
```
