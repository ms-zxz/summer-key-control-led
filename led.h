#ifndef LED_H 
#define LED_H 
#include "sys.h"         //LED 端口定义

#define LED0 PBout(5)    // PB5
#define LED1 PEout(5)    // PE5 
void LED_Init(void);     //初始化

#endif
