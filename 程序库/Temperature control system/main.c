#include "Usart.h"
#include "DHT11.h"
#include "oled.h"
#include "motor.h"
#include "Keymode.h"

 void OLED_show(int tem)
{
	
	OLED_ShowCHinese(24,2,1);
	OLED_ShowCHinese(40,2,2);
	OLED_ShowString(58,2,":",16);
	OLED_ShowNum(76,2,tem,2,16);
}
void LED_config()
{
	
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

}

int main()
{
	int dec1;
	int fol=19;
	LED_config();
	Usart(115200);
	DHT11_Init();
	OLED_Init();
	GPIO_Configuration();
   TIM_Configuration(1000,72);
	OLED_Clear();
	while(1)
	{
		if(Keymode()==1)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_13);
			OLED_show(DHT11_GetData());
			PWMAutoout(DHT11_GetData());
			delay(50);
		}
		else
		{
			fol=ADDkey();
			dec1=Deckey();
			fol=fol-dec1;
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);
			OLED_show(DHT11_GetData());
			TIM_SetCompare3(TIM2,10*fol);
			
				if(fol<=19)
				{
					fol=19;
				}
			}
			if(fol>=99)
				{
					fol=19;
				}
			delay(50);
		}
}
