#include "game.h"

/*Function GameStart
Description: <Function Description>
-Variables-
aiCode[4]: AI generated peg selection
userPeg[4]: User peg selection
response[4]: A container for status of peg values
total[3]: A container for the number of correct pegs/correct colors/wrong pegs.
colorCheck: Has this color already been claimed? ignore
colorFlag: A flag to determine if previous color was selected, 1 == yes, 2 == yes. ignore
numOfGuesses: Holds the number of guesses that the user has, currently 3 but can be changed later
g: User input, single char
i: A counter int variable
x: A counter int variable
y: A counter int variable
-End Variables-
Returns: N/A
Function File Declaration: game.h
*/
void GameStart() {
	//Gameplayloop
	//Make 4 color code
	FILE *moves;
	enum boardpegs aiCode[4], userPeg[4];
	enum coderesponse response[4];
	char g;
	int i, x, y, total[3], colorCheck, colorFlag, numOfGuesses = 12;

	moves = fopen("moveset.mm", "w");
	//fprintf(stdout, "Test Code: ");
	for (i = 0; i < 4; i++) {
		aiCode[i] = (enum boardpegs)(rand() % 6);
		//PrintNameOfBoardPeg(aiCode[i], stdout);
		//fprintf(stdout, " ");
	}
	//fprintf(stdout, "\n");

	while (numOfGuesses > 0) {
		x = 0;
		total[0] = 0;
		total[1] = 0;
		total[2] = 0;
		//Guess 4 color code
		fprintf(stdout, "Colors Available:\n1.Red\n2.Green\n3.Teal\n4.Yellow\n5.White\n6.Black\n\n");
		for (i = 0; i < 4; i++) {
			fprintf(stdout, "Enter peg %d:", (i + 1));
			g = getc(stdin);
			while ((getchar()) != '\n');
			userPeg[i] = (enum boardpegs)GetBoardPeg(g);
			PrintNameOfBoardPeg(userPeg[i], moves);
			fprintf(moves, " ");
		}
		fprintf(moves, "\n");
		fclose(moves);
		//Check and give response
		///TODO: fix the logical error with certain code patterns.
		for (i = 0; i < 4; i++) {
			if (aiCode[i] == userPeg[i]) {
				response[i] = PERFECT;
			}
			else {
				response[i] = INCORRECT;
			}
		}
		for (i = 0; i < 4; i++) {
			colorCheck = 0;
			colorFlag = 0;
			for (x = 0; x < 4; x++) {
				if (response[i] == PERFECT) {
					break;
				}

				if (i == x) {
				}

				else {
					if (response[x] == PERFECT) {
					}
					else if (userPeg[i] == aiCode[x]) {
						if (colorFlag == 0) {
							for (y = 0; y < i; y++) {
								if (response[y] == CORRECTCOLOR && userPeg[i] == userPeg[y]) {
									colorCheck = 1;
									colorFlag++;
									break;
								}
							}
						}
						else if (colorFlag == 1) {
							colorCheck = 0;
						}
						if (colorCheck == 0) {
							response[i] = CORRECTCOLOR;
						}
					}
				}

			}
		}

		for (i = 0; i < 4; i++) {
			switch (response[i])
			{
			case PERFECT:
				total[0]++;
				break;
			case CORRECTCOLOR:
				total[1]++;
				break;
			case INCORRECT:
				total[2]++;
				break;
			default:
				break;
			}
		}
		fprintf(stdout, "\nNumber of Correct Color/Postion: %d\nNumber of Correct Colors: %d\nNumber of Wrong: %d\n\n", total[0], total[1], total[2]);

		//Subtract guess
		--numOfGuesses;

		//Continue until win/out of guesses
		if (total[0] == 4) {
			fprintf(stdout, "Congratulations, you successfully cracked the code!\n");
			remove("moveset.mm");
			return;
		}
		//Print out list of prior guesses
		if (numOfGuesses != 0) {
			fprintf(stdout, "List of prior guesses:\n");
			moves = fopen("moveset.mm", "r");
			g = getc(moves);
			while (g != EOF) {
				fprintf(stdout, "%c", g);
				g = getc(moves);
			}
			fclose(moves);
			moves = fopen("moveset.mm", "a");
			fprintf(stdout, "\n");
		}
	}

	fprintf(stdout, "Aw, maybe next time\nHere is the correct code: ");

	for (i = 0; i < 4; i++) {
		PrintNameOfBoardPeg(aiCode[i], stdout);
		fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
	remove("moveset.mm");
	return;
}

/*Function PrintNameOfBoardPeg
Description: Prints corresponding board peg color based on enumerated value of peg(int is passed in)
-Variables-
peg: Enumerated peg value
-End Variables-
Returns: Returns nothing, prints name instead to stdout.
Function File Declaration: game.h
*/
void PrintNameOfBoardPeg(int peg, FILE *output) {
	switch (peg)
	{
	case 0:
		fprintf(output, "Red");
		break;
	case 1:
		fprintf(output, "Green");
		break;
	case 2:
		fprintf(output, "Teal");
		break;
	case 3:
		fprintf(output, "Yellow");
		break;
	case 4:
		fprintf(output, "White");
		break;
	case 5:
		fprintf(output, "Black");
		break;
	default:
		fprintf(stderr, "Color Peg Error");
		break;
	}
	return;
}

/*Function GetBoardPeg
Description: Returns enumerated value of peg based on char input but if not found then sends out error to stderr.
-Variables-
guess: inputted char value, checked with a switch statement.
-End Variables-
Returns: Enumerated value for specified peg, otherwise an error to stderr and returns 0 for red.
Function File Declaration: game.h
*/
int GetBoardPeg(char guess) {
	int x = 0;
	switch (guess)
	{
	case 'r':
		return 0;
	case 'R':
		return 0;
	case 'g':
		return 1;
	case 'G':
		return 1;
	case 't':
		return 2;
	case 'T':
		return 2;
	case 'y':
		return 3;
	case 'Y':
		return 3;
	case 'w':
		return 4;
	case 'W':
		return 4;
	case 'b':
		return 5;
	case 'B':
		return 5;
	default:
		x = guess - 49;
		if (x >= 0 && x <= 5) {
			return x;
		}
		break;
	}
	fprintf(stderr, "User Peg Input Error");
	return 0;
}