#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

		for(i = 100; i < 120; i++){
			if(i % 3 == 0)
				//continue;
				break;
			printf("%d\n", i);
		}

	return 0;
}
