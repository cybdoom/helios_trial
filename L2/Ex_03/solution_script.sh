#!/bin/bash

printf "Current user: "
echo $USER
printf "Current user's shell: "
echo $SHELL
printf "\nContent of /etc/passwd to verify:\n"
cat /etc/passwd

rm -f myfile1
printf "\nWriting \"myfile1\"..."
who >> myfile1
printf " Done\n"
printf "\nContent of \"myfile1\":\n"
more myfile1

rm -f myfile2
printf "\nWriting \"myfile2\"..."
date >> myfile2
who >> myfile2
printf " Done\n"
printf "\nContent of \"myfile2\":\n"
more myfile2

printf "\n1-st \"sed\" results:\n"
export SED_COMMAND='s/^.//'
cat my_table | sed $SED_COMMAND

printf "\n2-st \"sed\" results:\n"
SED_COMMAND='s/.\(.\)$/\1/'
cat my_table | sed $SED_COMMAND

####TO COMPLETE####
#printf "\n3-st \"sed\" results:\n"
#SED_COMMAND='s/\<[^\s\t]\>'
#cat my_table | sed $SED_COMMAND