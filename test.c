#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>



int main(){
    char* x = malloc(PATH_MAX*sizeof(char));

    x = "Shravan";
    printf("%s\n",x+strlen(x)-1);
}