#include <header.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX_BUF 200

void Zagreb()
{
    char path[MAX_BUF];
    
    chdir("Zagreb");
    getcwd(path, MAX_BUF);
    cut(path);
    printf("%s\n", strcat(path,"/Zagreb-program"));
    lab1z();


    Britanski();
    Cvjetni();
}

