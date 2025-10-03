#-------------------------------------------------------------------------------
# ENHANCED SUBMODULE MANAGEMENT MAKEFILE
#-------------------------------------------------------------------------------

# Terminal colors
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
MAGENTA:= $(shell tput -Txterm setaf 5)
CYAN   := $(shell tput -Txterm setaf 6)
WHITE  := $(shell tput -Txterm setaf 7)
RESET  := $(shell tput -Txterm sgr0)

# Text formatting
BOLD   := $(shell tput -Txterm bold)
BLINK  := $(shell tput -Txterm blink)
REVERSE:= $(shell tput -Txterm rev)
UNDERLINE := $(shell tput -Txterm smul)

# Paths to submodules
PATH_GNL    = Milestone1/get_next_line
PATH_PRINTF = Milestone1/printf
PATH_LIBFT  = Milestone0/libft

# Combine paths into a single variable
PATH_ALL_MODULES = $(PATH_GNL) $(PATH_PRINTF) $(PATH_LIBFT)

# Default commit message
DEFAULT_COMMIT_MSG = Automatic update of submodules

# Banner
define BANNER
$(BLUE)$(BOLD)
┌─────────────────────────────────────────────────────┐
│                                                     │
│  $(MAGENTA)SUBMODULE MANAGEMENT TOOL$(BLUE)                     │
│  $(CYAN)Manages nested repositories within the main project$(BLUE) │
│                                                     │
└─────────────────────────────────────────────────────┘
$(RESET)
endef
export BANNER

# Help message
define HELP_MESSAGE
$(YELLOW)$(BOLD)AVAILABLE COMMANDS:$(RESET)

  $(GREEN)make$(RESET) $(BOLD)init$(RESET)         Initialize all submodules
  $(GREEN)make$(RESET) $(BOLD)status$(RESET)       Show status of all submodules
  $(GREEN)make$(RESET) $(BOLD)update$(RESET)       Update all submodules to latest remote version
  $(GREEN)make$(RESET) $(BOLD)push$(RESET) [M="commit message"]  Add, commit, and push changes
  $(GREEN)make$(RESET) $(BOLD)pull-all$(RESET)     Pull updates for main repo and all submodules
  $(GREEN)make$(RESET) $(BOLD)clean$(RESET)        Discard any uncommitted changes in submodules
  $(GREEN)make$(RESET) $(BOLD)list$(RESET)         List all submodules with their paths

$(YELLOW)$(BOLD)SPECIFIC SUBMODULE COMMANDS:$(RESET)

  $(GREEN)make$(RESET) $(BOLD)update-gnl$(RESET)   Update only the get_next_line submodule
  $(GREEN)make$(RESET) $(BOLD)update-printf$(RESET) Update only the printf submodule  
  $(GREEN)make$(RESET) $(BOLD)update-libft$(RESET) Update only the libft submodule

endef
export HELP_MESSAGE

.PHONY: help init status update push pull-all clean list \
        update-gnl update-printf update-libft

# Default target
help:
	@echo "$$BANNER"
	@echo "$$HELP_MESSAGE"

# Initialize all submodules
init:
	@echo "$(CYAN)$(BOLD)Initializing all submodules...$(RESET)"
	@git submodule init
	@git submodule update
	@echo "$(GREEN)$(BOLD)✓ All submodules initialized successfully!$(RESET)"

# Show status of all submodules
status:
	@echo "$(CYAN)$(BOLD)Current status of submodules:$(RESET)"
	@git submodule status
	@echo "$(BLUE)────────────────────────────────────────────────────$(RESET)"
	@for module in $(PATH_ALL_MODULES); do \
		echo "$(YELLOW)$(BOLD)$$module:$(RESET)"; \
		cd $$module 2>/dev/null && git status -s || echo "$(RED)Error: Cannot access $$module$(RESET)"; \
		echo ""; \
	done

# Update all submodules to latest remote version
update:
	git pull
	@echo "$(CYAN)$(BOLD)Updating all submodules to latest remote version...$(RESET)"
	@git submodule update --remote --merge $(PATH_ALL_MODULES)
	@git add .
	@git commit -m "$(DEFAULT_COMMIT_MSG)"
	@git push
	@echo "$(GREEN)$(BOLD)✓ All submodules updated and changes pushed!$(RESET)"

# Push changes with an optional commit message
push:
	@if ! git diff-index --quiet HEAD --; then \
		echo "$(CYAN)$(BOLD)Committing and pushing changes...$(RESET)"; \
		git add .; \
		git commit -m "$(or $(M),$(DEFAULT_COMMIT_MSG))"; \
		git push && echo "$(GREEN)$(BOLD)✓ Changes pushed successfully!$(RESET)" || echo "$(RED)$(BOLD)✗ Failed to push changes!$(RESET)"; \
	else \
		echo "$(YELLOW)$(BOLD)No changes to commit.$(RESET)"; \
	fi

# Pull updates for main repo and all submodules
pull-all:
	@echo "$(CYAN)$(BOLD)Pulling updates for main repository...$(RESET)"
	@git pull
	@echo "$(CYAN)$(BOLD)Pulling updates for all submodules...$(RESET)"
	@git submodule foreach git pull origin master
	@echo "$(GREEN)$(BOLD)✓ All repositories updated!$(RESET)"

# Discard any uncommitted changes in submodules
clean:
	@echo "$(YELLOW)$(BOLD)Cleaning uncommitted changes in submodules...$(RESET)"
	@git submodule foreach git reset --hard
	@git submodule foreach git clean -fd
	@echo "$(GREEN)$(BOLD)✓ All submodules cleaned!$(RESET)"

# List all submodules with their paths
list:
	@echo "$(CYAN)$(BOLD)Submodules in this project:$(RESET)"
	@echo "$(BLUE)────────────────────────────────────────────────────$(RESET)"
	@for module in $(PATH_ALL_MODULES); do \
		echo "$(MAGENTA)• $(YELLOW)$$module$(RESET)"; \
	done

# Individual submodule update targets
update-gnl:
	@echo "$(CYAN)$(BOLD)Updating get_next_line submodule...$(RESET)"
	@git submodule update --remote --merge $(PATH_GNL)
	@git add $(PATH_GNL)
	@git commit -m "Update get_next_line submodule"
	@git push
	@echo "$(GREEN)$(BOLD)✓ get_next_line updated successfully!$(RESET)"

update-printf:
	@echo "$(CYAN)$(BOLD)Updating printf submodule...$(RESET)"
	@git submodule update --remote --merge $(PATH_PRINTF)
	@git add $(PATH_PRINTF)
	@git commit -m "Update printf submodule"
	@git push
	@echo "$(GREEN)$(BOLD)✓ printf updated successfully!$(RESET)"

update-libft:
	@echo "$(CYAN)$(BOLD)Updating libft submodule...$(RESET)"
	@git submodule update --remote --merge $(PATH_LIBFT)
	@git add $(PATH_LIBFT)
	@git commit -m "Update libft submodule"
	@git push
	@echo "$(GREEN)$(BOLD)✓ libft updated successfully!$(RESET)"

update-push-spec:
	cd $(PATH_CUSTOM)
	git add .
	git commit -m "update"
	git push
