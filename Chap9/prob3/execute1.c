#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
 printf("Parents procrss start\n");
 if (fork() == 0) {
  execl("/bin/echo", "echo", "hello", NULL);
  fprintf(stderr,"First Faile");
  exit(1);
 }
printf("Parents Process End\n");
}
