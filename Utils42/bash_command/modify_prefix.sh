#!/bin/bash
find . -type f -not -name "ft_*" -name "*.c" -exec bash -c '
  for file; do
    filename=$(basename "$file")
    if [[ "$filename" != ft_* ]]; then
      mv "$file" "$(dirname "$file")/ft_$filename"
    fi
  done
' bash {} +