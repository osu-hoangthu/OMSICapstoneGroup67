#ifndef FILEOPS_H
#define FILEOPS_H
#include <stdio.h>
#include <direct.h>
#include "encryption.h"
#include "decryption.h"

void InitializeDir();
void Menu();
void PrintError(char*, int);

//FILE *errorLog;

#endif // !FILEOPS_H