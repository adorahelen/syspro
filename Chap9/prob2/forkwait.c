#include <sys/types.h>

int main()
{
 int pid, child, status;
 printf("[%d] Parents process start\n", getpid());
 
pid = fork();
 if (pid == 0) { 
    printf("[%d] Child process start\n", getpid());
     exit(1);
}

child = wait(&status);
printf("[%d]child process %d end \n", getpid(), child);
printf("\t End Code %d\n", status >> 8);

}    
