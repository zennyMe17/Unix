#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int f1, f2;
    char buf[50];
    ssize_t n;

    if (((f1 = open(argv[1], O_RDONLY)) == -1) || ((f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700)) == -1)) {
        perror("File open error");
        exit(1);
    }

    while ((n = read(f1, buf, sizeof(buf))) > 0) {
        if (write(f2, buf, n) != n) {
            perror("Problem in writing");
            exit(3);
        }
    }

    if (n == -1) {
        perror("Problem in reading");
        exit(2);
    }

    close(f1);
    close(f2);
    exit(0);
}





#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    char dirname[100];
    DIR *p;
    struct dirent *d;

    printf("Enter directory name:\n");
    scanf("%s", dirname);

    p = opendir(dirname);
    if (p == NULL) {
        perror("Cannot open directory");
        exit(EXIT_FAILURE);
    }

    while ((d = readdir(p)) != NULL) {
        printf("%s\n", d->d_name);
    }

    closedir(p);

    return 0;
}


