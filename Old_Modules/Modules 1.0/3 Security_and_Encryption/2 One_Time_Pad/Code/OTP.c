#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileops.h"

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
	srand(time(NULL));
	
	InitializeDir();
	Menu();

	return 0;
}