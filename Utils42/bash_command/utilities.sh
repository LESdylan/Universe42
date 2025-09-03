#!/bin/bash

# Function to create a file or folder
create_entity() {
  local prefix_file="$1"
  local extension="$2"
  local path_location="$3"
  local entity_type="$4"

  # Validate path_location
  if [ ! -d "$path_location" ]; then
    echo "Error: The path '$path_location' does not exist."
    exit 1
  fi

  # Build the full path
  local full_path="${path_location}/${prefix_file}"

  # Check if the entity type is a file
  if [ "$entity_type" == "file" ]; then
    if [ -z "$extension" ]; then
      echo "Error: Extension is required for files."
      exit 1
    fi
    full_path="${full_path}.${extension}"
    # Create the file
    touch "$full_path"
    echo "File created at: $full_path"

  # Check if the entity type is a folder
  elif [ "$entity_type" == "folder" ]; then
    # Create the folder
    mkdir -p "$full_path"
    echo "Folder created at: $full_path"

  else
    echo "Error: Invalid type. Use 'file' or 'folder'."
    exit 1
  fi

  for i in {00..number}
  do
    $ complete_file = $full_path
}

# Main script
if [ "$#" -ne 4 ]; then
  echo "Usage: $0 <prefix_file> <extension> <path_location> <file|folder>"
  exit 1
fi

create_entity "$1" "$2" "$3" "$4"
