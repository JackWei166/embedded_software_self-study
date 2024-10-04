#include <stdio.h>

#define N 6

int main(){
	char buf[N];

	fgets(buf, N, stdin);

	printf("%s", buf);

	return 0;
}
