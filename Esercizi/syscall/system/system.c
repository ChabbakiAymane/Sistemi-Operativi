#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
  printf("Going to run commands!\n\n");
  if(system("ls -l ; sleep 3s")==-1){
    printf("?Error: %d\n", errno);
  };
  printf("\n\nEnd (%d)\n", errno);
  return 0;
}
