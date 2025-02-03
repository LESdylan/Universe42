#!/bin/bash

# Function to create a C file with a template
function template() {
    local file="$1"
    local extension="$2"
    if[["$extension" -eq "$f"]]; then
        cat <<EOF > "$file"
#include <stdio.h>
#include <stdlib.h>

void function()
{
    return;
}

int main(void)
{
    return (0);
}
EOF
    fi
    if[[ "$extension"-eq "$f"]]; then
        cat <<EOF > "$file"
        #ifndef _H
        #define _H
        
        //define a macros
        //
        
        
        #endif
        
        EOF
    echo "Template written to $file"
}

# Loop through all provided arguments
for file in "$@"; do
    template "$file"
done
