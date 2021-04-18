#!/bin/bash

#Filip Kryczek, 241302
#Skrypt 5

if [[ "$#" != 2 ]]; then
  echo "Wprowadz poprawnie dane - ./zad2.sh ./katalog1 .rozszerzenie"
  exit 1
fi

if [[ ! -d $1 ]]; then
  echo "Nie znaleziono podanego katalogu"
  exit 2
fi

writeFile=allFile$2
touch $writeFile

for file in $1/*; do
  if [[ $file != $writeFile ]]; then
    echo "Wpisywanie zawartosci $file do $writeFile"
    echo $file >> $writeFile
    cat $file >> $writeFile
  fi
done
