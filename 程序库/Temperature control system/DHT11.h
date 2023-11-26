#ifndef __DHT11_H__
#define __DHT11_H__

//其他包含头文件
#include<stm32f10x.h>

//函数声明
void Delay10us(void);
void delay(int ms);
void DHT11_Init(void);
void DHT11Out(void);
void DHT11In(void);
int DHT11_check(void);
int DHT11_Get_Data(u8 *tem,u8 *hum);
int DHT11_GetData(void);
//宏定义
//结构体模板定义
#endif
