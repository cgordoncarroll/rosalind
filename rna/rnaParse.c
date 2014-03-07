#include <stdio.h>
#define maxLength 1000

void makeRNA(char rnaString[], char dnaString[]);
int main()
{
	char dnaString [maxLength];
	char rnaString [maxLength];
	gets(dnaString);
	makeRNA(rnaString, dnaString);
	printf("%s\n", rnaString);
}

void makeRNA(char rnaString[], char dnaString[])
{
	int i = 0;
	for(i = 0; dnaString[i] != '\0'; i++)
		if(dnaString[i] == 'T')
			rnaString[i] = 'U';
		else
			rnaString[i] = dnaString[i];
}
