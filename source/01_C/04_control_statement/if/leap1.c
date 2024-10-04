#include <stdio.h>

int main(int argc, char *argv[])
{

	int year = 2000, n = 0;

	while(year <= 2500){
		if(year % 4 == 0){
			if(year % 100 != 0){
				printf("%d\n", year);
				n++;
			}
			else{
				if(year % 400 == 0){
					printf("%d\n", year);
					n++;
				}
			}
		}
		year++;
	}
	
	printf("%d\n", n);

	return 0;
}
