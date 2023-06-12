#include <msp430.h>

/* TURN LED ON PORT 1 PIN 0 TO ON STATE*/

int main(void)
{
    //STOP WATCHDOG TIMER (Not recommended in Production Level Codes)
    WDTCTL = WDTPW + WDTHOLD;

    //MSP-EXP430G2-2553 Has LED on P1.0 (RED) and P1.6 (GREEN)
    
    //SET Direction of P1.0 to OUT
    P1DIR |= BIT0;

    //SET Output at P1.0 to 1 i.e. LED => ON
    P1OUT |= BIT0;

    return 0;
}