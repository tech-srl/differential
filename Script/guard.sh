#!/bin/bash
echo Usage: guard.sh filename [-prep|x0|ret|inline=true|false]
if [[ $# < 1 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
# Set the default options for the ucc
x0="-x0=false"
ret_guard="-ret_guard=true"
ParseUccCommandLine $@
Preprocess $filename
Inline $filename
echo "Guarding $file...(ucc -g $filename $ret_guard $x0)"
ucc -g $filename $ret_guard $x0
echo Done
