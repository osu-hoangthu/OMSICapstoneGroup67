#include "decryption.h"

void Decrypt() {
	FILE *message, *key, *dMessage;
	fpos_t pos;
	char fileName[16], x;
	int  a, b, c, i, keyLen = 0;

	//Attempt to load message file
	///TODO: Recover from error and reset this interaction
	if ((message = fopen("encryptedMessage.txt", "r")) == NULL) {
		fprintf(stderr, "Issue opening file\n");
		exit(2);
	}

	//Get user input
	///TODO: Allow the user to manually select a file instead of inputting it
	printf("What key should be used to decrypt the message: ");
	fgets(fileName, 15, stdin);

	fileName[(strlen(fileName) - 1)] = '\0';

	//Attempt to load message file
	///TODO: Recover from error and reset this interaction
	if ((key = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Issue opening file\n");
		exit(2);
	}

	//Validate Key length then reset key file position
	fgetpos(key, &pos);

	while (1) {
		x = fgetc(key);
		if (feof(key)) {
			break;
		}
		keyLen++;
	}

	fsetpos(key, &pos);

	fopen_s(&dMessage, "decryptedMessage.txt", "w");
	printf("Decrypted message: ");

	//Decrypt the message
	for (i = 0; i < keyLen; i++) {
		a = fgetc(message);
		b = fgetc(key);

		c = a - b + 32;

		//loop if under 32 
		if (c < 32) {
			c += 95;
		}

		x = c;
		fprintf(dMessage, "%c", x);
		fprintf(stdout, "%c", x);
	}

	//Close the files used
	fclose(message);
	fclose(key);
	fclose(dMessage);
	//Remove encrypted message file
	remove("encryptedMessage.txt");

	printf("\nDecrypt Success\n");
	return;
}