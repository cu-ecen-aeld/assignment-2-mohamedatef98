#!/bin/bash
if [ $# -eq 2 ]; then
    writefile=$1
    writestr=$2

    mkdir -p $(dirname $writefile)
    touch $writefile
    echo "$writestr" > $writefile
else
    echo "Wrong number of arguments"
    exit 1
fi