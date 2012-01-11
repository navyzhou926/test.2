#!/bin/bash
find . -name $1 -print
echo $?
if [ $? = 0 ];then
    echo "find file $1"
else
    echo "can not find file $1"
fi
