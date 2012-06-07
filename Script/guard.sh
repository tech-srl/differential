#!/bin/bash
echo Usage: guard.sh filename [-prep] [-x0] [-ret] [-inline]
if [[ $# < 1 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
ParseCommandLine $@
Preprocess $filename
Inline $filename
echo "Guarding $file...(ucc -g $filename $ret_guard $x0)"
ucc -g $filename $ret_guard $x0
echo Done