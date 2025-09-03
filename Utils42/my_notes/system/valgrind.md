Valgrind is a powerful tool for memory debugging, memory leak allocation, while we don’t need to care too much about leaks memory when working in higher level of language. We strictly need to keep an eye on the potential leaks due to manual manipulation of bytes allocated in language like C.

<aside> 💡

</aside>

Valgrind is a framework that analyze our program with a dynamic binary instrumentation. It simplified the tasks of developers with its most common tool `Memcheck` (which detects memory errors):

# Instrumentation Engine:

did you ask what happend underneath the hood and why we need to put valgrind before the program launch ?

Well it’s because valgrind takes control before our program starts.

- it reads the program’s machine code (the compiled binary) and translates it, piece by piece until be transformed into an instrumented version. it’s a force brute method that have the merits to be really precise.
- it means that in order to keep track and debugging the our code the valgrind add extra piece of code for each statement of our code to know what exactly is going on. This is what perform the checks.

# Execution on a synthetic CPU:

Valgrind then executes this instrumented code on a synthetic CPU that it simulates. This is why programs run significantly slower under valgrind. it is considered that the program runs 10 to 50 times slower because of the ressources it uses during the execution.

# Memcheck tool (for memory errors):

for every bytes or bits depending on the detail, the program Memcheck keep track of :

- validity bits (alias V bits): Whether the corresponding memory bute has been initialized with a known value.
- initialized bits
- intercepting memory management functions:
- check memory access:
    - addressability:
    - initialization:
    - when our program writes to memory, valgrind updates the corresponding I bits in shadow memory to mark those bytes as initialized
- leak checking:
- **leak checking:** When our program exits, memcheck examines all memory blocks that were allocated but not freed. it categorizes them (`definitely lost` , `still reachable` ) based on whether any pointers to those blocks still exist.

<aside> 💡

valgrind is a framework henceforth, `Memcheck` is just one tool (often called a `skin`)

other tools like `Cachegrind` (cache profiler), `healgrind` (thread error detector), `DRD` (thread error detector) , `Massif` (heap profiler) use the same instrumentation engin but insert different checking code and maintain different kinds of metadata to analyze different aspects of our program’s execution

</aside>

<aside> 💡

In essence: Valgrind creates “ a sandboxed” environment where it can observe and analyze every instruction our program executes particularly those involving memory, allowing us to detect errors that might otherwise go unnoticed or cause crashes much later.

</aside>

# in practice where does that get us ?

## to prevent dangling pointers

- after `free(ptr)` , the `ptr`variable still holds the same memory address but without no data inside. if we accidentally use this “dangling pointer” later (dereference it or pass it to another function), it leads to undefined behavior. This could be a crash, corrupted data, or seemingly random errors.

so let’s take this example

```c
int main(int argc, char **argv)
{
    int *arr;
    int *arr_start;
    int len;
    int number;

    if (argc == 1)
        return (1);
    len = argc - 1;
    arr = ft_calloc(len, sizeof(int));
    if (!arr)
        return (1);
    argv++;
    arr_start = arr;
    while(*argv)
    {
        number = ft_atoi(*argv);
        ft_printf("number = %d\\n", number);
        *(arr++) = number;
        argv++;
    }
    ft_print_array(arr_start,len,'v');
    free(arr_start); //free is used to liberate the datas inside the memory address
    /**
    &arr_start = *ptr = data;
    # we delete the data with free it give us that
    &arr_start = *ptr = NULL;
    # the variable still point to the memory where the old data was
    so we need to make it NULL so it doesn't bother use
    &arr_start = NULL;
    */
    arr_start = NULL;
    arr = NULL;
    return (0);
}
```

let’s see what happens if I reuse the same code but this time I dereference the variable that has been NULLified.

```c
int main(int argc, char **argv)
{
// same code here
    free(arr_start);
    arr_start = NULL;
    arr = NULL;
    printf("%d\\n", *arr);
    return (0);
}
/**

input : 2 4 6
output:
2
4
6
segmentation fault (core dumped)
*/
```

and now let’s verify our without NULLIFIED the variable after freeing what is happening:

```c
int main(int argc, char **argv)
{
// same code here
    free(arr_start);
    printf("%d\\n", *arr);
    return (0);
}
/**

input : 2 4 6
output:
2
4
6
*/
```

let’s see what valgrind think of that same code

```c

==620193== Memcheck, a memory error detector      //tell us which tools the framework use, as refered before it is memcheck
==620193== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.       // the copyright and metadata of the program
==620193== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info    //teh version
==620193== Command: ./push_swap 1 2 3                                            // the command used our input
==620193== 
//standout output of our program 
number = 1
number = 2
number = 3
[0] --> 1 
[1] --> 2 
[2] --> 3 
==620193== Invalid read of size 4    
/*one critical message, the program tried to read a mmeory location that it shouldn't have
`size 4` was attempted to be reached by the program which correspond to the dereference I've made of a sizeof(int) -->reading integer
**/
// in /home/dlesieur/Documents/projects-42/Push_swap/dylan/push_swap (executable file where the error has been found)
==620193==    at 0x10929E: main (in /home/dlesieur/Documents/projects-42/Push_swap/dylan/push_swap) // the memory address of the error
==620193==  Address 0x4a8f04c is 0 bytes after a block of size 12 free'd // this is the memory we tried to read from
//our len was 3 and the size of int is 4 so 3 * 4 = 12, makes sense
==620193==    at 0x484988F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so) // it tells that is has already been freed     
==620193==    by 0x109299: main (in /home/dlesieur/Documents/projects-42/Push_swap/dylan/push_swap) // by main where the errorr occured
==620193==  Block was alloc'd at
==620193==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==620193==    by 0x1096BF: ft_calloc (in /home/dlesieur/Documents/projects-42/Push_swap/dylan/push_swap)
==620193==    by 0x109206: main (in /home/dlesieur/Documents/projects-42/Push_swap/dylan/push_swap)
==620193== 
0==620193== 
==620193== HEAP SUMMARY:
==620193==     in use at exit: 0 bytes in 0 blocks
==620193==   total heap usage: 2 allocs, 2 frees, 1,036 bytes allocated
==620193== 
==620193== All heap blocks were freed -- no leaks are possible
==620193== 
==620193== For lists of detected and suppressed errors, rerun with: -s
==620193== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
dlesieur@dlesieur42:~/Documents/projects-42/Push_swap/dylan$ 
```

[[more info]]

[[output valgrind example]]
[[valgrind]]
[[advice]]
[[more info]]
[[suite tools]]
[[presentation]]