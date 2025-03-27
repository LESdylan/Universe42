# Makefile for updating and pushing git submodules

# Paths to submodules
PATH_GNL = Milestone1/get_next_line
PATH_PRINTF = Milestone1/printf
PATH_LIBFT = Milestone0/libft

# Combine paths into a single variable
PATH_ALL_MODULES = $(PATH_GNL) $(PATH_PRINTF) $(PATH_LIBFT) $(PATH_B2B)

# Update submodules
update:
	git submodule update --remote $(PATH_ALL_MODULES)
	git add .
	git commit -m "Update submodules"
	git push

# Push changes with an optional commit message
push:
	@if ! git diff-index --quiet HEAD --; then \
		git add .; \
		git commit -m "$(or $(M),Automatic commit)"; \
		git push; \
	fi