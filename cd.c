#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "cd.h"

void cd(char* token, char* input, char* tokenedIP, char* cwd, char* cwd0, char* myhome, char* prev_dir){
    token = strtok(NULL, " ");
    if(token == NULL){
        strcpy(prev_dir,cwd0);
        int a = chdir(myhome);
        if(a != 0){
            perror("Couldn't change directory to HOME\n");
            return;
        }
        strcpy(cwd,"~\0");
        strcpy(cwd0,myhome);
        return;
    }
    char dest[PATH_MAX];
    strcpy(dest,token);
    token = strtok(NULL," ");
    if(token != NULL){
        perror("Expected only 1 argument with cd\n");
        return;
    }
    if(strcmp(dest,"~\0")==0){
        strcpy(prev_dir,cwd0);
        int a = chdir(myhome);
        if(a != 0){
            perror("Couldn't change directory to HOME\n");
            return;
        }
        strcpy(cwd,"~\0");
        strcpy(cwd0,myhome);
        return;
    }
    else if(strcmp(dest,"..\0")==0){
        strcpy(prev_dir,cwd0);
        if(chdir("..") != 0){
            perror("Couldn't go one level up in directory\n");
            return;
        }
        char current[PATH_MAX];
        getcwd(current,sizeof(current));
        strcpy(cwd0,current);
        strcpy(cwd,current);
        if (strncmp(cwd, myhome, strlen(myhome)) == 0) {
            strcpy(cwd,"~");
            strcat(cwd,cwd0+strlen(myhome));
        }
    }
    else if(strcmp(dest,"-\0")==0){
        char *oldpwd=malloc(PATH_MAX*sizeof(char));
        strcpy(oldpwd,prev_dir);
        printf("%s\n",oldpwd);
        int a = chdir(oldpwd);
        if(a != 0){
            perror("Couldn't change directory to previous directory\n");
        }
        strcpy(prev_dir,cwd0);
        strcpy(cwd,oldpwd);
        strcpy(cwd0,oldpwd);
        if (strncmp(cwd, myhome, strlen(myhome)) == 0) {
            strcpy(cwd,"~");
            strcat(cwd,cwd0+strlen(myhome));
        }
    }
    else{
        char home2[PATH_MAX];
        strcpy(home2,cwd0);
        if(dest[0] != '/' && cwd0[strlen(cwd0)-1] != '/') strcat(cwd0,"/");
        strcat(cwd0,dest);
        if(chdir(cwd0) != 0){
            perror("Couldn't find directory\n");
            strcpy(cwd0,home2);
            return;
        }
        strcpy(prev_dir,home2);
        if(dest[0] != '/' && cwd[strlen(cwd)-1] != '/') strcat(cwd,"/");
        strcat(cwd,dest);
        if (strncmp(cwd, myhome, strlen(myhome)) == 0) {
            strcpy(cwd,"~");
            strcat(cwd,cwd0+strlen(myhome));
        }
    }
}