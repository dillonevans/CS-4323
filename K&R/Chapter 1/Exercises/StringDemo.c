#include <stdio.h>
#define MAXLINE 100
//Function prototypes

int getLine(char a[], int lim);
void copy(char from[], char to[]);

//Program Entry Point
int main()
{
    char str[MAXLINE];
    getLine(str, MAXLINE);
    printf("%s", str);
    return 0;
}

int getLine(char a[], int lim)
{
    int index = 0, c = 0;
    while (index < lim && (c = getchar()) != '\n') {
        a[index++] = c;
    }
    return index;
}