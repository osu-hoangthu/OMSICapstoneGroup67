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
		
		fprintf(stdout, "%c", x);
	}

	//Close the files used
	fclose(message);
	fclose(key);
	

	fprintf(stdout, "\nDecrypt Success\nPress Enter to return to main menu.\n");
	fgetc(stdin);
	return;
}

void DecryptCaesar() {
	FILE *message;
	char x;
	int a;

	fopen_s(&message, "caeserCipher.txt", "r");

	fprintf(stdout, "Decrypted message: ");

	x = fgetc(message);

	while(!feof(message)) {
		a = x;
		if (a > 64 && a < 91) {
			a -= 3;
			if (a < 65) {
				a += 26;
			}
		}
		else if (a > 96 && a < 123) {
			a -= 3;
			if (a < 97) {
				a += 26;
			}
		}
		x = a;
		fprintf(stdout, "%c", x);
		x = fgetc(message);
	}
	fprintf(stdout, "\nDecrypt Success\nPress Enter to return to main menu.\n");
	fgetc(stdin);
	fclose(message);
	return;
}

void DecryptRail() {
	FILE *message;
	char x, transpose[256];
	int i = 0;
	memset(transpose, '\0', sizeof(transpose));

	fopen_s(&message, "railCipher.txt", "r");

	fprintf(stdout, "Decrypted message: ");

	x = fgetc(message);

	while (!feof(message)) {
		transpose[i] = x;
		
		x = fgetc(message);
		if (feof(message)) {
			break;
		}
		transpose[(1 + i) * 3] = x;
		
		x = fgetc(message);
		if (feof(message)) {
			break;
		}
		transpose[(2 + i) * 3] = x;

		x = fgetc(message);
		i++;
	}

	fprintf(stdout, "%s\nDecrypt Success\nPress Enter to return to main menu.\n", transpose);
	fgetc(stdin);
	memset(transpose, '\0', sizeof(transpose));
	fclose(message);
	return;
}
void DecryptionMenu() {
	char c;

	while (1) {
		fprintf(stdout, "Decryption Menu:\n1. Decrypt with Caesar Cipher\n2. Decrypt with One Time Pad\n3. Decrypt with Rail Fence\n4. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');

		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			DecryptCaesar();
			break;
		case '2':
			Decrypt();
			break;
		case '3':
			DecryptRail();
			break;
		case '4':
			return;
		default:
			PrintError("Improper Input", 1);
		}
	}
}