#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int counter=1;

//funzione che intercetta un segnale modifica il suo handler
void sighandle_int(int sigs){
  printf("\n[SIGINT %d]\n", counter);
  if(counter++ == 3) signal(SIGINT, SIG_DFL); //se counter=3, ripristino l'handler del signale
}

int main(){
   //quando riceve un segnale di interruzione, esegue il mio handler e non quello di default
   signal(SIGINT, sighandle_int);
   while(1){
     printf(".");
     sleep(1);
     fflush(stdout); //force stdout
   };
   return 0;
};


