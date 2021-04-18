#!/bin/bash
#Filip Kryczek, 241302

echo "Podpunkt A - procesy, które zużywają mniej CPU niż 10%"
ps aux | awk '
  {
    if( $3 < 10 ) {
      print "Użytkownik " $1 " ma uruchomiony proces o PID " $2 " - CPU = " $3 ", MEM = " $4 ".";
   }
  }'
echo "------------------------------------------------------------"

echo "Podpunkt B - procesy, które w COMMAND zawierając /usr/"
ps aux | awk '
  {
    if( $11 ~ /usr/ )
     print"Użytkownik " $1 " ma uruchomiony proces COMMAND: " $11 ".";
  }'
echo "------------------------------------------------------------"

echo "Podpunkt C - suma zużycia CPU i MEM"
ps aux | awk '
  BEGIN {
    CPU = 0;
    MEM = 0;
  }
  {
    CPU = CPU + $3;
    MEM = MEM + $4;
  }
  END {
    print "Suma CPU: " CPU ", Suma MEM: " MEM ".";
  }'
#ps pokazuje użycie procesora przez czas trwania procesu, a top pokauje użycie procesora od czasu kiedy zostało wykonane polecenie, dlatego mogą występować różnice.
echo "------------------------------------------------------------"

echo "Podpunkt D - liczba uruchomionych procesów przez danego użytkownika"
ps aux | awk '
  {
    if( $1 in processTab ){
      processTab[$1]++;
    }else{
      processTab[$1] = 0;
    }
  }
  END {
    for( user in processTab ){
      print "Użytkownik " user " łącznie ma uruchomionych " processTab[user] " procesów."
    }
  }'
echo "------------------------------------------------------------"

echo "Podpunkt E - użytkownicy, którzy mają najwięcej i najmniej uruchomiony procesów"
ps aux | awk '
  {
    if( $1 in processTab ){
      processTab[$1]++;
    }else{
      processTab[$1] = 0;
    }
  }
  END {
    mostProcess = 0;
    for ( user in processTab ){
      if( processTab[user] > mostProcess ){
        mostProcess = processTab[user];
        mostProcessUser = user;
      }
    }
    print "Użytkownik " mostProcessUser " ma najwięcej uruchomionych procesów: " mostProcess "."

    lessProcess = mostProcess;
    for( user in processTab ){
      if( processTab[user] < lessProcess){
        lessProcess = processTab[user];
        lessProcessUser = user;
      }
    }
      print "Użytkownik " lessProcessUser " ma najmniej uruchomionych procesów: " lessProcess " procesów."
  }'
echo "------------------------------------------------------------"
