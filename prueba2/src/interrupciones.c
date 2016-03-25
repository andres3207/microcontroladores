/*
 * interrupciones.c
 *
 *  Created on: 25 de mar. de 2016
 *      Author: andres
 */

#include "chip.h"


void TIMER1_IRQHandler(void){
	static int i=0;
	if (Chip_TIMER_MatchPending(LPC_TIMER1, 1)) {
			Chip_TIMER_ClearMatch(LPC_TIMER1, 1);
			ActivarLeds(i);
		}
	i++;
}
