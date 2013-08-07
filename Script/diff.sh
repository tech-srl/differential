#!/bin/bash
function usage {
	echo "Usage: $(basename $0) <compare-dir>"
	echo "Diffs all the c files in this dir with the files in <compare-dir> and puts the different files,"
	echo "alongside the files from the <compare-dir> under tmp (with patched.* prefix)"
}

if [[ $# < 1 ]]
    then
	usage
        echo "Not enough args, exiting"
        exit
fi

mkdir tmp 2>/dev/null
dir=$(echo $1 | sed 's/\/$//')
for file in $( ls *.i ); do
	echo diff $file $dir/$file
	if [[ $(diff $file $dir/$file) != "" ]]
	    then
#		file=$(echo $file | sed 's/c$/i/')
		echo "cp $file tmp/"
        	cp $file tmp/$file
		echo "cp $dir/$file tmp/patched.$file"
		cp $dir/$file tmp/patched.$file
	fi
done

