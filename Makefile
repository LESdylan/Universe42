#-------------------------------------------------------------------------------
#  UNIVERSE42 — SUBMODULE MANAGEMENT MAKEFILE
#-------------------------------------------------------------------------------
#  Auto-detects root-level submodules from .gitmodules.
#  Only root-level (depth=1) submodules are updated — nested submodules
#  inside each project are left pinned to avoid breaking dependencies.
#
#  The companion GitHub Actions workflow (.github/workflows/update-submodule.yml)
#  performs the same operations weekly and can be triggered manually.
#-------------------------------------------------------------------------------

# ── Terminal colours & formatting ─────────────────────────────────────────────
GREEN     := $(shell tput -Txterm setaf 2)
YELLOW    := $(shell tput -Txterm setaf 3)
BLUE      := $(shell tput -Txterm setaf 4)
MAGENTA   := $(shell tput -Txterm setaf 5)
CYAN      := $(shell tput -Txterm setaf 6)
WHITE     := $(shell tput -Txterm setaf 7)
RED       := $(shell tput -Txterm setaf 1)
RESET     := $(shell tput -Txterm sgr0)
BOLD      := $(shell tput -Txterm bold)
UNDERLINE := $(shell tput -Txterm smul)

# ── Auto-detect root-level submodule paths (no '/' → depth=1 only) ───────────
ROOT_SUBMODULES := $(shell git config --file .gitmodules \
                       --get-regexp 'submodule\..*\.path' 2>/dev/null \
                     | awk '{print $$2}' | grep -v '/')

# GitHub org to scan for public repos
GITHUB_ORG := Univers42

# Default commit message
DEFAULT_COMMIT_MSG := chore: update submodules

# ── Banner ────────────────────────────────────────────────────────────────────
define BANNER
$(BLUE)$(BOLD)
┌──────────────────────────────────────────────────────────────┐
│                                                              │
│  $(MAGENTA)UNIVERSE42 · SUBMODULE MANAGEMENT$(BLUE)                        │
│  $(CYAN)Auto-discovers & syncs Univers42 public repos (depth=1)$(BLUE)    │
│                                                              │
└──────────────────────────────────────────────────────────────┘
$(RESET)
endef
export BANNER

# ── Help ──────────────────────────────────────────────────────────────────────
define HELP_MESSAGE
$(YELLOW)$(BOLD)GENERAL COMMANDS:$(RESET)

  $(GREEN)make$(RESET) $(BOLD)help$(RESET)          Show this help message
  $(GREEN)make$(RESET) $(BOLD)init$(RESET)          Initialize root-level submodules (no recursion)
  $(GREEN)make$(RESET) $(BOLD)status$(RESET)        Show status of root-level submodules
  $(GREEN)make$(RESET) $(BOLD)list$(RESET)          List detected root-level submodules
  $(GREEN)make$(RESET) $(BOLD)update$(RESET)        Update root-level submodules to latest remote
  $(GREEN)make$(RESET) $(BOLD)push$(RESET) $(CYAN)[M="msg"]$(RESET)  Add, commit, and push changes
  $(GREEN)make$(RESET) $(BOLD)pull$(RESET)          Pull main repo + root-level submodules
  $(GREEN)make$(RESET) $(BOLD)clean$(RESET)         Discard uncommitted changes in submodules

$(YELLOW)$(BOLD)DISCOVERY COMMANDS (requires gh CLI):$(RESET)

  $(GREEN)make$(RESET) $(BOLD)discover$(RESET)      Add all new public repos from $(GITHUB_ORG) as submodules
  $(GREEN)make$(RESET) $(BOLD)sync$(RESET)          discover + update + push  $(CYAN)(same as the CI workflow)$(RESET)

$(YELLOW)$(BOLD)SINGLE SUBMODULE:$(RESET)

  $(GREEN)make$(RESET) $(BOLD)update-one$(RESET) $(CYAN)S=<name>$(RESET)  Update a specific root submodule

endef
export HELP_MESSAGE

# ── Phony targets ─────────────────────────────────────────────────────────────
.PHONY: help init status list update push pull clean discover sync update-one

# ── Default target ────────────────────────────────────────────────────────────
help:
	@echo "$$BANNER"
	@echo "$$HELP_MESSAGE"

# ── Initialize root-level submodules (no recursion) ──────────────────────────
init:
	@echo "$(CYAN)$(BOLD)Initializing root-level submodules...$(RESET)"
	@for sub in $(ROOT_SUBMODULES); do \
		echo "  · $$sub"; \
		git submodule init  -- "$$sub" 2>/dev/null; \
		git submodule update --depth 1 -- "$$sub"; \
	done
	@echo "$(GREEN)$(BOLD)✓ Root-level submodules initialized (nested submodules left pinned).$(RESET)"

# ── Show status of root-level submodules ─────────────────────────────────────
status:
	@echo "$(CYAN)$(BOLD)Root-level submodule status:$(RESET)"
	@echo "$(BLUE)────────────────────────────────────────────────────$(RESET)"
	@for sub in $(ROOT_SUBMODULES); do \
		printf "$(YELLOW)$(BOLD)%-20s$(RESET) " "$$sub"; \
		if [ -d "$$sub/.git" ] || [ -f "$$sub/.git" ]; then \
			cd "$$sub" && branch=$$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "detached"); \
			hash=$$(git rev-parse --short HEAD 2>/dev/null || echo "N/A"); \
			printf "$(GREEN)$$branch$(RESET)  $(CYAN)$$hash$(RESET)\n"; \
			cd ..; \
		else \
			printf "$(RED)not initialised$(RESET)\n"; \
		fi; \
	done

# ── List detected root-level submodules ──────────────────────────────────────
list:
	@echo "$(CYAN)$(BOLD)Root-level submodules (auto-detected from .gitmodules):$(RESET)"
	@echo "$(BLUE)────────────────────────────────────────────────────$(RESET)"
	@for sub in $(ROOT_SUBMODULES); do \
		url=$$(git config --file .gitmodules --get "submodule.$$sub.url" 2>/dev/null); \
		echo "  $(MAGENTA)•$(RESET) $(YELLOW)$$sub$(RESET)  →  $(CYAN)$$url$(RESET)"; \
	done
	@echo ""
	@echo "  $(WHITE)Total: $$(echo $(ROOT_SUBMODULES) | wc -w) submodules$(RESET)"

# ── Update root-level submodules to latest remote (NO recursion) ─────────────
update:
	@echo "$(CYAN)$(BOLD)Updating root-level submodules to latest remote...$(RESET)"
	@for sub in $(ROOT_SUBMODULES); do \
		echo "  ↻ $$sub"; \
		git submodule init -- "$$sub" 2>/dev/null || true; \
		git submodule update --remote --depth 1 -- "$$sub" || \
			echo "  $(RED)⚠  Failed to update $$sub$(RESET)"; \
	done
	@echo "$(GREEN)$(BOLD)✓ Root-level submodules updated.$(RESET)"

# ── Update a single submodule by name ────────────────────────────────────────
update-one:
ifndef S
	@echo "$(RED)$(BOLD)Usage: make update-one S=<submodule-name>$(RESET)"
	@exit 1
endif
	@echo "$(CYAN)$(BOLD)Updating $(S)...$(RESET)"
	@git submodule init -- "$(S)" 2>/dev/null || true
	@git submodule update --remote --depth 1 -- "$(S)"
	@git add "$(S)"
	@git commit -m "chore: update $(S) submodule" || true
	@git push
	@echo "$(GREEN)$(BOLD)✓ $(S) updated and pushed.$(RESET)"

# ── Commit & push (optional message: M="your message") ──────────────────────
push:
	@if ! git diff-index --quiet HEAD -- || ! git diff --staged --quiet; then \
		echo "$(CYAN)$(BOLD)Committing and pushing changes...$(RESET)"; \
		git add -A; \
		git commit -m "$(or $(M),$(DEFAULT_COMMIT_MSG))"; \
		git push && echo "$(GREEN)$(BOLD)✓ Changes pushed successfully!$(RESET)" \
		         || echo "$(RED)$(BOLD)✗ Failed to push!$(RESET)"; \
	else \
		echo "$(YELLOW)$(BOLD)Nothing to commit — working tree clean.$(RESET)"; \
	fi

# ── Pull main repo + update root submodules ─────────────────────────────────
pull:
	@echo "$(CYAN)$(BOLD)Pulling main repository...$(RESET)"
	@git pull
	@echo "$(CYAN)$(BOLD)Updating root-level submodules...$(RESET)"
	@for sub in $(ROOT_SUBMODULES); do \
		echo "  ↻ $$sub"; \
		git submodule update --depth 1 -- "$$sub" 2>/dev/null || true; \
	done
	@echo "$(GREEN)$(BOLD)✓ All up to date.$(RESET)"

# ── Discard uncommitted changes in submodules ────────────────────────────────
clean:
	@echo "$(YELLOW)$(BOLD)Cleaning uncommitted changes in submodules...$(RESET)"
	@git submodule foreach --quiet 'git reset --hard && git clean -fd'
	@echo "$(GREEN)$(BOLD)✓ All submodules cleaned.$(RESET)"

# ── Discover & add new public repos from Univers42 (requires gh CLI) ────────
discover:
	@command -v gh >/dev/null 2>&1 || { echo "$(RED)$(BOLD)Error: gh CLI not found. Install it: https://cli.github.com$(RESET)"; exit 1; }
	@echo "$(CYAN)$(BOLD)Scanning $(GITHUB_ORG) for public repos...$(RESET)"
	@added=0; \
	for repo in $$(gh repo list $(GITHUB_ORG) --public --no-archived --limit 200 \
	              --json name --jq '.[].name' | sort); do \
		[ "$$repo" = "Universe42" ] && continue; \
		if git config --file .gitmodules --get "submodule.$${repo}.url" >/dev/null 2>&1; then \
			echo "  $(GREEN)✓$(RESET) $$repo — already tracked"; \
			continue; \
		fi; \
		existing_urls=$$(git config --file .gitmodules --get-regexp 'submodule\..*\.url' 2>/dev/null | awk '{print $$2}'); \
		if echo "$$existing_urls" | grep -qi "/$$repo\(.git\)\?$$"; then \
			echo "  $(GREEN)✓$(RESET) $$repo — already tracked (different directory name)"; \
			continue; \
		fi; \
		if [ -d "$$repo" ]; then \
			echo "  $(YELLOW)⚠$(RESET) $$repo — directory exists, not a submodule, skipping"; \
			continue; \
		fi; \
		echo "  $(MAGENTA)➕$(RESET) Adding $$repo"; \
		git submodule add --depth 1 "https://github.com/$(GITHUB_ORG)/$$repo.git" "$$repo" || { \
			echo "  $(RED)❌$(RESET) Failed to add $$repo"; \
			continue; \
		}; \
		added=$$((added + 1)); \
	done; \
	echo ""; \
	echo "$(GREEN)$(BOLD)✓ Discovery complete. $$added new submodule(s) added.$(RESET)"

# ── Full sync: discover + update + push (mirrors the CI workflow) ────────────
sync: discover update
	@echo "$(CYAN)$(BOLD)Pushing all changes...$(RESET)"
	@git add -A
	@if ! git diff --cached --quiet; then \
		git commit -m "chore: sync Univers42 submodules [$$(date +%Y-%m-%d)]"; \
		git push; \
		echo "$(GREEN)$(BOLD)✓ Sync complete — changes pushed.$(RESET)"; \
	else \
		echo "$(GREEN)$(BOLD)✓ Already in sync — nothing to push.$(RESET)"; \
	fi
