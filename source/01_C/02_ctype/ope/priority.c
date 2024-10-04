#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 8, y = 0, z = 0;

	if(x++ && y++ || ++z){
	//if(!(x - 5) && y++ || ++z){
		printf("true:%d %d %d\n", x, y, z);
	}
	else{
		printf("false:%d %d %d\n", x, y, z);
	}

	return 0;
}
