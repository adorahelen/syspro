#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include "db.dat.h"

int main (int argc, char *argv[])
{
 
  int fd, id, n;
 char c;
 struct booklist record;
 if (argc < 2) {
 fprintf(stderr, "How to use : %s file \n", argv[0]);
 exit(1);
}
if ((fd = open(argv[1], O_RDONLY)) == -1) {
  perror(argv[1]);
  exit(2);
}

do { 
printf ("\ 0: list of all books, 1: list of available books )");
if (scanf("%d", &id) == 1 ) {
  lseek(fd, (id-START_ID)* sizeof(record), SEEK_SET);
if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id !=0))
printf("id%d\t bookname%s\t author%s\t year%d\t numofborrow%d\t borrow%d\t", record.id, record.bookname, record.author, record.year, record.numofborrow, record.borrow);
 else printf("Record %d Null\n", id);
} else printf("Input Error");
printf("Continue?(Y/N)");
scanf("%c", &c);
} while (c =='Y');
close(fd);
exit(0);
}
