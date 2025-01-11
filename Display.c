#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "Display.h"

void getCredentials(char *username,char *hostname, char *cwd, char* cwd0,char* myhome){
    char *Uname = getenv("USER");
    if (Uname == NULL) {
        perror("username");
    }
    strcpy(username,Uname);

    char HostName[1024];
    if (gethostname(HostName, sizeof(HostName)) != 0) {
        perror("gethostname");
    }
    char *breakp = strchr(HostName, '.');
    if (breakp != NULL) {
        *breakp = '\0';
    }
    strcpy(hostname,HostName);

    char home[PATH_MAX];
    getcwd(home,sizeof(home));
    strcpy(myhome,home);
    strcpy(cwd, "~\0");
    strcpy(cwd0, home);
    chdir(home);
}

void display(char *username,char *hostname, char *cwd){
    printf("<%s@%s:%s> ", username, hostname, cwd);
}