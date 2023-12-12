#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;
void alarmHandler();



int main(int argc, char *argv[])
{ 
 int child, status, limit;

 signal(SIGALRM, alarmHandler);
 scanf(argv[1], "%d", &limit);
 alarm(limit);

 pid = fork();
 if (pid == 0) { 
   execvp(argv[2], &argv[2]);
   fprintf(stderr, "%s No Run\n", argv[1]);
 } else { 
 child = wait(&status);
 printf("[%d] child process %dend\n", getpid(), pid);
 }
}

void alarmHandler()
{
 printf("[alarm] child process %d time over\n", pid);
 kill(pid, SIGINT);
}
