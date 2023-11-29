#!/bin/bash

# Function to check if a file ends with ".cpp"
function endsWithCpp {
    [[ "$1" == *.hpp ]]
}

# Function to compile the C++ file using g++
function compileWithGpp {
    file="main.cpp"
    echo "Compiling $file with g++..."
    g++ -Wall "$file" -o "${file%.cpp}.out"
}

# Monitor the current directory for file changes
inotifywait -m -e close_write --format "%f" . |
while read -r filename; do
    if endsWithCpp "$filename"; then
        compileWithGpp "$filename"
    fi
done
