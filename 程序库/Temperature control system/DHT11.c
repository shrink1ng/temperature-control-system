#include"DHT11.h"

void Delay10us(void)
{
	int i=100;
	while(i--);
}
void delay(int ms)
{
	while(ms--)
	{
		for(int i=0;i<8050;i++);
	}
}

void DHT11_Init(void)
{
	 int i=100;
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
	while(i--)
	delay(10);
}
void DHT11Out(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}
void DHT11In(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}
 int DHT11_check(void)
 {
	 again:
	 DHT11Out();
	 GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
	delay(20);
	 GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
	 delay(20);
	 GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
	 //输入模式
	 DHT11In();
	 Delay10us();
	 Delay10us();
	 Delay10us();
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==RESET)
		 {
			 while(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4));//等待结束
				while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4));
			 
			 return 0;//表示等待发送数据
		 }
		 else
		 {

			goto again;
		 }
 }
 
 int DHT11_Get_Data(u8 *tem,u8 *hum)
 {
	 int count=0;
	 u8 data[5]={0};
	 
	 u8 i;
	 
	 if(0 == DHT11_check())
	 {
		 for(i=0;i<40;i++)
		 {
			 while(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4));
			 count =0;
			 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4))
			 {
				 Delay10us();
				 count++;
			 }
			 if(count >5)
			 {
				 data[i/8]|=1<<(7-i%8);
			 }
		 }
		 Delay10us();
		 DHT11Out();
		 GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
		 if(data[4]!=(data[0]+data[1]+data[2]+data[3]))
		 {
			 return -1;
		 }
		 else
		 {
			 *tem=data[2];
			 *hum=data[0];
			 return 0;
		 }
	 }
	 return -1;
 }

int DHT11_GetData(void)
{
	 u8 tem;
	 u8 hum;
	 u8 temper;
	 if(DHT11_Get_Data(&tem,&hum)==0)
	{
		temper=tem;
	}
	return temper;
}
