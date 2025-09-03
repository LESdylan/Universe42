[How does the processor handle conditions?](https://stackoverflow.com/questions/683126/how-does-the-processor-handle-conditions)

[https://github.com/helight/xblog](https://github.com/helight/xblog)

[Máscara (informática)](https://es.wikipedia.org/wiki/M%C3%A1scara_\(inform%C3%A1tica\))

[docs.arduino.cc](https://docs.arduino.cc/learn/programming/bit-mask/)

# how work the bitwise operator

## Bitwise operator in C

```c
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a & b;  // 0001 in binary, which is 1 in decimal
```

### OR `|`:

```c
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a | b;  // 0111 in binary, which is 7 in decimal
```

### XOR `^`

```c
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a ^ b;  // 0110 in binary, which is 6 in decimal
```

### NOT `~`

```c
int a = 5;
int result = ~a;
```

### LEFT Shift `<<` :

```c
int a = 5;  // 0101 in binary
int result = a << 1;  // 1010 in binary, which is 10 in decimal
```

### Right SHIFT `>>` :

```c
int a = 5;  // 0101 in binary
int result = a >> 1;  // 0010 in binary, which is 2 in decimal
```

- **AND (`&`)**: `0101 & 0011` results in `0001` (1 in decimal).
- **OR (`|`)**: `0101 | 0011` results in `0111` (7 in decimal).
- **XOR (`^`)**: `0101 ^ 0011` results in `0110` (6 in decimal).
- **NOT (`~`)**: `~0101` results in `1010` (for a 4-bit representation, which is -6 in decimal using two's complement).
- **Left Shift (`<<`)**: `0101 << 1` results in `1010` (10 in decimal).
- **Right Shift (`>>`)**: `0101 >> 1` results in `0010` (2 in decimal).

---

The bit mask is design patterrn to access bits in a byte, each combination of bit position would be designed as a signature or an indice of function, process, an object or anything like that that gather information. The whole idea is to facilitate the computing of the CPU avoiding to consume more ressources and scaling up steps.

```c
static void set_flag_bit_internal(int flag_char, t_flags *flags)
{
    static const unsigned int flag_map[128] = {
    ['0'] = ZERO_FLAG,
    ['-'] = LEFT_FLAG,
    ['.'] = DOT_FLAG,
    ['#'] = HASH_FLAG,
    [' '] = SPACE_FLAG,
    ['+'] = PLUS_FLAG,
    ['*'] = STAR_FLAG
    };

    flags->flags_bits |= flag_map[flag_char & 0x7F];
}
```

• This function uses a static array `flag_map` to map flag characters (e.g., '0', '-', '.', '#', ' ', '+', '*') to their corresponding flag bits (e.g., `ZERO_FLAG`, `LEFT_FLAG`, `DOT_FLAG`, `HASH_FLAG`, `SPACE_FLAG`, `PLUS_FLAG`, `STAR_FLAG`).

The `flag_char` is masked with `0x7F` to ensure it falls within the range of the array `127`

```c
#define ZERO_FLAG   0x01  // 00000001 in binary
#define LEFT_FLAG   0x02  // 00000010 in binary
#define DOT_FLAG    0x04  // 00000100 in binary
#define HASH_FLAG   0x08  // 00001000 in binary
#define SPACE_FLAG  0x10  // 00010000 in binary
#define PLUS_FLAG   0x20  // 00100000 in binary
#define STAR_FLAG   0x40  // 01000000 in binary
```

# Demonstration

let’s consider the following t_flags structure:

```c
typedef struct {
    unsigned int flags_bits;
    int precision;
} t_flags;

t_flags flags = {0, -1}; //flags_bits = 0 (no flags set), precision = -1 (default)

```

```c
set_flag_bit_internal('0', &flags);
//flags_bits |= LEFT_FLAG
// flag_bits = 00000001 | 00000010
// flag_bits = 00000011 (ZERO_FLAG and LEFT_FLAG)
```

```c
handle_dot(&flags, NULL);
// set_flag_bit_internal('.', &flags)
// flags_bits |= DOT_FLAG
// flags_bits = 00000010 | 00000100
// flags_bits = 00000110 (LEFT_FLAG and DOT_FLAG are set)
// flags_bits &= ~ZERO_FLAG
// flags_bits = 00000110 & 11111110
// flags_bits = 00000110 (ZERO_FLAG remains cleared, LEFT_FLAG and DOT_FLAG remain set)
// flags.precision = 0
```

## Example

```c
int	ft_print_char(int c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.flags_bits & LEFT_FLAG)
	{
		count += ft_print_c(c);
		count += ft_print_width(flags.width - 1, 0, 0);
	}
	else
	{
		count += ft_print_width(flags.width - 1, 0, 0);
		count += ft_print_c(c);
	}
	return (count);
}
```

in the ft_printf_char function, the bitwise operations are used to check wheher specific flags are set in the `flags.flags_bits` field. This allows the function to determine how to format the output based on the flags provided.

```c
if (flags.flags_bits & LEFT_FLAG)
```

the bitwise operator `&` is used ot check if a specific bit is set in a bitmask. in this case

in other words, we’re looking for

<aside> 💡

the bitwise AND operator is used to check if a specific bit is set in a bitmask

</aside>

In this exammple , `flags.flags_bits & LEFT_FLAG` checs whether the `LEFT_FLAG` bit is set in the `flags.flags_bits` field

Suppose `flags.flags_bits` is `00000010` and LEFT_FLAG is 0x02 (Which is `00000010` in binary

- The condition `flags.flags_bits & LEFT_FLAG` will be evaluated as follows:

```c
000000010
& 00000010
----------
00000010 result (non-zero, true)
```

if `flags.flags_bits` does not have the `LEFT_FLAG` bit set (e.g, 000000000)

<aside> 💡

The use of bitwise operations allows the function to check and handle multiple flags efficiently. In the ft_print_char function, the `LEFT_FLAG` determinves whether the character should be left-aligned or right-aligned within the specified width.

</aside>

Thi was the demonstration but now let’s take a look at what happen if we work with this format specifier `"the character is %c"`

`%c` : Print a single character

`50` : The width of the field in which the character will be printed is 50 characters wide.

```c
t_flags flags;
flags.flags_bits = 0;
flags.width = 50;
```

# why bitmap is usually faster in condition than others..

let’s check in assembly code something easy between two integers `jj` and `ii` . If `jj` is greater than `ii` , it prints the string “jj > ii”

## Setup Stack Frame :

```c
leal    4(%esp), %ecx
andl    $-16, %esp
pushl   -4(%ecx)
pushl   %ebp
movl    %esp, %ebp
pushl   %ecx
subl    $20, %esp
```

## Initialize Variable :

```c
movl    $10, -8(%ebp)    ; ii = 10
movl    $20, -12(%ebp)   ; jj = 20
```

## Comparison and Conditional Jump:

```c
movl    -12(%ebp), %eax  ; eax = jj
cmpl    -8(%ebp), %eax   ; Compare jj (eax) with ii
jle .L2                  ; Jump to .L2 if jj <= ii
```

## Print String if condition met:

```c
movl    $.LC0, (%esp)    ; Load address of string "jj > ii \\n"
call    puts             ; Call puts to print the string
```

## End function

```c
.L2:
movl    $0, %eax
addl    $20, %esp
popl    %ecx
popl    %ebp
leal    -4(%ecx), %esp
ret
```

<aside> ↕️

The CPU performs a series of setup instructions. It starts with initializing variable `ii`and `jj` Performs a comparison `cmpl` and a conditional jump `jle`

If the condition is met it executes the printing

</aside>

# now we check with bitmap

```c
.section    .rodata
.LC0:
    .string "Bit is set\\n"
.text
.globl main
    .type   main, @function
main:
    leal    4(%esp), %ecx
    andl    $-16, %esp
    pushl   -4(%ecx)
    pushl   %ebp
    movl    %esp, %ebp
    pushl   %ecx
    subl    $20, %esp
    movl    $1, -8(%ebp)   ; Set ii with a specific bit pattern, e.g., 1 (0001)
    movl    $2, -12(%ebp)  ; Set jj with a specific bit pattern, e.g., 2 (0010)
    movl    -12(%ebp), %eax
    andl    -8(%ebp), %eax ; Perform bitwise AND between jj and ii
    testl   %eax, %eax     ; Test if result is non-zero
    jz .L2                 ; Jump to .L2 if result is zero
    movl    $.LC0, (%esp)
    call    puts
.L2:
    movl    $0, %eax
    addl    $20, %esp
    popl    %ecx
    popl    %ebp
    leal    -4(%ecx), %esp
    ret
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.3.2-1ubuntu12) 4.3.2"
    .section    .note.GNU-stack,"",@progbits
```

1. **Direct Bit Manipulation**: Bitwise operations directly manipulate individual bits, making them very efficient.
2. **Single Instruction**: Bitwise operations like AND, OR, and XOR are single instructions that execute in constant time.
3. **Predictable Execution**: No branching or complex comparison logic, leading to fewer CPU cycles and predictable execution.

Using bitwise operations can significantly reduce the number of instructions and CPU cycles required, especially in cases where multiple conditions or flags need to be checked. This efficiency is why bit masking is preferred in performance-critical application