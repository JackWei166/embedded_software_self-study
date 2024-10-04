#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char ch;
	
	while((ch = getchar()) != EOF){
		if(isalpha(ch)){
			if(isupper(ch)){
				ch = tolower(ch);
			}
			else{
				ch = toupper(ch);
			}
				printf("%c\n", ch);
		}
	}

	return 0;
}
