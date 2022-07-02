
#include<stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "gpio.h"
const int no_raws = 4;
const int no_cols = 3;
char rows[4]={12,13,14,15}; //fill the array
char cols[3]={4,5,6}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

char currentvalue;


void KeyPad_INIT(void)
{
	GPIO_Init(GPIOB,12,0,1);
	GPIO_Init(GPIOB,13,0,1);
	GPIO_Init(GPIOB,14,0,1);
	GPIO_Init(GPIOB,15,0,1);

	GPIO_Init(GPIOB,4,1,1);
	GPIO_Init(GPIOB,5,1,1);
	GPIO_Init(GPIOB,6,1,1);

	GPIO_Init(GPIOB,0,1,1);
	GPIO_Init(GPIOB,1,1,1);
	GPIO_Init(GPIOB,2,1,1);
	GPIO_Init(GPIOB,3,1,1);


	GPIO_pull_up_down_mode(GPIOB,12,2);
	GPIO_pull_up_down_mode(GPIOB,13,2);
	GPIO_pull_up_down_mode(GPIOB,14,2);
	GPIO_pull_up_down_mode(GPIOB,15,2);
}

void KeyPad_MANAGE(void)
{

	for(int i=0;i<3;i++){
		GPIO_Write(GPIOB,cols[i],1);

		for(int j=0;j<4;j++){
			if(GPIO_read(GPIOB,rows[j])){
				while(GPIO_read(GPIOB,rows[j]));

				if(lookupTable[j][i]<=9 && lookupTable[j][i]>=0 ){
					currentvalue=lookupTable[j][i];
					KeypadCallouts_KeyPressNotificaton();
				}
			}
		}
		GPIO_Write(GPIOB,cols[i],0);
	}
}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	switch(KeyPad_GET_VALUE()){
	case 0:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,0);
		break;
	case 1:
		GPIO_Write(GPIOB,0,1);
				GPIO_Write(GPIOB,1,0);
				GPIO_Write(GPIOB,2,0);
				GPIO_Write(GPIOB,3,0);
				break;
	case 2:
		GPIO_Write(GPIOB,0,0);
				GPIO_Write(GPIOB,1,1);
				GPIO_Write(GPIOB,2,0);
				GPIO_Write(GPIOB,3,0);
				break;
	case 3:
			GPIO_Write(GPIOB,0,1);
					GPIO_Write(GPIOB,1,1);
					GPIO_Write(GPIOB,2,0);
					GPIO_Write(GPIOB,3,0);
					break;
	case 4:
			GPIO_Write(GPIOB,0,0);
					GPIO_Write(GPIOB,1,0);
					GPIO_Write(GPIOB,2,1);
					GPIO_Write(GPIOB,3,0);
					break;
	case 5:
			GPIO_Write(GPIOB,0,1);
					GPIO_Write(GPIOB,1,0);
					GPIO_Write(GPIOB,2,1);
					GPIO_Write(GPIOB,3,0);
					break;
	case 6:
			GPIO_Write(GPIOB,0,0);
					GPIO_Write(GPIOB,1,1);
					GPIO_Write(GPIOB,2,1);
					GPIO_Write(GPIOB,3,0);
					break;
	case 7:
			GPIO_Write(GPIOB,0,1);
					GPIO_Write(GPIOB,1,1);
					GPIO_Write(GPIOB,2,1);
					GPIO_Write(GPIOB,3,0);
					break;
	case 8:
			GPIO_Write(GPIOB,0,0);
					GPIO_Write(GPIOB,1,0);
					GPIO_Write(GPIOB,2,0);
					GPIO_Write(GPIOB,3,1);
					break;
	case 9:
			GPIO_Write(GPIOB,0,1);
					GPIO_Write(GPIOB,1,0);
					GPIO_Write(GPIOB,2,0);
					GPIO_Write(GPIOB,3,1);
					break;
	}
}



