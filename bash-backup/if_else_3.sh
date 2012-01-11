#!/bin/bash
# Who is upper case,then it is default. so "Y/n" means "Y" is default
echo -n "Do you want to create a folder (Y/n) :"
read -e YesOrNo
# "YesOrNo:-y" means if YesOrNo is empty,then let YesOrNo equal "y"
if [ "${YesOrNo:-y}" = "y" ] || [ "${YesOrNo:-y}" = "Y" ];then
    echo "please input folder name:"
    read -e filename
    echo "success to create a folder named $filename"
else
    echo passed
fi
