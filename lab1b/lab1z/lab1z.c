#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <header.h>

int counter = 0;
void lab1z(){
    counter++;
    printf("lab1z pokrenut %d puta\n", counter);
}
