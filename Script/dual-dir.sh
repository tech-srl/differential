#!/bin/bash
echo "Usage: dual-dir.sh [-m=<domain manager>] [-c_p=<canonization point>] [-c_s=<canonization strategy>] [-clear] [-prep] [-x0] [-eq] [-diffp] [-ret] [-inline] [-asserts]"
source util.sh
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
mkdir -p Results
for file in $( ls *.i ); do
        if [[ $file != *patched* && $file != *guarded* && $file != *union* ]] 
        then
            echo "Dual run: (timeout 1000 dual $file -u=patched.$file $x0 $tag_equality $clear $diff_points $ret_guard $asserts $manager $canon_point $canon_strategy -r=Report.log > Results/$file.out 2> Results/$file.err)"
            timeout 1000 dual $file -u=patched.$file $x0 $tag_equality $clear $diff_points $ret_guard $asserts $manager $canon_point $canon_strategy -r=Report.log > Results/$file.out 2> Results/$file.err
	    echo $file "done."
        fi
done

