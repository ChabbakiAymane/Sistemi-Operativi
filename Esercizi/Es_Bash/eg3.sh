#!/bin/bash

x=7

#./eg3.sh --help --esempio
#tutto quello che viene scritto dopo il file, viene assegnato a $1, $2, ecc
#$@ è l'insieme di tutti gli elementi ($1,...,$9)
#shift elimina il primo paramentro e sposta tutti gli altri
echo Dollaro 1 = $1
echo Dollaro 2 = $2