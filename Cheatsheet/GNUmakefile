# Advanced Makefile with multiple features for learning

# Program name
NAME = program_name
BONUS_NAME = program_name_bonus

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
SRC_DIR = srcs/
INC_DIR = includes/
OBJ_DIR = objs/
LIB_DIR = libs/

# Sources
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
SRC_BONUS = $(wildcard $(SRC_DIR)bonus/*.c)

# Objects
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
OBJ_BONUS = $(patsubst $(SRC_DIR)bonus/%.c,$(OBJ_DIR)bonus/%.o,$(SRC_BONUS))

# Dependencies
DEPS = $(OBJ_FILES:.o=.d) $(OBJ_BONUS:.o=.d)
CFLAGS += -MMD -MP -I$(INC_DIR)

# Libraries
LIBFT = $(LIB_DIR)libft/libft.a
LIBFT_DIR = $(LIB_DIR)libft/

# Colors and formatting
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
BOLD = \033[1m

# Progress counter
TOTAL_FILES = $(words $(SRC_FILES))
CURR_FILE = 0

# Define the progress function
define progress
	$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling: [%-$(TOTAL_FILES)s] %d%%$(RESET)" $(shell printf '%*s' $$(($(CURR_FILE) * $(TOTAL_FILES) / $(TOTAL_FILES))) | tr ' ' '#') $$(($(CURR_FILE) * 100 / $(TOTAL_FILES)))
endef

# Main targets
all: pre_build $(NAME)
	@echo "\n$(GREEN)$(BOLD)Build successful!$(RESET)"

bonus: pre_build $(BONUS_NAME)
	@echo "\n$(GREEN)$(BOLD)Bonus build successful!$(RESET)"

pre_build:
	@echo "$(CYAN)Starting build process...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)bonus

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "\n$(BLUE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(RESET)"

$(BONUS_NAME): $(LIBFT) $(OBJ_BONUS)
	@echo "\n$(BLUE)Linking bonus...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) created!$(RESET)"

# Library compilation
$(LIBFT):
	@echo "$(MAGENTA)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Object compilation with pattern rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress)

$(OBJ_DIR)bonus/%.o: $(SRC_DIR)bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call progress)

# Debug mode with sanitizers
debug: CFLAGS += -g3 -fsanitize=address
debug: re
	@echo "$(YELLOW)Debug mode enabled with ASan$(RESET)"

# Profiling with gprof
profile: CFLAGS += -pg
profile: re
	@echo "$(YELLOW)Profile mode enabled with gprof$(RESET)"

# C++ compilation mode (for mixed projects)
cpp_mode: CC = c++
cpp_mode: CFLAGS += -std=c++98
cpp_mode: re
	@echo "$(YELLOW)C++ mode enabled$(RESET)"

# Clean targets
clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Full cleaning...$(RESET)"
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Install and uninstall
install: all
	@echo "$(GREEN)Installing $(NAME) to /usr/local/bin$(RESET)"
	@cp $(NAME) /usr/local/bin/

uninstall:
	@echo "$(RED)Uninstalling $(NAME) from /usr/local/bin$(RESET)"
	@$(RM) /usr/local/bin/$(NAME)

# Tests
test: all
	@echo "$(CYAN)Running tests...$(RESET)"
	@./tests/run_tests.sh

# Documentation
docs:
	@echo "$(CYAN)Generating documentation...$(RESET)"
	@doxygen Doxyfile

# Help
help:
	@echo "$(BOLD)Available commands:$(RESET)"
	@echo "  $(GREEN)make$(RESET)        - Build the program"
	@echo "  $(GREEN)make bonus$(RESET)  - Build with bonus features"
	@echo "  $(GREEN)make clean$(RESET)  - Remove object files"
	@echo "  $(GREEN)make fclean$(RESET) - Remove object files and executable"
	@echo "  $(GREEN)make re$(RESET)     - Rebuild from scratch"
	@echo "  $(GREEN)make debug$(RESET)  - Build with debug symbols and ASan"
	@echo "  $(GREEN)make profile$(RESET)- Build with profiling support"
	@echo "  $(GREEN)make test$(RESET)   - Run tests"
	@echo "  $(GREEN)make docs$(RESET)   - Generate documentation"

# Include dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re bonus debug profile cpp_mode test docs help install uninstall pre_build
