#include <stdio.h>
#define maxLength 1000

int numChars( char string[], char search);
int main()
{
	int numA;
	int numC;
	int numG;
	int numT;

	char dnaString [maxLength];	
	printf("Enter a string.\n");
	gets(dnaString);
	numA = numChars(dnaString, 'A');
	numC = numChars(dnaString, 'C');
	numG = numChars(dnaString, 'G');
	numT = numChars(dnaString, 'T');	
	
	printf("%d %d %d %d\n", numA, numC, numG, numT);
	return 0;
}

int numChars(char dnaString[], char searchChar)
{
	int i, count = 0;

	for ( i = 0; dnaString[i] != '\0' ; i++)
		if ( dnaString[i] == searchChar ) 
			count++;
	return count;
}
