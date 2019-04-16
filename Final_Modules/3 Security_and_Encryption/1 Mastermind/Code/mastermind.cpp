#include "programoperations.h"
#include "player.h"

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

int main() {
	//Initialize the current profile
	struct profileSettings *currentProfile;
	currentProfile = new struct profileSettings();

	//initialize directory
	InitializeDir();

	//Load Settings
	LoadSettings(currentProfile);
	
	//initialize game state
	SetGameState();
	
	//initialize Menu
	MainMenu(currentProfile);

	//Save Settings
	SaveSettings(currentProfile);
	
	delete currentProfile;

	return 0;
}
