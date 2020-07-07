#!/bin/bash

echo "Digita una lettera e premi INVIO"
read char #aspetta un comando prima di andare avanti
case $char in
    y|Y) 
        echo "Input: y" 
    ;; #alla fine devo mettere un doppio ;

    n) 
        echo "Input: n" 
    ;;

    *) 
        echo "Input: ne y ne n" 
    ;; #il * è un wildcat, se nessun caso si verifica stampa questo
esac