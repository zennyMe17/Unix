#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd1[2];
    int fd2[2];
    char fixed_str[] = "Security.org";
    char input_str[100];
    pid_t p;

    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    if (pipe(fd2) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    scanf("%s", input_str);

    p = fork();

    if (p < 0) {
        fprintf(stderr, "fork Failed");
        return 1;
    } else if (p > 0) {
        char concat_str[100];
        close(fd1[0]);
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]);
        wait(NULL);
        close(fd2[1]);
        read(fd2[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        close(fd2[0]);
    } else {
        close(fd1[1]);
        char concat_str[100];
        read(fd1[0], concat_str, 100);
        int k = strlen(concat_str);
        int i;
        for (i = 0; i < strlen(fixed_str); i++)
            concat_str[k++] = fixed_str[i];
        concat_str[k] = '\0';
        close(fd1[0]);
        close(fd2[0]);
        write(fd2[1], concat_str, strlen(concat_str) + 1);
        close(fd2[1]);
        exit(0);
    }

    return 0;
}



======================================================================

#include <stdio.h>
#include <string.h>

void main() {
    char fn[10], pt[10], temp[200];
    FILE *fp;

    printf("Enter file name\n");
    scanf("%s", fn);
    printf("Enter pattern to be searched\n");
    scanf("%s", pt);

    fp = fopen(fn, "r");

    while (!feof(fp)) {
        fgets(temp, 200, fp);
        if (strstr(temp, pt))
            printf("Strings are matching and the string is %s", temp);
    }

    fclose(fp);
}

