#include <stdio.h>

int main()
{
    int c, spaceCount = 0, spacesNeeded = 0, tabsNeeded = 0;

    printf("Press \"Enter\" to finalize input.\n");
    while ((c = getchar()) != '\n') {
        //If the encountered character delimits a word
        if (c == ' ') {
           spaceCount++;
        }
        else {
            if (spaceCount % 3 == 0) {
                tabsNeeded = spaceCount / 3;
                spacesNeeded = 0;
            }
            else {
                spacesNeeded = spaceCount % 3;
                tabsNeeded = (spaceCount - spacesNeeded) / 3;
            }

            if (tabsNeeded > 0) {
                for (int i = 0; i < tabsNeeded; i++) {
                    putchar('\t');
                }
            }
            if (spacesNeeded > 0) {
                for (int i = 0; i < spacesNeeded; i++) {
                    putchar(' ');
                }
            }

            tabsNeeded = spacesNeeded = spaceCount = 0;
            putchar(c);
           // printf("\nSpaces: %d, Tabs: %d\n", spacesNeeded, tabsNeeded);
        }
    }
    return 0;
}