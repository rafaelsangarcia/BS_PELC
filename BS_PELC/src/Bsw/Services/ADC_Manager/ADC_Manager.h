#include "ADC.h"

int dutyCycle, value;
//percentage;

void Control_ADC (int);
void Control_ADC_clean_flag (void);
void PWM_0 (int channel);
int Sensor(void);
