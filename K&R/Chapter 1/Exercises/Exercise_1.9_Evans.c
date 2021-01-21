//Prompt: Replace one more spaces with a single space.
#include <stdio.h>

//Defining States
#define IN 1
#define OUT 0

//Program Entry Point
int main()
{
    int state = IN, c;
    printf("This program replaces one or more spaces with a single space.\n");
    printf("Press \"Enter\" to finalize input.\n");
    while ((c = getchar()) != '\n') {
        //If the encountered character is a space
        if (c == ' ' || c == '\t') {
            //If the state is IN, print the current character and switch states
            if (state == IN) { 
                putchar(' ');
                state = OUT;
            }
        }
        //Otherwise,
        else { 
            //Switch the state and print the current character.
            state = IN;
            putchar(c);
        }
    }
    return 0;
}