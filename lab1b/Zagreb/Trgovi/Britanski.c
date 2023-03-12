#include <header.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX_BUF 200

void Britanski(){
    char path[MAX_BUF];
    chdir("Trgovi");
    getcwd(path, MAX_BUF);
    cut(path);
    printf("%s\n", strcat(path,"/Britanski-program"));
      
}

