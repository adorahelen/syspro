#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main() 
{ 
 printf("real ID : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
 printf("use ID : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
 printf("real groub ID : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
 printf("use groub ID : %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
}
