for file in $( ls *.i ); do
    mv $file `basename $file .i`.c
done


