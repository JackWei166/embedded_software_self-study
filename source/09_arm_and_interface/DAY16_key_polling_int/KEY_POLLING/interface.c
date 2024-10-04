#include "exynos_4412.h"

int main(void){

	GPX1.CON = GPX1.CON & (~(0xF << 4));

	while (1) {
		if (!(GPX1.DAT & (1 << 1))) {
			printf("key pressed\n");

			while (!(GPX1.DAT & (1 << 1)));
		} else {
			//no operation
		}
	}

	return 0;
}
