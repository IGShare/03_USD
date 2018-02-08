/*
 * PWBD_TWI.cpp
 *
 * Created: 2018-01-08 오전 11:18:39
 * Author : myeom
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h>

#include "i2c_master.h"

#define TPL0102_00 0x50
#define TPL0102_01 0x57

#define TPL0102_00_WRITE	0xA0
#define TPL0102_00_READ		0xA1

#define TPL0102_01_WRITE	((TPL0102_01<<1) | I2C_WRITE)
#define TPL0102_01_READ		((TPL0102_01<<1) | I2C_READ)


void TPL0102_WriteEnable(void){

	i2c_start(TPL0102_01_WRITE);
	i2c_write(0x40);
	i2c_write(0x00);
	i2c_stop();
}

void SET_TPL0102_00(void){

	i2c_start(TPL0102_00_WRITE);
	i2c_write(0x00);
	i2c_write(0x80);
	i2c_stop();
	
	i2c_start(TPL0102_00_WRITE);
	i2c_write(0x01);
	i2c_write(0x1F);
	i2c_stop();
}

void SET_TPL0102_01(void){

	i2c_start(TPL0102_01_WRITE);
	i2c_write(0x00);
	i2c_write(0x80);
	i2c_stop();
	
	i2c_start(TPL0102_01_WRITE);
	i2c_write(0x01);
	i2c_write(0x1F);
	i2c_stop();
}

void GET_TPL0102_00(void){
	i2c_start(TPL0102_00_WRITE);
	i2c_write(0x00);
	i2c_stop();
	
	i2c_start(TPL0102_00_READ);
	i2c_read_nack();
	i2c_stop();
}

void PortInit()
{
	//DDRA = (0<<DDB7)|(0<<DDB6)|(0<<DDB5)|(0<<DDB4)|(0<<DDB3)|(0<<DDB2)|(0<<DDB1)|(0<<DDB0);
	DDRB = (0<<DDB7)|(0<<DDB6)|(0<<DDB5)|(0<<DDB4)|(0<<DDB3)|(1<<DDB2)|(1<<DDB1)|(0<<DDB0);
	DDRC = (0<<DDB7)|(0<<DDB6)|(0<<DDB5)|(0<<DDB4)|(1<<DDB3)|(1<<DDB2)|(0<<DDB1)|(0<<DDB0);
	DDRD = (0<<DDB7)|(0<<DDB6)|(0<<DDB5)|(1<<DDB4)|(1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0);
	//PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
}



//float getHeading(void){
//
	//i2c_start(TPL0102_00_WRITE);
	//i2c_write(0x03); // set pointer to X axis MSB
	//i2c_stop();
//
	//i2c_start(TPL0102_00_READ);
//
	//raw_x = ((uint8_t)i2c_read_ack())<<8;
	//raw_x |= i2c_read_ack();
//
	//raw_z = ((uint8_t)i2c_read_ack())<<8;
	//raw_z |= i2c_read_ack();
//
	//raw_y = ((uint8_t)i2c_read_ack())<<8;
	//raw_y |= i2c_read_nack();
//
	//i2c_stop();
//
	//return 0;
//}

int main(void){
	
	PortInit();
	//i2c_init();
	//TPL0102_WriteEnable();
	//SET_TPL0102_00();
	//SET_TPL0102_01();
	//init_TPL0102();
	
	//i2c_start(TPL0102_00_WRITE);
	//i2c_write(0x00);
	//i2c_stop();
	
	//PORTB = (0<<PB7)|(0<<PB6)|(0<<PB5)|(0<<PB4)|(0<<PB3)|(1<<PB2)|(1<<PB1)|(0<<PB0);
	//PORTC = (0<<PC7)|(0<<PC6)|(0<<PC5)|(0<<PC4)|(1<<PC3)|(1<<PC2)|(0<<PC1)|(0<<PC0);
	PORTD = (0<<PD7)|(0<<PD6)|(0<<PD5)|(1<<PD4)|(1<<PD3)|(1<<PD2)|(1<<PD1)|(1<<PD0);
	
	
	while(1){
		//TPL0102_WriteEnable();
		//GET_TPL0102_00();
		//_delay_ms(10);
	}
	
	return 0;
}
