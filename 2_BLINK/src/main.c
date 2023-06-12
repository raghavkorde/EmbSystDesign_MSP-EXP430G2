#include <msp430g2553.h>

/* BLINK RED AND GREEN LED ONE AFTER THE OTHER WITH A DELAY*/

int main(void)
{
    //STOP WATCHDOG TIMER (Not recommended in Production Level Codes)
    WDTCTL = WDTPW + WDTHOLD;

    //MSP-EXP430G2-2553 Has LED on P1.0 (RED) and P1.6 (GREEN)
    //SET Direction of P1.0 and P1.6 to OUT
    P1DIR |= (BIT0 | BIT6);

    while(1){

        //GREEN => OFF and RED LED  ON 
        P1OUT &= (~BIT6);
        P1OUT |= BIT0;

        //DELAY of 1 second (appx not sure)
        __delay_cycles(1600000);

        //TOGGLE RED and GREEN LED => OFF and ON
        P1OUT ^= BIT0;
        P1OUT ^= BIT6;

        //DELAY of 1 second (appx not sure)
        __delay_cycles(1600000);

    }
    

    return 0;
}