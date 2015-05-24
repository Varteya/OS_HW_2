#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


void main(int argc, char* argv[]){
    static const int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];

    int ffile = open("/home/nariel/human", O_RDONLY);
    int sfile = open("/home/nariel/alien", O_RDONLY);

    int new_file = open("/home/nariel/hell", O_CREAT | O_WRONLY, 0666);

    int i;
    while ((i = read(ffile, buffer, BUFFER_SIZE)) > 0){
        write(new_file, buffer, i);
    }
    while ((i = read(sfile, buffer, BUFFER_SIZE)) > 0){
        write(new_file, buffer, i);
    }

    close(ffile);
    close(sfile);
    close(new_file);

    return;
}

