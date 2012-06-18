#!/bin/sh

REBOOT_RECORD=./reboot_record.txt
    if [ -s $REBOOT_RECORD ]; then
        REBOOT_COUNT=`cat $REBOOT_RECORD`
        #REBOOT_COUNT=`expr $REBOOT_COUNT "+" 1`
        echo $REBOOT_COUNT
        REBOOT_COUNT=$[ $REBOOT_COUNT + 1 ];
        echo $REBOOT_COUNT
        echo $REBOOT_COUNT > $REBOOT_RECORD
    else
        touch $REBOOT_RECORD
        echo 0 > $REBOOT_RECORD
    fi
