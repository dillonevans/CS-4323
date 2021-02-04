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
 * Returns a line of user input from the console without overflow
 * @return A string containing the input
 */
static char *getLine()
{
    char *buffer = malloc(BUFFER_SIZE);
    char temp;
    int len = 0;
    while ((temp = getchar()) != '\n' && len < BUFFER_SIZE - 1)
    {
        buffer[len++] = temp;
    }
    buffer[len] = '\0';
    return buffer;
}

/**
 *  Prompts the player to enter pertinent info
 */
void playerInfo()
{
    char *name, *date, numBuffer[BUFFER_SIZE];
    int numGenerations = 0;
    bool isValid = FALSE;

    printf("Enter Your Name >> ");
    name = getLine();
   
    printf("Enter Today's Date >> ");
    date = getLine();

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
    free(name);
    free(date);
}