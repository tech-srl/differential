#!/bin/bash
echo "Usage: $(basename $0) <compare-dir>"
echo "Diffs all the c files in this dir with the files in <compare-dir> and puts the different files,"
echo "alongside the files from the <compare-dir> under tmp (with patched.* prefix)"
if [[ $# < 1 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
echo "Press 'Enter' to continue or terminate with 'Ctrl+c'"
read -n1 kbd
mkdir tmp 2>/dev/null
dir=$(echo $1 | sed 's/\/$//')
for file in $( ls *.c ); do
	echo diff $file $dir/$file
	if [[ $(diff $file $dir/$file) != "" ]]
    then
		file=$(echo $file | sed 's/c$/i/')
		echo "cp $file tmp/"
        cp $file tmp/
		echo "cp $dir/$file tmp/"
		cp ../../coreutils-6.11/src/$file tmp/patched.$file
	fi
done

