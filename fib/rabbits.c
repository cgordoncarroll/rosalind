#include <stdio.h>

#define MAX_MONTHS 40
#define MAX_PAIRS 5

int main(int argc, char *argv[])
{
    int months = 0;
    int pairsPerLitter = 0;

    printf("Enter number of months: ");
    fscanf(stdin, "%d", &months);
    if(months > MAX_MONTHS || months < 0)
    {
        printf("You must enter a number between 0 and %d.\n", MAX_MONTHS);
        return 1;
    }
    printf("Enter number of pairs per litter: ");
    fscanf(stdin, "%d", &pairsPerLitter);
    if(pairsPerLitter > MAX_PAIRS || pairsPerLitter < 0)
    {
        printf("You must enter a number between 0 and %d.\n", MAX_PAIRS);
        return 1;
    }

    int result = breed(months, pairsPerLitter);
    printf("Resultant number of rabbit pairs: %d.\n", result);
}

int breed(int months, int pairsPerLitter)
{
    int youngPairs = 1;
    int maturePairs = 0;

    for(int i = 0; i < months-1; i++)
    {
        int newbornPairs = maturePairs * pairsPerLitter;
        maturePairs += youngPairs;
        youngPairs = newbornPairs;
    }
    return youngPairs + maturePairs;
}
