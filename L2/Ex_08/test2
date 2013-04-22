#!/bin/bash

#find $PWD -type f |
#while read filename;
#do
#	if [ -r filename ] && [ -w filename] && [ -x filename ];
#	then
#		echo $filename
#	fi
#done

ls -l | cut -d " " -f 1,9 | grep ".rwx" | cut -d " " -f 2