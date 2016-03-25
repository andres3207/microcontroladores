/*
 * mis_funciones.c
 *
 *  Created on: 25 de mar. de 2016
 *      Author: andres
 */
#include "chip.h"

void ActivarLeds(int valor){
	if((valor & (1<<0))==(1<<0)){
		Chip_GPIO_SetValue(LPC_GPIO_PORT, 5,(1<<0));
	}else{
		Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0));
	}
	if((valor & (1<<1))==(1<<1)){
			Chip_GPIO_SetValue(LPC_GPIO_PORT, 5,(1<<1));
		}else{
			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<1));
		}
	if((valor & (1<<2))==(1<<2)){
			Chip_GPIO_SetValue(LPC_GPIO_PORT, 5,(1<<2));
		}else{
			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<2));
		}
	if((valor & (1<<3))==(1<<3)){
			Chip_GPIO_SetValue(LPC_GPIO_PORT, 0,(1<<14));
		}else{
			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
		}
	if((valor & (1<<4))==(1<<4)){
			Chip_GPIO_SetValue(LPC_GPIO_PORT, 1,(1<<11));
		}else{
			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<11));
		}
	if((valor & (1<<5))==(1<<5)){
			Chip_GPIO_SetValue(LPC_GPIO_PORT, 1,(1<<12));
		}else{
			Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<12));
		}

}



