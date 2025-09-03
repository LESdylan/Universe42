#!/bin/bash 
TARGET_DIR=${1:-$(PWD)}
for file in "$TARGET_DIR"/*;do
    EXT="${file##*.}"
    mdkir -p "$TARGET_DIR/$EXT"
    mv "$file" "$TARGET_DIR/$EXT"
fi
done
echo "Files organized by extension."