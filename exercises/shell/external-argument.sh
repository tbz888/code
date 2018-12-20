#!/bin/bash
echo "Path: "`pwd`
echo "number: "$#
declare -i pos=0
for i in $*
do
	let "pos=$pos+1"
	echo $pos":"$i
done
