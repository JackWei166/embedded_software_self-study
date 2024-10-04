#include "exynos_4412.h"

void Delay(unsigned int time);

int main(void){

	GPD0.CON = GPD0.CON & (~(0xF << 0)) | (0x2 << 0);
	PWM.TCFG0 = PWM.TCFG0 & (~(0xFF << 0)) | 99;
	PWM.TCFG1 = PWM.TCFG1 & (~(0xF << 0));
	PWM.TCON = PWM.TCON | (1 << 3);
	PWM.TCNTB0 = 2000;
	PWM.TCMPB0 = 1000;
	PWM.TCON = PWM.TCON | (1 << 1);
	PWM.TCON = PWM.TCON & (~(1 << 1));
	PWM.TCON = PWM.TCON | 1;

	while (1) {
		PWM.TCON = PWM.TCON | 1;
		Delay(1000000);
		PWM.TCON = PWM.TCON & (~(1 << 0));
		Delay(1000000);
	}

	return 0;
}

void Delay(unsigned int time){
	while(time--);
}
