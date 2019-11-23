#include<reg51.h>
#include"lcd.h"
#include"delay.h"
#include"types.h"
sbit led= P1^0;

void INTO_ISR(void) interrupt 0
{
	s8 i=0;
	LCD_str("S");
	while(i<=16){
		LCD_cmd(0x1c);
		delay_ms(500);
		i++;
	}
	
}
main()
{
	LCD_Init();
	EA=1;
	EX0=1;
	IT0=1;
	while(1)
	{
		led = ~led;
	}
}