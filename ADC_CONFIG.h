/****************************************************************/
/*   Author             :    Mustafa Kazem				    */
/*	 Date 				:    25 February 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Configuration for ADC  	            */
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/


#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

/****************************************************************/
/**          Please choose the desired Voltage Reference		*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define VOLTAGE_SOURCE			AVCC

/****************************************************************/
/**          Please choose the desired ADJUSTMENT		    	*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/	
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJ				LEFT_ADJUSTMENT


/****************************************************************/
/** !comment : Please choose the desired Channel				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					 DIO_PIN0
                                             DIO_PIN1
                                             DIO_PIN2
                                             DIO_PIN3
                                             DIO_PIN4
                                             DIO_PIN5
                                             DIO_PIN6
                                             DIO_PIN7			*/	
/****************************************************************/

#define ADC_CHANNEL_NUMBER		DIO_PIN1


/*************************************************************************************/
/**        Please choose the desired Auto Trigger Source    */
/** 		   Auto Trigger Source  can be : 						*/
/*					    					  FREE_RUNNING_MODE 					*/
/*						    				  ANALOG_COMPARATOR						*/
/*							    	   		  EXTERNAL_INTERRPUT_REQUEST_0 			*/	
/*                                            TIMER_COUNTER_0_COMPARE_MATCH
                                              TIMER_COUNTER_0_OVERFLOW	
                                              TIMER_COUNTER_COMPARE_MATCH_B
                                              TIMER_COUNTER_1_OVERFLOW	
                                              TIMER_COUNTER_1_CAPTURE_EVENT         */
/*************************************************************************************/

#define ADC_AUTO_TRIGGER_SOURCE		EXTERNAL_INTERRPUT_REQUEST_0

/****************************************************************/
/** !comment : Please choose the desired Prescaller				*/
/** 		   Prescaller can be : 						*/
/*					    					DIVID_BY_2				
/*						    				DIVID_BY_4				
/*							    			DIVID_BY_8					
                                            DIVID_BY_16	
                                            DIVID_BY_32	
                                            DIVID_BY_64	
                                            DIVID_BY_128*/
/****************************************************************/
											
#define ADC_PRESCALLER				DIVID_BY_128											
											
											
#endif  /* End of the file guard*/         