#!/usr/bin/bash
echo -n "Enter soruce file name : "
read src
now=`wc --word < $src`
echo "--------------------------------------------------------"
echo "1.Number of words: $now"
echo "--------------------------------------------------------"
echo "2.printing the starting and last 5 lines of file"
head -5 $src
echo " -------"
tail -5 $src 
echo "--------------------------------------------------------"
echo "3.Occerence of the file"
egrep -c '\<Management\>' $src
echo "--------------------------------------------------------"
echo "4.Displaying the contents of the file"
cat $src

