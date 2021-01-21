//Prompt: Write a program that prints its input one word per line
#include <stdio.h>
#define IN 1
#define OUT 0

//Program Entry Point
int main()
{
    int state = IN, c;

    printf("Press \"Enter\" to finalize input.\n");
    while ((c = getchar()) != '\n') {
        //If the encountered character delimits a word
        if (c == ' ' || c == '\t' || c == ',') {
            //If the state is IN, print a new line
            if (state == IN) { 
                putchar('\n');
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