#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

void KEY_Init(void)                                          //IO初始化
	{ 
		GPIO_InitTypeDef GPIO_InitStructure;
	 
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);  //PORTE时钟

		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4; //KEY0-KEY1
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //设置成上拉输入
		GPIO_Init(GPIOE, &GPIO_InitStructure);                //初始化GPIOE3,4
	}
															 //mode:0,不支持连续按;1,支持连续按;
															 //0,没有任何按键按下,1,KEY0按下,2,KEY1按下
u8 KEY_Scan(u8 mode)
	{	 
		static u8 key_up=1;                                  //按键按松开标志
		if(mode)key_up=1;                                    //支持连按		  
		if(key_up&&(KEY0==0||KEY1==0))
		{
			delay_ms(10);                                    //去抖动 
			key_up=0;
			if(KEY0==0)return KEY0_PRES;
			else if(KEY1==0)return KEY1_PRES;
		}else if(KEY0==1&&KEY1==1)key_up=1; 	    
		return 0;                                            // 无按键按下
	}
