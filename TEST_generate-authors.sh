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
	echo ""
	echo "Reference: [Moby AUTHORS file](https://github.com/moby/moby/blob/master/AUTHORS)"
} > "$AUTHORS_FILE"

echo "AUTHORS file created."

# Check for Betty compliance
for file in $C_FILES; do
	echo "Checking $file for Betty compliance..."
	betty-style "$file"
	betty-doc "$file"
done

echo "Betty checks completed."
