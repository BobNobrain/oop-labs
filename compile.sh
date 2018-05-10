#!/usr/bin/bash

file_name=${1:-main.cpp}
if ! [[ -f "${file_name}" ]]; then
    echo "No such file: ${file_name}!"
    exit 1
fi

exe_name=${file_name%.*}

if g++ -Wall -std=c++11 "${file_name}" -o "${exe_name}"; then
    echo "Compiled successfully into ${exe_name}"
else
    echo "Failure!"
fi
