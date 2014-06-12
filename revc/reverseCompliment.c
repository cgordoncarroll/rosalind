#include <stdio.h>
#define maxlength 1000

void translate(char *str)
{
	for(; *str != '\0'; str++){
		if(*str == 'C'){
			*str = 'G';
		}else if(*str == 'G'){
			*str = 'C';
		}

		if(*str == 'A'){
			*str = 'T';
		}else if(*str == 'T'){
			*str = 'A';
		}
	}
}

int main(int argc, char *argv[])
{
	char *str = "AAACCCGGT";
	translate(str);
	printf("%s\n", str);
}
