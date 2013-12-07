/*
 * robot_movements.c
 *
 *  Created on: Nov 14, 2013
 *      Author: C15Gared.Chapman
 */
#include <msp430.h>
#include "robot_movements.h"

void initializeMotors(void);


void moveForward(void){


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

void LeftSmall(void){


	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_5;		// set TACCTL0 to Reset

	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_4;		// set TACCTL0 to Reset



}


void RightSmall(void){


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
