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
	char* first = str;
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
	if(argc == 2){
	translate(argv[1]);
	reverse(argv[1]);
	printf("%s\n", argv[1]);
	}else{
		printf("Wrong number of arguments");
	}
}
