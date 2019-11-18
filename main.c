#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
sbit led = P3^0;

s8 flg=0,cnt,key_pin=0,i=0,cmd=0x80;

void ISR_TF (void) interrupt 1
{
	TF0=0;
	TR0=0;
  cmd=0x06;
	led=0;
}


sbit LED = P1^4;
sbit sw= P3^2;
code s8 c[][4]={{'1'},"ABC2","DEF3","GHI4","JKL5","MNO6","PQR7","STU8","VWX9","YZ*",{'0'},{'#'}};
	

main()
{
	s8 ch,prev='\0';
	LCD_Init();
	//interrupts initialization
	EA=1;
	ET0=1;
	//timers initialization
	TMOD = 0X01;


	while(1){
		LCD_cmd(cmd);
		TL0 = 0X00;
	  TH0 = 0XFF;
		Row_Init();
	while(ColStatus()==1)
	{
		TR0=1;
	}
	ch=KeyScan();//ch given key num
	if(ch != prev)
	{
		prev=ch;
		cnt=0;
		}
	else
	{
		goto sw;
	}
	
	
	sw:	switch(ch){
			
		//key 0
			case 0:
     				cnt++;//cnt gives exctly key pin to disply from loop up tble
		        if(cnt==1)
			      LCD_char(c[ch][cnt-1]);	
		        cnt=0;
	          break;
						 //key 9*/
			 	case 9:
		         cnt++;
	           if(cnt==1)
		         LCD_char(c[ch][cnt-1]);
             else if(cnt==2)
             LCD_char(c[ch][cnt-1]);
             else if(cnt==3)
             LCD_char(c[ch][cnt-1]);
	           else
		         cnt=0;
						 break;
						 //key 10
			  case 10:
				     cnt=0;
		         LCD_char(c[ch][cnt]);
						 break;
				case 11:
		         cnt=0;
		         LCD_char(c[ch][cnt]);  
						 break;
				default:
					  cnt++;
	           if(cnt==1)
		         LCD_char(c[ch][cnt-1]);
             else if(cnt==2)
             LCD_char(c[ch][cnt-1]);
             else if(cnt==3)
             LCD_char(c[ch][cnt-1]);
             else if(cnt==4) 
             LCD_char(c[ch][cnt-1]);
	           else
		         cnt=0;
						 break;
					 }//switch
	}//while
}//main