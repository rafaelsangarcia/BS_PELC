#include "ADC.h"

int dutyCycle, percentage;

void Control_ADC (void);
void Control_Duty (int);
void Control_ADC_clean_flag (void);
void PWM_0 (int channel);
