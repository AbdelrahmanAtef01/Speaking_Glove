#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include"util/delay.h"
#include"lcd_cfg.h"

void LCD_vidWriteData(uint8_t data)
{
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPortValue(LCD_Data_PORT,data);
	DIO_u8SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void LCD_vidWriteCmd(uint8_t command)
{
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPortValue(LCD_Data_PORT,command);
	DIO_u8SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void LCD_vidInit(void)
{
	DIO_u8SetPinMode(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_u8SetPinMode(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_u8SetPinMode(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	DIO_u8SetPortMode(LCD_Data_PORT,255);
	_delay_ms(40);
	LCD_vidWriteCmd(0b00111000);
	_delay_ms(2);
	LCD_vidWriteCmd(0b00001100);
	_delay_ms(2);
	LCD_vidWriteCmd(0b00000001);
	_delay_ms(2);
	LCD_vidWriteCmd(0b00000110);
}

void LCD_vidDisplayString(uint8_t * string)
{
	for(uint8_t i=0;string[i]!='\0';i++)
	{
		if(i==16)LCD_vidWriteCmd(0b11000000);
		LCD_vidWriteData(string[i]);
	}
}
void LCD_vidNewLine()
{
	LCD_vidWriteCmd(0b11000000);
}
void LCD_vidDisplayStringLeftShift(uint8_t* string)
{
	uint8_t i,y=0;
	for(i=0;string[i]!='\0';i++)
		{
			LCD_vidWriteData(string[i]);
		}
	while(1)
	{
		if((y%i)-16==0)LCD_vidWriteCmd(0b10000000);
		LCD_vidWriteCmd(0b00011000);
		_delay_ms(500);
		y++;
	}
}

void LCD_vidDisplayStringRightShift(uint8_t* string)
{
	uint8_t i,y=0;
	for(i=0;string[i]!='\0';i++)
		{
			LCD_vidWriteData(string[i]);
		}
	while(1)
	{
		if((y%i)-16==0)LCD_vidWriteCmd(0b10000000);
		LCD_vidWriteCmd(0b00011100);
		_delay_ms(500);
		y++;
	}
}

void LCD_vidClearDisplay()
{
	LCD_vidWriteCmd(0b00000001);
}

void LCD_vidGoTo(uint8_t x,uint8_t y)
{
	if(x==1&&y<=39)LCD_vidWriteCmd((0b10000000+y));
	else if(x==2&&(y+64)<103) LCD_vidWriteCmd((0b11000000+y));
}

void LCD_vidSetCursor(uint8_t x,uint8_t y)
{
	LCD_vidGoTo(x,y);
	LCD_vidWriteCmd(0b00001111);
}

void LCD_vidWriteInteger(uint16_ number)
{
	uint16_ num_mask=number,p=1;
	uint8_t i=0;
	sint8_t nxtl;
	if(num_mask==0)LCD_vidWriteData('0');
	for(;num_mask!=0;i++)
	{
		num_mask/=10;
		p*=10;
	}

	p/=10;
	nxtl = i - 16;
	if(nxtl < 0) nxtl =0;
	for(;i>0;i--)
	{
		if(i==nxtl)LCD_vidWriteCmd(0b11000000);
		num_mask= (uint8_t)(number/p);
		LCD_vidWriteData((uint8_t)'0'+num_mask);
		number -= num_mask*p;
		p/=10;
	}
}
