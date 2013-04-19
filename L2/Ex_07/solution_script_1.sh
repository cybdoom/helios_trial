#!/bin/bash

printf "\nEnter basic salary: "
read basic_salary

if [ $basic_salary -lt 1500 ];
then
	let "HRA = basic_salary / 10"
	let "DA = (basic_salary * 9) / 10"
else
	HRA=500
	let "DA = (basic_salary * 98) / 100"
fi

printf "\nHRA = "$HRA"\tDA = "$DA"\n"