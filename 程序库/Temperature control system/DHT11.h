#ifndef __DHT11_H__
#define __DHT11_H__

//��������ͷ�ļ�
#include<stm32f10x.h>

//��������
void Delay10us(void);
void delay(int ms);
void DHT11_Init(void);
void DHT11Out(void);
void DHT11In(void);
int DHT11_check(void);
int DHT11_Get_Data(u8 *tem,u8 *hum);
int DHT11_GetData(void);
//�궨��
//�ṹ��ģ�嶨��
#endif
