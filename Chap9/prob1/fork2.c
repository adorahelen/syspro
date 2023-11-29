#include <stdlib.h>
#include <stdio.h>

int main() 
{ 
 int pid;
 pid = fork(); // 분기 
 if (pid == 0) { 
 printf("[Child] : Hello, world pid= %d\n", getpid());
 }  // 자식 프로세스 
 else {  // 부모 프로세스 
      printf("[Parent] : Hello, world pid = %d\n", getpid());
 }
}


