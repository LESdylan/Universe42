#!/bin/bash
# Download Manager

URL_FILE=${1:-urls.txt}
DEST_DIR=${2:-downloads}

mkdir -p "$DEST_DIR"
while read -r URL; do
  wget -P "$DEST_DIR" "$URL"
done < "$URL_FILE"
echo "Downloads completed."
