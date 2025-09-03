[MAKEFILES Variable (GNU make)](https://www.gnu.org/software/make/manual/html_node/MAKEFILES-Variable.html)

## Basic Example of MAKEFILES Usage

```bash
# Setting MAKEFILES environment variable
export MAKEFILES="common.mk utils.mk"
make
```

In this case, make will read [common.mk](http://common.mk) and [utils.mk](http://utils.mk) before reading the main Makefile.

## Example Structure

```makefile
# common.mk
CFLAGS = -Wall -O2
SOURCE_DIR = ./src

# utils.mk
LIBS = -lmath -lpthread

# Makefile
program: $(SOURCE_DIR)/main.c
    $(CC) $(CFLAGS) $^ $(LIBS) -o $@
```

## Important Points to Remember

- The files listed in MAKEFILES are read first, before the main Makefile
- If any file in MAKEFILES is not found, make will not throw an error
- Default goals from MAKEFILES are ignored
- Better practice is to use explicit include directives in the Makefile: