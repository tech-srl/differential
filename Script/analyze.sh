#!/bin/bash
echo "Usage: analyze.sh filename [-m=<domain manager>] [-c_p=<canonization point>] [-c_s=<canonization strategy>]"
if [[ $# < 1 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
echo "Filename : [$filename]"
ParseAnalyzerCommandLine $@
echo "Press 'Enter' to continue or terminate with 'Ctrl+c'"
read -n1 kbd
mkdir $2.$3.$4$5 2>/dev/null
echo "Analyzing...(diffyzer $filename $manager $canon_point $canon_strategy > analysis.$filename.out 2> analysis.$filename.err)"
diffyzer $filename $manager $canon_point $canon_strategy > analysis.$filename.out 2> analysis.$filename.err
echo "$filename Done"

