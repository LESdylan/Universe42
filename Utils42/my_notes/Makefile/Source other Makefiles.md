[Include (GNU make)](https://www.gnu.org/software/make/manual/html_node/Include.html)

## Understanding Makefile Inclusion

The include directive in Makefiles allows you to read and incorporate other Makefiles into your current one. This is useful for organizing common variables, rules, or automatically generated prerequisites.

### Basic Syntax

```makefile
# Basic include syntax
include filename.mk

# Multiple files
include config.mk rules.mk vars.mk

# Using wildcards
include *.mk

# Using variables
include $(CONFIG_FILES)
```

### Include vs -include

There are two ways to include files:

- **include:** Will throw an error if the file is missing and cannot be created
- **-include** or **sinclude:** Will silently ignore missing files

```makefile
# Will error if missing
include config.mk

# Will ignore if missing
-include optional.mk
sinclude also_optional.mk
```

### Practical Examples

1. Common configuration setup:

```makefile
# config.mk
CC = gcc
CFLAGS = -Wall -O2
LIBS = -lm

# main Makefile
include config.mk

program: $(OBJS)
    $(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)
```

1. Multiple project components:

```makefile
# component_rules.mk
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# main Makefile
include component_rules.mk
include components/*.mk  # Include all component makefiles
```

### Search Paths

Make searches for included files in the following order:

- Current directory
- Directories specified with -I or --include-dir options
- /usr/local/include
- /usr/gnu/include
- /usr/include

### Best Practices

- Use include for essential files that must exist
- Use -include for optional configurations
- Keep included files modular and well-documented
- Use meaningful names for included makefiles (e.g., [config.mk](http://config.mk), [rules.mk](http://rules.mk))

[secondary expansion](https://www.notion.so/secondary-expansion-18e52b568218809d8971cd5e67298f03?pvs=21)