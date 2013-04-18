#!/bin/bash

printf "\nEnter word for search: "
read WORD
printf "Enter file name: "
read FILE_NAME
FILE_NAME="solution_script_3.sh"
printf "Occurs: "
awk -v word=$WORD '/word/ {++counter}
				   END {print counter}' $FILE_NAME
