/****************************************************************/
/*   Author             :    Mustafa Kazem				    */
/*	 Date 				:    25 February 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							and Prescaller & Voltage Source 
                            Left or Right Adjusment & Auto Trigger
                        	source					[int.h] 	*/
/****************************************************************/



/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/


#ifndef _ADC_INT_H
#define _ADC_INT_H

/****************************************************************/	
/**                 Voltage Source      				   		*/
/****************************************************************/

#define AVCC 					5
#define AREF 					4
#define INTERNAL				2.56

#define NULL  0
/****************************************************************/	
/**                 Left & Right Adjusment     				    */
/****************************************************************/

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1

/****************************************************************/	
/**                           Prescaller    				    */
/****************************************************************/

#define DIVID_BY_2				1
#define DIVID_BY_4				2
#define DIVID_BY_8				3
#define DIVID_BY_16				4
#define DIVID_BY_32				5
#define DIVID_BY_64				6
#define DIVID_BY_128			7


/****************************************************************/	
/**                           Auto Trigger source  		        */
/****************************************************************/

#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7

/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void);




//****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable();


/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable();


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable();


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion();


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger();



/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 ADC);


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*						   [For External Interrupt Two ]									*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC       */
/*     				 initialized 							    */
/****************************************************************/

void ADC_VidSetCallBack(void (*Copy_PVidCallBack)(u16));

#endif 