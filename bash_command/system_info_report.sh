#!/bin/bash
# System Info Report

echo "System Information Report"
echo "=========================="
echo "Uptime: $(uptime -p)"
echo "Disk Usage:"
df -h | grep '^/dev'
echo "Memory Usage:"
free -h
