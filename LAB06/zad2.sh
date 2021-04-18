#!/bin/bash
#Filip Kryczek, 241302

echo zawierających tylko same cyfry
egrep '^[0-9]+$' hasla -c

echo zawierających tylko same małe litery
egrep '^[a-z]+$' hasla -c

echo składających się z powtórzonego tego samego znaku
egrep '^(.)\1+$' hasla -c
