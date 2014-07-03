#include "hamm.h"

int main(int argc, char *argv[])
{
    char strand1 [MAX_SIZE];
    char strand2 [MAX_SIZE];
    printf("Enter first strand: ");
    fgets(strand1, MAX_SIZE-1, stdin);
    printf("Enter second strand: ");
    fgets(strand2, MAX_SIZE-1, stdin);
    if(strlen(strand1) == strlen(strand2)){
        int result = compare_strands(strand1, strand2);
        printf("Hamming Distance: %d\n", result);
    } else {
        printf("Please enter two strands of equivalent length.");
    }
}

int compare_strands(char strand1[MAX_SIZE], char strand2[MAX_SIZE])
{
    return 1;
}
