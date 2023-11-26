#include"stm32f10x.h"

void GPIOco(void)
{
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}
void GPIOrin(void)
{
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
int ADDkey()
{
	static int keybuf=1;
	static int back=1;
	static int cnt=0;
	static int temp1=1;

			GPIOco();
			GPIOrin();
			GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
			keybuf=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7);
			if(keybuf!=back)
			{
				delay(15);
				if(keybuf==GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7))
				{
					if(back==0)
					{
						temp1=0;
						cnt+=10;
					}
					else
						temp1=1;
					back=keybuf;
				}
			}
			return cnt;
}
int Deckey()
{
	static int keybuf=1;
	static int back=1;
	static int dec=0;
	static int temp2=1;

			GPIOco();
			GPIOrin();
			GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
			keybuf=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8);
			if(keybuf!=back)
			{
				delay(15);
				if(keybuf==GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8))
				{
					if(back==0)
					{
						temp2=0;
						dec+=10;
					}
					else
						temp2=1;
					back=keybuf;
				}
			}
			return dec;
}
int Keymode()
{
	static int keybuf=1;
	static int back=1;
	static int temp=1;

			GPIOco();
			GPIOrin();
			GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
			keybuf=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);
			if(keybuf!=back)
			{
				delay(15);
				if(keybuf==GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6))
				{
					if(back==0)
					{
						temp=!temp;
					}
					back=keybuf;
				}
			}
			return temp;
}
