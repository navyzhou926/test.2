#!/bin/bash

un=`id -nu xx 2> /dev/null`
if [ "$un" == "navyzhou" ]
then
    echo "用户存在"
else
    echo "用户不存在"
fi 
#!/bin/bash
cat /etc/passwd | grep  cyq


