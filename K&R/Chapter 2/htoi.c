#include <stdio.h>
#include <math.h>

int htoi(char s[]);
int hex(int c);
int isHexDigit(int c);
int main()
{
    printf("%d", htoi("0xAEF"));
    return 0;
}

int htoi(char s[])
{

    int sum = 0, i = (s[1] == 'x' || s[1] == 'X') ? 2 : 0;
    
    for (i; isHexDigit(s[i]); i++) {
        sum = hex(s[i]) + (16 * sum);
    }
    return sum;
}

int hex(int c)
{
    if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    } else if (c >= 'A' && c <= 'F') {
        return 10 + (c-'A');
    } else {
        return c - '0';
    }
}

int isHexDigit(int c)
{
   return ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'));
}