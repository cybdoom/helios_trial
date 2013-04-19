#!/bin/bash

string=$1
let "from = $2 - 1"

case $# in
	2 )
		string_length=${#string}
		let "substring_length = string_length - from"
		;;
	3 ) let "substring_length = $3 - from + 1"
esac

echo ${string:$from:$substring_length}
