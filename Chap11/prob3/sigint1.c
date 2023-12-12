#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler();

int main()
{ 
 signal(SIGINT, intHandler);
 while (1)
  pause();
printf("No runnig \n");

}

void intHandler (int signo)
{
  printf("interupt signal hanlde\n");
  printf("signal number: %d\n", signo);
  exit(0);

}


