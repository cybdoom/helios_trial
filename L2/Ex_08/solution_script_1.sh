#!/bin/bash

content_1="`cat $1`"
content_2="`cat $2`"

if [ "$content_1" == "$content_2" ];
then
	rm -rf $2
	echo "The content are same, file \"""$2""\" was deleted"
else
	echo -e "The contents differs"
fi