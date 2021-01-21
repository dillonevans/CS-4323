#include <stdio.h>
int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    int a[] = {1,2,3};
    int *pa = &a[0];
    //Equivalently,
    pa = a;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("Value stored at 0x%X = %d\n", (pa+i), *(pa+i));
}