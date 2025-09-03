## Portable code

stdint has been introduced by the programmers to create more portable code. This header is particularly useful for embedded manipulation of hardware specifici I/O registers requiring
integer data of fixed widths. specific locations and exact alignments. 

| Specifier  | Signing  | Bits | Bytes | Minimum Value                                | Maximum Value                                  |
| ---------- | -------- | ---- | ----- | -------------------------------------------- | ---------------------------------------------- |
| `int8_t`   | Signed   | 8    | 1     | −27 which equals −128                        | 27 − 1 which is equal to 127                   |
| `uint8_t`  | Unsigned | 8    | 1     | 0                                            | 28 − 1 which equals 255                        |
| `int16_t`  | Signed   | 16   | 2     | −215 which equals −32,768                    | 215 − 1 which equals 32,767                    |
| `uint16_t` | Unsigned | 16   | 2     | 0                                            | 216 − 1 which equals 65,535                    |
| `int32_t`  | Signed   | 32   | 4     | −231 which equals −2,147,483,648             | 231 − 1 which equals 2,147,483,647             |
| `uint32_t` | Unsigned | 32   | 4     | 0                                            | 232 − 1 which equals 4,294,967,295             |
| `int64_t`  | Signed   | 64   | 8     | −263 which equals −9,223,372,036,854,775,808 | 263 − 1 which equals 9,223,372,036,854,775,807 |
| `uint64_t` | Unsigned | 64   | 8     | 0                                            | 264 − 1 which equals 18,446                    |
|            |          |      |       |                                              |                                                |
## int8_t

## uint8_t
## int16_t
## uint16_t
## int32_t
## int64_t
## uint64_t

## uint32_t
- a `uint32_t` is a 32-bit unsigned integer, which provides exactly 4 bytes (32 bits of storage). This is ideal for representing colors in formats like RGB or RGBA, where each color channel (red, green, blue, and optionally alpha) is typically stored as an 8-bit value (0-255)
- common colors format:
	- RDB: 3 channels (reg, green, blue), each 8 bits, often padded with 8 unused bits (e.g., 00RRGGBB)
	- RGBA: 4 channels (reg, green, blue, alpha),each 8 bits (e.g., 0XRRGGBBAA)
A `uint32_t` allows all color channels to be stored in a single integer, which is efficient memory and for processing datas.

> [!NOTE]
> A `uint32_t` alligns perfectly with these formats, making it easy to pass color data to GPUs or display systems without additional conversion


## `void*`
- a genereic pointer type in C that can piont to any data type (e.g., `int`, `struct`)
- it represents a memory address but carries no infromation about the type or size of the data it points to
- Size: matches teh system's pointer size (32 bits on 32-bit system, 64 bits on a 64-bit system)
- used for: Type agnositc pointer storage, passing pointers to functions, or abstracting
## Uintptr_t
-  An unsigned integer type defined in `stdint.h` that is guaranteed to be large enough to hold the value of `void*` pointer
- it  is not a pointer; it's an integer that can store teh numerical value of a pointer (i.e. the memory address)
- size: Matches the system's pointer size (e.g., 32 bits on a 32-bit system, 64 bits on a 64-bit system).
- Used for: Converting pointers to integers for arithmetic, storage, or manipulation in a portable way.

> [!EXAMPLE]
    > `return (blend_rgb( (uint32_t)(uintptr_t)color->low, (uint32_t)(uintptr_t)color->mid, t / 0.5f ));`
    > while `uintptr_t` is designed to hold hte value of a `void*` pointer, but they server different purposes.
    > `void*` is  a pointer type used to reference memory.
    > `uintptr_t` is  an integer type used to store the numerical value of a pointer's address
    > we can things of uintptr_t  as a bridge between pointers and integeres. It allows us to safely convert a `void*` to an `integer`

| **Type**       | Pointer type                                  | Unsigned integer type                         |     |
| -------------- | --------------------------------------------- | --------------------------------------------- | --- |
| **Purpose**    | References a memory address                   | Holds the numerical value of a pointer        |     |
| **Size**       | Matches system’s pointer size (32 or 64 bits) | Matches system’s pointer size (32 or 64 bits) |     |
| **Usage**      | Points to data of any type                    | Stores pointer value for manipulation         |     |
| **Operations** | Pointer arithmetic, dereferencing             | Integer arithmetic, bitwise operations        |     |
| **Standard**   | Part of core C language                       | Defined in `<stdint.h>` (C99+)                |     |
| **Example**    | `void* ptr = (void*)0xFF0000;`                | `uintptr_t val = (uintptr_t)ptr;`             |     |

[[difference between uintptr_t and void]]