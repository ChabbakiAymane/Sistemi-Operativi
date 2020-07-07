#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int *shared; //puntatore alla shared memory
int shmid; //identificativo della shared memory
int pid; //process id

int main(){
    int s, i;
    /*
        Visto che la relazione è tra processo padre e figlio,
        usiamo IPC_PRIVATE
        0600 --> specifica i privilegi che ha il segmento, in questo caso
        solo il proprietario (chi lo ha creato) può leggere e scrivere 
    */
    shmid = shmget(IPC_PRIVATE, sizeof(int), 0600);
    printf("shmid = %d\n", shmid);

    shared = (int*)shmat(shmid, 0, 0);
    //shared = shmat(shmid, 0, 0);
    *shared = 100;

    printf("%d\n", *shared);

    //Creazione di figlio in modalità sincrona
    pid = fork();
    if(pid == 0){
        //SON
        sleep(5);
        *shared = 1000;
        shmdt((const void *) shared); //si stacca dal segmento
    }else{
        //FATHER
        wait(&s); //il padre aspetta il figlio
        printf("%d\n", *shared);
        shmdt((const void *) shared); //si stacca dal segmento
        shmctl(shmid, IPC_RMID, 0); //distrugge il segmento
    }
    return 0;
}
