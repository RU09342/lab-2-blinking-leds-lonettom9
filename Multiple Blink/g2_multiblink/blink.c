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
//  J. Stevenson
//  Texas Instruments, Inc
//  July 2011
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>				


int main(void) {
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer
    P1DIR |= 0x01;                  // Set P1.0 to output direction
    P1DIR |= BIT6;

    volatile unsigned int i;

    while(1)
    {
        P1OUT ^= 0x01;          // toggle P1.0
        for(i=10000; i>0; i--);     // delay
        P1OUT ^= BIT6;
        P1OUT ^= 0x01;      // toggle P4.7
        for(i=10000; i>0; i--);     // delay
    }


    return 0;
}
