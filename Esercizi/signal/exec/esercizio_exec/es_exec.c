#include <stdio.h>
#include <stdlib.h>

int warn(char *msg, int code){
   fprintf(stderr, "%s\n", msg);
   return code;
};

int rnd(int min, int max){
  srand(time(NULL) + getpid());
  int steps = (max - min) + 1;
  int r;
  r = rand() % (steps);
  r += min;
  return r;
};

int myFork(){
  int f;
  f = fork();
  if(f == -1){ f = warn("?. Error fork", -1); }
  return f;
};

int compute(int time){
  int i;
  int r; //variabile random
  int res = 0; //codice d'uscita

  char str[5];
  int newTime = (int) time/2;

  sprintf(str, "%d", newTime);
  char *args[] = {"./es_exec", str};
  printf("time = %d, str=%s\n", time, str);

  printf("ASPETTO %d secondi\n", time);
  printf("START. PID=%d PPID=%d\n", getpid(), getppid());
  fflush(stdout);

  for(i=1; i<=time; i++){
    printf("Secondi passati %d\n", i);
    fflush(stdout);

    sleep(1);

    r = rnd(0, 10);
    if(r%2 == 0){
      res = myFork();
      printf("Nuovo processo, aspetto %s secondi\n", args[1]);
      execvp(args[0], args);
      //printf("args = %s %s\n", args[0], args[1]);
    };
  };

  printf("END. PID=%d PPID=%d\n", getpid(), getppid());
  return res;
};

int main(int argc, char *argv[]){
   int res = 0;
   int time = 0;

   if(argc!=2){
     res = warn("?Error... only one arguments.\n./es_exec [seconds]", 1);
   }else{
     time = atoi(argv[1]); //secondi
     if(time==0){
       res = warn("!Time=0", 2);
     }else{
       res = compute(time);
     };
   };
   return res;
};
