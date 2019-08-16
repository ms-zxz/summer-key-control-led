#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"


 int main(void)
 {
 	vu8 key=0;	
	u16 a,b,i;
	delay_init();	                             //延时函数初始化	  
 	LED_Init();			                         //LED端口初始化
	KEY_Init();                                  //初始化与按键连接的硬件接口
	
	 a=5200;
	 b=4800;                                     //初始a,b的时间值
	 
	 LED0=0;
	 LED1=0;                                     //初始LED0，LED1常亮
	 
	while(1)
	{
 		key=KEY_Scan(0);                         //扫描得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	                 //跑马灯	 
				   while(1)
						{
							 LED0=1;
							 LED1=0;
							 delay_ms(200);
							 if(KEY1==0)
					         break;
							 
							 LED0=0;
							 LED1=1;
							 delay_ms(200);				
							 if(KEY1==0)
					         break;
						}

						break;
						
				case KEY0_PRES:	                  //呼吸灯
				   while(1)
						{
							for(i=0;i<=a;i++)     //缓亮
								{
									LED0=0;
									LED1=0;
								delay(i);	
									LED0=1;
									LED1=1;
								delay(a-i);
								
								if(KEY0==0)
								break;
						    	}
								
							for(i=0;i<b;i++)      //缓灭
								{
									LED0=0;
									LED1=0;
								delay(b-i);	
									LED0=1;
									LED1=1;
								delay(i);
								
								if(KEY0==0)
								break;
						    	}
						} 
			}
		}
	    else delay_ms(10); 
	}	 
}

