//Prompt: Write a program that prints a histogram of the frequency of entered characters.
#include <stdio.h>
#define IN 1
#define OUT 0
#define SIZE '~' - ' '

//Program Entry Point
int main()
{
    int state = IN, c, numWords = 0, wordLength = 0;
    int frequencies[SIZE];
    printf("Press \"Enter\" to finalize input.\n>>");

    //Fill the array with zeros
    for (int i = 0; i < SIZE; i++) {
        frequencies[i] = 0;
    }
    while ((c =getchar()) != '\n') {
        frequencies[c-32]++;
    } 
 
    for (int i = 0; i < SIZE; i++) {
        if (frequencies[i] > 0) {
            printf("%c: ", (char)(i+32));
            for (int j = 0; j < frequencies[i]; j++) {
                printf("_ ");
            }
            printf("\n");
        }
    }
    printf("   ");
    for (int i = 1; i < 50; i++) {
        printf("%d ", i);
    }
    return 0;
}