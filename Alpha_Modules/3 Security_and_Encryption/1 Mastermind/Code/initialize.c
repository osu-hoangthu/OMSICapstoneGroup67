#include "initialize.h"
/* Function InitializeDir
Description: Redirects OS operations to the proper game folder
and checks to see if the folder exists. If it does exist then simply change to it, 
otherwise create the directory with proper permissions.
-Variables-
directoryName: Name of the directory
-End Variables-
Returns: Nothing
Function File Declaration: initialize.h
*/
void InitializeDir() {
	if (chdir("MM") == -1) {
		//Create DIR name
		char directoryName[3] = "MM";
		//Make the actual DIR with proper permissions
		mkdir(directoryName, 0755);
		//Change into the Proper DIR
		chdir(directoryName);
	}
}

/*Function LoadSettings
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: initialize.h
*/
void LoadSettings() {
	FILE *settingsFile;
	//char *buffer, *substrA, *substrB;
	char buffer[192], substrA[64], substrB[128];

	/* If no settings file exist create one and write default values to it */
	if ((settingsFile = fopen("setting.mm", "r")) == NULL) {
		settingsFile = fopen("setting.mm", "w");
		fprintf(settingsFile, "Name: Default\n");
		//strcpy(currentProfile->playerName, "Default");
		//currentProfile->playerNameLength = 7
		fprintf(settingsFile, "Difficulty: %d\n", NORMAL);
		//currentProfile->aiStrength = NORMAL
		fprintf(settingsFile, "Language: English");
		//currentProfile->language = ENGLISH;
		fclose(settingsFile);
		return;
	}

	//buffer = (char*)malloc(sizeof(char) * 192);
	//substrA = (char*)malloc(sizeof(char) * 64);
	//substrB = (char*)malloc(sizeof(char) * 128);
	ResetBuffer(buffer, substrA, substrB);

	//Load Name and current Difficulty into current profile
	fgets(buffer, 191, settingsFile);
	sscanf(buffer, "%s %s", substrA, substrB);
	//substrB[strlen(substrB)] = '\0';
	//strcpy(currentProfile->playerName, substrB)
	//currentProfile->playerNameLength = strlen(substrB)
	ResetBuffer(buffer, substrA, substrB);
	fgets(buffer, 191, settingsFile);
	sscanf(buffer, "%s %s", substrA, substrB);
	//substrB[strlen(substrB)] = '\0';
	//currentProfile->aiStrength = substrB[0] - 48;

	fclose(settingsFile);
	ResetBuffer(buffer, substrA, substrB);
	//free(buffer);
	//free(substrA);
	//free(substrB);

}

/*Function ResetBuffer
Description: Reset all the char arrays given, mainly used as a helper function.
-Variables-
N/A
-End Variables-
Returns: buffer and substrs written with null chars
Function File Declaration: initialize.h
*/
void ResetBuffer(char *buffer, char *substrA, char *substrB) {
	memset(buffer, '\0', sizeof(buffer));
	memset(substrA, '\0', sizeof(substrA));
	memset(substrB, '\0', sizeof(substrB));
}