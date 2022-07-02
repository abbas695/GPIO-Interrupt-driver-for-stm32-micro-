/*
 * interrupt.h
 *
 *  Created on: May 27, 2022
 *      Author: win10
 */

#ifndef INCLUDE_INTERRUPT_H_
#define INCLUDE_INTERRUPT_H_
void interrupt_init(char enable_pin,char exti_num,char port_num,char edge_type);
void interrupt_disable(char exti_num);

#endif /* INCLUDE_INTERRUPT_H_ */
