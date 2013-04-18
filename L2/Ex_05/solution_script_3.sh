#!/bin/bash

echo $1" uses system for:"
w -h | grep "\<"$1"\>" | head -1 | sed 's/  */ /g' | cut -d " " -f 4