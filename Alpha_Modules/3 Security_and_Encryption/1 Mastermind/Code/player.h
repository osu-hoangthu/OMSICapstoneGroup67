#ifndef PLAYER_H
#define PLAYER_H

enum difficulty
{
	EASY,
	NORMAL,
	HARD
};

/*Struct playRecords
Description: Holds the win/loss records of all game modes for the given profile
-Variables-
regWin: Number of regular wins
regLoss: Number of regular losses
numberOfRegularGames: Number of games played in Mastermind's regular game mode
challWin: Number of Challenge wins
challLoss: Number of Challenge losses
numberOfChallengeGames: Number of games played in Mastermind's challenge game mode
-End Variables-
Struct File Declaration: player.h
*/
struct playRecords
{
	int regWin;
	int regLoss;
	int numberOfRegularGames;
	int challWin;
	int challLoss;
	int numberOfChallengeGames;//Might have to diversify later
};

/*Struct profileSettings
Description: Holds the data for the individual player and is written to a play file.
Currently holds player name, difficulty level, and current win/loss record.
-Variables-
playerName: Pointer for profile player name
playerNameLength: Length of player name;
aiStrength: Difficulty level of AI for Mastermind
currentRecord: Struct that maintains the current player's win/loss record.
-End Variables-
Struct File Declaration: player.h
*/
struct profileSettings
{
	char **playerName;
	int playerNameLength;
	enum difficulty aiStrength;
	struct playRecords currentRecord;
};

#endif // !PLAYER_H
