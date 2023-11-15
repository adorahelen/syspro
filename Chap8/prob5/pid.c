#include <stdio.h>
#include <unistd.h>

int main () 
{
 printf("my process number : [%d]\n", getpid());
 printf("my Pprocess number : [%d]\n", getppid());

} 

