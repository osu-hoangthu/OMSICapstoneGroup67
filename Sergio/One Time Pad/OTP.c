#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void Menu();
void ValidateDir();
void Encrypt();
void Decrypt();
void Keygen(int);

int main() {
	ValidateDir();
	Menu();
	return 0;
}

void ValidateDir() {
	//If an issue with opening the DIR, make it. 
	///TODO: Validate DIR existance prior to changing to it.
	if (chdir("OTPTemp")==-1) {
		//Create DIR name
		char directoryName[8] = "OTPTemp";
		//Make the actual DIR with proper permissions
		mkdir(directoryName, 0755);
		//Change into the Proper DIR
		chdir(directoryName);
	}
}

void Menu() {
	char buffer[16];
	int x;
	memset(buffer, '\0', sizeof(buffer));
	///TODO: Create an actual menu
	//Quick and dirty menu to have basic functionality
	while (1) {
		///TODO: Have some actual user input validation -_-
		printf("Simple Menu:\n1. Encrypt and Generate Key\n2. Decrypt with Key\n3. Exit\n");
		fgets(buffer, 15, stdin);
		x = buffer[0];
		printf("NUM:%d\nSTRLEN:%d\n", x,strlen(buffer));
		//Switch to proper valid action otherwise just exit. Future GUI will make this unnecessary hopefully
		switch (x) {
			case 49:
				Encrypt();
				break;
			case 50:
				Decrypt();
				break;
			case 51:
				printf("Exit Success\n");
				exit(0);
			default:
				printf("ERROR\n");
				exit(1);
		}
		//Reset user buffer, not really necessary but..... at least try to make it proper
		memset(buffer, '\0', sizeof(buffer));
	}

}

void Encrypt() {
	FILE *message, *key;
	char buffer[256], fileName[5], x;
	int  a, b, c, i;

	memset(buffer, '\0', sizeof(buffer));
	sprintf(fileName, "%d", getpid());

	///TODO: Implement selection menu for different methods of encryption. Also enable the ability to use your own keygen

	//Receive user input
	printf("Enter sentence to encrypt:\n");
	fgets(buffer, 255, stdin);

	//Call keygen to make a OTP key
	Keygen( (strlen(buffer) - 1) );

	//Open files necessary for encryption
	message = fopen("message.txt", "w");
	key = fopen(fileName, "r");

	printf("Encrypted message: ");
	
	//Encrypt Sentence and place in a message file
	///TODO:Account for upper and lower case
	for (i = 0; i < strlen(buffer)-1; i++) {
		a = buffer[i];
		b = fgetc(key);

		c = a + b - 65;

		//loop if over 27 
		if (c > 91) {
			c -= 27;
		}

		//If it lands on space convert to proper ascii num
		if (c == 91) {
			c = 32;
		}

		x = c;
		fprintf(message, "%c", x);
		printf("%c", x);
	}

	//Close the files used
	fclose(message);
	fclose(key);

	printf("\nEncrypt Success\n");
	return;
}

void Decrypt() {
	FILE *message, *key, *dMessage;
	fpos_t pos;
	char fileName[16], x;
	int  a, b, c, i, keyLen = 0;

	//Attempt to load message file
	///TODO: Recover from error and reset this interaction
	if ((message = fopen("message.txt", "r")) == NULL) {
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

	dMessage = fopen("decryptedMessage.txt", "w");
	printf("Decrypted message: ");
	
	//Decrypt the message
	///TODO:FIX THE DECRYPTION! I messed up somewhere
	for (i = 0; i < keyLen; i++) {
		a = fgetc(message);
		b = fgetc(key);
		//Account if space char is used
		if (a == 32) {
			a = 91;
		}
		if (b == 32) {
			b = 91;
		}

		c = a - b + 65;

		//loop if under 27 
		if (c < 65) {
			c += 27;
		}

		//If it lands on space convert to proper ascii num
		if (c == 91) {
			c = 32;
		}

		x = c;
		fprintf(dMessage,"%c", x);
		printf("%c", x);
	}

	//Close the files used
	fclose(message);
	fclose(key);
	fclose(dMessage);
	//Remove encrypted message file
	remove("message.txt");

	printf("\nDecrypt Success\n");
	return;
}

void Keygen(int len) {
	FILE *key;
	char fileName[5], c;
	int x, i;
	
	//THIS IS NOT SECURE! ONLY FOR EDUCATION.
	srand(time(NULL));
	sprintf(fileName, "%d", getpid());

	key = fopen(fileName, "w");
	
	for (i = 0; i < len; i++) {
		x = rand() % 95;
		c = x + 32;
		fprintf(key, "%c", c);
	}

	fclose(key);
}