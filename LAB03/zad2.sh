#!/bin/bash

#Filip Kryczek, 241302
#Zadanie 2

if [[ "$#" != 1 ]]; then
  echo "Wprowadz nazwe katalogu np.: Z1"
  exit 1
fi

./zad1.sh $1

cp -a $1/A/link_plik1.txt $1/C/D/E/
#System Linux wyswietla komunikat, ze plik link_plik1.txt jest uszkodzony, poniewaz wykorzystuje on sciezke wzgledna.
cp -a $1/A/link_bez_plik_plik3.txt $1/C/D/E/
#link_bez_plik_plik3.txt jest prawidlowo skopiowany, poniewaz wykorzystuje sciezke bezwzgledna(kanoniczna).

rm `readlink $1/A/link_bez_plik_plik3.txt`

readlink -f `ls -a -R | grep "plik3.txt"`

