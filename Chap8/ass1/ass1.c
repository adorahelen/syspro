#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void print_environment_value(char *env_name) {
    char *env_value = getenv(env_name);
    if (env_value) {
        printf("%s: %s\n", env_name, env_value);
    } else {
        printf("%s: No Enviroment \n", env_name);
    }
}

void print_user_ids() {
    printf("Real user ID: %d\n", getuid());
    printf("Now user ID: %d\n", geteuid());
}

void print_group_ids() {
    printf("Real Group ID: %d\n", getgid());
    printf("Now Group ID: %d\n", getegid());
}

void print_process_ids() {
    printf("Process ID: %d\n", getpid());
    printf("PProcess ID: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "e:ugip")) != -1) {
        switch (opt) {
            case 'e':
                print_environment_value(optarg);
                break;
            case 'u':
                print_user_ids();
                break;
            case 'g':
                print_group_ids();
                break;
            case 'i':
                print_process_ids();
                break;
            case 'p':
                print_process_ids();
                break;
            default:
                fprintf(stderr, "UsingMethod: %s [-e] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}

