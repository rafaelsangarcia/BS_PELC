#include "ADC_Manager.h"

int i=0;

void Control_ADC (void) {
	convertAdcChan(12);
	while(adc_complete()==0){}
	i = (1251*percentage)/100;             //(read_adc_chx()*1251)/5000;
}

void Control_ADC_clean_flag (void) {
	convertAdcChan(29);                   /* Convert chan 29, Vrefsh */
	while(adc_complete()==0){}            /* Wait for conversion complete flag */
	i = read_adc_chx();       /* Get channel's conversion results in mv */
}

/*
  FTM0->CONTROLS[0].CnV = i;
			/*FTM0->CONTROLS[5].CnV = i;
			FTM0->CONTROLS[2].CnV = i;
			FTM0->CONTROLS[3].CnV = i;
			FTM0->CONTROLS[4].CnV = i;
			FTM0->CONTROLS[1].CnV = i;
			FTM1->CONTROLS[0].CnV = i;
			FTM1->CONTROLS[1].CnV = i;*/
