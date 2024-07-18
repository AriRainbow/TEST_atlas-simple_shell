#!/bin/bash

# This script generates the AUTHORS file and checks for Betty compliance

# Path to the AUTHORS file to be created
AUTHORS_FILE="AUTHORS"

# Find all C source files in current directory and its subdirectories
C_FILES=$(find . -name "*.c")

# Create AUTHORS file