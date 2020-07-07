#!/bin/bash

#x = 6 non va bene mettere spazi
#tutto quello che scrivo viene visto come stringa
#dipende dal contesto in cui vengono usate
x=7

#$x viene usato per accedere alla variabile
#${x} usato per accedere alla variabile x in modo più "sicuro"
echo Ciao $x !
#quando viene eseguito, interpreta l'intera stringa come variabile, non vedo 7
echo Ciao $xilofono ! 
#stampa 7ilofono
echo Ciao ${x}ilofono !