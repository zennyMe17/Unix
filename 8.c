

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int fd1=0,fd2=0;
char buf[50];
if((fd1=open("t12.txt", O_RDWR,0))<0)
printf("file open error");

fd2=dup(fd1);

read(fd1, buf,12);
lseek(fd2, 0L, SEEK_END);
write(fd2, buf, 12);

return 0;
}


#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *d;
    struct dirent *dir;

    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    
    return 0;
}
