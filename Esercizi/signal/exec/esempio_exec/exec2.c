#include <stdio.h>

int main(){
  char *args[] = {"./exec1", NULL};
  //vuole come parametri il nome dell'eseguibile da usare e poi una lista di argomenti
  //dopo execvp() tutto viene sovrascritto con la nuova immagine
  execvp(args[0], args);
  printf("I'm ALICE\n");
  return 0;
}

