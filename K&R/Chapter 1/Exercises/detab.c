#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
    int state = IN, c;

    printf("Press \"Enter\" to finalize input.\n");
    while ((c = getchar()) != '\n') {
        //If the encountered character delimits a word
        if (c == '\t') {
           for (int i = 0; i < 3; i++) {
               putchar(' ');
           }
        }
        else {
            putchar(c);
        }
    }
    return 0;
}