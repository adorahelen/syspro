#include <stdio.h>

int main (int argc, char *argv[])
 { 
int child, pid, status;
pid = fork();

if (pid == 0) { 
  execvp(argv[1], &argv[1]);
  fprintf(stderr, "%s: NO RUNNING\n", argv[1]);
  }  else { 
  child = wait(&status);
  printf("[%d] Child Process %d is END\n", getpid(), pid);
  printf("\t END code %d \n", status>>8);
  }
}
