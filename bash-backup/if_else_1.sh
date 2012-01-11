if [ ! -d abc ]; then
    mkdir abc
    echo creat directory abc
    echo $?
else
    echo directory abc exists
    echo $?
fi
