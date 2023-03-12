/*****************************************************************/
/* 	Author 	 	 : Mustafa Kazem                            */
/* 	Date   		 : 25 February 2023                            */
/* 	Version 	 : 1V 								          */
/* 	Description	 : prog.c for ADC                            */
/************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_Types.h"
#include "Bit_Math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h" 
#include "dio.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	/*To select Right or Left ADJS*/
	#if (ADJ == LEFT_ADJUSTMENT)
	SET_BIT (ADMUX , ADLAR); /*Left Adjustment*/
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,INPUT);
	
	#elif (ADJ == RIGHT_ADJUSTMENT)
	CLEAR_BIT (ADMUX , ADLAR); 
    dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,INPUT);
	#endif
	
	/*To select the Voltage Source*/
	#if (VOLTAGE_SOURCE == AVCC)
	SET_BIT (ADMUX,REFS0);
	CLEAR_BIT (ADMUX,REFS1);
	#elif (VOLTAGE_SOURCE == AREF)
	CLEAR_BIT (ADMUX,REFS0);
	CLEAR_BIT (ADMUX,REFS1);
	#elif (VOLTAGE_SOURCE == INTERNAL)
	SET_BIT (ADMUX,REFS0);
	SET_BIT (ADMUX,REFS1);
	#endif
	
	
	
	ADC_voidAutoTrigger();
	/*Prescaler*/

	#if (ADC_PRESCALLER == DIVID_BY_2)
	SET_BIT (ADCSRA,ADPS0);
	CLEAR_BIT (ADCSRA,ADPS1);
	CLEAR_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_4 )
	CLEAR_BIT (ADCSRA,ADPS0);
	SET_BIT (ADCSRA,ADPS1);
	CLEAR_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_8 )
	SET_BIT (ADCSRA,ADPS0);
	SET_BIT (ADCSRA,ADPS1);
	CLEAR_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_16 )
	CLEAR_BIT (ADCSRA,ADPS0);
	CLEAR_BIT (ADCSRA,ADPS1);
	SET_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_32 )
	SET_BIT (ADCSRA,ADPS0);
	CLEAR_BIT (ADCSRA,ADPS1);
	SET_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_64 )
	CLEAR_BIT (ADCSRA,ADPS0);
	SET_BIT (ADCSRA,ADPS1);
	SET_BIT (ADCSRA,ADPS2);
	
	#elif (ADC_PRESCALLER == DIVID_BY_128 )
	SET_BIT (ADCSRA,ADPS0);
	SET_BIT (ADCSRA,ADPS1);
	SET_BIT (ADCSRA,ADPS2);
	
	#endif
	/*Enable Interrupt*/
	SET_BIT (ADCSRA,ADIE);
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , ADEN );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , ADIE );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , ADEN );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , ADSC );
	
}

/****************************************************************/
/* Description    : This function used to select which auto 
                             is used .      					*/ 
/*																*/
/*					Inputs : void				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
	
    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , ADTS0);
	CLEAR_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}

/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting       	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADC (u8 ADC)
{

	ADMUX &=0b11100000  ;  /*Clear The Channels*/
	                       
	ADMUX |= ADC; /* select the channel by MUX 0 -> MUX 4*/
	//wait for the conversion
	while(CHECK_BIT(ADCSRA,ADSC)==0);
	SET_BIT (ADCSRA,ADIF);
	u16 y = ADCL ;
	return y;
}



/*****************************************************
                    CallBack Func
******************************************************/

void (*PVidADC_CallBack)(u16 x)= NULL ;


void ADC_VidSetCallBack(void (*Copy_PVidCallBack)(u16))
{
	PVidADC_CallBack=Copy_PVidCallBack;
}
void __vector_16(void) __attribute__(( signal , used ));
void __vector_16(void)
{
	
	PVidADC_CallBack((ADCL));
}
