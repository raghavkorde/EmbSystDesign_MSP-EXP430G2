#include <msp430g2553.h>

#define LED_EXT BIT0
#define SWITCH_EXT BIT3

void setup(){
    WDTCTL = WDTPW | WDTHOLD;

    P2DIR |= LED_EXT; //SET P2.0 as OUTPUT
    P2OUT &= ~LED_EXT; //Initially LED_EXT is OFF
    

    P2DIR &= ~SWITCH_EXT; //SET P2.2 as INPUT
    P2REN |= SWITCH_EXT; //Enable Pull-up/ Pull-down resistor
    P2OUT |= SWITCH_EXT; //SELECT Pull-Up configuration
}

void main(void){
    setup(); 
    while (1){
        if(!(P2IN & SWITCH_EXT)){

            __delay_cycles(20000);

            if(!(P2IN & SWITCH_EXT)){

                P2OUT ^= LED_EXT;
                while (!(P2IN & SWITCH_EXT)){}
                __delay_cycles(20000);
            }
        }
    }
}
