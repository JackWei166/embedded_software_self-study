#include "exynos_4412.h"

int main(void){
	unsigned int NewSec, OldSec = 0;
	
	RTCCON = RTCCON | (1 << 0);
	RTC.BCDYEAR = 0x23;
	RTC.BCDMON = 0x12;
	RTC.BCDDAY = 0x7;
	RTC.BCDWEEK = 0x31;
	RTC.BCDHOUR = 0x23;
	RTC.BCDMIN = 0x59;
	RTC.BCDSEC = 0x50;
	RTCCON = RTCCON & (~(1 << 0));

	while (1) {
		NewSec = RTC.BCDSEC;

		if (NewSec != OldSec) {
			printf("20%x-%x-%x %x %x:%x:%x\n", RTC.BCDYEAR, RTC.BCDMON, RTC.BCDDAY, RTC.BCDWEEK, RTC.BCDHOUR, RTC.BCDMIN, RTC.BCDSEC);
			OldSec = NewSec;
		}
	}

	return 0;
}
