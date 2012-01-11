#!/bin/bash
if [ ! -d lll ];then
    mkdir ./lll
fi
for ((i=1;i<50;i++));do
    mkdir ./lll/$i
    echo "create folder $i"
done
