#include "keygen.h"

void RandomKeygen(int len) {
	FILE *key;
	char fileName[5], c;
	int x, i;

	sprintf(fileName, "%d", _getpid());

	fopen_s(&key, fileName, "w");

	for (i = 0; i < len; i++) {
		x = rand() % 95;
		c = x + 32;
		fprintf(key, "%c", c);
	}

	fclose(key);
}