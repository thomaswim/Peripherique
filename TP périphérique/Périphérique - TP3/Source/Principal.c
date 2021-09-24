#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

	
unsigned short int  loulou;

		MyGPIO_Struct_TypeDef PA5 ;
	  MyTimer_Struct_TypeDef Timer2;


	
	void IT_function ( void )
	{
		MyGPIO_Struct_TypeDef PA5 ;
		PA5.GPIO = GPIOA ;
		PA5.GPIO_Pin = 5 ;
		PA5.GPIO_Conf = Out_Ppull ;
		
		TIM2->SR &=~(0x01 << 0); 
		MyGPIO_Toggle(PA5.GPIO,5); 
	}
		

int main ( void )
{
		//MyGPIO_Struct_TypeDef PC13 ;

	
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ; 
		RCC->APB1ENR |= (0x01<<0);
		
	Timer2.Timer = TIM2;
	Timer2.ARR=65454;
	Timer2.PSC=550;
	
	
		PA5.GPIO = GPIOA ;
		PA5.GPIO_Pin = 5 ;
		PA5.GPIO_Conf = Out_Ppull ;
	MyGPIO_Init ( &PA5 );
	
	MyTimer_Base_Init ( &Timer2 );
	MyTimer_Base_Start(Timer2.Timer);
	MyTimer_ActiveIT(Timer2.Timer,8, &IT_function); 
	
	
	do
{
	
	
	loulou=TIM2->CNT;
	
		
	

	
	
}while(1) ;
}
