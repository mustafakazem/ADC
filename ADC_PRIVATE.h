/****************************************************************/
/*   Author             :    Mustafa Kazem				    */
/*	 Date 				:    25 February 2023 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   ADC Private contain the memory 
                            mapping of [ADCSRA,ADMUX,ADCL,ADCH] 
/****************************************************************/


/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/
#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADCSRA    	*/
/**			   Register	is  0X26						    	*/
/****************************************************************/
/**			   ADCSRA : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define ADCSRA		*((volatile u8 * ) (0X26))

/* MACROS for the bits of GIFR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */

#define ADEN     7
#define ADSC     6
#define ADATE    5
#define ADIF     4
#define ADIE     3
#define ADPS2    2
#define ADPS1    1
#define ADPS0    0

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADMUX     	*/
/**			   Register	is  0X27.								*/
/****************************************************************/
/**			   ADMUX : ADC Multiplexer Selection Register		*/
/****************************************************************/

#define ADMUX       *((volatile u8 * ) (0X27))

/* MACROS for the bits of GIFR to indentify the bits 
                 & avoid MAGIC NUMBERS                     */

#define REFS1  7
#define REFS0  6
#define ADLAR  5
#define MUX4   4
#define MUX3   3  
#define MUX2   2
#define MUX1   1
#define MUX0   0

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADCL     	*/
/**			   Register	is  0X24.								*/
/****************************************************************/
/**		      ADCL : ADC Data Register Low Byte                   	*/
/****************************************************************/

#define ADCL        *((volatile u16* ) (0X24))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADCH     	*/
/**			   Register	is  0X25.								*/
/****************************************************************/
/**		      ADCH :  ADC Data Register High Byte                    	*/
/****************************************************************/

#define ADCH        *((volatile u8 * ) (0X25))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of SFIOR     	*/
/**			   Register	is  0X50.								*/
/****************************************************************/
/**		      SFIOR :  Special FunctionIO Register                    	*/
/****************************************************************/

#define SFIOR       *((volatile u8 * ) (0X50))

#define ADTS2   7
#define ADTS1   6
#define ADTS0   5
#define ACME    3
#define PUD     2
#define PSR2    1 
#define PSR10   0



#endif  /* End of the file guard*/
