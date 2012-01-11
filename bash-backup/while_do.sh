#!/bin/bash
count=5
while [ $count -gt 0 ]
do
    echo $count
    let count=$count-1
done
    echo “The end count is $count”
