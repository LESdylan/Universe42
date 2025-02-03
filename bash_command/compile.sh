#!/bin/bash

main() {
    # Check if the correct number of arguments is provided
    if [[ $# -ne 1 ]]; then
        echo "ERROR: You need to input the path to the .c file"
        exit 1
    fi

    # Get the path of the .c file and determine the filename (without extension)
    src_path=$1
    filename=$(basename "$src_path" .c)

    # Define the output directory and file
    output_dir="/home/dyl-syzygy/Student42/lib.ft/exp"
    output="${output_dir}/${filename}"

    # Check if the source file exists
    if [[ ! -f "$src_path" ]]; then
        echo "ERROR: The source file does not exist: $src_path"
        exit 1
    fi

    # Ensure the output directory exists
    mkdir -p "$output_dir"

    # Compile the source file and link the math library
    gcc -o "$output" -Wall -Werror -Wextra "$src_path" -lm

    # Check if compilation was successful
    if [[ $? -ne 0 ]]; then
        echo "ERROR: Compilation failed for $filename. Please check your C code."
        exit 1
    fi

    echo "Compilation successful! Executable created at $output"
}

# Call the main function with the provided argument
main "$@"
