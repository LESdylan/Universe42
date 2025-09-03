```c
x = 42;
y = 24;

```

The CPUs are designed to be FAST, not intuitive. They run the code out-of-order because:

`Pipelining`
CPU's break instructions into tiny steps (fetch, decode, execute, store...)
while one instruction is storing a result, the next can already be decoding.

Out of order exectuion:
they maximize the core usage minimizin the idle time. so if instructions #5 rely on #2 the compiler will might run 2 or 5 but not both.

