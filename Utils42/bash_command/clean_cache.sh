#!/bin/bash

echo -e "from: https://github.com/ombhd/Cleaner_42\n"

# Banner
echo -e "\n"
echo -e " 		█▀▀ █▀▀ █░░ █▀▀ ▄▀█ █▄░█ "
echo -e " 		█▄▄ █▄▄ █▄▄ ██▄ █▀█ █░▀█ "

# Function to calculate available storage
calculate_storage() {
    df -h "$HOME" | grep "$HOME" | awk '{print($4)}' | tr 'i' 'B'
}

# Function to clean specified directories
clean_directory() {
    local dir=$1
    /bin/rm -rf "$dir" &>/dev/null
}

# Calculate the current available storage
Storage=$(calculate_storage)
if [ "$Storage" == "0BB" ]; then
    Storage="0B"
fi
echo -e "\033[33m\n -- Available Storage Before Cleaning : || $Storage || --\033[0m"

echo -e "\033[31m\n -- Cleaning ...\n\033[0m "

# 42 Caches
clean_directory "$HOME/Library/*.42*"
clean_directory "$HOME/*.42*"
clean_directory "$HOME/.zcompdump*"
clean_directory "$HOME/.cocoapods.42_cache_bak*"

# Trash
clean_directory "$HOME/.Trash/*"

# General Caches files
/bin/chmod -R 777 "$HOME/Library/Caches/Homebrew" &>/dev/null
clean_directory "$HOME/Library/Caches/*"
clean_directory "$HOME/Library/Application Support/Caches/*"

# Slack, VSCode, Discord and Chrome Caches
clean_directory "$HOME/Library/Application Support/Slack/Service Worker/CacheStorage/*"
clean_directory "$HOME/Library/Application Support/Slack/Cache/*"
clean_directory "$HOME/Library/Application Support/discord/Cache/*"
clean_directory "$HOME/Library/Application Support/discord/Code Cache/js*"
clean_directory "$HOME/Library/Application Support/discord/Crashpad/completed/*"
clean_directory "$HOME/Library/Application Support/Code/Cache/*"
clean_directory "$HOME/Library/Application Support/Code/CachedData/*"
clean_directory "$HOME/Library/Application Support/Code/Crashpad/completed/*"
clean_directory "$HOME/Library/Application Support/Code/User/workspaceStorage/*"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Profile [0-9]/Service Worker/CacheStorage/*"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Default/Service Worker/CacheStorage/*"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Profile [0-9]/Application Cache/*"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Default/Application Cache/*"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Crashpad/completed/*"

# .DS_Store files
find "$HOME/Desktop" -name .DS_Store -depth -exec /bin/rm {} \; &>/dev/null

# Temporary downloaded files with browsers
clean_directory "$HOME/Library/Application Support/Chromium/Default/File System"
clean_directory "$HOME/Library/Application Support/Chromium/Profile [0-9]/File System"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Default/File System"
clean_directory "$HOME/Library/Application Support/Google/Chrome/Profile [0-9]/File System"

# Things related to pool (piscine)
clean_directory "$HOME/Desktop/Piscine Rules *.mp4"
clean_directory "$HOME/Desktop/PLAY_ME.webloc"

# Things related to francinette
clean_directory "$HOME/francinette/temp"

# Calculate the new available storage after cleaning
Storage=$(calculate_storage)
if [ "$Storage" == "0BB" ]; then
    Storage="0B"
fi

echo -e "\033[32m -- Available Storage After Cleaning : || $Storage || --\n\033[0m"

# Summary of cleaned items
echo -e "\033[34m -- Summary of Cleaned Items --\033[0m"

# Timestamp
echo -e "\033[34m -- Script run at: $(date) --\033[0m"