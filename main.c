#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"


 int main(void)
 {
 	vu8 key=0;	
	u16 a,b,i;
	delay_init();	                             //��ʱ������ʼ��	  
 	LED_Init();			                         //LED�˿ڳ�ʼ��
	KEY_Init();                                  //��ʼ���밴�����ӵ�Ӳ���ӿ�
	
	 a=5200;
	 b=4800;                                     //��ʼa,b��ʱ��ֵ
	 
	 LED0=0;
	 LED1=0;                                     //��ʼLED0��LED1����
	 
	while(1)
	{
 		key=KEY_Scan(0);                         //ɨ��õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	                 //�����	 
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
						
				case KEY0_PRES:	                  //������
				   while(1)
						{
							for(i=0;i<=a;i++)     //����
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
								
							for(i=0;i<b;i++)      //����
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

