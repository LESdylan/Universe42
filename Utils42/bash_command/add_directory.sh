#!/bin/bash

# Prompt the user for inputs
read -p "Enter the prefix name for the files/directories: " prefix
read -p "Enter the number of items to create: " number
read -p "Enter the file extension (e.g., .txt, .csv) [Leave blank if creating directories]: " extension
read -p "Enter the directory where items should be created: " directory
read -p "Enter the command you want to execute (mkdir | touch): " cmd

# Validate the command
if [[ "$cmd" != "mkdir" && "$cmd" != "touch" ]]; then
    echo "Invalid command. Please use 'mkdir' or 'touch'."
    exit 1
fi

# Check if the directory exists; if not, create it
if [ ! -d "$directory" ]; then
    echo "Directory does not exist. Creating it..."
    mkdir -p "$directory"
fi

# Calculate zero padding based on the number of items
padding_length=${#number}

# Create the files or directories
for ((i=1; i<=number; i++))
do
    # Generate zero-padded numbers
    padded_number=$(printf "%0${padding_length}d" "$i")

    item_name="${prefix}${padded_number}${extension}"
    if [[ "$cmd" == "mkdir" ]]; then
        # Remove the extension for directories
        item_name="${prefix}${padded_number}"
    fi

    $cmd "${directory}/${item_name}"
    echo "Created: ${directory}/${item_name}"
done

echo "All items have been created successfully."
