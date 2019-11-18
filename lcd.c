#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"

#define lcd P0

sbit rs= P3^4;
sbit rw= P3^5;
sbit en= P3^6;
void LCD_Init(void)
{
	delay_ms(16);
	LCD_cmd(0x30);
	
	delay_ms(6);
	LCD_cmd(0x30);
	
	delay_ms(1);
	LCD_cmd(0x30);
	delay_ms(1);
	
	LCD_cmd(0x38);
	LCD_cmd(0x10);
	LCD_cmd(0x01);
	LCD_cmd(0x04);//cursor shift is 0x06
	LCD_cmd(0x0f);//cursor blink is OFF (0x0c) & for ONis (0x0f)
}
void LCD_disp(s8 val)
{
	rw=0;
	lcd=val;
	en=1;
	en=0;
	delay_ms(1);
}

void LCD_cmd(s8 cmd)
{
	rs=0;
	LCD_disp(cmd);
}

void LCD_char(s8 ch)
{
	rs=1;
	LCD_disp(ch);
}

