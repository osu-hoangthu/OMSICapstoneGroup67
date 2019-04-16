#include "settingsoperation.h"

/*Function SettingsMenu
Description: Houses the settings menu for the Mastermind program.
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: Nothing
Function File Declaration: settingsoperation.h
*/
void SettingsMenu(struct profileSettings *profile) {
	char c;
	
	while (1) {
		fprintf(stdout, "\nCurrent Settings:\nName: %s\nDifficulty: Normal\nCurrent Language: %s\n", profile->playerName.c_str(), profile->language.c_str());
		PrintDividerLine(4);

		fprintf(stdout, "Settings Menu:\n1. Change Profile\n2. Change Name\n3. Change Difficulty\n4. Change Language\n5. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');
		PrintSpacer(0);
		PrintDividerLine(5);

		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			fprintf(stdout, "Minor problem with file manipulation, will be changed in 1.1.\n");
			//ChangeProfile();
			break;
		case '2':
			ChangeName(profile);
			break;
		case '3':
			ChangeDifficulty(profile);
			break;
		case '4':
			fprintf(stdout, "Will be implemented when we have a proper translation for other languages.\n");
			//ChangeLanguage();
			break;
		case '5':
			return;
		default:
			PrintError("Improper Input", 1, 0);
		}
	}
}

void ChangeProfile() {
	char c;
	while (1) {
		//Pull profiles available
		fprintf(stdout, "\nProfiles Currently available:\n");
		PrintDividerLine(4);

		fprintf(stdout, "Profiles Menu:\n1. Add new profile\n2. Delete profile\n3. Switch to another profile\n4. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');
		PrintSpacer(0);
		PrintDividerLine(5);

		//Switch to valid action, otherwise, print error to log file and reprompt user.
		switch (c) {
		case '1':
			//AddProfile();
			break;
		case '2':
			//DeleteProfile();
			break;
		case '3':
			//SwitchProfile();
			break;
		case '4':
			return;
		default:
			PrintError("Improper Input", 1, 0);
		}
	}
	return;
}

void ChangeName(struct profileSettings *profile) {
	PrintSpacer(0);
	char buffer[32];
	memset(buffer, '\0', sizeof(buffer));

	fprintf(stdout, "Enter your new name: ");
	
	fgets(buffer, 31, stdin);
	buffer[strlen(buffer)-1] = '\0';

	if (strlen(buffer) != 0) {
		profile->playerName = buffer;
		memset(buffer, '\0', sizeof(buffer));
		return;
	}
	
	fprintf(stdout, "No name entered, keeping last name.");
	memset(buffer, '\0', sizeof(buffer));
	return;
}

void ChangeDifficulty(struct profileSettings *profile) {
	char c;
	while (1) {
		fprintf(stdout, "Difficulties available:\n1. Easy\n2. Normal\n3. Hard\n4. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');
		PrintSpacer(0);
		PrintDividerLine(5);

		//Switch to valid action, otherwise, print error to log file and reprompt user.
		switch (c) {
		case '1':
			profile->aiStrength = EASY;
			fprintf(stdout, "Difficulty changed to Easy");
			return;
		case '2':
			profile->aiStrength = NORMAL;
			fprintf(stdout, "Difficulty changed to Normal");
			return;
		case '3':
			profile->aiStrength = HARD;
			fprintf(stdout, "Difficulty changed to Hard");
			return;
		case '4':
			return;
		default:
			PrintError("Improper Input", 1, 0);
		}
	}
	return;
}

void PlayerRecords(struct profileSettings *profile) {
	PrintSpacer(0);
	
	fprintf(stdout, "Hello %s!\n\nCurrent Records:\nNormal wins: %d, Normal losses: %d\nChallenge wins: %d, Challenge losses: %d\nPress enter to return to Main Menu.\n", profile->playerName.c_str(), profile->currentRecord.regWin, profile->currentRecord.regLoss, profile->currentRecord.challWin, profile->currentRecord.challLoss);

	fgetc(stdin);
	PrintDividerLine(5);
	PrintSpacer(0);
}