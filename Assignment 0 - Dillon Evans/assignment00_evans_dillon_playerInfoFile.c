#include "decl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a new PlayerInfo struct and assigns fields
 * @param name The player's name
 * @param date The current date
 * @param gen The number of generations
 * @return a new PlayerInfo struct
 */ 
struct PlayerInfo *createPlayerInfo(char *name, char *date, int gen)
{
    struct PlayerInfo *info = malloc(sizeof *info);
    info->name = name;
    info->date = date;
    info->numGenerations = gen;
    return info;
}

/**
 *  Prompts the player to enter pertinent info
 */
void playerInfo()
{
    char name[BUFFER_SIZE], date[BUFFER_SIZE], numBuffer[BUFFER_SIZE];
    int numGenerations = 0;
    bool isValid = FALSE;

    printf("Enter Your Name >> ");
    gets(name);
   
    printf("Enter Today's Date >> ");
    scanf("%s", date);

    printf("Enter The Desired Number of Generations >> ");
    scanf("%s", numBuffer);
    isValid = sscanf(numBuffer, "%d", &numGenerations);
    
    /*Prompt the user for valid input if necesssary*/
    while (!isValid) {
        printf("Please enter a valid Integer >> ");
        scanf("%s", numBuffer);
        isValid = sscanf(numBuffer, "%d", &numGenerations);
    }

    struct PlayerInfo *info = createPlayerInfo(name, date, numGenerations);
    boardInitialization(info);
    readPlayersInformation(info);
}