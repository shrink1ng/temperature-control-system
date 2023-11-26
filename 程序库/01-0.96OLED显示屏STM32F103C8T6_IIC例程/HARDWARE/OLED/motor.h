#ifndef __MOTOR_H__
#define __MOTOR_H__


#include<stm32f10x.h>

void GPIO_Configuration(void);
void PWMAutoout(u16 temper);
void TIM_Configuration(u16 Per,u16 Pre);



#endif
