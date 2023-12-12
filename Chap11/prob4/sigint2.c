#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo);

int main(void)
{ 
 newact.sa_handler = sigint_handler;
 sigfillset(&newact.sa_mask);

 sigaction(SIGINT, &newact, &oldact);

while(1) { 
  printf("press the Ctrl-C !\n");
  sleep(1);
  } 
}


void sigint_handler(int signo)
{ 
  printf("%d signal handle!\n", signo);
  printf("if you press == end\n");
  sigaction(SIGINT, &oldact, NULL);
} 
