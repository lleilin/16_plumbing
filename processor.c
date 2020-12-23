#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

int main() {
  mkfifo("pipe1", 0644);
  mkfifo("pipe2", 0644);

  int fd1 = open("pipe1", O_RDONLY);
  int fd2 = open("pipe2", O_WRONLY);

  char in[256];
  char out[256];

  while (1) {
      int chr;
      read(fd1, in, sizeof(in));

      int i;
      while (in[i]) {
        chr = in[i];
        out[i] = toupper(chr);
        i++;
      }

      write(fd2, out, sizeof(out));
  }

  close (fd1);
  close (fd2);

  return 0;
}
