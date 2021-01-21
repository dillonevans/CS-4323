#include <stdio.h>
#include <math.h>
int atoi(char s[]);
int main()
{
    int result = atoi("55");
    char c = 68;
    printf("%c", c);
    return 0;
}

//ASCII to Integer
int atoi(char s[])
{
    //Base 10 representation 
    int sum = 0;

    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        sum += ((s[i] - '0') * (int)pow(10,i));
    }
    return sum;
}