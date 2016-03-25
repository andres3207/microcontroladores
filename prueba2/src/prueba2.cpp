/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC43xx.h"
#endif

#include <cr_section_macros.h>

#if defined (__MULTICORE_MASTER_SLAVE_M0APP) | defined (__MULTICORE_MASTER_SLAVE_M0SUB)
#include "cr_start_m0.h"
#endif

// TODO: insert other include files here
#include "chip.h"
// TODO: insert other definitions and declarations here

#include "mis_funciones.h"
#include "configuraciones.h"

int main(void) {

    // Start M0APP slave processor
#if defined (__MULTICORE_MASTER_SLAVE_M0APP)
    cr_start_m0(SLAVE_M0APP,&__core_m0app_START__);
#endif

    // Start M0SUB slave processor
#if defined (__MULTICORE_MASTER_SLAVE_M0SUB)
    cr_start_m0(SLAVE_M0SUB,&__core_m0sub_START__);
#endif

    // TODO: insert code here
    Leds_Config();
    Inputs_Config();
    Timer1_Config();





    // Force the counter to be placed into memory
        volatile static int i = 0 ;
        // Enter an infinite loop, just incrementing a counter
        volatile static int i2 = 0 ;
        int j=0;

        while(1) {
            i++ ;
            /*if (i2==0){
            	Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
            	i2=1;
            }else{
            	Chip_GPIO_SetValue(LPC_GPIO_PORT, 0,(1<<14));
            	i2=0;
            }*/
         /*   while (j<1000000){
            	j++;
            }
            j=0;
            ActivarLeds(i);*/

        }
        return 0 ;
    }
