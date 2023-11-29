#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <setjmp.h>

#define MAXCMDLINE 100

int mysystem (const char *cmdstring);

int main() {
    char cmd[MAXCMDLINE] = {0};
    char *token;
    int status;

    while(1) {
        printf("input cmd : ");
        fgets(cmd, MAXCMDLINE, stdin);
        if (!strcmp(cmd, "exit\n")) {
            break;
        }
        token = strtok(cmd, ";");
        while(token != NULL) {
            if((status = mysystem(token) < 0))
                perror("system() err");
            token = strtok(NULL, ";");
        }
    }
    printf("Parent process end");
    return 0;
}


int mysystem (const char *cmdstring)
{
    printf("[%d] Parent process start\n", getpid());
    int pid, status, child;

    if (cmdstring == NULL) /* 명령어가 NULL인 경우 */
        return 1;

    pid = fork();
    if (pid == -1) /* 프로세스 생성 실패 */
        return -1;


    if (pid == 0) {
        printf("[%d] child process start\n", getpid());
        execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
        _exit(127); /* 명령어 실행 오류 */
    }
    do {
        if ((child = waitpid(pid, &status, 0)) == -1) {
            if (errno != EINTR) /* waitpid()로부터 EINTR 오류 외 */
                return -1;
        }
        else
            printf("[%d] child process end %d\n", getpid(), child);
            return status;
    }
    while(1);
}
