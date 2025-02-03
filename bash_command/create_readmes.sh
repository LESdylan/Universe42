#!/bin/bash

# Set the root directory (you can replace "." with a specific path if needed)
echo "Enter the path within you want to generate all the README file : "
read dir
ROOT_DIR="$dir"

# Loop through all directories in the root directory
for dir in "$ROOT_DIR"/*/; do
    # Check if it's a directory
    if [ -d "$dir" ]; then
        # Set the README path
        README_PATH="${dir}README.md"
        
        # Check if README.md already exists in this directory
        if [ ! -f "$README_PATH" ]; then
            echo "Creating README.md in $dir"
            
            # Write a basic template to the README.md file
            cat <<EOT > "$README_PATH"
# $(basename "$dir")

This folder contains functions related to the $(basename "$dir") category of the library.

## Functions

- List of functions will go here.

EOT
        else
            echo "README.md already exists in $dir, skipping..."
        fi
    fi
done

echo "README.md files have been created in all folders that didn't already have one."
