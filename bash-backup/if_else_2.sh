if [ -d abc ]; then
    rmdir abc
    echo abc have been deleted
else
    echo directory abc doesn\'t exist
fi
