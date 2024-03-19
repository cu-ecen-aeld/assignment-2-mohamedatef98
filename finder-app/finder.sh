#!/bin/bash
if [ $# -eq 2 ]; then
    filesdir=$1
    searchstr=$2

    if [ -d "$filesdir" ]; then
        num_matches=$(grep $searchstr $filesdir -r | wc -l)
        num_files=$(grep $searchstr $filesdir -c -r | wc -l)
        echo "The number of files are $num_files and the number of matching lines are $num_matches"
    else
        echo "$filesdir isn't a directory"
        exit 1
    fi
else
    echo "Wrong number of arguments"
    exit 1
fi