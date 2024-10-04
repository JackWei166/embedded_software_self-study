#include "exynos_4412.h"

int main(void){
	unsigned int AdcVal;

	ADCCON = ADCCON | (1 << 16);
	ADCCON = ADCCON | (1 << 14);
	ADCCON = ADCCON & (~(0xFF << 6)) | (19 << 6);
	ADCCON = ADCCON & (~(1 << 2)); 
	ADCCON = ADCCON & (~(1 << 1));
	ADCMUX = 3;

	while (1) {
		ADCCON = ADCCON | 1;
		while (!(ADCCON & (1 << 15)));
		AdcVal = ADCDAT & 0xFFF;
		AdcVal = AdcVal * 0.44;
		printf("AdcVal = %dmv\n", AdcVal);
	}

	return 0;
}
