//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P1DIR |= BIT1;

        volatile unsigned int i;            // volatile to prevent optimization

        while(1)
        {
            P1OUT ^= 0x01;          // toggle P1.0
            for(i=10000; i>0; i--);     // delay
            P1OUT ^= BIT1;
            P1OUT ^= 0x01;      // toggle P4.7
            for(i=10000; i>0; i--);     // delay
        }

}
