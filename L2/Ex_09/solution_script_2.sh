#!/bin/bash

echo "Enter word: "
read word
echo "Enter filename: "
read filename

cat $filename | grep -o "\<"$word"\>" | wc -w
