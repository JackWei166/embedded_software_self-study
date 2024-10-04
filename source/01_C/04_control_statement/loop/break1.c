#include <stdio.h>

#define PI 3.14

int main(int argc, char *argv[])
{
	int i;
	float area;

	while(1){
		for(i = 1; i < 11; i++){
			area = PI * i * i;
			if(area > 100)
				break;
			printf("%d %f\n", i, area);
		}
		puts("");
	}

	return 0;
}
