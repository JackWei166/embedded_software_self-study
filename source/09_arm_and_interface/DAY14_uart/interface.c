#include "exynos_4412.h"

void UART_Init(void);
char UART_Rec_Byte(void);
void UART_Send_Byte(char Dat);
void UART_Send_Str(char *ps);

int main(void){
	char RecDat = 0;

	UART_Init();

	while (1) {
		RecDat = UART_Rec_Byte();

		if (RecDat == 0) {
			//no operation
		} else {
			RecDat++;
			UART_Send_Byte(RecDat);
		}
	}
	
	UART_Send_Str("Hello, World!");

	return 0;
}

void UART_Init(void){
	GPA1.CON = GPA1.CON & (~(0xFF << 0)) | (0x22 << 0);
	UART2.ULCON2 = UART2.ULCON2 & (~(0x7F << 0)) | (0x3 << 0);
	UART2.UCON2 = UART2.UCON2 & (~(0xF << 0)) | (0x5 << 0);
	UART2.UBRDIV2 = 53;
	UART2.UFRACVAL2 = 4;
}

void UART_Send_Byte(char Dat){
	while (!(UART2.UTRSTAT2 & (1 << 1)));
	UART2.UTXH2 = Dat;
}

char UART_Rec_Byte(void){
	if (UART2.UTRSTAT2 & 1) {
		return UART2.URXH2;
	} else {
		return 0;
	}
}

void UART_Send_Str(char *ps){
	while (*ps != '\0') {
		UART_Send_Byte(*ps++);
	}
}
