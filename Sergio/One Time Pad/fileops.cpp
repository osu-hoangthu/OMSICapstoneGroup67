#include "fileops.h"

FILE *errorLog;

/* Function InitializeDir
Description: Redirects OS operations to the proper game folder
and checks to see if the folder exists. If it does exist then simply change to it,
otherwise create the directory with proper permissions.
-Variables-
N\A
-End Variables-
Returns: Nothing
Function File Declaration: fileops.h
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
Function File Declaration: fileops.h
*/
void Menu() {
	char c;
	
	while (1) {
		fprintf(stdout, "Menu:\n1. Encrypt and Generate Key\n2. Decrypt with Key\n3. Exit\n");
		
		c = fgetc(stdin);
		while ((getchar()) != '\n');
		
		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			Encrypt();
			break;
		case '2':
			Decrypt();
			break;
		case '3':
			fclose(errorLog);
			return;
		default:
			PrintError("Improper Input", 1);
		}
	}
}

/*Function PrintError
Description: <Function Description>
-Variables-
msgError: Error message
errorCode: Specific Error Code
-End Variables-
Returns: Nothing
Function File Declaration: fileops.h
*/
void PrintError(char *msgError, int errorCode) {
	fprintf(errorLog, "Error: %s, Error Code: %d\n", msgError, errorCode);
}