/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "interrupt.h"
#include "stm32f4xx.h"
void ISR_OF_EXTI0(void);
void ISR_OF_EXTI1(void);
void segment(void);
int counter =0;
			
int main(void)
{


	GPIO_Init (GPIOA,0,0,0);
	GPIO_Init (GPIOA,1,0,0);
	GPIO_pull_up_down_mode (GPIOA,0,1);
	GPIO_pull_up_down_mode (GPIOA,1,1);

	GPIO_Init (GPIOA,3,1,0);
	GPIO_Init (GPIOA,4,1,0);
	GPIO_Init (GPIOA,5,1,0);
	GPIO_Init (GPIOA,6,1,0);

	interrupt_init(14,0,0,0);
	interrupt_init(14,1,0,0);

}

void segment(void){
	switch(counter){
		case 0:
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,0);
			break;
		case 1:
			GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,0);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,0);
					break;
		case 2:
			GPIO_Write(GPIOA,3,0);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,0);
					break;
		case 3:
				GPIO_Write(GPIOA,3,1);
						GPIO_Write(GPIOA,4,1);
						GPIO_Write(GPIOA,5,0);
						GPIO_Write(GPIOA,6,0);
						break;
		case 4:
				GPIO_Write(GPIOA,3,0);
						GPIO_Write(GPIOA,4,0);
						GPIO_Write(GPIOA,5,1);
						GPIO_Write(GPIOA,6,0);
						break;
		case 5:
				GPIO_Write(GPIOA,3,1);
						GPIO_Write(GPIOA,4,0);
						GPIO_Write(GPIOA,5,1);
						GPIO_Write(GPIOA,6,0);
						break;
		case 6:
				GPIO_Write(GPIOA,3,0);
						GPIO_Write(GPIOA,4,1);
						GPIO_Write(GPIOA,5,1);
						GPIO_Write(GPIOA,6,0);
						break;
		case 7:
				GPIO_Write(GPIOA,3,1);
						GPIO_Write(GPIOA,4,1);
						GPIO_Write(GPIOA,5,1);
						GPIO_Write(GPIOA,6,0);
						break;
		case 8:
				GPIO_Write(GPIOA,3,0);
						GPIO_Write(GPIOA,4,0);
						GPIO_Write(GPIOA,5,0);
						GPIO_Write(GPIOA,6,1);
						break;
		case 9:
				GPIO_Write(GPIOA,3,1);
						GPIO_Write(GPIOA,4,0);
						GPIO_Write(GPIOA,5,0);
						GPIO_Write(GPIOA,6,1);
						break;
		}
}

void ISR_OF_EXTI0(void)
{

	if (counter==9){
		counter=0;
	}else {
		counter=counter+1;
	}

	segment();
}

void ISR_OF_EXTI1(void)
{
	if (counter==0){
		counter=9;
	}else {
		counter=counter-1;
	}
	segment();
}

void EXTI0_IRQHandler(void){

	interrupt_disable(1);
	ISR_OF_EXTI0();
	interrupt_init(14,1,0,0);
}

void EXTI1_IRQHandler(void){

	interrupt_disable(0);
	ISR_OF_EXTI1();
	interrupt_init(14,0,0,0);
}
