#include "printgraphics.h"

/*Function PrintTitle
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: <Header Name>
*/
void PrintTitle() {
	PrintDividerLine(4);

	PrintSpacer(5);
	fprintf(stdout, "Welcome to the One Time Pad Software.");
	PrintSpacer(0);
	
	PrintDividerLine(4);
}

void PrintTutorial() {
	for (int i = 0; i < 2; i++) {
		PrintSpacer(0);
	}
	
	PrintDividerLine(5);
	fprintf(stdout, "The One Time Pad will help encode and decode information that is fed to it.\n");
	fprintf(stdout, "Option 1: Choose a cipher to encrypt your message and then generate the encrypted message.\n");
	fprintf(stdout, "Option 2: Choose a cipher to decrypt an encrypted message that was generated earlier\n");
	fprintf(stdout, "Option 3: Using one of the ciphers, create your own encryption and decryption method.\n");
	PrintDividerLine(5);

	return;
}

void PrintDividerLine(int lineOption) {
	switch (lineOption)
	{
		case 1:
			fprintf(stdout, "___________________________________________________________");
			break;
		case 2:
			fprintf(stdout, "-----------------------------------------------------------");
			break;
		case 3:
			fprintf(stdout, "|");
			break;
		case 4:
			fprintf(stdout, "_______________________________________________________________________________________________________________________\n");
			break;
		case 5:
			fprintf(stdout, "-----------------------------------------------------------------------------------------------------------------------\n");
			break;
		default:
			break;
	}
}

void PrintSpacer(int spacerOption) {
	switch (spacerOption)
	{
		case 0:
			fprintf(stdout, "\n");
			break;
		case 1:
			fprintf(stdout, "	");
			break;
		case 2:
			fprintf(stdout, "		");
			break;
		case 3:
			fprintf(stdout, "			");
			break;
		case 4:
			fprintf(stdout, "				");
			break;
		case 5:
			fprintf(stdout, "					");
			break;
		case 6:
			fprintf(stdout, "						");
			break;
		default:
			break;
	}
}