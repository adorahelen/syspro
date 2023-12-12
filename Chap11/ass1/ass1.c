#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarmHandler(int signo);

int sec = 1;

int main()
{
    struct sigaction sa;
    sa.sa_handler = alarmHandler;
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    alarm(5);

    printf("infinite loop\n");

    while (1)
    {
        sleep(1);
        printf("%d sec\n", sec++);
    }

    printf("No running\n");

    return 0;
}

void alarmHandler(int signo)
{
    printf("wake up\n");
    exit(0);
}

