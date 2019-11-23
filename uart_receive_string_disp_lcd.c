#include<reg51.h>
#include"lcd.h"
#include"delay.h"
#include"types.h"
sbit led = P1^0;
s8 i=0,c[10]={0};
void UART_Init(void)
{
	SCON = 0X50;
	TMOD = 0X20;
	TH1= -3;
	TR1=1;
}

void  ISR_SER(void) interrupt 4
{
	
	RI=0;
	c[i]=SBUF;
  LCD_cmd(0xc0);
  if((c[i]!='#')&&(i<9))
	   i++;
	else
	{
		c[i]='\0';
		i=0;
	do{
		LCD_char(c[i]);
		i++;
	}while(c[i]!='\0');
	}
}
main()
{
	UART_Init();
	LCD_Init();
	LCD_cmd(0x80);
	LCD_str("sid...");
	
	EA=1;
	ES=1;
	while(1)
	{
		led = ~led;
    delay_ms(500);
	}
	
}
