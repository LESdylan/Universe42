#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No color

# Menu Function
function show_menu() {
    echo -e "${GREEN}File Descriptor Manager${NC}"
    echo "1) List Open File Descriptors"
    echo "2) Redirect stdout to a file"
    echo "3) Redirect stderr to a file"
    echo "4) Create a custom FD (write mode)"
    echo "5) Write to a custom FD"
    echo "6) Read from a custom FD"
    echo "7) Close a custom FD"
    echo "8) Reset stdout & stderr"
    echo "9) Exit"
    echo -n "Choose an option: "
}

# List Open File Descriptors
function list_fds() {
    echo -e "${GREEN}Listing Open File Descriptors:${NC}"
    ls -l /proc/$$/fd
}

# Redirect stdout to a file
function redirect_stdout() {
    echo -n "Enter file name to redirect stdout: "
    read file
    exec 1> "$file"
    echo "stdout is now redirected to $file"
}

# Redirect stderr to a file
function redirect_stderr() {
    echo -n "Enter file name to redirect stderr: "
    read file
    exec 2> "$file"
    echo "stderr is now redirected to $file"
}

# Create a custom file descriptor (write mode)
function create_fd() {
    echo -n "Enter FD number (>=3): "
    read fd
    echo -n "Enter filename: "
    read file
    exec {fd}> "$file"
    echo "FD $fd is now pointing to $file (write mode)"
}

# Write to a custom FD
function write_fd() {
    echo -n "Enter FD number to write to: "
    read fd
    echo -n "Enter message: "
    read message
    echo "$message" >&"$fd"
    echo "Message written to FD $fd"
}

# Read from a custom FD
function read_fd() {
    echo -n "Enter FD number to read from: "
    read fd
    cat <&"$fd"
}

# Close a custom FD
function close_fd() {
    echo -n "Enter FD number to close: "
    read fd
    exec {fd}>&-
    echo "FD $fd closed"
}

# Reset stdout & stderr
function reset_stdio() {
    exec 1>&3 2>&4
    echo "stdout and stderr reset"
}

# Save original stdout & stderr for reset functionality
exec 3>&1 4>&2

# Menu Loop
while true; do
    show_menu
    read option
    case $option in
        1) list_fds ;;
        2) redirect_stdout ;;
        3) redirect_stderr ;;
        4) create_fd ;;
        5) write_fd ;;
        6) read_fd ;;
        7) close_fd ;;
        8) reset_stdio ;;
        9) echo "Exiting..."; exit 0 ;;
        *) echo -e "${RED}Invalid option!${NC}" ;;
    esac
    echo
done
