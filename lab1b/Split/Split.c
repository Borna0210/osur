#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <header.h>
#include <string.h>

#define MAX_BUF 200

void Split()
{
  char path[MAX_BUF];
  chdir("Split");
  getcwd(path, MAX_BUF);
  cut(path);
  printf("%s\n", strcat(path, "/Split-program"));

  Dioklecijanova();
}
