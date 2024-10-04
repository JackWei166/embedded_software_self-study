#include <stdio.h>

int main(int argc, char *argv[])
{
	float score;

	printf("Please input your score:");
	scanf("%f", &score);
	
	if(score < 0 || score > 100){
		printf("The score is not in [0, 100].\n");
		return -1;
	}

	if(score >= 90){
		printf("You got A!\n");
	}
	else if(score >= 70){
		printf("You got B!\n");
	}
	else if(score >= 60){
		printf("You got C!\n");
	}
	else{
		printf("You got D!\n");
	}

	return 0;
}
