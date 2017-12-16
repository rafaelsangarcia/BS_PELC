
#include "PWM.h"

uint16_t CurrentCaptureVal = 0;
uint16_t PriorCaptureVal = 0;
uint16_t DeltaCapture = 0;
void FTM0_init(void) {
	PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK; /* Ensure clk disabled for config */
	PCC->PCCn[PCC_FTM0_INDEX] |= PCC_PCCn_PCS(0b001)/* Clock Src=1, 8 MHz SOSCDIV1_CLK */
				| PCC_PCCn_CGC_MASK; /* Enable clock for FTM regs */
	FTM0->MODE |= FTM_MODE_WPDIS_MASK; /* Write protect to registers disabled (default) */
	FTM0->SC = 0x003F0007; /*Enable all the channels in PWM (0,1,2,3,4,5)*/
						   /* TOIE (Timer Overflow Interrupt Ena) = 0 (default) */
						   /* CPWMS (Center aligned PWM Select) = 0 (default, up count) */
						   /* CLKS (Clock source) = 0 (default, no clock; FTM disabled) */
						   /* PS (Prescaler factor) = 7. Prescaler = 128 */
	FTM0->COMBINE = 0x00000000;/* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0 */
	FTM0->POL = 0x00000000; /* Polarity for all channels is active high (default) */
	FTM0->MOD = 1251 ; /* 62500 FTM1 counter final value (used for PWM mode) */
	/* FTM1 Period = MOD-CNTIN+0x0001 ~= 62500 ctr clks */
	/* 8MHz /128 = 62.5kHz -> ticks -> 1Hz */
}

void FTM0_CH_PWM_init(void) {
	FTM0->CONTROLS[5].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[4].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[3].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[2].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[1].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[0].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
}


void start_FTM0_counter (void) {
	FTM0->SC |= FTM_SC_CLKS(3);
}
