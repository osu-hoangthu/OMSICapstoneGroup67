#include "encryption.h"

void Encrypt() {
	FILE *message, *key;
	char buffer[256], fileName[5], x;
	int  a, b, c, i;

	memset(buffer, '\0', sizeof(buffer));
	sprintf(fileName, "%d", _getpid());

	///TODO: Implement selection menu for different methods of encryption. Also enable the ability to use your own keygen

	//Receive user input
	fprintf(stdout, "Enter sentence to encrypt:\n");
	fgets(buffer, 255, stdin);

	//Call keygen to make a OTP key
	RandomKeygen((strlen(buffer) - 1));

	//Open files necessary for encryption
	fopen_s(&message, "encryptedMessage.txt", "w");
	fopen_s(&key, fileName, "r");

	fprintf(stdout, "Encrypted message: ");

	//Encrypt Sentence and place in a message file
	for (i = 0; i < strlen(buffer) - 1; i++) {
		a = buffer[i];
		b = fgetc(key);

		c = a + b - 32;

		//loop if over 126
		if (c > 126) {
			c -= 95;
		}

		x = c;
		fprintf(stdout, "%c", x);
		fprintf(message, "%c", x);
	}

	//Close the files used
	fclose(message);
	fclose(key);

	fprintf(stdout, "\nEncrypt Success\n");
	return;
}