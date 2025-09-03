- by default :
    - makefile
    - Makefile
    - MAKEFILE (better option because appear with [README.md](http://README.md))
    - GNUmakefile
- change the name

```makefile
# This is our custom makefile named 'build.mk'
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = program

SRC = main.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

To use this custom makefile, you would run:

```bash
make -f build.mk
# or for specific targets:
make -f build.mk clean
make -f build.mk re
```