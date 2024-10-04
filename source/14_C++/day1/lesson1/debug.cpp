#include <stdio.h>

void debug(const char *ptr = "------------------------")
{
	printf("%s\n", ptr);
}

int main(void)
{
	debug();
	debug("hello, world");

	return 0;
}
