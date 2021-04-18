#!/usr/bin/python3
#Filip Kryczek, 241302
#skrypt nr 13

import sys, os

if len(sys.argv) != 3:
    print("Wprowadz poprawnie dane - ./zad3.py katalog1 kataolg2")
    exit()

if os.path.isdir(sys.argv[1]) == 0:
    print("Nie znaleziono pierwszego podanego katalogu")
    exit()
    
if os.path.isdir(sys.argv[1]) == 0:
    print("Nie znaleziono drugiego podanego katalogu")
    exit()

for firstFile in os.listdir(sys.argv[1]):
    for secoundFile in os.listdir(sys.argv[2]):
        if firstFile == secoundFile and os.path.isdir(os.path.join(sys.argv[1], firstFile)) == 0 and  os.path.isdir(os.path.join(sys.argv[2], secoundFile)) == 0:
            os.remove(os.path.join(sys.argv[1],firstFile))
