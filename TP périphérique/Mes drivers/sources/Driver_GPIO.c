//driver.c 
#include "stm32f10x.h"

#include "Driver_GPIO.h"

//RCC-> APP2ENR| = (0 × 01 << 2)|(0 × 01 << 3)|(0 × 01 << 4) 

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
	GPIO -> IDR & (0x0);
	
}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
		GPIO->BSRR = (0x01<<GPIO_Pin);
}
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
		GPIO->BRR = (0x01<<GPIO_Pin);
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
}

