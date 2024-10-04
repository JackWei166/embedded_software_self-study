#include <stdio.h>

#define N 50

char *mstrcat(char *dest, char *src);

int main(int argc, char *argv[]){
	char dest[N] = "Welcome to ";
	char src[] = "Beijing!";

	puts(mstrcat(dest,src));
	puts(dest);

	return 0;
}

char *mstrcat(char *dest, char *src){
	char *r;

	r = dest;

	while(*dest)
		dest++;

	while(*dest++ = *src++);

	return r;
}
