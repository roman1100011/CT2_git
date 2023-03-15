/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zurich University of                       -
 * --  _| |_| | | | |____ ____) |  Applied Sciences                           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 * --
 * -- Project     : CT2 Lab GPIO
 * -- Description : Configure and use GPIO port B as output and 
 * --               GPIO port A is input.
 * --               Lab version without additional hardware 
 * --               except for three wires.
 * --
 * -- $Id: main.c ostt $
 * ------------------------------------------------------------------------- */

#include <stdint.h>
#include <reg_stm32f4xx.h>

#include "reg_ctboard.h"

/* user macros */

#define MASK_3_BITS  0x0007

/* ----------------------------------------------------------------------------
 * Main
 * ------------------------------------------------------------------------- */

int main(void)
{
    uint16_t data_gpio_in;              // use to read input values from gpio
    uint8_t data_dip_switch;            // use to read values from dip switches

    GPIOA_ENABLE();                     // peripheral clk enable
    GPIOB_ENABLE();                     // peripheral clk enable

    /* Reset GPIOA specific values */
    GPIOA->MODER = 0xa8000000;           // mode register
    GPIOA->OSPEEDR = 0x00000000;         // output speed register
    GPIOA->PUPDR = 0x64000000;           // pull resistor register
    GPIOA->OTYPER = 0x00000000;          // type register (pp / f. gate)
    GPIOA->AFRL = 0x00000000;
    GPIOA->AFRH = 0x00000000;
    GPIOA->ODR = 0x00000000;             // output data register
    
    /* Reset GPIOB specific values */
    GPIOB->MODER = 0x00000280;           // mode register
    GPIOB->OSPEEDR = 0x000000c0;         // output speed register
    GPIOB->PUPDR = 0x00000100;           // pull resistor register
    GPIOB->OTYPER = 0x00000000;          // type register (pp / f. gate)
    GPIOB->AFRL = 0x00000000;
    GPIOB->AFRH = 0x00000000;
    GPIOB->ODR = 0x00000000;             // output data register
    

    /* configure GPIO pins
     * clear register bits: GPIOx->xxxx &= ~(clear_mask << bit_pos);
     * set register bits:   GPIOx->xxxx |=  (set_value << bit_pos);
     * On GPIOA and GPIOB only pins 11 down to 0 are available to the user. 
     * Pins 15 down to 12 are used for system functions of the discovery board, 
     * e.g. connection of the debugger.
     * These pins must not be reconfigured. 
     * OTHERWISE THE DEBUGGER CANNOT BE USED ANY MORE!!!
     */
    /// STUDENTS: To be programmed
		
//Mode A
		//Pin0A
		GPIOA->MODER &= (uint32_t)~(0x03<<0); //clear 	In_A_1
		GPIOA->MODER |= (0x00<<0);	//set
		
		//Pin1A
		GPIOA->MODER &= (uint32_t)~(0x03<<2);	//clear		In_A_2
		GPIOA->MODER |= (0x00<<2);	//set
		
		//Pin2A
		GPIOA->MODER &= (uint32_t)~(0x03<<4);	//Clear		In_A_3
		GPIOA->MODER |= (0x00<<4);	//set
//pull UP/Down A
		GPIOA->PUPDR &= (uint32_t)~(0x01<<0);					//In_A_1
    GPIOA->PUPDR |=  (0x01<<1);
 
    GPIOA->PUPDR &= (uint32_t)~(0x02<<2);					//In_A_2
    GPIOA->PUPDR |=  (0x01<<2);
 
    GPIOA->PUPDR &= (uint32_t)~(0x03<<4);					//In_A_3
    GPIOA->PUPDR |=  (0x00<<4);
//Mode B
		GPIOB->MODER &= (uint32_t)~(0x01<<1);					//Out_B_1
    GPIOB->MODER |=  (0x01<<0);
 
    GPIOB->MODER &= (uint32_t)~(0x01<<3);					//Out_B_2
    GPIOB->MODER |=  (0x01<<2);
 
    GPIOB->MODER &= (uint32_t)~(0x01<<5);					//Out_B_3
    GPIOB->MODER |=  (0x01<<4);
//pull Up/Down B
		GPIOB->PUPDR &= (uint32_t)~(0x03<<0);					//Out_B_1
    GPIOB->PUPDR |=  (0x00<<2);
 
    GPIOB->PUPDR &= (uint32_t)~(0x03<<2);					//Out_B_2
    GPIOB->PUPDR |=  (0x00<<2);
 
    GPIOB->PUPDR &= (uint32_t)~(0x02<<4);					//Out_B_3
    GPIOB->PUPDR |=  (0x01<<4);
//Speed B
		GPIOB->OSPEEDR &= (uint32_t)~(0x03<<0);
    GPIOB->OSPEEDR |=  (0x00<<0);
                               
    GPIOB->OSPEEDR &= (uint32_t)~(0x01<<3);
    GPIOB->OSPEEDR |=  (0x01<<2);
                               
    GPIOB->OSPEEDR &= (uint32_t)~(0x00<<6);
    GPIOB->OSPEEDR |=  (0x03<<4);
//Push/pull
		GPIOB->OTYPER &= (uint32_t)~(0x01<<0);
    GPIOB->OTYPER |=  (0x00<<0);
                               
    GPIOB->OTYPER &= (uint32_t)~(0x00<<1);
    GPIOB->OTYPER |=  (0x01<<1);
                               
    GPIOB->OTYPER &= (uint32_t)~(0x00<<2);
    GPIOB->OTYPER |=  (0x01<<2);


    /// END: To be programmed

    while (1) {
        /* implement tasks 6.1 to 6.2 below */
       /// STUDENTS: To be programmed

			uint8_t pa_werte = GPIOA-> IDR & MASK_3_BITS;
		   CT_LED->BYTE.LED23_16 = pa_werte;
                                                       
			data_dip_switch = CT_DIPSW->BYTE.S15_8;                       //einlesen
			CT_LED->BYTE.LED15_8 = data_dip_switch& MASK_3_BITS;          //auslesen
			GPIOB -> ODR = data_dip_switch ;            									//schreiben ins ODR
			CT_LED->BYTE.LED7_0 = GPIOB->ODR & MASK_3_BITS;
        /// END: To be programmed

    }
}
