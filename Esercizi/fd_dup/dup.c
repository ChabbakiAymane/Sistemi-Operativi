#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int fdlog; //descrittore file
  char *cmd;
  char *args[] = {NULL, NULL, NULL, NULL, NULL, NULL};

  //Ogni processo ha 3 canali (input, output, error)
  //Tramite la dup() possiamo alterare il comportamento di questi canali

  //param: nome del file, il file dove salvare i dati, il comando da eseguire e fino a 5 arg
  if(argc < 3 || argc > 7){
    printf("?.ERROR. Usate: %s <logfile> <cmd> ... [up to 5 args]\n", argv[0]);
    exit(1);
  }

  int a=0;
  printf("logfile=%s\n", argv[1]);
  printf("command=%s\n", argv[2]);

  //per eseguirlo: ./dup /tmp/log.txt ls -l /tmp/esempio
  fdlog = open(argv[1], O_WRONLY|O_CREAT, 0777); //apre il file in sola scrittura, se non esiste lo crea

  //modifico il canale 1, facendo si che il canale 1 non punti piu' al video, ma al file appena aperto
  dup2(fdlog, STDOUT_FILENO); //STDOUT_FILENO macro per il canale stdout (1)
  dup2(fdlog, STDERR_FILENO); //STDERR_FILENO macro per il canale error (3)
  //i canali 1 e 2 vengono modificati (rimango esistenti) ma semplicemente puntano a fdlog (file)

  cmd = argv[2];
  //argomenti da passare alla exec
  args[0] = cmd; //il primo e' il comando stesso

  //prendo gli argomenti passati da riga di terminale e li salvo in args
  for(a=3; a<argc; a++){
    args[a-2] = argv[a];
  };

  //sostituisce l'immagine del processo in esecuzione, con quello del comando che viene eseguito
  //la logica viene cambiata, ma eredita delle informazioni (come la tabella di file descriptor)
  execvp(cmd, args);
  close(fdlog);
  return 0;
}
