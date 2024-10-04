#include "exynos_4412.h"

void Delay(unsigned int time);

int main(void){
	GPX1.CON = GPX1.CON | (0xF << 4);
	EXT_INT41_CON = EXT_INT41_CON & (~(0x7 << 4)) | (0x2 << 4);
	EXT_INT41_MASK = EXT_INT41_MASK & (~(1 << 1));

	ICDDCR = ICDDCR | 1;
	ICDISER.ICDISER1 = ICDISER.ICDISER1 | (1 << 25);
	ICDIPTR.ICDIPTR14 = ICDIPTR.ICDIPTR14 & (~(0xFF << 8)) | (1 << 8);
	CPU0.ICCICR = CPU0.ICCICR | 1;

	GPX2.CON = GPX2.CON & (~(0xF << 28)) | (1 << 28);

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

void do_irq(void){
	unsigned int IrqNum;

	IrqNum = CPU0.ICCIAR & 0x3FF;

	switch (IrqNum) {
	case 0:
		break;
	case 1:
		break;
	case 57:
		printf("key pressed\n");
		EXT_INT41_PEND = EXT_INT41_PEND & (~(1 << 1));
		CPU0.ICCEOIR = CPU0.ICCEOIR & (~(0x3FF << 0)) | (57);
		break;
	case 159:
		break;
	default:
		break;
	}
}
