#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dt;

	if(argc < 2){
		printf("Usage: %s <directory>\n", argv[1]);
		return -1;
	}

	dp = opendir(argv[1]);
	if(dp == NULL){
		perror("opendir");
		return -1;
	}

	while((dt = readdir(dp)) != NULL){
		printf("%s ", dt->d_name);
	}
	puts("");

	closedir(dp);

	return 0;
}
