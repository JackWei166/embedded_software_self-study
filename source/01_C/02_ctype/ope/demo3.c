#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 8, b = 7;

	if(!((a - b) == 7)){
	//if(!(a - b) == 7){
		printf("true\n");
	}
	else{
		printf("false\n");
	}

	return 0;
}
