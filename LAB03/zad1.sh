#!/bin/bash

#Filip Kryczek, 241302
#Zadanie 1

if [[ "$#" != 1 ]]; then
  echo "Wprowadz nazwe katalogu np.: Z1"
  exit 1
fi

rm -r $1

mkdir $1

mkdir $1/A
mkdir $1/A/B

mkdir $1/C
mkdir $1/C/D
mkdir $1/C/D/E

echo "Test 1" > $1/A/plik1.txt
echo "Test 2" > $1/A/B/plik2.txt
echo "Test 3" > $1/C/plik3.txt
echo "Test 4" > $1/C/D/E/plik4.txt

ln -s `realpath $1/C/plik3.txt` $1/A/link_bez_plik_plik3.txt
ln -s `realpath $1/A/B/plik2.txt` $1/C/link_bez_plik_plik2.txt
ln -s ../A/plik1.txt $1/A/link_plik1.txt
ln -s ../../../A/B/plik2.txt $1/C/D/E/link_plik_plik2.txt
ln -s ../../C/plik3.txt $1/A/B/link_plik_plik3.txt
