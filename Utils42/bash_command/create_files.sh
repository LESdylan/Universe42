#!/bin/bash
chek_path() {
    local $path_location="$1"
    if [[ ! -d "$path_location" ]]; then
        echo "Error: The path '$path_location' does not exist"
        exit 1
    fi
}
# Function to create files or folders from a generic range
create_generic_entity() {
    local prefix_file="$1"
    local extension="$2"
    local path_location="$3"
    local entity_type="$4"
    local start="$5"
    local end="$6"

    check_path "$path_location";

    for ((i = start; i <= end; i++)); do
        local formatted_index=$(printf "%02d" "$i") # Format as two digits
        local full_path

        if [[ "$entity_type" == "f" ]]; then
            local file_name="${prefix_file}${formatted_index}${extension}"
            full_path="${path_location}/${file_name}"
            touch "$full_path"
            echo "Created file: $full_path"

        elif [[ "$entity_type" == "d" ]]; then
            full_path="${path_location}/${prefix_file}${formatted_index}"
            mkdir -p "$full_path"
            echo "Created folder: $full_path"

        else
            echo "Error: Invalid entity type. Use 'f' for file or 'd' for directory."
            exit 1
        fi
    done
}

# Function to create files or folders from a list of names
create_list_entity() {
    local list_of_names="$1"
    local extension="$2"
    local path_location="$3"
    local entity_type="$4"

    check_path "$path_location";
    for name in $list_of_names; do
        local full_path

        if [[ "$entity_type" == "f" ]]; then
            full_path="${path_location}/ft_${name}${extension}"
            touch "$full_path"
            echo "Created file: $full_path"

        elif [[ "$entity_type" == "d" ]]; then
            full_path="${path_location}/${name}"
            mkdir -p "$full_path"
            echo "Created folder: $full_path"

        else
            echo "Error: Invalid entity type. Use 'f' for file or 'd' for directory."
            exit 1
        fi
    done
}

# Main script
echo "Choose mode (generic or list): "
read mode

if [[ "$mode" == "generic" ]]; then
    echo "Enter the prefix (e.g., 'ex'): "
    read prefix

    echo "Enter file extension (e.g., '.c'): "
    read extension

    echo "Enter path location (e.g., '/home/user/documents'): "
    read path

    echo "Enter type of entity (f for file, d for folder): "
    read entity_type

    echo "Enter starting number: "
    read start

    echo "Enter ending number: "
    read end

    create_generic_entity "$prefix" "$extension" "$path" "$entity_type" "$start" "$end"

elif [[ "$mode" == "list" ]]; then
    echo "Enter the list of names separated by spaces (e.g., 'list1 list2 list3'): "
    read list_of_names

    echo "Enter file extension (e.g., '.c'): "
    read extension

    echo "Enter path location (e.g., '/home/user/documents'): "
    read path

    echo "Enter type of entity (f for file, d for folder): "
    read entity_type

    create_list_entity "$list_of_names" "$extension" "$path" "$entity_type"

else
    echo "Error: Invalid mode. Use 'generic' or 'list'."
    exit 1
fi
