#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd1 = open("pipe1", O_WRONLY);
    int fd2 = open("pipe2", O_RDONLY);

    char str[256];

    while(1) {
        printf("input: ");
        int size = sizeof(str);
        fgets(str, size, stdin);
        write(fd1, str, size);
        read(fd2, str, size);
        printf("output: %s\n", str);
    }

    close(fd1);
    close(fd2);

    return 0;
}
