#include <stdio.h>
#include <stdlib.h>


int get_string(char **p){
	if((*p = (char *)malloc(10*sizeof(char))) == NULL){
		printf("Malloc failed!");
		return -1;
	}

	printf("Input:");
	scanf("%s", *p);

	return 0;
}

int main(int argc, char *argv[]){
	char *p;
	
	get_string(&p);
	printf("%s\n", p);

	free(p);
	p = NULL;

	return 0;
}
