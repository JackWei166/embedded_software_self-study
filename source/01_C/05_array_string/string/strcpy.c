#include <stdio.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[])
{
	char s1[] = "www.makeru";
	char s2[N];
	int i, n;

	//strcpy(s2, s1);

	n = strlen(s1);
	for(i = 0; i < n; i++){
		s2[i] = s1[i];
	}
	s2[n] = '\0';

	puts(s1);
	puts(s2);

	return 0;
}
