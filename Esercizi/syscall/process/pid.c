#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  //Posso usare int o pid_t (sono compatibili)
  int pid; //processo
  int ppid; //padre
  int uid; //utente

  pid=getpid(); //recupero pid per processo
  ppid=getppid(); //recupero pid del padre
  uid=getuid(); //recupero id dell'utente

  printf("PID=%d\n", pid);
  printf("PPID=%d\n", ppid);
  printf("UID=%d\n", uid);
  return 0;
}

