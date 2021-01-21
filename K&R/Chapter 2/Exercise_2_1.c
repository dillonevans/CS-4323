#include <stdio.h>
#include <math.h>
#include <limits.h>

void printIntRange();
void printDoubleRange();
int main()
{
    printf("%f", 2e7);
}

void printIntRange()
{
    int signedIntBits = (sizeof(int) * 8) - 1;
    int upperBound = pow(2,signedIntBits) - 1;
    int lowerBound = pow(2,signedIntBits) * -1;
    printf("[%d, %d]\n", lowerBound, upperBound);
    printf("%d", INT_MAX);
}

void printDoubleRange()
{
    double signedDoubleBits = (sizeof(double) * 8) - 1;
    double upperBound = pow(2,signedDoubleBits) - 1;
    double lowerBound = pow(2,signedDoubleBits) * -1;
    printf("[%f, %f]\n", lowerBound, upperBound);

}




