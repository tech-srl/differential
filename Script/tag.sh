#!/bin/bash
echo Usage: tag.sh patched_filename [-prep] [-x0] [-eq] [-ret] [-asserts]
if [[ $# < 1 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
ParseCommandLine $@
Preprocess $file
Inline $file
echo "Guarding $file...(ucc -g_t $file -ret_guard=$ret_guard -x0=$x0)"
ucc -g_t $file -ret_guard=$ret_guard -x0=$x0
echo "Tagging guarded.$file...(ucc -t guarded.$file -tag_equality=$tag_equality -asserts=$asserts)"
ucc -t guarded.$file -tag_equality=$tag_equality -asserts=$asserts
echo Done

