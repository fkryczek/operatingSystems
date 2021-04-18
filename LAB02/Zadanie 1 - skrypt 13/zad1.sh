#!/bin/bash

#Filip Kryczek, 241302
#Skrypt 13

if [[ "$#" != 2 ]]; then
  echo "Wprowadz poprawnie dane - ./zad1.sh ./katalog1 ./katalog2"
  exit 1
fi

if [[ ! -d $1 ]]; then
  echo "Nie znaleziono pierwszego katalogu"
  exit 2
fi

if [[ ! -d $2 ]]; then
  echo "Nie znaleziono drugiego katalogu"
  exit 3
fi

for firstFile in `ls $1`; do
  for secoundFile in `ls $2`; do
    if [[ $firstFile = $secoundFile ]] &&  [[ ! -d $firstFile ]] &&  [[ !  -d $secoundFile ]]; then
      if [[ -d $1/$firstFile ]]; then
        echo "Katalogi nie zotana usuniete"
      else
        rm -f $1/$firstFile
      fi
    fi
  done
done
