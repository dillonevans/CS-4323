//Prompt: Replace multiple occurrence of tab backspace or backslash with a single character respectively. 
#include <stdio.h>

//Defining States
#define IN 1
#define OUT 0

//Program Entry Point
int main()
{
    int state = IN, c, previousChar;
    printf("Press \"Enter\" to finalize input.\n");
    while ((c = getchar()) != '\n') {
        //If the encountered character is a space
        if (c == '\b' || c == '\t' || c == '\\') {
            //If the state is IN, print the current character and switch states
            if (state == IN || c != previousChar) { 
                putchar(c);
            }
            state = OUT;
        }
        //Otherwise,
        else { 
            //Switch the state and print the current character.
            state = IN;
            putchar(c);
        }
        previousChar = c;
    }
    return 0;
}