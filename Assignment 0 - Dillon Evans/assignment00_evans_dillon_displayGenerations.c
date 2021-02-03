#include "decl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Stores the current number of generations*/
static int currentGeneration = 1;

/**
 * Outputs the current state of the grid.
 * @param grid The grid to print.
 * @param rows The number of rows in the grid.
 * @param cols The number of columns in the grid.
 */
static void display(char *grid, int rows, int cols)
{
    char temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp = *(grid + i * rows + j);
            printf("\t%c ", temp);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Displays n generations to the player
 * @param state The current state of the game
 * @param nextState The next state of the game
 * @param gen The number of generations to produce
 * @param rows The number of rows in the grid
 * @param cols The number of columns in the grid
 * @param info The PlayerInfo struct to update as needed.
 * @param displayInitialState Determines if the initial state of the board should be displayed
 */
void displayGenerations(char *state, char *nextState, int gen, int rows, int cols, struct PlayerInfo *info, bool displayInitialState)
{
    char buf[BUFFER_SIZE];
    int additional = 0;
    bool isValid = FALSE;

    /*Display the initial state*/
    if (displayInitialState) {
        printf("Initial State: \n");
        display(state, rows, cols);
    }

    for (int i = 0; i < gen; i++) {
        /* Prevent redundant computation if all the cells are inactive by terminating */
        if (!generations(state, nextState, rows, cols)) {
            printf("After generation %d, all cells in the board are inactive.\n", i);
            exit(1);
        }
        /* The next state becomes the current state after each iteration*/
        memcpy(state, nextState, sizeof(char) * rows * cols);
        printf("Generation %d: \n", currentGeneration++);

        /* Display the current state after updating */
        display(state, rows, cols);
    }

    printf("Would you like to see more? Enter 'yes' or 'no' >> ");
    scanf("%s", buf);
    isValid = (strcmp(buf, "yes") == 0 || strcmp(buf, "no") == 0);

    /*Prompt the user for a valid response if necessary*/
    while (!isValid) {
        printf("Please enter 'yes' or 'no' >> ");
        scanf("%s", buf);
        isValid = (strcmp(buf, "yes") == 0 || strcmp(buf, "no") == 0);
    }

    if (strcmp(buf, "yes") == 0) {
        printf("Enter the number of generations >> ");
        scanf("%s", buf);
        isValid = sscanf(buf, "%d", &additional);

        /*Prompt the user for a valid response if necessary*/
        while (!isValid) {
            printf("Please enter a valid Integer >> ");
            scanf("%s", buf);
            isValid = sscanf(buf, "%d", &additional);
        }

        /*Update the number of generations in the struct*/
        info->numGenerations += additional;

        /*Recurse for the additional generations*/
        displayGenerations(state, nextState, additional, rows, cols, info, FALSE);
    } else {
        return;
    }   
}