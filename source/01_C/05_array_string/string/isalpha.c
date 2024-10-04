#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char ch;
	
	while((ch = getchar()) != EOF){
		if(isalpha(ch)){
			if(isupper(ch)){
				printf("Upper: %c\n", ch);
			}

			if(islower(ch)){
				printf("Lower: %c\n", ch);
			}
		}

		if(isdigit(ch)){
			printf("Digit: %c\n", ch);
		}
	}

	return 0;
}
