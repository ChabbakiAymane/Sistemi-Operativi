#!/bin/bash
x=2+3
echo "x=$x" #la vede come stringa, non stampa 5
z1=$(( x*2 )) #elabora il contenuto interno come espressione matematica (5*2)
z2=$(( $x*2 )) #il $x ha priorità suò $((..)) quindi abbiamo (2+3*2)
echo "z1=$z1"
echo "z2=$z2"

#manda la stringa a bc che stampa 3.14
echo ‘1.12 + 2.02’ | bc 

#da errore, perchè cerca 3.14 come comando ma visto che ho messo
#$(), viene invocato un altro programma bash (un altro processo) 
#e l'intera riga viene sostituita con il valore appena calcolato
# al posto di $(), quindi da errore perchè lo interpreta come comando
$(echo ‘1.12 + 2.02’ | bc)

echo "$(echo ‘1.12 + 2.02’ | bc)"