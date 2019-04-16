#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>
#include "programoperations.h"
#include "player.h"


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

void GameStart(struct profileSettings*);
void ChallengeGameStart(struct profileSettings*);
void PrintNameOfBoardPeg(int, FILE*);
int GetBoardPeg(char);

#endif // !GAME_H