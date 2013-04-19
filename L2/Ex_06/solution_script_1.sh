#!/bin/bash

awk -v from=$2 -v to=$3 '
	{
		if (NR >= from && NR <= to)
		{
			print
		}
	}' $1
