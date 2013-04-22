#!/bin/bash

printf "Please type an action:\n\"cp\" - copy\n\"rm\" - remove\n\"mv\" - rename\n\"ln\" - link\n"
read action

case $action in
	"cp" )
		printf "Enter target file name: "
		read arg_1
		printf "Enter new file name: "
		read arg_2
		cp $arg_1 $arg_2
		;;
	"rm" )
		printf "Enter target file name: "
		read arg_1
		rm -rf $arg_1
		;;
	"mv" )
		printf "Enter target file name: "
		read arg_1
		printf "Enter new file name: "
		read arg_2
		mv -f $arg_1 $arg_2
		;;
	"ln" )
		printf "Enter target file name: "
		read arg_1
		printf "Enter link name: "
		read arg_2
		ln -s $arg_1 $arg_2
		;;
	* )
		printf "Wrong command!\n"
		;;
esac
