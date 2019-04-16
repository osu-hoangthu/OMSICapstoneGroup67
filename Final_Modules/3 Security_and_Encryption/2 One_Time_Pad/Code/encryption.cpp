#include "encryption.h"

void Encrypt() {
	FILE *message, *key;
	char buffer[256], fileName[5], x;
	int  a, b, c, i;

	memset(buffer, '\0', sizeof(buffer));
	sprintf(fileName, "%d", _getpid());

	//Receive user input
	fprintf(stdout, "Enter a sentence to encrypt:\n");
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

void EncryptCaesar() {
	FILE *message;
	char buffer[256], x;
	int a;
	memset(buffer, '\0', sizeof(buffer));

	fopen_s(&message, "caeserCipher.txt", "w");

	//Receive user input
	fprintf(stdout, "Enter sentence to encrypt:\n");
	fgets(buffer, 255, stdin);

	buffer[strlen(buffer)] = '\0';

	fprintf(stdout, "Encrypted message: ");
	
	for (int i = 0; i < strlen(buffer); i++) {
		a = buffer[i];
		if (a > 64 && a < 91) {
			a += 3;
			if (a > 90) {
				a -= 26;
			}
		}
		else if (a > 96 && a < 123) {
			a += 3;
			if (a > 122) {
				a -= 26;
			}
		}
		x = a;
		fprintf(stdout, "%c", x);
		fprintf(message, "%c", x);
	}
	fclose(message);
	return;
}

void EncryptRail() {
	FILE *message;
	char buffer[256], transpose[256];
	int i;
	memset(buffer, '\0', sizeof(buffer));
	memset(transpose, '\0', sizeof(transpose));

	fopen_s(&message, "railCipher.txt", "w");

	//Receive user input
	fprintf(stdout, "Enter sentence to encrypt:\n");
	fgets(buffer, 255, stdin);

	buffer[strlen(buffer)-1] = '\0';

	fprintf(stdout, "Encrypted message: ");

	for (i = 0; i < strlen(buffer)/3; i++) {
		transpose[i] = buffer[i * 3];
		transpose[i + 1] = buffer[(1 + i) * 3];
		transpose[i + 2] = buffer[(2 + i) * 3];
	}

	if (strlen(buffer) % 3 != 0) {
		transpose[i++] = buffer[i * 3];
		transpose[i + 1] = buffer[(1 + i) * 3];
	}
	fprintf(stdout, "%s\n", transpose);
	fprintf(message, "%s", transpose);

	memset(buffer, '\0', sizeof(buffer));
	memset(transpose, '\0', sizeof(transpose));

	fclose(message);
	return;
}

void EncryptionMenu() {
	char c;

	while (1) {
		fprintf(stdout, "Encryption Menu:\n1. Encrypt with Caesar Cipher\n2. Encrypt with One Time Pad\n3. Encrypt with Rail Fence\n4. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');

		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			EncryptCaesar();
			break;
		case '2':
			Encrypt();
			//EncryptOTP();
			break;
		case '3':
			EncryptRail();
			break;
		case '4':
			return;
		default:
			PrintError("Improper Input", 1);
		}
	}
}