#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <header.h>
#define MAX_BUF 200

void Cvjetni(){
    char path[MAX_BUF];
    getcwd(path, MAX_BUF);
    cut(path);
    printf("%s\n", strcat(path,"/Cvjetni-program"));
      
}


