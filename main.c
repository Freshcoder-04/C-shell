#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "History.h"
#include "Echo.h"
#include "cd.h"
#include "pwd.h"
#include "Display.h"

#define hist 21

int main() {
    char* history[hist];
    for (int i = 0; i < hist; i++) {
        history[i] = (char *)malloc(1000 * sizeof(char));
    }
    int s = 0;
    int e = 0;
    char currdir[1000];
    getcwd(currdir,sizeof(currdir));
    char tempstr[1000];
    strcpy(tempstr,currdir);
    strcat(tempstr,"/history.txt");
    char * filename=tempstr;

    readHistoryFromFile(filename, history, &s, &e);

    char* myhome=(char*)malloc(PATH_MAX*sizeof(char));
    char* cwd0=(char*)malloc(PATH_MAX*sizeof(char));
    char* cwd=(char*)malloc(PATH_MAX*sizeof(char));
    char* prev_dir=(char*)malloc(PATH_MAX*sizeof(char));
    char username[1024];
    char hostname[1024];
    getCredentials(username,hostname,cwd,cwd0,myhome);
    display(username,hostname,cwd);

    char input[10000];
    char tokenedIP[10000];
    fgets(input, sizeof(input), stdin);
    char *breakp = strchr(input, '\n');
    *breakp = '\0';
    strcpy(tokenedIP,input);
    char *token = strtok(tokenedIP, " ");
    strcpy(history[e],input); 
    e = (e+1)%hist;
    if(s == e) s = (s+1)%hist;
    writeArrayToFile(filename,history,s,e);

    while(strcmp(token, "exit\0") != 0){
        if(strcmp(token,"echo") == 0){
            echo(token, input);
        }
        else if(strcmp(token, "pwd\0") == 0){
            pwd(cwd0);
        }
        else if(strcmp(token, "cd") == 0){
            if(strcmp(input,"cd\0") == 0){
                strcpy(input,"cd ~\0");
                strcpy(tokenedIP,input);
                token = strtok(tokenedIP, " ");
            }
            cd(token,input,tokenedIP,cwd,cwd0,myhome,prev_dir);
        }
        else if(strcmp(token, "history") == 0){
            printHistory(history,s,e);
        }
        else{
            printf("Invalid command\n");
        }
        display(username,hostname,cwd);
        fgets(input, sizeof(input), stdin);
        char *breakp = strchr(input, '\n');
        *breakp = '\0';
        strcpy(tokenedIP,input);
        token = strtok(tokenedIP, " ");
        if(s != e){
            if(strcmp(history[(e-1+20)%20],input) != 0){
                strcpy(history[e],input); e = (e+1)%hist;
                if(e==s) s = (s+1) % hist;
            }
        }
        writeArrayToFile(filename,history,s,e);
    }
}