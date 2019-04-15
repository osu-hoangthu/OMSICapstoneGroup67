#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>


enum boardpegs
{
	RED,
	GREEN,
	TEAL,
	YELLOW,
	WHITE,
	BLACK
};

enum coderesponse
{
	INCORRECT,
	PERFECT,
	CORRECTCOLOR
};

void GameStart();
void PrintNameOfBoardPeg(int, FILE*);
int GetBoardPeg(char);

#endif // !GAME_H