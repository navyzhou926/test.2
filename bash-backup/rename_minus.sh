#!/bin/bash
#cd /home/navyzhou/test.2/bash-test/
DIR=$1
cd $DIR 
#filename="abc.c"
for filename in `ls` 
do 
    #mv $filename $filename.c
    file=`echo $filename|awk -F '.' '{printf $1"."$2}'`
    echo $file
    mv $filename $file
done
