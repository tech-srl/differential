#!/bin/bash
echo Usage: analyze-file.sh filename manager canon_point canon_strategy [canon_threshold]
if [[ $1 == "" ]] # No filename given, exit
    then
        echo "No filename given, exiting"
        exit
fi
if [[ $2 == "" ]] # No Mgr given, exit
    then
        echo "No Domain manager given, exiting"
        exit
fi
if [[ $3 == "" ]] # No CP given, try all of them
    then
        cp="try all of them"
fi
if [[ $4 == "" ]] # No CS given, exit
    then
        echo "No Canonization Strategy given, exiting"
        exit
fi
if [[ $5 == "threshold" && $4 == "" ]] # No threshold given, exit
    then
        echo "No Canonization Threshold given when needed, exiting"
        exit
fi
echo Filename = $1, Manager = $2, Canonization Point = $3, Canonization Strategy = $4, Canonization Threshold = $5
echo "Press 'Enter' to continue or terminate with 'Ctrl+c'"
read -n1 kbd
mkdir $2.$3.$4$5 2>/dev/null
timeout 600 complete $1 -c=patched.$1 -m=$2 -c_p=$3 -c_s=$4 -c_t=$5 -r=report.$2.$3.$4""$5.out > $2.$3.$4$5/$1.out 2> $2.$3.$4$5/$1.err
echo $1 done

