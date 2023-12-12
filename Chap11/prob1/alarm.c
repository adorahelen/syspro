#include <stdio.h>

int main()
{ 
  int a = 0;  

  alarm(5);
  printf("infinite loof\n");
  while (1) { 
    sleep(1);
    printf("%d sec \n", a++);
  } 
   printf("No running\n");

 } 
  
