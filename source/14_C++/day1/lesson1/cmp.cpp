#include <stdio.h>
#include <string.h>

int cmp(int a, int b)
{
	return a-b;
}

int cmp(const char *str1, const char *str2)
{
	return strcmp(str1, str2);
}

int main(void)
{
	printf("%d\n", cmp(1, 2));
	printf("%d\n", cmp("aaa", "bbb"));

	return 0;
}
