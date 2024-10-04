#include <stdio.h>
#include <stdlib.h>

#define N 15

//void qsort(void *, int n, int size, int(*compare)(const void *, const void *));
int compare(const void *p1, const void *p2);
int quick_sort(int *data, int low, int high);
int partion(int *data, int low, int high);

int main(int argc, char *argv[]){
	int i, data[N];

	srandom(10);   //xxx 哦，原来是种子，确保下面随机生成的序列保持一致

	for(i = 0; i < N; i++){
		data[i] = random() % 100;   //xxx 保持数据在0-99
	}

	for(i = 0; i < N; i++){
		printf("%d ", data[i]);
	}
	puts("");

	//qsort(data, N, sizeof(int), compare);
	quick_sort(data, 0, N-1);

	for(i = 0; i < N; i++){
		printf("%d ", data[i]);
	}
	puts("");

	return 0;
}

int compare(const void *p1, const void *p2){
	return *(const int *)p1 - *(const int *)p2;   //xxx 强制转换完，还是地址，你得用地址上面的数值去减
}

int quick_sort(int *data, int low, int high){
	int t;

	if(!data){
		printf("data is null\n");
		return -1;
	}

	if(low >= high){
		//printf("low >= high\n");
		return 0;
	}

	t = partion(data, low, high);
	quick_sort(data, low, t-1);
	quick_sort(data, t+1, high);

	return 0;
}

int partion(int *data, int low, int high){
	int temp;

	temp = data[low];

	while(low < high){
		while(low < high && temp <= data[high]){
			high--;
		}
		data[low] = data[high];

		while(low < high && temp >= data[low]){
			low++;
		}
		data[high] = data[low];
	}

	data[low] = temp;   //xxx 好好理解这段代码，想了一两个小时！！！ 由此也觉得真是28定律

	return low;
}
