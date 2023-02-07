#! /bin/bash

for i in {1..1000};
do echo $RANDOM;
done > nums.txt;

echo end >> nums.txt
