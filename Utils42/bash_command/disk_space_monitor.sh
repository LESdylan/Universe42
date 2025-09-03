#!/bin/bash
# Disk Space Monitor

THRESHOLD=80

USAGE=$(df / | tail -1 | awk '{print $5}' | sed 's/%//')
if [ "$USAGE" -gt "$THRESHOLD" ]; then
  echo "Warning: Disk usage is at ${USAGE}%."
fi
