#!/bin/bash

# This .sh script uses jq to read json files, you should install it first.

config=$(cat config.json)

file=$(echo "$config" | jq -r '.src')
output=$(echo "$config" | jq -r '.out')
compile_cmd=$(echo "$config" | jq -r '.compile')
run_cmd=$(echo "$config" | jq -r '.run')

eval "$compile_cmd"

# check if compile is successful
if [ $? -eq 0 ]; then
    eval "$run_cmd"
else
    echo "Compilation failed."
fi