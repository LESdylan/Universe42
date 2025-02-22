_fishy_collapsed_wd() {
    local pwd_path="${PWD/#$HOME/~}"
    echo "$pwd_path"
}

_show_git_status() {
    local repo_name=$(git_repo_name)
    if [[ -n "$repo_name" ]]; then
        echo "$(git_prompt_status)%{$fg_bold[blue]%} "
    fi
}

git_prompt_info() {
    local ref
    ref=$(git symbolic-ref HEAD 2>/dev/null) || \
    ref=$(git rev-parse --short HEAD 2>/dev/null) || return
    echo "${ref#refs/heads/}"
}

git_prompt_status() {
    if git rev-parse --is-inside-work-tree &>/dev/null; then
        local status
        status=$(git status --porcelain 2>/dev/null)
        if [[ -n "$status" ]]; then
            echo "%{$fg_bold[red]%}✗"
        else
            echo "%{$fg_bold[green]%}✓"
        fi
    fi
}

git_repo_name() {
    if git rev-parse --is-inside-work-tree &>/dev/null; then
        basename "$(git rev-parse --show-toplevel 2>/dev/null)"
    fi
}

# Theme settings
PROMPT="%(?:%{$fg_bold[green]%}➜ :%{$fg_bold[red]%}➜ )"
PROMPT+='%{$fg[cyan]%}$(_fishy_collapsed_wd)%{$reset_color%} '
PROMPT+='$(git_prompt_info)$(_show_git_status)%{$fg_bold[magenta]%}»%{$reset_color%} '

# Git theme settings
ZSH_THEME_GIT_PROMPT_PREFIX="%{$fg_bold[white]%}"
ZSH_THEME_GIT_PROMPT_SUFFIX=""
ZSH_THEME_GIT_PROMPT_DIRTY=""
ZSH_THEME_GIT_PROMPT_CLEAN=""

ZSH_THEME_GIT_PROMPT_ADDED="%{$fg_bold[green]%}+"
ZSH_THEME_GIT_PROMPT_MODIFIED="%{$fg_bold[blue]%}!"
ZSH_THEME_GIT_PROMPT_DELETED="%{$fg_bold[red]%}-"
ZSH_THEME_GIT_PROMPT_RENAMED="%{$fg_bold[magenta]%}>"
ZSH_THEME_GIT_PROMPT_UNMERGED="%{$fg_bold[yellow]%}#"
ZSH_THEME_GIT_PROMPT_UNTRACKED="%{$fg_bold[red]%}?"