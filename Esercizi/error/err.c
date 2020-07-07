#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){
  int fp=open("pippo1.txt", "r"); //apro un file che non esiste
  printf("BEGIN\n\n");
  printf("ERRNO + STRERROR:\n");
  printf("Last error: %d, %s\n", errno, strerror(errno));
  printf("\n");
  printf("PERROR:\n");
  perror("?Error"); //di default viene aggiunto un 'a capo'
  printf("\nEND\n\n");
  return 0;
}

