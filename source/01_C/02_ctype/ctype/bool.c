#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	_Bool a = 0;
	bool b = true;
	
	if(a){
		printf("true: %d\n", a);
	}else{
		printf("false: %d\n", a);
	}

	
	if(b){
		printf("true: %d\n", b);
	}else{
		printf("false: %d\n", b);
	}

	return 0;
}
