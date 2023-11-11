#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <utime.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "How to use : touch file1 \n");
        exit(-1);
    }
    utime(argv[1], NULL);
}
