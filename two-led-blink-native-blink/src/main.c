#include <msp430g2553.h>

void delay(){
        __delay_cycles(10000);
    }

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    // make the LED pin an output for P1.0 and P1.6
    P1DIR |= (BIT0 | BIT6);
    while (1)
    {
        delay();
        // toggle the LED at port 1.6
        P1OUT ^= BIT6;
        delay();
        P1OUT ^= BIT0;
        delay();
    }

    return 0;
}