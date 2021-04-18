#!/bin/bash

#Filip Kryczek, 241302
#Zadanie 1

if [[ "$#" != 1 ]]; then
  echo "Wprowadz nazwe katalogu np.: Z1"
  exit 1
fi

mkdir $1
touch $1/1.t
touch $1/2.tx
touch $1/3.txt
touch $1/4.tx
touch $1/5.t
touch $1/test1.t
touch $1/test2.tx
touch $1/test3.txt
touch $1/test4.txt
touch $1/test5.txt
touch $1/1test2.txt
touch $1/2test3.tx
touch $1/4test5.t

echo "-----"

find $1 -name "test*" -print | sort | tail -n 4

echo "-----"

find $1 -maxdepth 2 -name "*.txt" -print | while read file
do
  echo `realpath $file` | tr '/' '|'
done

echo "-----"

find $1 \( -mmin +1 -o -size -1k \) -print -exec rm {} \;

echo "-----"

