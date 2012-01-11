#!/bin/bash
#DIR=/home/navyzhou/test.2/bash-test/
DIR=$1
cd $DIR 
#cd bash-test/
for filename in `ls` 
do 
    mv $filename $filename.c
    echo $filename.c
done
