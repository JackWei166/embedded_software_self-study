#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char *p;

	if((p = (char *)malloc(10*sizeof(char))) == NULL){
		printf("Malloc failed!");
		return -1;
	}

	printf("%p\n", &p);
	
	printf("Input:");
	scanf("%s", p);

	printf("%s\n", p);

	free(p);
	p = NULL;

	return 0;
}
