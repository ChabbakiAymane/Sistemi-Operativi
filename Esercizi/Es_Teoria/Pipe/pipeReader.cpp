//Compilare: /usr/bin/g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o xxx Xxx.cpp
#include <fcntl.h> //per le pipe
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

#define MAX_BUF 1024

int main(){
    int fd;
    char *myfifo = "./myfifo";
    char buf[MAX_BUF]; //dichiaro un buffer

    //open, read and display the message from the FIFO
    fd = open(myfifo, O_RDONLY); //diritti di lettura
    read(fd, buf, MAX_BUF);
    printf("Received: %s", buf);
    close(fd);

    return 0;
}