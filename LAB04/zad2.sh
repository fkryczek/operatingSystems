#!/bin/bash

#Filip Kryczek, 241302
#Zadanie 2

if [[ "$#" != 1 ]]; then
  echo "Wprowadz nazwe katalogu np.: Z2"
  exit 1
fi

rm -r $1
mkdir $1
touch $1/1.t
touch $1/2.jpg
touch $1/3.jpg
touch $1/4.jpg
touch $1/5.jpg
touch $1/6.png
touch $1/7.png
touch $1/8.png
touch $1/9.png
touch $1/10.t

find $1 \( -name "*.jpg" -o -name "*.png" \) -writable -print | while read file
do
  echo `realpath $file`"|"`date +'%d.%m.%Y'`"|"`date +'%H:%M:%S'`
done | tee result.dat

