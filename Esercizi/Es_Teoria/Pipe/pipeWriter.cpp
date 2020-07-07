//Compilare: /usr/bin/g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o xxx Xxx.cpp
#include <fcntl.h> //per le pipe
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

//PROCESSO CHE MANDA DATI NELLA PIPE E ASPETTA CHE IL READER LI RICEVA
int main(){
    int fd;
    char *myfifo = "./myfifo";

    //create the FIFO (named pipe)
    //0666 --> privilegi, tutti possono scrivere e leggere
    mkfifo(myfifo, 0666);

    //write HI to the FIFO
    //O_WRONLY --> privilegi, solo owner può leggere e scrivere
    fd = open(myfifo, O_WRONLY);
    write(fd, "I am your named pipe", sizeof("I am your named pipe"));
    close(fd);

    //remove the FIFO
    unlink(myfifo);

    return 0;
}