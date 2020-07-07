#include <stdio.h>

int main(){
  int f;
  f=fork();
  if(f==-1){
    printf("Errore fork\n");
    return 1;
  };
  if(f>0){
    //PADRE
    printf("Sono il padre, PID=%d, FIGLIO=%d\n", getpid(), f);
  }else{
    //FIGLIO
    printf("Sono il figlio con PID=%d, PADRE=%d\n", getpid(), getppid());
  };

  return 0;
}
