#!/bin/bash

printf "\nEnter word for search: "
read WORD
printf "Enter file name: "
read FILE_NAME
printf "Occurs: "
grep -c $WORD $FILE_NAME
