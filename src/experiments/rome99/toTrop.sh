#!/bin/bash

while read type src tgt val
do
	if [ $type = "a" ]
       	then
		echo -e "$src\t$tgt\t$val"
	fi
done
exit()
