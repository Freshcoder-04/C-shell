#ifndef HISTORY_H
#define HISTORY_H

void writeArrayToFile(const char* filename, char** arr, int s,int e);
int readHistoryFromFile(const char* filename, char** arr, int* s, int* e);
void printHistory(char** arr, int s, int e);

#endif