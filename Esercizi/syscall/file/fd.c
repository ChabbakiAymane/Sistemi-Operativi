#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define bufsize 255

//mia funzione open() dove eseguo la exit con controllo
//mia funzione per la read() dove controllo e in caso libero le risorse

int main(){
  int fd; //variabile che contiene identificativo del file aperto (descrittore)
  char buf[bufsize]; //variabile dove salvo i dati del file
  int size; //contiene il numero di byte effettivamente letti
  int loop = 0;

  //chiamata di sistema che apre un canale con un file e resituisce l'identificativo
  fd = open("fd.c", O_RDONLY);
  //Controllo se la e' andata a buon fine
  if(fd==-1){
    printf("?Error: open");
    exit(2); //restituisco un mio codice d'errore
  };
  printf("FD=%d\n", fd);

  size=1;
  while(size>0){
    loop++;
    printf("\nLoop %d\n", loop);

    //Chiamata di sistema che legge i dati contenuti nel file rappresentato da fd
    //di salvare i dati letti all'interno dell'area di memoria puntata da buf
    //e di leggere fino a bufsize - 1 byte (minore della dimensione della variabile buf)
    size=read(fd, buf, bufsize-1); //permette di leggere il file
    if(size==-1){
      printf("?Error: read");
      close(fd); //libero le risorse
      exit(3);
    };

    if(size > 0){
      //se ho letto qualcosa, imposto come carattere terminatore lo 0 e stampo
      buf[size]='\0';
      printf("%s", buf);
    }
  };

  printf("size=%d\n", size);
  close(fd); //chiusura del canale e liberazione delle risorse
  return 0;
}
