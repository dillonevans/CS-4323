#include <stdio.h>
#include "Process.h"

int main()
{
    Process p1{1,2,3};
    printf("Process ID: %d", p1.pid);
}