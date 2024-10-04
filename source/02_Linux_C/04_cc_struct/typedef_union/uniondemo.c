#include <stdio.h>

union  gy {
	char a;
	short b;
	int c;
};

int main(int argc, char *argv[]){
	union gy u;

	u.a = 'C';
	u.b = 12;
	u.c = 0x12345678;

	printf("%c %#x\n", u.a, u.a);
	printf("%p %p %p\n", &u.a, &u.b, &u.c);
	printf("%d\n", sizeof(union gy));

	return 0;
}
