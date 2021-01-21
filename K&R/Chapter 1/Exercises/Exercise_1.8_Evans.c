//Prompt: Write a program that displays the number of spaces, tabs, and newlines
#include <stdio.h>
int main()
{
    int spaces = 0, tabs = 0, newlines = 0, c = 0;
    printf("This program counts and displays the number of spaces, tabs, and new lines in the user input.\n");
    printf("Enter '=' to finalize input.\n");
    while ((c = getchar()) != '=') {
        switch (c)
        {
            case ' ':
                spaces++;
                break;
            case '\t':
                tabs++;
                break;
            case '\n':
                newlines++;
                break;
        }
    }
    printf("Spaces: %d\nTabs: %d\nNew Lines: %d\n", spaces, tabs, newlines);
    return 0;
}