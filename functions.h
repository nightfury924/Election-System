#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

typedef struct
{
    char name[50];
    char cnic[14];
    char prof[50];
    char seckey[50];
} voter;

int authAdmin();
void hexToText(char* hexInput, char* textOutput);
void registerper();
void clearFile();
void storeRegistered(voter *data,int num);
char* textTOhex(char *text);