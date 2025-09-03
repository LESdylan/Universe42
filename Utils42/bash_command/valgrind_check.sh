#!/bin/bash

# Check if the correct number of arguments is provided
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 <path> <output_executable>"
    exit 1
fi

SRC_PATH=$1
OUTPUT_EXEC=$2

# Check if the source path exists
if [[ ! -d $SRC_PATH ]]; then
    echo "Error: Source path '$SRC_PATH' does not exist."
    exit 1
fi

# Find all .c files in the source path
SOURCE_FILES=$(find "$SRC_PATH" -name "*.c")
if [[ -z $SOURCE_FILES ]]; then
    echo "Error: No .c files found in '$SRC_PATH'."
    exit 1
fi

echo "Compiling the source files..."
gcc -Wall -Wextra -Werror -g -I"$SRC_PATH" $SOURCE_FILES -o "$OUTPUT_EXEC"
if [[ $? -ne 0 ]]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful!"
echo "Running valgrind to check for memory leaks..."
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind_leak_check.out.txt --error-exitcode=1 ./"$OUTPUT_EXEC"
valgrind --tool=cachegrind --log-file=valgrind_cachegrind.out.txt --error-exitcode=1 ./"$OUTPUT_EXEC"
valgrind --tool=massif --log-file=valgrind_massif.out.txt --error-exitcode=1 ./"$OUTPUT_EXEC"

rm -f "$OUTPUT_EXEC"
echo "Done."