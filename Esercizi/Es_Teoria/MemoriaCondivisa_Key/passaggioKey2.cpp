//Compilare: /usr/bin/g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o xxx Xxx.cpp
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
    key_t key;
    int i, s;
    int shm, shm1;
    char *addr, *addr1;
    struct shmid_ds buf;

    /*
        ftok --> file to key, è una funzione che preso il nome di una file
        lo trasforma in un valore che va bene per una chiave

        se i due processi richiamano la funzione con lo stesso pathname, ottengono
        la chiave per la memoria condivisa
    */
    key = ftok("/home/chabby/Documents/Projects_SistemiOperativi/MemoriaCondivisa_Key", 3);
    printf("key = %d\n", key);

    shm1 = shmget(key, 100, IPC_CREAT + S_IRUSR + S_IWUSR);
    addr1 = (char*)shmat(shm1, NULL, 0);

    printf("P4: identifier of the shared memory shm1 = %d\n", shm1);
    printf("P4 read from shared memory %s\n", addr1);
    sprintf(addr1, " P4 wrote on shared memory: chabby");
    printf("%s\n", addr1);

    shmdt(addr1); //eseguo la detach
    shmctl(shm1, IPC_RMID, 0); //distruggo il segmento
}