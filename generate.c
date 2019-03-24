
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int x = atoi(argv[1]);
  x *= (x < 0) ? (-1) : (1);
  char *hold;
  int len;
  int fd;

  fd = open("./del", O_RDONLY);
  while (x)
    {
      hold = itoa(rand());
      len = strlen(hold);
      write(fd, hold, len);
      write(fd, " ", 1);
      x--;
    }
  return (0);
}
