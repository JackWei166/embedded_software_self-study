#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	char ch;

	printf("Please input char:");
	scanf("%c", &ch);

	for(i = 0; i < ch - 'A'; i++){
		for(j = 0; j < i; j++){
			putchar('_');
		}

		for(j = 0; j <= i; j++){
			putchar(ch - j);
		}

		puts("");
	}

	return 0;
}
