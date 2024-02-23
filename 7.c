#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct dirent *dir;
    struct stat mystat;
    DIR *dp;

    dp = opendir(".");
    if (dp) {
        while (dir = readdir(dp)) {
            stat(dir->d_name, &mystat);

            // Print file details
            printf("%ld\t%d\t%d\t%ld\t%ld\t%ld\t%lu\t%s\t%s\t",
                   mystat.st_ino, mystat.st_uid, mystat.st_gid,
                   mystat.st_blksize, mystat.st_blocks, mystat.st_size,
                   mystat.st_nlink, ctime(&mystat.st_atime), dir->d_name);

            printf("\nFile Permissions User\n");

            // Print user permissions
            printf((mystat.st_mode & S_IRUSR) ? "r" : ".");
            printf((mystat.st_mode & S_IWUSR) ? "w" : ".");
            printf((mystat.st_mode & S_IXUSR) ? "x" : ".");
            printf("\n");

            printf("\nFile Permissions Group\n");

            // Print group permissions
            printf((mystat.st_mode & S_IRGRP) ? "r" : ".");
            printf((mystat.st_mode & S_IWGRP) ? "w" : ".");
            printf((mystat.st_mode & S_IXGRP) ? "x" : ".");
            printf("\n");

            printf("\nFile Permissions Other\n");

            // Print other permissions
            printf((mystat.st_mode & S_IROTH) ? "r" : ".");
            printf((mystat.st_mode & S_IWOTH) ? "w" : ".");
            printf((mystat.st_mode & S_IXOTH) ? "x" : ".");
            printf("\n");
        }

       
    } 

    return 0;
}




===========================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main()
{

	DIR *dp;
	struct dirent *dir;
	
	int fd,n;
	dp=opendir(".");
	
	if (dp)
	{
		while((dir=readdir(dp))!=NULL)
		{
			fd=open(dir->d_name, O_RDWR,0777);
			n=lseek(fd,0,SEEK_END);
			if(!n)
			{
				unlink(dir->d_name);

			}
		}
	}
}
