#include "exynos_4412.h"

void Delay(unsigned int time);

int main(void){
	WDT.WTCON = WDT.WTCON | (0xFF << 8);
	WDT.WTCON = WDT.WTCON | (0x3 << 3);
	WDT.WTCON = WDT.WTCON & (~(0x1 << 2));
	WDT.WTCON = WDT.WTCON | 1;
	WDT.WTCNT = 3052 * 5;
	WDT.WTCON = WDT.WTCON | (1 << 5);

	while (1) {
		printf("WDT.WTCNT = %d\n", WDT.WTCNT);

		Delay(100000);

		WDT.WTCNT = 3052;
	}

	return 0;
}

void Delay(unsigned int time){
	while(time--);
}
