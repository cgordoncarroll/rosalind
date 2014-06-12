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

void reverse(char *str)
{
	char* first = &str[ 0 ];
	char* last = &str[ strlen( str ) - 1 ];
	while( first < last) {
		char temp = *first;
		*first = *last;
		*last = temp;
		++first;
		--last;
	}
}

int main(int argc, char *argv[])
{
	char str[] = "AAAACCCGGT";
	translate(str);
	reverse(str);
	printf("%s\n", str);
}
