#include <stdio.h>

#define N 50

char *itoa(char *p, int n);

int main(int argc, char *argv[]){
	int n;
	char s[N], *t;

	printf("input:");
	scanf("%d", &n);

	t = itoa(s, n);

	puts(s);
	puts(t);

	return 0;
}

char *itoa(char *p, int n){
	int i = 0, t, x, y, r;
	//static char p[N];

	while(n){
		t = n % 10;
		n /= 10;
		p[i] = t + '0';

		i++;
	}
	p[i] = '\0';

	x = 0;
	y = i - 1;

	while(x < y){
		r = p[x];
		p[x] = p[y];
		p[y] = r;

		x++;
		y--;
	}

	return p;
}
