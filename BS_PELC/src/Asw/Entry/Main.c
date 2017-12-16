/*
 * Main implementation: use this 'C' sample to create your own application
 *
 */

#include "Std_Types.h"
#include "Port.h"
#include "Wdog.h"
#include "Nvic.h"
#include "Mcu.h"
#include "SchM.h"
#include "FlexCAN.h"
#include "PWM.h"
#include "ADC.h"


int main(void)
{

	WDOG_disable();
	//FLEXCAN0_init();         /* Init FlexCAN0 */
	PORT_init();             				/* Configure ports */
	SOSC_init_8MHz();        				/* Initialize system oscilator for 8 MHz xtal */
	SPLL_init_160MHz();      				/* Initialize SPLL to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz();   				/* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	FTM0_init(); /* Init FTM0 */
	FTM1_init(); /* Init FTM0 */
	FTM0_CH_PWM_init(); /* Init FTM0 CHANNELS, Ports with PWM channels*/
	FTM1_CH_PWM_init(); /* Init FTM0 CHANNELS, Ports with PWM channels*/
	start_FTM0_counter(); /* Start FTM0 counter */
	start_FTM1_counter(); /* Start FTM0 counter */
	ADC_init();            /* Init ADC resolution 12 bit*/
	FLEXCAN0_init();         /* Init FlexCAN0 */
	NVIC_init_IRQs();        				/* Enable desired interrupts and priorities */
	SchM_Init(&SchedulerConfig);			/* Scheduler Services Initialization */
	SchM_Start();							/* Start Scheduler Services */


	/* Further code should not be reached */
	for(;;) {

	}

	return (0);
}
