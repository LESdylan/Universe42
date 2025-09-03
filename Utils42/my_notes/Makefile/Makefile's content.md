It contain 5 kind of things :

- An explicit rule: Tells how to make a target file from other files
- An implicit rule: Built-in rules that make automatically knows how to use
- Variable definitions: Store values that can be reused throughout the makefile
- Directives: Special instructions for make (include files, conditional parts)
- Comments: Lines starting with # to explain the makefile

## Explicit Rules

An explicit rule tells make how to execute a series of commands to create a target file from source files. Format:

```makefile
target: dependencies
    commands
```

## Implicit Rules

Make has built-in rules for common operations. For example:

- '.c' to '.o': Automatically knows how to compile C source files
- '.o' to executable: Knows how to link object files

## Variables

Variables make the makefile more maintainable. Common types:

- Simple variables (=): Immediate assignment
- Recursive variables (:=): Evaluated when used
- Automatic variables ($@, $^, etc.): Special meanings in rules

## Directives

Special instructions that control make's behavior:

- include: Include other makefiles
- ifdef/ifndef: Conditional execution
- ifeq/ifneq: Value comparison

## Comments

Comments start with # and continue to the end of the line. They're useful for:

- Explaining complex rules
- Documenting variables
- Providing usage instructions

## splitting long lines

Makefile use a “line-based” syntax = the neline character is special and marks the end of a statement. So to let understand make that the list is not done, we need to backslashed the line before ending

normally if we do that we need to add some whitespace this way :

```makefile
var :=  one\\
					two
#avoiding whitespace
var :=  one$\\
				two
#is equivalent with
var := one$ two
```

<aside> <img src="/icons/light-bulb_yellow.svg" alt="/icons/light-bulb_yellow.svg" width="40px" />

$ alone refers to NULL but correspond to a white space so $ = ‘ ’;

</aside>