#include "decl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Write the player's information from the struct to the file and
 * read pre-existing data into a buffer to be displayed
 * @param info The struct containing the player's info
 */
void readPlayersInformation(struct PlayerInfo *info)
{
    /*Open the file for writing*/
    FILE *outFile = fopen("summary.txt", "a");
    fprintf(outFile, "%s, %s, %d\n", info->name, info->date, info->numGenerations);

    /*
        I close the file here only to open it again which may seem redundant,
        but the reason is a file cannot be opened for reading if it hasn't
        been created. However, opening a file for appending if it doesn't exist will create
        it. Thus, I ensure that the file will be written to regardless.
    */
    fclose(outFile);

    char *entries[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int line = 0;
    outFile = fopen("summary.txt", "r");
    
    /*Read the file line by line until EOF is reached*/
    while (fgets(buffer, BUFFER_SIZE, outFile))
    {
        /*
            Allocate memory on the heap for each "string" by malloc-ing 
            enough bytes to fit it as well as the terminating character.
            Note: sizeof(char)is redundant since a char occupies 1 byte
            but it increases readability and makes it explicitly clear to
            anyone reading the code.
        */
        entries[line] = malloc(sizeof(char) * (strlen(buffer) + 1));
        
        /*After allocating enough memory, store the string in the current index*/
        strcpy(entries[line++], buffer);
    }
    fclose(outFile);
    displayGameSummary(entries,line);
}