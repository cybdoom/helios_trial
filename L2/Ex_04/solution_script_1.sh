#!/bin/bash

awk -F: '{print "Home directory of " $1 "=" $6}' /etc/passwd
