#include <stdio.h>

int main(int argc, char *argv[])
{
	float score;

	printf("Please input your score:");
	scanf("%f", &score);

	if(score < 0 || score > 100){
		printf("Score is not in [0, 100].\n");
		return -1;
	}
	else{
		switch((int)(score / 10)){
		case 10:
		case 9:
			printf("You got a A!\n");
			break;
		
		case 8:
		case 7:
			printf("You got a B!\n");
			break;
		
		case 6:
			printf("You got a C!\n");
			break;
		
		default:
			printf("You got a D!\n");		
		}
	}

	return 0;
}
