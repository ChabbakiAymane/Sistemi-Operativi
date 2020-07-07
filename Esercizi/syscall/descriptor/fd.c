#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
  int fd; //indice file
  //funzione per riservare una zona di memoria (inizializzata a 0)
  //viene allocata una zona di memoria formata da 100 unita', ognuna che occupa 1B (dimensione di char)
  char *txt = (char *) calloc(100, sizeof(char)); //riserva 100 Byte
  int rd; //read
  
  fd = open("fd.c", O_RDONLY); //file aperto in lettura
  if(fd<0) exit(1);

  printf("FD=%d\n", fd);

  //qua bisogna stare attenti... nel nostro caso vengono stampati 10 caratteri, perche'
  //abbiamo inizializzato la zona di memoria txt con calloc() che mette tutto a 0
  //quindi quando stampo, alla 11 cella viene trovato uno 0 che fa da terminatore di stringa
  //printf("txt=%s\n", txt);


  //la funzione read() restituisce il numero di caratteri letti (byte letti)
  while(rd=read(fd, txt, 10)){
    if(rd>0){
       //SOLUZIONE: porre alla fine il terminatore di stringa
       //txt[10]=0; per forzare ma non funziona sempre bene
       txt[rd]=0; //migliore, perche' se leggo meno caratteri non ho problemi
       printf("%s", txt);
       //printf("RD=%d\n", rd);
    }else{
      break;
    };
  };

  close(fd);
  return 0;
}
