#include <stdio.h>


int main(){
  FILE *fp;
  int c;
  printf("Esempio stream\n");
  fp = fopen("stream.c", "r"); //syscall che apre un file in modalita' read (r)

  while(1){
    c = fgetc(fp); //funzione che dato un riferimento ad un file, leggere un carattere (e continua)

    //funzione che verifica se il corsore del file (fp) non ha raggiunto la fine del file
    if(feof(fp)) break; //se raggiungo la fine, esco dal while

    printf("%c", c);
  };

  fclose(fp);
  printf("Fine.\n");

  return 0;
}
