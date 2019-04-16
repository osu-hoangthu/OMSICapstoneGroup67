#include "printgraphics.h"

/*Function PrintTitle
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: printgraphics.h
*/
void PrintTitle() {
	PrintDividerLine(4);

	PrintSpacer(0);
	PrintSpacer(6);
	fprintf(stdout, "Welcome to Mastermind");
	PrintSpacer(0);
	
	PrintDividerLine(4);
	PrintSpacer(0);
}

/*Function PrintIntroduction
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: printgraphics.h
*/
void PrintIntroduction() {
	for (int i = 0; i < 2; i++) {
		PrintSpacer(0);
	}
	
	PrintDividerLine(5);
	//Bleh
	PrintDividerLine(5);

	return;
}

/*Function PrintDividerLine
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: printgraphics.h
*/
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

/*Function PrintSpacer
Description: <Function Description>
-Variables-
<Variable Name>: <Variable Description>
-End Variables-
Returns: <Description of expected return>
Function File Declaration: printgraphics.h
*/
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