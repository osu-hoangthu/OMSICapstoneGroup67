#include "fileops.h"

FILE errorLog*

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
	fprintf(errorLog, "Error: %s, Error Code: %d\n", msgError, errorCode);
	if (exitCode > 0) {
		exit(exitCode);
	}
}