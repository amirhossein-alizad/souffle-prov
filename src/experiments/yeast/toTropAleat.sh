#!/bin/bash

while read src tgt
do
	echo -e "$src\t$tgt\t$((($RANDOM%$1)+1))"
done
exit()
