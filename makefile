PATH_GNL=Milestone1/GetNextLine
PATH_PRINTF=Milestone1/ft_printf
PATH_LIBFT=Milestone0/libft
PATH_B2B=Milestone

update:
	git submodule update --remote $(PATH_LIBFT)
	git add . && git commit -m "update" && git push
push:
	@git diff-index --quiet HEAD -- || (git add . ; git commit -m "$(M)" ; git push)
