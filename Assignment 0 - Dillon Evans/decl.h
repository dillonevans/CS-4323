#include "defs.h"

void playerInfo();
void boardInitialization(struct PlayerInfo *info);
bool generations(char *board, char *nextState, int row, int col);
void displayGenerations(char *board, char *nextState, int gen, int rows, int cols, struct PlayerInfo *info, bool displayInitialState);
void readPlayersInformation(struct PlayerInfo *info);
void displayGameSummary(char **entries, int numberOfEntries);