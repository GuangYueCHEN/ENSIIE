#!/bin/bash
#
#usage: punition1.sh n word

if test $# -gt 3 ; then
  echo 1>&2 "$0:FATAL: $# invalid argument number (expected )"
  exit 1
fi

if test $# = 0; then
  n=10;m=3;word="je_ne_qsdqsdsqdsqdqsd"
elif test $# = 1; then
 n=10;m=3;word=$1
elif test $# = 2; then
n=10;m=$1;word=$2
else
n=$1;m=$2;word=$3
fi


./punition3.sh "$n" "$m" "$word"

