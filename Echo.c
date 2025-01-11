#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "Echo.h"

void echo(char* token, char* input){
    token = strtok(NULL," ");
    if(token[0] == '\"'){
        char* echostr = "echo";
        int i = 0;
        int j = 0;
        while(input[i] == ' ') {
            i++;
        }
        while(input[i] == echostr[j] && j < 4){
            i++;
            j++;
        }
        while(input[i] == ' ') {
            i++;
        }
        char printing[100];
        printing[0] = '\"';
        int l = 1;
        i++;
        while(input[i] != '\"' && input[i] != '\0') printing[l++] = input[i++];
        if(input[i] == '\0') {
            perror("dequote error\n");
            return;
        }
        if(input[i] == '\"') {
            printing[l++] = '\"';
            i++;
        }
        printing[l] = '\0';
        printf("%s\n",printing);
    }
    else{
        while(token != NULL){
            printf("%s ",token);
            token = strtok(NULL," ");
        }
        printf("\n");
    }
}