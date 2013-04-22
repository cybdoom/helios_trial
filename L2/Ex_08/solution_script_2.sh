#!/bin/bash

echo "Enter users name:"
read user_name

row=`w -h | grep "^"$user_name | head -1`
if [[ row != "" ]];
then
	echo -n $user_name"'s last login at: "
	echo $row | tr -s " " | cut -d " " -f 3
else
	echo "Unknown user"
fi
