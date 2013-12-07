/*
 * IR_Sensor.c
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Gared.Chapman
 */
#include "IR_Sensor.h"

void ADC10init(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
    ADC10CTL0 |= ADC10DIV0|ADC10DIV1|ADC10DIV2;
}


//left sensor
unsigned int detectLeft(){
        ADC10CTL0 &= ~ENC;
        ADC10CTL1 = INCH_3;
        ADC10AE0 |= BIT3;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);

        return ADC10MEM;
}

//right sensor
unsigned int detectRight(){
        ADC10CTL0 &= ~ENC;
        ADC10CTL1 = INCH_5;
        ADC10AE0 |= BIT5;
        ADC10CTL0 |= ENC + ADC10SC;
        __bis_SR_register(CPUOFF + GIE);

        return ADC10MEM;
}

// ADC10 interrupt
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);
}


