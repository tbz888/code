#!/bin/bash
mkdir /mnt/USB &> /dev/null
mount -t vfat /dev/sdb1 /mnt/USB	#[root@localhost]:
ln -s /mnt/USB /home/tom/usb &> /dev/null
