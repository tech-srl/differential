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
# Change the default options for the ccc
clear="-clear=false"
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
echo "Guarding $filename...(ccc -g $filename $ret_guard $x0)"
ccc -g $filename $ret_guard $x0 #2> ccc.guarded.$filename.err
echo "Guarding $patched_filename...(ccc -g_t $patched_filename $ret_guard $x0)"
ccc -g_t $patched_filename $ret_guard $x0 #2> ccc.guarded.$patched_filename.err
echo "Tagging guarded.$patched_filename...(ccc -t guarded.$patched_filename $tag_equality $asserts)"
ccc -t guarded.$patched_filename $tag_equality $asserts #2> ccc.tagged.guarded.$patched_filename.err 
echo "Unioning guarded.$filename and tagged.guarded.$patched_filename...(ccc -u tagged.guarded.$patched_filename guarded.$filename $clear $diff_points)"
ccc -u tagged.guarded.$patched_filename guarded.$filename $clear $diff_points #2> ccc.union.$filename.err
echo
echo "Look for error messages (if emitted) in the ccc.*.err files."
echo Done.
