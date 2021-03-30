#include <stdio.h>

int main()
{
    int a[] = {1,2,3};
    int *b = a;

    for (int i = 0; i < 3; i++)
    {
        printf("Current Address: %p\n", (b+i));
        printf("%d\n", *(b+i));       
    }
}