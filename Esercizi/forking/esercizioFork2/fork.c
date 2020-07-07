#include <stdio.h>
#include <sys/wait.h>

int figlio(){
  int r=3;
  printf("FIGLIO\n");
  return r;
};

int padre(){
  int r=4;
  int c;
  int st;

  printf("PADRE\n");
  c = wait(&st); //attendo che un figlio termini, passo st per riferimento

  //c = identificatore del processo terminato (PID del figlio)
  //st = stato di ritorno, non solo il codice d'errore numerico (contiene tante informazioni)
  //utilizzando delle macro definite nella libreria wait.h, e' possibile estrapolare i singoli 
  //componenti di questo stato passando la variabile inizializzata tramite wait
  //WEXITSTATUS(var) restituisce lo stato d'uscita del processo terminato
  printf("wait result: %d, %d\n", c, WEXITSTATUS(st));
  return r;
};

int main(){
  int r=0;
  int f;
  f = fork();
  if(f==-1) {
    printf("?Error fork\n");
    r=1;
  }else{
    if(f == 0){
      r = figlio();
    }else{
      r = padre();
    }
  }
  return r;
};
