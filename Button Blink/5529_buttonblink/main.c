#include <msp430.h> 
#include <msp430F5529.h>

void main (void)
{
int j;
volatile unsigned int i;        // volatile to prevent optimization
WDTCTL = WDTPW | WDTHOLD;
//PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                        // to activate previously configured port settings
P1SEL =0;
P1DIR|=BIT0;
P1DIR&=~BIT1;
P1REN|=BIT1;
P1OUT|=BIT1;
P1OUT &=~(BIT0);
while (1){
j= P1IN&BIT1;
    if(j!=2){
           P1OUT ^= BIT0;
           for(i=100000000000; i>0; i--);     // delay
    }
    else{
P1OUT &=~(BIT0);
    }
}
}
