#include "myheader.h"
#include "type.h"

void scrolling_led(u_8bit num)
{
   u_8bit i=8,j=8,num2,num3;
	  num^=0x0F;
		P0=num;
		num2=num;	
		while(i)
		{
			if(i--)
				{
			num2<<=1;
			P0=num2;
			}
		}
		P0=num;	
		num3=num;
		while(j--)
			{
				num3>>=1;
				P0=num3;
			}delay(5000);
		}