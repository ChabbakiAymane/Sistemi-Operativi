#include <stdio.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

// ./piperedir ls cat == ls | cat

int main(int argc, char *argv[]){
  int fd[2];

  pipe(fd);

  if(fork() > 0){
    close(fd[READ]);
    //quando il comando verra' eseguito, mandera' il suo output al descrittore e non a video
    dup2(fd[WRITE], 1); //dirotto il canale di output
    close(fd[WRITE]);
    execlp(argv[1], argv[1], NULL);
    perror("?Connect"); //viene visualizzato solo la exec non va a buon fine
  }else{
    close(fd[WRITE]);
    //mando i dati in input al descrittore
    dup2(fd[READ], 0); //dirotto il canale di input 0 con il descrittore
    close(fd[READ]);
    execlp(argv[2], argv[2], NULL);
    perror("?Connect"); //viene visualizzato solo la exec non va a buon fine
  };
}
