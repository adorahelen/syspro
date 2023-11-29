#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


void print(const char *message) {
    printf("%s", message);
}



int main (int argc, char* argv[])
{
 int fd, status;
 fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0600);
 dup2(fd, 1);
 close(fd);
 print("Hello stdout! \n");
 fprintf(stderr,"Hello stderr !\n");

}
