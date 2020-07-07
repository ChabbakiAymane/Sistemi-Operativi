#include <stdio.h>
#include <fcntl.h>

//al posto di char * ora posso usare string (e' un alias)
typedef char* string;

//Errori vengono stampati sul canale stderr=2 non su stdout=1
int warn(string msg, int code){
   //printf("%s\n", msg);
   //uso la funzione fprintf() che permette di specificare il canale d'uscita (stderr)
   fprintf(stderr, "%s\n", msg);
   return code;
};

void nl(){
  printf("\n");
};


void feedback(string filename, int size){
   printf("%s : %d bytes\n", filename, size);
}

int computeSize(string filename){
   int code=2;
   int fd;
   int size;

   fd=open(filename, O_RDONLY);
   if(fd>-1){
     //int dim = lseek(file, offset, option); //restituisce la posizione corrente calcolata dall'inizio
     //lseek(fd, 5, SEEK_SET); //SEEK_SET impongo che il corsore parta con l'offset scelto
     //lseek(fd, 10, SEEK_CUR); //SEEK_CUR prende il cursore corrente e ci aggiunge 10 (spostamento)
     //lseek(fd, -1, SEEK_END); //SEED_END posiziona il cursore alla fine del file e torna indietro
     size=lseek(fd, 0, SEEK_END); //cursore viene posizionato all'ultima posizione possibile (dimFile-0)
     feedback(filename, size);
     code=0; //andato tutot bene
     close(fd); //rilascio le risorse
   }else{
     code = warn("?Error opening file", 3);
   };
   return code;
};

int main(int argc, char *argv[]){
   //char *argv[] e' un puntatore di stringhe (quindi puntatore di puntatori)
   //argv[] viene valorizzato dal nome dell'eseguibile e poi da eventuali parametri
   //printf("argc=%d, argv=%s,%s,%s\n", argc, argv[0], argv[1], argv[2]);

   nl();
   int ret=0;
   string filename;

   //Se l'eseguibile non viene invocato con "nomeExe" e con un solo parametro genero un errore
   if(argc!=2){
     //printf("?Errore\n");
     //ret=1;
     ret = warn("?Errore", 1);
   }else{
     filename=argv[1]; //prendo il nome del file
     ret = computeSize(filename);
   };
   nl();
   return ret;
}
