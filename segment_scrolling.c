#include<reg51.h>
#define SEG_DATA P2
sbit SEG_1 = P1^0;
sbit SEG_2 = P1^1;
sbit SEG_3 = P1^2;
sbit SEG_4 = P1^3;
void delay_ms(unsigned int i)
{
	unsigned int j;
	for(i;i>0;i--)
		for(j=121;j>0;j--);
}
main()
{
	signed int i=0,j=0;
	code char a[]={0XFF,0XFF,0XFF,0X89,0X86,0XC7,0X8C,0XFF,0XC1,0X92,0XFF,0XFF,0XFF};// HELP US scrolling display
	//code char c[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X98}; //for 0 to 9 digits


	while(1){
			for(i=0;i<10;i++)//outer for loop is scrolling
			{//inner for loop is displaying 7 seg data at a time
				for(j=150;j>0;j--)
				{
				 SEG_DATA = a[i+0];
				 SEG_1=0;
				 delay_ms(1);
				 SEG_1=1;
				
				 SEG_DATA = a[i+1];
				 SEG_2=0;
				 delay_ms(1);
				 SEG_2=1;
				
				 SEG_DATA = a[i+2];
				 SEG_3=0;
				 delay_ms(1);
				 SEG_3=1;
				
				 SEG_DATA = a[i+3];
				 SEG_4=0;
				 delay_ms(1);
				 SEG_4=1;
					}
	  
			}
		}
}