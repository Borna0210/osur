#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <header.h>

#define MAX_BUF 200

void Dioklecijanova(){
    char path[MAX_BUF];
    chdir("Ulice");
    getcwd(path, MAX_BUF);
    cut(path);
    printf("%s\n", strcat(path,"/Dioklecijanova-program"));
    lab1z();
    chdir("../..");
      
}