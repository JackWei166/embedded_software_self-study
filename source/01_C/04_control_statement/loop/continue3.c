#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int i, n;
	int temp;
	char ch;

	while(1){
		printf("Please input:");
		if(scanf("%d", &n) == 0){
			if((ch = getchar()) == '#'){
				break;
			}
			else{
				printf("Input error!\n");
				continue;
			}
		}
		
		i = 2;
		temp = sqrt(n);

		while(i <= temp){
			if(n % i == 0)
				break;
			i++;
		}

		if(i <= temp){
			printf("not\n");
		}
		else{
			printf("is\n");
		}

	}

	return 0;
}
