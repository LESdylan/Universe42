.PHONY: all clean fclean re temp mk run fclean push help

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)

# Directories
SRC_DIR = src
TEST_DIR = framework_test
INCLUDE_DIR = include
BUILD_DIR = build
NAME = file
# Source and test files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(TEST_DIR)/generate_random.c
TEST_FILES = $(wildcard $(TEST_DIR)/test_ft_*.c) $(TEST_DIR)/test_runner.c

# Object files
SRC_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES)))
TEST_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(TEST_FILES)))

# Executable
EXEC = $(BUILD_DIR)/test_program

# Default target
all: $(EXEC)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile the executable
$(EXEC): $(BUILD_DIR) $(SRC_OBJS) $(TEST_OBJS)
	$(CC) $(SRC_OBJS) $(TEST_OBJS) -o $(EXEC)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -rf $(BUILD_DIR)

# Remove everything (including executables)
fclean: clean

# Rebuild everything
re: fclean all

# Run the program
run: 
	./build/test_program

# Create the directory for temp files
mk:
	mkdir -p "atomicVerif"

# Compile the program (temp rule)
temp: mk
	$(CC) $(CFLAGS) -o atomicVerif/temp $(NAME)

# Run the temp executable
run_temp: temp
	./atomicVerif/temp

# Clean up the temporary directory
tclean: 
	rm -rf atomicVerif

# Git commit and push changes
push:
	git add .; git commit -m "updated"; git push

# Help message with description of targets
help:
	@echo "Usage: make [target]"
	@echo ""
	@echo " \e[34;4mAvailable Targets:\e[0m		| \e[34;4mInstruction\e[0m"
	@echo "				|		"
	@echo " \e[32mall\e[0m            		| \e[33mBuild the program (default target)"
	@echo " \e[31mclean\e[0m      			| \e[33mRemove object files"
	@echo " \e[31mfclean\e[0m      			| \e[33mRemove object files and the program"
	@echo " \e[31mre\e[0m      			| \e[33mRebuild the program (clean and all)"
	@echo " \e[35mtemp\e[0m      			| \e[33mCompile a temporary program"
	@echo " \e[35mrun\e[0m      			| \e[33mRun the compiled test program"
	@echo " \e[36mhelp\e[0m      			| \e[33mDisplay this help message"
	@echo " \e[36mpush\e[0m				| \e[33mPush to git repository"
