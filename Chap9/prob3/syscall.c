#include <sys/wait.h>
#include <stdio.h>

int main() 
 { 
 int status;
if ((status = system("date")) < 0)
	perror ("system()ERROR");
 printf("ENDcode %d\n", WEXITSTATUS(status));

if ((status = system("hello")) < 0)
  perror("system() ERROR");
 printf("END_CODE %d\n", WEXITSTATUS(status));

if ((status = system("who; exit 44")) < 0)
  perror("system() ERROR");
 printf 
