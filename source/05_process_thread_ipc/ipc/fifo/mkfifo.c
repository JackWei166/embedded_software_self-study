#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){
	if (mkfifo("myfifo", 0666) < 0) {
		perror("mkfifo");
		return 1;
	}

	return 0;
}
