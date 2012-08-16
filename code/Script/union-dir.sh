#!/bin/bash
for file in $( ls *.i ); do
        if [[ $file != *patched* && $file != *guarded* && $file != *union* ]] 
        then
            echo Unioning $file...
	    union.sh $file patched.$file $@
	    echo Done.
        fi
done

