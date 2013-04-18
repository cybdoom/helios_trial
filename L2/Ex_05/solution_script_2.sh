#!/bin/bash

for i
do
	name_uppercase=${i^^}
	if [ -a $PWD"/"$name_uppercase ];
	then
		printf "File "$name_uppercase" is in current directory\n"
	else
		printf "File "$name_uppercase" is absent in current directory\n"
	fi
done
