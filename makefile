PATH=Milestone1/ft_printf
update:
	git submodule update --remote $(PATH)
	&& git push
push:
	@git diff-index --quiet HEAD -- || (git add . ; git commit -m "$(M)" ; git push)