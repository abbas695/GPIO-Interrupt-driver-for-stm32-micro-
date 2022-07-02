/*
 * interrupt.c

 *
 *  Created on: May 27, 2022
 *      Author: win10
 */
#include<stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "interrupt.h"
void interrupt_init(char enable_pin,char exti_num,char port_num,char edge_type){
	RCC->APB2ENR|=(1u<<enable_pin);

	if(exti_num<=3 && exti_num>=0){
		SYSCFG->EXTICR[0] &=~(15<<(exti_num*4));
		SYSCFG->EXTICR[0] |=(port_num<<(exti_num*4));
	}
	else if(exti_num<=7 && exti_num>=4){
		exti_num=exti_num % 4;
		SYSCFG->EXTICR[1] &=~(15<<(exti_num*4));
		SYSCFG->EXTICR[1] |=(port_num<<(exti_num*4));
	}
	else if(exti_num<=11 && exti_num>=8){
		exti_num=exti_num % 8;
		SYSCFG->EXTICR[2] &=~(15<<(exti_num*4));
		SYSCFG->EXTICR[2] |=(port_num<<(exti_num*4));
	}
	else if(exti_num<=15 && exti_num>=12){
		exti_num=exti_num % 12;
		SYSCFG->EXTICR[3] &=~(15<<(exti_num*4));
		SYSCFG->EXTICR[3] |=(port_num<<(exti_num*4));
	}
	EXTI->IMR |=(1u<<exti_num);
	if(edge_type==1){
		EXTI->RTSR |=(1u<<exti_num);
	}
	else{
	EXTI->FTSR |=(1u<<exti_num);
	}
	NVIC->ISER[0] |=(1u<<(exti_num+6));

}

void interrupt_disable(char exti_num){
	NVIC->ICER[0] |=(1u<<(exti_num+6));
}
