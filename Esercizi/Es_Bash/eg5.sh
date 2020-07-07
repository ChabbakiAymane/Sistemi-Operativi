#!/bin/bash
#codice per testare (debug)
echo "res=$?"
x=3
#test è un comando che fa confronti e restituisce 0 se è andato a buon
#fine o 1 se non è andato bene
test $x -eq 3 #verifica se x è uguale a 3
echo "res=$?"
#comando [], posso leggerle come "BEGIN TEST" e "CLOSE TEST"
#verifica se x è uguale a 0
[ $x -eq 0 ] #notare gli spazi
echo "res=$?"

#if e then sono 2 comandi diversi; devo mettere il ; oppure vado a capo
#righe diverse sono intepretate come comandi differenti
if [[ $x>5 ]]; then 
    echo "ciao"
else
    echo "ciao"
fi