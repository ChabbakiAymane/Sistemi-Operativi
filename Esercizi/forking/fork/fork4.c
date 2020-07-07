#include <stdio.h>

int myFork(){
  int f;
  f = fork();
  if(f==-1){
    printf("Errore fork\n");
    return -1;
  };
  return f;
}

int main(){
  int f;
  f=myFork();
  if(f>0){
    //PADRE
    f=myFork();
    if(f>0){
      printf("Sono il padre (nonno), PID=%d, FIGLIO=%d\n", getpid(), f);
    }else{
      printf("Sono il secondo figlio, PID=%d, PADRE=%d\n", getpid(), getppid());
    };

  }else{
    //FIGLIO
    f=myFork();
    if(f>0){
      printf("Sono il padre-figlio con PID=%d, PADRE=%d, FIGLIO=%d\n", getpid(), getppid(), f);
    }else{
      printf("Sono il figlio del figlio, PID=%d, PADRE=%d\n", getpid(), getppid());
    };
  };

  return 0;
}
