#ifndef PROGRAMOPERATIONS_H
#define PROGRAMOPERATIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <direct.h>
#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include <cstring>
#include "game.h"
#include "player.h"
#include "printgraphics.h"
#include "settingsoperation.h"


void MainMenu(struct profileSettings*);
void PrintError(char*, int, int);
void InitializeDir();
void SetGameState();
void SetTitle();
void LoadSettings(struct profileSettings*);
void LoadProfile(struct profileSettings*);
void SaveSettings(struct profileSettings*);
void ResetBuffer(char*, char*, char*);

#endif // !PROGRAMOPERATIONS_H
