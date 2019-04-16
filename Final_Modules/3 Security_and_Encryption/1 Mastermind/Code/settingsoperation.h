#ifndef SETTINGSOPERATIONS_H
#define SETTINGSOPERATIONS_H
#include <stdio.h>
#include <string>
#include "programoperations.h"
#include "player.h"

void SettingsMenu(struct profileSettings*);
void ChangeProfile();
void ChangeName(struct profileSettings*);
void ChangeDifficulty(struct profileSettings*);
void PlayerRecords(struct profileSettings*);


#endif // !SETTINGSOPERATIONS_H
