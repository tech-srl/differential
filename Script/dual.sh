#!/bin/bash
echo "Usage: dual.sh filename patched_filename [-m=<domain manager>] [-c_p=<canonization point>] [-c_s=<canonization strategy>] [-clear=] [-prep=] [-x0=] [-eq=] [-diffp=] [-ret=] [-inline=] [-asserts=]"
if [[ $# < 2 ]]
    then
        echo "Not enough args, exiting"
        exit
fi
source util.sh
echo "Filename : [$filename]"
echo "Patched Filename (if required) : [$patched_filename]"
ParseAnalyzerCommandLine $@
# Change the default options for the ucc to adhere to the dual run
clear="-clear=true"
x0="-x0=false"
tag_equality="-tag_equality=true"
diff_points="-diff_points=true"
ret_guard="-ret_guard=true"
ParseUccCommandLine $@
echo "Press 'Enter' to continue or terminate with 'Ctrl+c'"
read -n1 kbd
Preprocess $filename
Preprocess $patched_filename
Inline $filename
Inline $patched_filename
mkdir -p Results
echo "Dual run: (dual $filename -u=$patched_filename $manager $canon_point $canon_strategy $x0 $tag_equality $clear $diff_points $ret_guard $asserts -r=Report.log > Results/$filename.out 2> Results/$filename.err)"
dual $filename -u=$patched_filename $x0 $tag_equality $clear $diff_points $ret_guard $asserts $manager $canon_point $canon_strategy -r=Report.log > Results/$filename.out 2> Results/$filename.err
