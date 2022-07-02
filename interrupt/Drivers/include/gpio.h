/*
 * gpio.h
 *
 *  Created on: Apr 30, 2022
 *      Author: moham
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
void GPIO_pull_up_down_mode (GPIO_TypeDef * GPIOx,char pin,char state);
uint32_t GPIO_read (GPIO_TypeDef * GPIOx,char pin);
int debounce(GPIO_TypeDef * GPIOx,char pin);
void KeyPad_INIT();
void KeyPad_MANAGE();
char KeyPad_GET_VALUE();
void KeypadCallouts_KeyPressNotificaton();
#endif /* INCLUDE_GPIO_H_ */
