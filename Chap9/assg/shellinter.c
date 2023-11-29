#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAXCMDLINE 100

int execute_command(const char *cmdstring);

int main() {
    char cmd[MAXCMDLINE] = {0};
    char *token;
    int status;

    while(1) {
        printf("[shell] ");
        fgets(cmd, MAXCMDLINE, stdin);
        if (!strcmp(cmd, "exit\n")) {
            break;
        }
        // Tokenize input based on semicolon
        token = strtok(cmd, ";");
        while(token != NULL) {
            // Execute each command sequentially
            if((status = execute_command(token)) < 0)
                perror("Command execution error");
            token = strtok(NULL, ";");
        }
    }

    printf("Shell exit\n");
    return 0;
}

int execute_command(const char *cmdstring) {
    printf("[shell] Executing command: %s", cmdstring);

    // Check for background execution
    int background = 0;
    if (cmdstring[strlen(cmdstring) - 2] == '&') {
        background = 1;
        cmdstring[strlen(cmdstring) - 2] == '\0';
    }

    int pid, status, child;

    if (cmdstring == NULL || strlen(cmdstring) == 0) {
        return 0;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork error");
        return -1;
    }

    if (pid == 0) {
        // Child process
        printf("[shell] Child process start\n");

        // Check for input and output redirection
        char *input_file = strchr(cmdstring, '<');
        char *output_file = strchr(cmdstring, '>');

        if (input_file != NULL) {
            *input_file = '\0';
            freopen(input_file + 1, "r", stdin);
        }

        if (output_file != NULL) {
            *output_file = '\0';
            freopen(output_file + 1, "w", stdout);
        }

        // Execute the command using the shell
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        perror("Command execution error");
        _exit(127);  // Command execution error
    }

    // Parent process
    if (!background) {
        // Wait for the child process to complete if not in the background
        do {
            if ((child = waitpid(pid, &status, 0)) == -1) {
                if (errno != EINTR)
                    return -1;
            } else {
                printf("[shell] Child process end %d\n", child);
                return status;
            }
        } while(1);
    } else {
        // Print background process ID
        printf("[shell] Background process ID: %d\n", pid);
    }

    return 0;
}

