#include "custom.h"

void CustomEncryption() {
	return;
}

void CustomMenu() {
	char c;

	while (1) {
		fprintf(stdout, "Custom Menu:\n1. Create new Caesar Cipher\n2. Create new Key Generator\n3. List Custom Encryptions\n4. Return\n");

		c = fgetc(stdin);
		while ((getchar()) != '\n');

		//Switch to valid action, otherwise, print error to log file and reprompt user. Future GUI will make this unnecessary hopefully
		switch (c) {
		case '1':
			//CreateCustomCaesar();
			break;
		case '2':
			//CreateCustomKeyEncrypt();
			break;
		case '3':
			//ListCustomEncryption();
			break;
		case '4':
			return;
		default:
			PrintError("Improper Input", 1);
		}
	}
}