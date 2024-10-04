#include "exynos_4412.h"

void Delay(unsigned int time);

int main(void){
	GPX2.CON = GPX2.CON & (~(0xF << 28)) | (0x1 << 28);

	while (1) {
		GPX2.DAT = GPX2.DAT | (1 << 7);

		Delay(1000000);

		GPX2.DAT = GPX2.DAT & (~(1 << 7));

		Delay(1000000);
	}

	return 0;
}

void Delay(unsigned int time){
	while(time--);
}
