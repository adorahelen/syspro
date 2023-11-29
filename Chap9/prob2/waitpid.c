#include <sys/types.h> 

int main ()
{ 
 int pid1, pid2, child, status;

 printf("[%d] Farents Process Start\n", getpid());
 
pid1 = fork();
 if (pid1 == 0 ) {
    printf("[%d] Child process [1] start\n", getpid());
    sleep(1);

    printf("[%d] Child process [1] End\n", getpid());
    exit(1);
 } 

pid2 = fork();
if (pid2 == 0) {
 printf("[%d] Child process #2 start\n", getpid());
 sleep(2);
 printf("[%d] Child process #2 End\n", getpid());
 exit(2);
}

child = waitpid(pid1, &status, 0);
printf("[%d] Child process #1 %d End \n", getpid(), child);
printf("\t End code %d\n", status>>8);
}
