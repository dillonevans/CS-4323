//Prompt: Write a program that prints a histogram of the length of entered words.
#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORDS 10

//Program Entry Point
int main()
{
    int state = IN, c, numWords = 0, wordLength = 0;
    int lengths[MAX_WORDS];
    printf("Press \"Enter\" to finalize input.\n");
    do {
        c = getchar();
        if (c == ' ' || c == '\t' || c == ',' || c == '\n') {
            //If the state is IN, print a new line
            if (state == IN) { 
                lengths[numWords++] = wordLength;
                wordLength = 0;
                state = OUT;
            }
        }
        //Otherwise,
        else { 
            //Switch the state and print the current character.
            state = IN;
            wordLength++;
        }
    } while (c != '\n' && numWords < MAX_WORDS);
 
    for (int i = 0; i < numWords; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            printf("_");
        }
        printf("\n");
    }
    return 0;
}