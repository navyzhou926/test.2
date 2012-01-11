#!/bin/bash
x=3
while test $x -gt 0
do
    y=3
    while test $y -gt 0
    do   
        echo “[$x, $y]”
        if test $y -eq 2
        then
            echo “breaking”
            break 1;
        fi 
        let y=$y-1 
    done 
    let x=$x-1 
done
