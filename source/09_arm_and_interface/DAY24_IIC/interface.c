#include "exynos_4412.h"

#define SMPLRT_DIV 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define PWR_MGMT_1 0x6B
#define SlaveAddress 0x68

void MPU6050_Init(void);
void iic_write(unsigned char slave_addr, unsigned char addr, unsigned char data);
unsigned char iic_read(unsigned char slave_addr, unsigned char addr);
void mydelay_ms(unsigned int time);

int main(void){
	unsigned char zvalue_h, zvalue_l;
	short int zvalue;

	GPB.CON = GPB.CON & (~(0xF << 12)) | (0x3 << 12);
	GPB.CON = GPB.CON & (~(0xF << 8)) | (0x3 << 8);
	MPU6050_Init();

	while (1) {
		zvalue_h = iic_read(SlaveAddress, GYRO_ZOUT_H);
		zvalue_l = iic_read(SlaveAddress, GYRO_ZOUT_L);
		zvalue = (zvalue_h << 8) | zvalue_l;

		printf("GYRO-Z: %d\n", zvalue);

		mydelay_ms(100);
	}

	return 0;
}

void MPU6050_Init(void){
	iic_write(SlaveAddress, PWR_MGMT_1, 0x00);
	iic_write(SlaveAddress, SMPLRT_DIV, 0x07);
	iic_write(SlaveAddress, CONFIG, 0x06);
	iic_write(SlaveAddress, GYRO_CONFIG, 0x18);
	iic_write(SlaveAddress, ACCEL_CONFIG, 0x0);
}

void iic_write(unsigned char slave_addr, unsigned char addr, unsigned char data){
	I2C5.I2CCON = I2C5.I2CCON | (1 << 6) | (1 << 5);

	I2C5.I2CSTAT = 0xd0;
	I2C5.I2CDS = slave_addr << 1;
	I2C5.I2CSTAT = 0xf0;
	while(!(I2C5.I2CCON & (1 << 4)));

	I2C5.I2CDS = addr;
	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));
	while(!(I2C5.I2CCON & (1 << 4)));

	I2C5.I2CDS = data;
	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));
	while(!(I2C5.I2CCON & (1 << 4)));

	I2C5.I2CSTAT = 0xd0;
	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));

	mydelay_ms(10);
}

unsigned char iic_read(unsigned char slave_addr, unsigned char addr){
	unsigned char data = 0;

	I2C5.I2CCON = I2C5.I2CCON | (1 << 6) | (1 << 5);

	I2C5.I2CSTAT = 0xd0;

	I2C5.I2CDS = slave_addr << 1;
	I2C5.I2CSTAT = 0xf0;
	while(!(I2C5.I2CCON & (1 <<4)));

	I2C5.I2CDS = addr;
	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));
	while(!(I2C5.I2CCON & (1 << 4)));

	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));

	I2C5.I2CDS = slave_addr << 1 | 0x01;
	I2C5.I2CSTAT = 0xb0;
	while(!(I2C5.I2CCON & (1 << 4)));

	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 7)) & (~(1 << 4));
	while(!(I2C5.I2CCON & (1 <<4)));
	data = I2C5.I2CDS;

	I2C5.I2CSTAT = 0x90;
	I2C5.I2CCON = I2C5.I2CCON & (~(1 << 4));
	mydelay_ms(10);

	return data;
}

void mydelay_ms(unsigned int time){
	int i, j;

	while (time--) {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 514; j++) {
				//no operation
			}
		}
	}
}
