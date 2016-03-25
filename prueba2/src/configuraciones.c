/*
 * configuraciones.c
 *
 *  Created on: 25 de mar. de 2016
 *      Author: andres
 */

#include "chip.h"

void Timer1_Config(void){
	#define TICKRATE_HZ 1
    uint32_t timerFreq;
    /* Enable timer 1 clock and reset it */
    Chip_TIMER_Init(LPC_TIMER1);
    Chip_RGU_TriggerReset(RGU_TIMER1_RST);
    while (Chip_RGU_InReset(RGU_TIMER1_RST)) {}

    /* Get timer 1 peripheral clock rate */
    timerFreq = Chip_Clock_GetRate(CLK_MX_TIMER1);

    /* Timer setup for match and interrupt at TICKRATE_HZ */
    Chip_TIMER_Reset(LPC_TIMER1);
    Chip_TIMER_MatchEnableInt(LPC_TIMER1, 1);
    Chip_TIMER_SetMatch(LPC_TIMER1, 1, (timerFreq / TICKRATE_HZ));
    Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 1);
    Chip_TIMER_Enable(LPC_TIMER1);

    /* Enable timer interrupt */
    NVIC_EnableIRQ(TIMER1_IRQn);
    NVIC_ClearPendingIRQ(TIMER1_IRQn);
}

void Leds_Config(void){
	/* LEDs */
	       Chip_SCU_PinMux(2,0,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[0], LED0R */
	       Chip_SCU_PinMux(2,1,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[1], LED0G */
	       Chip_SCU_PinMux(2,2,MD_PUP|MD_EZI,FUNC4);  /* GPIO5[2], LED0B */
	       Chip_SCU_PinMux(2,10,MD_PUP|MD_EZI,FUNC0); /* GPIO0[14], LED1 */
	       Chip_SCU_PinMux(2,11,MD_PUP|MD_EZI,FUNC0); /* GPIO1[11], LED2 */
	       Chip_SCU_PinMux(2,12,MD_PUP|MD_EZI,FUNC0); /* GPIO1[12], LED3 */

	       Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2),1);
	       Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<14),1);
	       Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<11)|(1<<12),1);

	       Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2));
	       Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
	       Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<11)|(1<<12));
}
