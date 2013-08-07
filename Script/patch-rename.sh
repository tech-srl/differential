#!/bin/bash
for file in $( ls *.{i,c} ); do
	echo Proccessing $file
	mv $file patched.$file
	echo Done
done
