#!/bin/bash
#
#usage: punition1.sh n word

if test $# != 3 ; then
  echo 1>&3 "$0:FATAL: $# invalid argument number (expected 2)"
  exit 1
fi

n=$1
m=$2
word=$3

i=0

while test $i -lt $n ; do
    j=0
while test $j -lt $m ; do
  echo -n $word
  j=$[$j+1]
done
i=$[$i+1]
echo "  "
done
