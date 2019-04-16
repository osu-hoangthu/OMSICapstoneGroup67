#include "programops.h"

FILE *errorLog;

/* Function InitializeDir
Description: Redirects OS operations to the proper game folder
and checks to see if the folder exists. If it does exist then simply change to it,
otherwise create the directory with proper permissions.
-Variables-
N\A
-End Variables-
Returns: Nothing
Function File Declaration: programops.h
*/
void InitializeDir() {
	//Attempt to change to created DIR 
	if (_chdir("OTP") == -1) {
		//If the directory does not exist then create DIR
		_mkdir("OTP");
		//Move file operations to the proper DIR
		_chdir("OTP");
	}

	fopen_s(&errorLog, "Error.log", "w");
}

/*Function Menu
Description: Houses the main menu for the One Time Pad program
Allows the user to move to different aspects of the program.
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: Nothing
Function File Declaration: programops.h
*/
void Menu() {
	char c;
	
	PrintTitle();

	while (1) {
		fprintf(stdout, "Main Menu:\n1. Encryption Menu\n2. Decryption Menu\n3. Create your own Encryption\n4. Help\n5. Exit\n");
		
		c = fgetc(stdin);
		while ((getchar()) != '\n');
		
		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			EncryptionMenu();
			break;
		case '2':
			DecryptionMenu();
			break;
		case '3':
			CustomMenu();
			break;
		case '4':
			PrintTutorial();
			break;
		case '5':
			fclose(errorLog);
			return;
		default:
			PrintError("Improper Input", 1);
		}
	}
}

/*Function SetTitle
Description: Changes the console title on the application 
-Variables-
consoleTitle: Holds the name of the new console title.
-End Variables-
Returns: Nothing on success, prints error output to error.log if it fails to set console title.
Function File Declaration: programops.h
*/
void SetTitle() {
	TCHAR consoleTitle[MAX_PATH];
		
	// Build new console title string.
	StringCchPrintf(consoleTitle, MAX_PATH, TEXT("One Time Pad"));

	// Set console title to new title
	if (!SetConsoleTitle(consoleTitle))
	{
		PrintError("SetConsoleTitle failed", 20);
		return;
	}

	return;
}

/*Function PrintError
Description: <Function Description>
-Variables-
msgError: Error message
errorCode: Specific Error Code
-End Variables-
Returns: Nothing
Function File Declaration: programops.h
*/
void PrintError(char *msgError, int errorCode) {
	fprintf(errorLog, "Error: %s, Error Code: %d\n", msgError, errorCode);
}