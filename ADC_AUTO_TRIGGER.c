#define F_CPU 8000000
#include "ADC_INT.h"
#include "GIE_INT.h"
#include "led.h"
#include "EXTI_INT.h"
#include "PUSH_BOTTUN_INT.h"
#include <util/delay.h>

int main(void)
{
    /* General Interrupt Enable */
	GIE_vidEnable();
	/* EXTI0 Interrupt Enable */
	EXTI0_voidInit();
	EXTI0_voidEnable();
	/* ADC Enable */
	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidAutoTrigger ();
	/* switch Enable */
	button_vidInit();
	/* LED Enable */
	led_init();
    while (1) 
    {
		 u8 x = 0;
		 x = ADC_u16ReadADC (0);
		 if (x != 0 )
		 {
		 led_toggle(LED_RED);
		 _delay_ms(100);
		 }
		 else 
		 {
			 led_on (LED_GREEN);
		 }
    }
}

