#define F_CPU 8000000
#include "ADC_INT.h"
#include "GIE_INT.h"
#include "led.h"

#include <util/delay.h>

u8 x = 0 ;

int main(void)
{
    /* General Interrupt Enable */
	
	GIE_vidEnable();
	
	/* ADC Enable */
	
	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidAutoTrigger();
	ADC_voidStartConversion();
	
	/* LED Enable */
	
	led_init();
	
    while (1) 
    {
			
		 x = ADC_u16ReadADC(0);
		 if (x != 0)
		 {
			 led_toggle(LED_RED);
		 }
		 else
		 {
			 led_on(LED_GREEN);
		 }
		 x=0 ;
		 ADC_voidStartConversion();
		 
    }
}