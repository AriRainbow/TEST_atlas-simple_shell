#!/bin/bash

# This script generates the AUTHORS file and checks for Betty compliance

# Path to the AUTHORS file to be created
AUTHORS_FILE="AUTHORS"

# Find all C source files in current directory and its subdirectories
C_FILES=$(find . -name "*.c")

# Create AUTHORS file
{
	echo "# List of contributors to the Simple Shell project."
	echo "# This file is read by the 'generate-authors' script."
	echo ""
	echo "Ari Williams <mariel.williams@atlasschool.com>"
	echo "Harrison Gearhart <harrison@example.com>"
} > "$AUTHORS_FILE"

echo "AUTHORS file created."

# Check for Betty compliance
