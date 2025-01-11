#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "History.h"

#define hist 21

void writeArrayToFile(const char* filename, char** arr, int s,int e) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }
    for (int i = s; i != e; i=(i+1)%hist) {
        fprintf(file, "%s\n", arr[i]);
    }
    fclose(file);
}

int readHistoryFromFile(const char* filename, char** arr, int* s, int* e) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *s = 0;
        *e = 0;
        return 0;
    }

    char line[1000];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(arr[*e], line);
        *e = (*e + 1) % hist;
        if (*e == *s) {
            *s = (*s + 1) % hist;
        }
        count++;
    }
    fclose(file);
    return count;
}

void printHistory(char** arr, int s, int e) {
    int count = 0;
    int size = (e >= s) ? (e - s) : (hist - s + e);
    int start = (size > 10) ? (e - 10 + hist) % hist : s;
    for (int i = start; i != e && count < 10; i = (i + 1) % hist) {
        printf("%s\n", arr[i]);
        count++;
    }
}