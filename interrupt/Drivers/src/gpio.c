#include<stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "gpio.h"
void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}
	else
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}

}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}

void GPIO_pull_up_down_mode (GPIO_TypeDef * GPIOx,char pin,char state){
	switch(state){
	//No pull-up, pull-down
	case 0:
		GPIOx->PUPDR &=~(1u<<(2*pin));
		GPIOx->PUPDR &=~(1u<<(2*pin+1));
		break;
	//Pull-up
	case 1:
		GPIOx->PUPDR |=(1u<<(2*pin));
		GPIOx->PUPDR &=~(1u<<(2*pin+1));
		break;
	//Pull-down
	case 2:
		GPIOx->PUPDR &=~(1u<<(2*pin));
		GPIOx->PUPDR |=(1u<<(2*pin+1));
		break;
	}

}
uint32_t GPIO_read (GPIO_TypeDef * GPIOx,char pin){

	if (GPIOx->MODER & (1u<<(2*pin))){
		return(GPIOx->ODR &(1u<<pin));
	}
	else{
		return(GPIOx->IDR &(1u<<pin));
	}
}
int debounce(GPIO_TypeDef * GPIOx,char pin){
	int condition;

	if(GPIOx->IDR &(1u<<pin)){
		condition=1;
	}
	else{
		condition=0;
	}
	static uint16_t state=0x0000;
	state=(state<<1)|(condition)|0xfe00;
	return(state==0xff00);
}



