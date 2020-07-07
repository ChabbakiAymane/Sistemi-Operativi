//READER
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
   int fd;
   char *myfifo = "/tmp/pipe/pipe3/myfifo";
   //crea un file particolare su disco
   mkfifo(myfifo, 0666); //mkfifo(<pathname>, <permission>)
   char str1[80], str2[80];
   while(1){
     //open() fa da sincronizzatore
     fd = open(myfifo, O_RDONLY); //open FIFO for read only
     read (fd, str1, 80); //read from FIFO
     printf("User1: %s\n", str1); //print message and close
     close(fd);

     fd = open(myfifo, O_WRONLY); //Open FIFO for write only
     fgets(str2, 80, stdin); //input from user, maxlen=80
     write(fd, str2, strlen(str2)+1); //write and close
     close(fd);
   };
   return 0;
}
