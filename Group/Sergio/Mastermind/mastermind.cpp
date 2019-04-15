#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "initialize.h"
#include "game.h"

//Function Comment Template
/*Function <name>
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: <Header Name>
*/

//Struct Comment Template
/*Struct <name>
Description: <Struct Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Struct File Declaration: <Header Name>
*/
void SetGameState();

int main() {
	//initialize directory
	InitializeDir();
	//Load Settings
	LoadSettings();
	//initialize game state
	SetGameState();
	//initialize game
	GameStart();
	//record data
	//RecordData();
	//repeat/exit
	fprintf(stdout, "Press Enter to exit...");
	getc(stdin);
	return 0;
}


void SetGameState() {
	srand(time(NULL));
	return;
}
