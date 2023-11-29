#include <stdio.h>
#include <unistd.h>

/*make child process*/

int main()
{
 int pid;
 printf("[%d] process start \n", getpid());

 pid = fork();
 printf ("[%d] process : return value %d\n", getpid(), pid);

} 
