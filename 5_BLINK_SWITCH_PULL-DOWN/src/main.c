#include <msp430.h>

#define LED_PIN BIT0     // LED at Pin 1.0
#define SWITCH_PIN BIT3  // SWITCH at Pin 1.3

void setup() {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    P1DIR |= LED_PIN;  // Set LED pin as output
    P1OUT &= ~LED_PIN; // Turn off LED initially

    P1DIR &= ~SWITCH_PIN; // Set switch pin as input
    P1REN |= SWITCH_PIN;  // Enable pull-down resistor
    P1OUT &= ~SWITCH_PIN;  // Set pull-down resistor at switch pin
}

void main(void) {
    setup();
    while (1) {
        if (P1IN & SWITCH_PIN) {  // Check if switch is released (logic high)
            __delay_cycles(20000); // Delay of 20ms to debounce

            if (P1IN & SWITCH_PIN) {  // Check if switch is still released after debounce interval
                P1OUT ^= LED_PIN; // Toggle LED
                while (P1IN & SWITCH_PIN) {}  // Wait for switch press
                __delay_cycles(20000); // Delay of 20ms to debounce
            }
        }
    }
}
