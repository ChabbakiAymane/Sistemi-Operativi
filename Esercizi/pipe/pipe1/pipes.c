#include <stdio.h>
#include <string.h>

#define READ 0 		//lato lettura pipe
#define WRITE 1 	//lato scrittura pipe
#define MAXLEN 100

char *msg = "Content of pipe.";

int main(){
  int fd[2]; //contiene i riferimenti all'estremita della pipe
  int bytesRead; //byte letti
  char message [MAXLEN]; //buffer

  ////inizializza il vettore fd con due interi creando due descrittori che sono intercorrelati tra loro
  pipe(fd); //devo controllare che sia andato tutto bene
  if(fork() > 0){ //PADRE scrive dati
    close(fd[READ]); //chiudo lato lettura del buffer
    write(fd[WRITE], msg, strlen(msg)+1); //strlen() non tiene conto del terminatore di stringa
    printf("PARENT: Written data.\n");
    close(fd[WRITE]);
  }else{ //FIGLIO legge dati
    close(fd[WRITE]); //chiudo lato scrittura del buffer
    bytesRead = read(fd[READ], message, MAXLEN);
    printf("CHILD: Read %d bytes: %s\n", bytesRead, message);
    close(fd[READ]);
  }
}
