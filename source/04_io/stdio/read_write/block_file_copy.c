#include <stdio.h>

#define N 64

int main(int argc, char *argv[]){
	FILE *fps, *fpd;
	char buf[N];
	int n;

	fps = fopen(argv[1], "r");
	if(!fps){
		perror("fopen fps");
		return -1;
	}

	fpd = fopen(argv[2], "w");
	if(!fpd){
		perror("fopen fpd");
		fclose(fps);   //xxx 可读性；关联资源释放；平台兼容
		return -1;
	}

	while((n = fread(buf, 1, N, fps)) > 0){   //xxx 到末尾可能EOF，也可能0，类似的 要考虑0的情况！！！
		fwrite(buf, 1, n, fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;
}
