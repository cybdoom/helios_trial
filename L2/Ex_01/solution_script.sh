#!/bin/bash
cat /etc/passwd | cut -d : -f1,6 | sed 's/\([^:]*\):/Home directory of \1=/'
