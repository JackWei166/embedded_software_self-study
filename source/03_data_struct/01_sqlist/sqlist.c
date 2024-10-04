#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

sqlink list_create(){
	sqlink L;

	if(!(L = (sqlink)malloc(sizeof(sqlist)))){
		printf("Malloc failed.");
		return NULL;
	}	

	memset(L, 0, sizeof(sqlist));
	L->last = -1;

	return L;
}

int list_clear(sqlink L){
	
	if(!L){
		printf("The object has not been created.");
		return -1;
	}

	memset(L, 0, sizeof(sqlist));
	L->last = -1;

	return 0;
}

int list_free(sqlink L){
	if(L == NULL){
		printf("The object has not been created.");
		return -1;
	}

	free(L);
	L = NULL;

	return 0;
}

int list_empty(sqlink L){
	if(L == NULL){
		printf("The object has not been created.");
		return -1;
	}

	if(L->last == -1){
		return 1;
	}else{
		return 0;
	}

}

int list_length(sqlink L){
	if(L == NULL){
		printf("The object has not been created.");
		return -1;
	}
	
	return L->last+1;
}

int list_locate(sqlink L, data_t value){
	int i;

	if(L == NULL){
		printf("The object has not been created.");
		return -2;
	}

	for(i = 0; i <= L->last; i++){
		if(L->data[i] == value){
			return i;
		}
	}

	return -1;
}

int list_insert(sqlink L, data_t value, int pos){
	int i;

	if(L->last == N -1){
		printf("List is full.");
		return -1;
	}

	if(pos < 0 || pos > L->last + 1){
		printf("Pos is unvalid.");
		return -1;
	}

	for(i = L->last; i >= pos; i--){
		L->data[i+1] = L->data[i];
	}

	L->data[pos] = value;
	L->last++;

	return 0;
}

int list_delete(sqlink L, int pos){
	int i;

	if(L == NULL){
		printf("The object has not been created.");
		return -1;
	}

	if(pos < 0 || pos > L->last){
		printf("pos is invalid.");
		return -1;
	}

	if(L->last == N-1){
		printf("List is empty.");
		return -1;
	}

	for(i = pos+1; i <= L->last; i++){
		L->data[i-1] = L->data[i];
	}

	L->last--;

	return 0;
}

int list_merge(sqlink L1, sqlink L2){
	int i;

	if(!L1){
		printf("The object sqlink1 has not been created.");
		return -1;
	}

	if(!L2){
		printf("The object sqlink2 has not been created.");
		return -1;
	}

	for(i = 0; i <= L2->last; i++){
		if(list_locate(L1, L2->data[i]) == -1){
			if(list_insert(L1, L2->data[i], L1->last+1) == -1){
				printf("Insert failed.");
				return -1;
			}
		}
	}

	return 0;
}

int list_purge(sqlink L){
	int i;
	int j;

	if(L->last == -1){
		printf("List is empty.");
		return -1;
	}

	if(L->last == 0){
		return 0;
	}

	i = 1;
	while(i <= L->last){
		j = i - 1;
		while(j >= 0){
			if(L->data[j] == L->data[i]){
				list_delete(L, i);
				break;
			}else{
				j--;
			}
		}
		
		if(j < 0){
			i++;
		}
	}

	return 0;
}


int list_show(sqlink L){
	int i;

	if(L == NULL){
		printf("The object has not been created.");
		return -1;
	}

	if(L->last == -1){
		printf("List is empty.");
		return 0;
	}

	for(i = 0; i <= L->last; i++){
		printf("%d ", L->data[i]);
	}
	puts("");

	return 0;
}
