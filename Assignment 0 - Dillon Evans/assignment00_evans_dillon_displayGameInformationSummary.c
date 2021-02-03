#include <stdio.h>
#include <stdlib.h>
#include "decl.h"

/**
 * Displays the information of every game played on record
 * @param entries An array of information to print
 * @param numberOfEntries The number of entries to iterate over
 */
void displayGameSummary(char **entries, int numberOfEntries)
{
    for (int i = 0; i < numberOfEntries; i++) {
        /*
            Dereferencing a pointer to a pointer yields the pointer being
            pointed to.
        */
        printf("%s\n", *(entries + i));
        free(*(entries + i));
    }
}