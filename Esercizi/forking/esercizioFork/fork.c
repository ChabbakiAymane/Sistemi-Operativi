#include <stdio.h>  // for printf, ...
#include <unistd.h> // for fork, getpid, getppid, ...
#include <time.h>   // for time, ...
#include <stdlib.h> // for rand, wait, ...

void nl(){
  printf("\n");
};

void info(){
  printf("Fork example"); nl();
  printf("try command: ps -o pid,ppid,stat,command"); nl(); nl();
  // stat rappresenta lo stato del processo:
  //  - S: attesa interrompibile S
  //  - D: attesa non interrompibile
  //  - R: esecuzione normale
  //  - Z: zombie
  //  - +: appartiene ai processi in forground
  //  - ecc...
};

int rnd(int min, int max){
  srand(time(NULL) + getpid()); //init rand's seed
  int steps = (max - min) + 1;  //how many
  int r; 			//will hold result
  r = rand()%(steps);
  r += min;
  return r;
}

//funzione che attende un certo lasso di tempo (secondi) passato per parametro
int delay(double dly){
  time_t start = time(NULL); //restituisce il tempo corrente come secondi secondo la UNIX epoc time
  time_t current;
  do{
     time(&current); //valorizzo la variabile current, la passo per riferimento (puntatore)
  } while(difftime(current, start) < dly);
  return dly;
};


int main(){
  nl();
  info();
  delay(2);
  pid_t fid; //variabile che rappresenta l'identificativo di un processo
  int r; //valore casuale di secondi da aspettare
  int status;//stato d'uscita
  int res = 1;

  //Con \n, la funzione manda il buffer nel canale d'uscita (stdout) e viene stampato a video
  //printf("PRIMA...\n"); delay(5); printf("...DOPO\n");
  //Senza \n, non e' detto che la funzione mandi il buffer in uscita, quindi non vediamo la scritta a video
  //Per risolvere il problema basta usare la funzione fflush() che forza l'uscita dei dati sul canale stdout
  //printf("PRIMA..."); fflush(stdout); delay(5); printf("...DOPO\n");

  fid = fork();
  if(fid == -1){
    printf("?Error. Forking failed\n");
    return res; //meglio avere un unico punto di uscita (un unico return)
  };

  printf("FORKED. PID=%d, PPID=%d\n", getpid(), getppid());
  delay(2);
  nl();

  if(fid>0){
    r = delay(rnd(2,4));
    printf("PARENT. Waited for %d secs. My PID is %d. My child has PID = %d\n", r, getpid(), fid);
    int cpid = wait(&status); //aspetta la terminazione di un figlio
    //Per recuperare lo stato d'uscita si usa WEXITSTATUS() vedere PDF
    printf("OK! My CHILD %d terminated with status=%d\n", cpid, WEXITSTATUS(status));
    res=0;
  }else{
    r = delay(rnd(5,7));
    printf("CHILD. Waited for %d secs. My PID is %d. My parent has PID = %d\n", r, getpid(), getppid());
    res=4;
  }

  nl();
  return res;
};
