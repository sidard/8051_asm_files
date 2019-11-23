#include<reg51.h>
sbit rs = P3^4;
sbit rw = P3^5;
sbit en = P3^6;
#define LCD_data P0

void delay_ms(unsigned int delay)
{
	unsigned int j;
	for(delay; delay>0;delay--)
	  for(j=121;j>0;j--);
}
	
void LCD_Init(void);
void LCD_cmd(char);
void LCD_disp(char);
void LCD_char(char);
void LCD_str(char*);

void UART_Init(void)
{
	SCON = 0x50;
	TMOD = 0X20;
	TH1= -3;
	TR1=1;
}

char UART_Rx(void)
{
   while(RI==0);
		 RI=0;
	  return (SBUF);
}
void UART_Tx(char ch)
{
	  SBUF=ch;
		while(TI==0);
	  TI=0;     
}

main()
{
	char j=0,i=0,tmp=0,ch,c[2]={0},d,o[2]={0};
	LCD_Init();
	LCD_cmd(0x80);
	LCD_str("Serial Comm");
	LCD_cmd(0xc0);
	UART_Init();
	while(1){
	ch=UART_Rx();
		//ch='B';
  d=ch;
	do
	{
		c[i]=d%10 + 48;
    i++;
		d/=10;
	}while(d);
  //c[i]= '\0';
	i--;
	do
	{
	LCD_char(c[i]);
	i--;
	}while(i!=-1);
 
	d=ch;
	o[j]=d%16 + 48;
	j++;
	o[j]=d/16 + 48;
  LCD_cmd(0xc3);
	do
	{
	LCD_char(o[j]);
	j--;
	}while(j!=-1);
  
		
	UART_Tx(ch);
	}
}
void LCD_cmd(char cmd)
{
	rs = 0;
	LCD_disp(cmd);
}
void LCD_disp(char cmd)
{
	rw =0;
	LCD_data = cmd;
	en = 1;
	en = 0;
	delay_ms(1);
}

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
	LCD_cmd(0x06);
	LCD_cmd(0x0f);		
}
void LCD_char(char ch)
{
	rs=1;
	LCD_disp(ch);
}

void LCD_str(char *s)
{
	int i=0 ;
	while(s[i]!='\0')
	{
		LCD_char(s[i]);
		i++;
	}
}