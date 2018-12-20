#!/bin/bash
#[root@localhost]:
umount /dev/sdb1 && eject /dev/sdb1
yes | rm -r /home/tom/usb &> /dev/null
