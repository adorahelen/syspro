#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
 printf("Start Parents process \n");
 if (fork() == 0) { 
  execl("/bin/echo", "echo", "hello", NULL);
  fprintf(stderr, "First Faile");
  exit(1);
}

if (fork() == 0) { 
  execl("/bin/date", "date", NULL);
  fprintf(stderr, "Second Faile");
  exit(2);
}


if (fork() == 0) {
  execl("/bin/ls", "ls", "-l", NULL);
  fprintf(stderr,"third Faile");
  exit(3);

}

printf("Parents process END \n");
}  

