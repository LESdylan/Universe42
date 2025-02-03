#!/bin/bash

# Function to create files in a loop
create_files() {
  local prefix="$1"
  local extension="$2"
  local path="$3"
  local start="$4"
  local end="$5"

  # Validate path
  if [ ! -d "$path" ]; then
    echo "Error: The path '$path' does not exist."
    exit 1
  fi

  # Create files in a loop
  for ((i = start; i <= end; i++)); do
    local formatted_index=$(printf "%02d" "$i") # Format as two digits, e.g., 01, 02
    local file_name="${prefix}${formatted_index}.${extension}"
    local full_path="${path}/${file_name}"

    # Create the file
    touch "$full_path"
    echo "Created: $full_path"
  done
}

# Main script
echo "Enter file prefix (e.g., 'ex'): "
read prefix

echo "Enter file extension (e.g., 'c'): "
read extension

echo "Enter path location (e.g., '/home/user/projects'): "
read path

echo "Enter starting number: "
read start

echo "Enter ending number: "
read end

# Call the function with user inputs
create_files "$prefix" "$extension" "$path" "$start" "$end"
