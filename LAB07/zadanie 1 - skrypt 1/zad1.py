#!/usr/bin/python3
#Filip Kryczek, 241302
#skrypt nr 1

import sys, os

if len(sys.argv) != 2:
    print("Wprowadz poprawnie dane - ./zad1.py katalog1")
    exit()

if os.path.isdir(sys.argv[1]) == 0:
    print("Nie znaleziono podanego katalogu")
    exit()

filelist = [ f for f in os.listdir(sys.argv[1]) if f.endswith(".old") ]
for f in filelist:
    os.remove(os.path.join(sys.argv[1],f))

for f in os.listdir(sys.argv[1]):
    src = os.path.join(sys.argv[1], f)
    dst = os.path.join(sys.argv[1], f + ".old")
    os.rename(src, dst)
