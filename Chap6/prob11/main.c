#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void printStat(char *, char *, char *);

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *d;
    char path[BUFSIZ + 1];

    int option_l = 0;
    int option_i = 0;
    int option_s = 0;

    // Parse command line options
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            option_l = 1;
        } else if (strcmp(argv[i], "-i") == 0) {
            option_i = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            option_s = 1;
        }
    }

    if ((dp = opendir(".")) == NULL) {
        perror(".");
        exit(EXIT_FAILURE);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "./%s", d->d_name);

        if (option_l) {
            printStat(path, d->d_name, "l");
        } else if (option_i) {
            printStat(path, d->d_name, "i");
        } else if (option_s) {
            printStat(path, d->d_name, "s");
        } else {
            printf("%s\n", d->d_name);
        }
    }

    closedir(dp);
    exit(EXIT_SUCCESS);
}

void printStat(char *pathname, char *file, char *option) {
    struct stat st;

    if (lstat(pathname, &st) < 0) {
        perror(pathname);
        return;
    }

    if (strcmp(option, "l") == 0) {
        // Print detailed information
        printf("%s %5ld %s\n", file, st.st_size, ctime(&st.st_mtime));
    } else if (strcmp(option, "i") == 0) {
        // Print i-node number
        printf("%s %lu\n", file, st.st_ino);
    } else if (strcmp(option, "s") == 0) {
        // Print file size
        printf("%s %ld\n", file, st.st_blocks);
    }
}

