#!/bin/bash

printf "\nEnter the word: "
read WORD

for i
do
	cat $i | sed "/\<"$WORD"\>/d" >new
	mv -f new $i
done
