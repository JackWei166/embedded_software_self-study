#include <stdio.h>

int main(int argc, char *argv[]){
	char *s[] = {"apple", "pear", "potato"};
	char **p;
	int i, n;

	i = 0;
	n = sizeof(s) / sizeof(s[0]);
	p = s;

	while(i < n){
		printf("%s  %s\n", s[i], p[i]);
		i++;
	}

	return 0;
}
