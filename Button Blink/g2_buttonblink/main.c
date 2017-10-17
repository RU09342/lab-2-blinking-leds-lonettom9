#include <msp430.h>

void main (void)
{
volatile unsigned int i;        // volatile to prevent optimization
WDTCTL = WDTPW | WDTHOLD;


P1DIR|=BIT0;
P1DIR&=~BIT3;
P1REN|=BIT3;
P1OUT|=BIT3;
P1OUT &=~(BIT0);
while (1){
    if((P1IN&BIT3)!=BIT3){
           P1OUT ^= BIT0;
           for(i=100000000000; i>0; i--);     // delay
    }
}
}
