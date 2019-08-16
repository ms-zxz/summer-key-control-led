#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
	 
#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)   //��ȡKEY0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)   //��ȡKEY1

#define KEY0_PRES 	1	                                //KEY0����
#define KEY1_PRES	2	                                //KEY1����

void KEY_Init(void);                                    //IO��ʼ��
u8 KEY_Scan(u8);                                     	//����ɨ��				    
#endif
