#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
u16 dely;
s8 cnt,key_pin=0,i=0;
sbit LED = P1^4;
sbit sw= P3^2;
	

main()
{
	s8 ch;
	LCD_Init();
	LCD_cmd(0x80);

	while(1){
  LCD_cmd(0x80);
	
	Row_Init();
	while(ColStatus());
	ch=KeyScan();//ch given key num
    ch+=48;
    LCD_char(ch);
	}//while
}//main