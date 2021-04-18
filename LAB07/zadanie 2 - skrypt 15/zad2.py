#!/usr/bin/python3
#Filip Kryczek, 241302
#skrypt nr 15

import sys, os

if len(sys.argv) != 2:
    print("Wprowadz poprawnie dane - ./zad2.py katalog2")
    exit()

if os.path.isdir(sys.argv[1]) == 0:
    print("Nie znaleziono podanego katalogu")
    exit()

count= 0
for f in os.listdir(sys.argv[1]):
           if os.path.isfile(os.path.join(sys.argv[1], f)) and os.access(os.path.join(sys.argv[1], f), os.X_OK):
              count = count + 1
print (count)
