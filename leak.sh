#!/usr/bin/bash

if [[ "$1x" == "x" ]]; then
    echo "Specify an input file!"
    exit 1
fi

file_name="$1"

if ! [ -x "${file_name}" ]; then
    echo "Not an executable: ${file_name}!"
    exit 1
fi

output_name="${file_name}.valgrind.txt"

valgrind --leak-check=full --show-leak-kinds=all "$file_name" 2>&1 | tee "$output_name"
