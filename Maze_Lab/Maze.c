#include "Maze.h"
#include <msp430.h>
/*
 * Maze.c
 *
 *  Created on: Dec 8, 2013
 *      Author: C15Gared.Chapman
 */

void initializeMotors(){
  	P1DIR |= BIT2;                // TA0CCR1 on P1.2
        P1SEL |= BIT2;                // TA0CCR1 on P1.2
        P1DIR |= BIT1;                // TA0CCR0 on P1.1
        P1SEL |= BIT1;                // initialize left motor

        P2DIR |= BIT0;                // TA0CCR1 on P1.2
        P2SEL |= BIT0;                // TA0CCR1 on P1.2
        P2DIR |= BIT1;                // TA0CCR0 on P1.1
        P2SEL |= BIT1;                // TA0CCR0 on P1.1

        TA0CTL &= ~(MC1|MC0);            // stop timer A0

        TA0CTL |= TACLR;                // clear timer A0

        TA0CTL |= TASSEL1;           // configure for SMCLK

        TA0CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
        TA0CCR1 = 50;                // set duty cycle to 25/100 (25%)

        TA1CTL &= ~(MC1|MC0);            // stop timer A0

        TA1CTL |= TACLR;                // clear timer A0

        TA1CTL |= TASSEL1;           // configure for SMCLK

        TA1CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
        TA1CCR1 = 60;                // set duty cycle to 25/100 (25%)

		TA0CTL |= MC0;                // count up
		TA1CTL |= MC0;                // count up
}

void ADC10init(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
    ADC10CTL0 |= ADC10DIV0|ADC10DIV1|ADC10DIV2;
    ADC10AE0 |= BIT3|BIT4|BIT5;
}


//left sensor
unsigned int detectLeft(){
        ADC10CTL0 &= ~ENC;
        ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
        ADC10CTL1 |= INCH_4;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);

        return ADC10MEM;
}

//right sensor
unsigned int detectRight(){
        ADC10CTL0 &= ~ENC;
        ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
        ADC10CTL1 |= INCH_5;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);

        return ADC10MEM;
}

unsigned int detectCenter(){
        ADC10CTL0 &= ~ENC;
        ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
        ADC10CTL1 |= INCH_3;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);

        return ADC10MEM;
}
void moveForward(void){
    TA0CCR1 = ;                // set duty cycle to 25/100 (25%)
		TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
		TA0CCTL0 |= OUTMOD_5;		// set TACCTL0 to Reset

		TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
		TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
		TA1CCTL0 |= OUTMOD_5;		// set TACCTL0 to Reset
}

void moveBackward(void){


	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_4;
			;		// set TACCTL0 to Reset

	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_4;		// set TACCTL0 to Reset

}

void LeftTurn(void){

	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_5;		// set TACCTL0 to Reset

	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_4;		// set TACCTL0 to Reset
}


void RightTurn(void){
    TA0CCR1 = 60;                // set duty cycle to 25/100 (25%)
	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_4;		// set TACCTL0 to Reset

	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_5;		// set TACCTL0 to Reset
}


void Stop(void){

    TA0CTL &= ~(MC1 | MC0);
    TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
    TA0CCTL1 &= ~(OUTMOD_5|OUTMOD_7);
    TA0CCTL0 |= OUTMOD_5;                                //set to reset to stop
    TA0CCTL1 |= OUTMOD_5;
    TA0CTL |= MC0;

    TA1CTL &= ~(MC1 | MC0);
    TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
    TA1CCTL1 &= ~OUTMOD_5;
    TA1CCTL1 &= ~OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;                                //set to reset to stop
    TA1CCTL1 |= OUTMOD_5;
    TA1CTL |= MC0;
}

// ADC10 interrupt
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);
}
