#!/bin/bash
echo "Usage: union.sh filename patched_filename [-clear|prep|x0|eq|diffp|ret|inline|asserts=true|false]"
if [[ $# < 2 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
echo "Filename : [$filename]"
echo "Patched Filename (if required) : [$patched_filename]"
# Change the default options for the ucc
clear="-clear=true"
x0="-x0=false"
tag_equality="-tag_equality=true"
diff_points="-diff_points=true"
ret_guard="-ret_guard=true"
ParseUccCommandLine $@
echo "Press 'Enter' to continue or terminate with 'Ctrl+c'"
#read -n1 kbd
Preprocess $filename
Preprocess $patched_filename
Inline $filename
Inline $patched_filename
echo "Guarding $filename...(ucc -g $filename $ret_guard $x0)"
ucc -g $filename $ret_guard $x0 #2> ucc.guarded.$filename.err
echo "Guarding $patched_filename...(ucc -g_t $patched_filename $ret_guard $x0)"
ucc -g_t $patched_filename $ret_guard $x0 #2> ucc.guarded.$patched_filename.err
echo "Tagging guarded.$patched_filename...(ucc -t guarded.$patched_filename $tag_equality $asserts)"
ucc -t guarded.$patched_filename $tag_equality $asserts #2> ucc.tagged.guarded.$patched_filename.err 
echo "Unioning guarded.$filename and tagged.guarded.$patched_filename...(ucc -u tagged.guarded.$patched_filename guarded.$filename $clear $diff_points)"
ucc -u tagged.guarded.$patched_filename guarded.$filename $clear $diff_points #2> ucc.union.$filename.err
echo
echo "Look for error messages (if emitted) in the ucc.*.err files."
echo Done.
