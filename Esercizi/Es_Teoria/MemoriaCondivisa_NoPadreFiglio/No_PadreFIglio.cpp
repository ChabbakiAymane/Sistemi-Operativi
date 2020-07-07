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

//Non c'è una relazione Padre-Figlio tra due processi
int main(){
    key_t key; //chiave 
    int i, a;
    int shm;
    char *addr;
    struct shmid_ds buf;

    key = 8888; //deve essere passata processi, deve essere conosciuta
    
    /*
        Crea un segmento con chiave = 8888 e di dimensione 1000
        IPC_CREAT --> segmento viene creato da questo processo
        S_IRUSR & S_IWUSR --> privilegi mediante i quali il proprietario può leggere e scrivere
    */
    shm = shmget(key, 1000, IPC_CREAT + S_IRUSR + S_IWUSR);
    addr = (char*)shmat(shm, NULL, 0); //viene attaccato al processo (SO sceglie dove mettere il puntatore)
    
    sprintf(addr, "P1 wrote this content to shared memory %d ", shm);

    printf("P1: address of the shared memory addr = %d\n", *addr);
    printf("P1: identifier of the shared memory shm1 = %d\n", shm);
    printf("%s\n", addr);

    shmdt(addr);
    shmctl(shm, IPC_RMID, 0);
}
