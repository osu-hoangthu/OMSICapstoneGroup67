#include "programoperations.h"

FILE *errorLog;

/* Function InitializeDir
Description: Redirects OS operations to the proper game folder
and checks to see if the folder exists. If it does exist then simply change to it,
otherwise create the directory with proper permissions.
-Variables-
directoryName: Name of the directory
-End Variables-
Returns: Nothing
Function File Declaration: programoperations.h
*/
void InitializeDir() {
	if (_chdir("MM") == -1) {
		//Make the actual DIR with proper permissions
		_mkdir("MM");
		//Change into the Proper DIR
		_chdir("MM");
	}

	fopen_s(&errorLog, "Error.log", "w");
}

/*Function LoadSettings
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: programoperations.h
*/
void LoadSettings(struct profileSettings *profile) {
	FILE *settingsFile;
	char buffer[192], substrA[64], substrB[128];

	/* If no settings file exist create one and write default values to it */
	if ((settingsFile = fopen("setting.ini", "r")) == NULL) {
		settingsFile = fopen("setting.ini", "w");

		fprintf(settingsFile, "Name: Default\n");
		profile->playerName = "Default";
		profile->playerNameLength = 7;

		fprintf(settingsFile, "Difficulty: %d\n", NORMAL);
		profile->aiStrength = NORMAL;

		fprintf(settingsFile, "Language: English");
		profile->language = "English";
		
		fclose(settingsFile);
		return;
	}
	
	ResetBuffer(buffer, substrA, substrB);

	//Load Name into current profile
	fgets(buffer, 191, settingsFile);
	sscanf(buffer, "%s %s", substrA, substrB);
	
	substrB[strlen(substrB)] = '\0';
	
	profile->playerName = substrB;
	profile->playerNameLength = strlen(substrB);

	ResetBuffer(buffer, substrA, substrB);
	
	//Load Difficulty into current profile
	fgets(buffer, 191, settingsFile);
	sscanf(buffer, "%s %s", substrA, substrB);

	substrB[strlen(substrB)] = '\0';
	
	profile->aiStrength = (enum difficulty)(substrB[0] - 48);

	profile->language = "English";

	fclose(settingsFile);
	ResetBuffer(buffer, substrA, substrB);
	
	LoadProfile(profile);
}

void LoadProfile(struct profileSettings *profile) {
	FILE *profileFile;
	std::string fName;
	char buffer[192], substrA[64], substrB[128];
	ResetBuffer(buffer, substrA, substrB);

	fName = profile->playerName;
	fName.append(".mm");

	if ((profileFile = fopen(fName.c_str(), "r")) == NULL) {
		
		profile->currentRecord.regWin = 0;
		profile->currentRecord.regLoss = 0;
		profile->currentRecord.numberOfRegularGames = 0;
		
		profile->currentRecord.challWin = 0;
		profile->currentRecord.challLoss = 0;
		profile->currentRecord.numberOfChallengeGames = 0;
		return;
	}
	
	//Loads regular win/losses
	fgets(buffer, 191, profileFile);
	ResetBuffer(buffer, substrA, substrB);

	fgets(buffer, 191, profileFile);
	sscanf(buffer, "%s %s", substrA, substrB);
	
	fName = substrB;
	
	profile->currentRecord.regWin = std::stoi(fName);
	ResetBuffer(buffer, substrA, substrB);
	
	fgets(buffer, 191, profileFile);
	sscanf(buffer, "%s %s", substrA, substrB);

	fName = substrB;
	
	profile->currentRecord.regLoss = std::stoi(fName);
	ResetBuffer(buffer, substrA, substrB);

	//Loads Challenge win/losses
	fgets(buffer, 191, profileFile);
	ResetBuffer(buffer, substrA, substrB);

	fgets(buffer, 191, profileFile);
	sscanf(buffer, "%s %s", substrA, substrB);

	fName = substrB;
	
	profile->currentRecord.challWin = std::stoi(fName);
	ResetBuffer(buffer, substrA, substrB);

	fgets(buffer, 191, profileFile);
	sscanf(buffer, "%s %s", substrA, substrB);

	fName = substrB;
	
	profile->currentRecord.challLoss = std::stoi(fName);
	ResetBuffer(buffer, substrA, substrB);

	fclose(profileFile);

	profile->currentRecord.numberOfRegularGames = profile->currentRecord.regWin + profile->currentRecord.regLoss;
	profile->currentRecord.numberOfChallengeGames = profile->currentRecord.challWin + profile->currentRecord.challLoss;

	return;
}

/*Function SaveSettings
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: programoperations.h
*/
void SaveSettings(struct profileSettings *profile) {
	FILE *settingsFile, *profileFile;

	//Save to settings.ini
	settingsFile = fopen("setting.ini", "w");

	fprintf(settingsFile, "Name: %s\n", profile->playerName.c_str());
	fprintf(settingsFile, "Difficulty: %d\n", profile->aiStrength);
	fprintf(settingsFile, "Language: %s\n", profile->language.c_str());

	fclose(settingsFile);

	//Save to profile.mm file
	std::string buf = profile->playerName;
	buf.append(".mm");
	profileFile = fopen(buf.c_str(), "w");

	fprintf(profileFile, "Number of Games Regular\nWins: %d\nLosses: %d\n", profile->currentRecord.regWin, profile->currentRecord.regLoss);
	fprintf(profileFile, "Number of Games Challenges\nWins: %d\nLosses: %d\n", profile->currentRecord.challWin, profile->currentRecord.challLoss);
	fprintf(profileFile, "Name: %s\n", profile->playerName.c_str());
	fprintf(profileFile, "Difficulty: %d\n", profile->aiStrength);
	fprintf(profileFile, "Language: %s", profile->language.c_str());

	fclose(profileFile);

	return;
}

/*Function SetGameState
Description: Setups the random seeding for the program, sets up the console title, and prints out the title screen.
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: Nothing
Function File Declaration: programoperations.h
*/
void SetGameState() {
	srand(time(NULL));

	SetTitle();
	PrintTitle();

	return;
}

/*Function SetTitle
Description: Changes the console title on the application
-Variables-
consoleTitle: Holds the name of the new console title.
-End Variables-
Returns: Nothing on success, prints error output to error.log if it fails to set console title.
Function File Declaration: programoperations.h
*/
void SetTitle() {
	TCHAR consoleTitle[MAX_PATH];

	// Build new console title string.
	StringCchPrintf(consoleTitle, MAX_PATH, TEXT("Mastermind"));

	// Set console title to new title
	if (!SetConsoleTitle(consoleTitle))
	{
		PrintError("SetConsoleTitle failed", 20, 0);
		return;
	}

	return;
}

/*Function MainMenu
Description: Houses the main menu for the Mastermind program
Allows the user to move to different aspects of the program.
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: Nothing
Function File Declaration: programops.h
*/
void MainMenu(struct profileSettings *profile) {
	char c;

	while (1) {
		fprintf(stdout, "Main Menu:\n1. Start a new game\n2. Start a challenge game\n3. Records\n4. Settings\n5. Exit\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');

		PrintSpacer(0);
		PrintDividerLine(5);

		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			GameStart(profile);
			break;
		case '2':
			ChallengeGameStart(profile);
			break;
		case '3':
			PlayerRecords(profile);
			break;
		case '4':
			SettingsMenu(profile);
			break;
		case '5':
			fclose(errorLog);
			return;
		default:
			PrintError("Improper Input", 1, 0);
		}
	}
}

/*Function PrintError
Description: <Function Description>
-Variables-
errMsg: Error message
errorCode: Specific Error Code
exitCode: Exit the system if required
-End Variables-
Returns: Nothing
Function File Declaration: fileops.h
*/
void PrintError(char *errMsg, int errorCode, int exitCode) {
	fprintf(errorLog, "Error: %s, Error Code: %d\n", errMsg, errorCode);
	if (exitCode > 0) {
		exit(exitCode);
	}
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