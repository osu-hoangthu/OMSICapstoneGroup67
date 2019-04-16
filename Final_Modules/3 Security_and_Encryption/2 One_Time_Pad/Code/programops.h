#ifndef PROGRAMOPS_H
#define PROGRAMOPS_H
#include <stdio.h>
#include <direct.h>
#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include "custom.h"
#include "encryption.h"
#include "decryption.h"
#include "printgraphics.h"

void InitializeDir();
void Menu();
void SetTitle();
void PrintError(char*, int);

#endif // !PROGRAMOPS_H