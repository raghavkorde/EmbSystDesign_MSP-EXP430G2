#include <msp430.h>

/* TOGGLE LED ON PORT 1 PIN 0 TO ON STATE WHEN SWITCH IS PRESSED*/

int main(void)
{
    //STOP WATCHDOG TIMER (Not recommended in Production Level Codes)
    WDTCTL = WDTPW + WDTHOLD;

    //MSP-EXP430G2-2553 Has LED on P1.0 (RED) and SWITCH at P1.3
    
    //SET Direction of P1.0 to OUT
    P1DIR |= BIT6;

    //SET Direction of P1.3 to INPUT
    P1DIR &= (~BIT3);

    while(1){
        if(!(P1IN & BIT3)){

            //__delay_cycles(20000);
            while (!(P1IN & BIT3));
            //__delay_cycles(20000);
            //SET Output at P1.0 to 1 i.e. LED => ON
            P1OUT ^= BIT6;
   
        }
    }

    return 0;
}