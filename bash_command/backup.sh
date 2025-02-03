#!/bin/bash
# Backup Script

SOURCE_DIR=${1:-$HOME}
BACKUP_DIR=${2:-$HOME/backups}
TIMESTAMP=$(date +"%Y%m%d%H%M%S")
BACKUP_FILE="backup-$TIMESTAMP.tar.gz"

mkdir -p "$BACKUP_DIR"
tar -czf "$BACKUP_DIR/$BACKUP_FILE" -C "$SOURCE_DIR" .
echo "Backup completed: $BACKUP_DIR/$BACKUP_FILE"
