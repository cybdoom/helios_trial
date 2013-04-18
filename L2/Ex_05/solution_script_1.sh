#!/bin/bash

for i
do
	if [ -d $i ];
	then
		printf "$i\t=>\tdirectory\n"
	else
		if [ -a $i ];
		then
			printf "$i\t=>\tfile\n"
		else
			printf "$i\t=>\tsomething else\n"
		fi
	fi
done