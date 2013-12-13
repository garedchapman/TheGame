#include <msp430.h> 
#include "Maze.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initializeMotors();
	ADC10init();
	//_delay_cycles(1000000);
	//P1DIR |= BIT0|BIT6;
	for (;;) {
		unsigned int centerscan = detectCenter();
		unsigned int leftscan = detectLeft();

	//	if (centerscan > 0x1ff){
	//		RightTurn();

	//	}
		/*
		if (leftscan > 0x225) {
			RightTurn();
		} else if (leftscan < 0x1A0) {
			LeftTurn();
		} else {
			moveBackward();
		}
		*/
		if (leftscan > 0x1b0){
						LeftTurn();
						_delay_cycles(100000);
		}
		else if (centerscan > 0x1ff)
		{
			LeftTurn();
			_delay_cycles(100000);
		}
		else if (detectRight() > 0x380){
			RightTurn();
			_delay_cycles(100000);
		}
		else
		{
			moveForward();
		}

		/*
		if (leftscan > 0x1ff)
			P1OUT |= BIT0;
		else
			P1OUT &= ~BIT0;

		if (centerscan > 0x1ff)
			P1OUT |= BIT6;
		else
			P1OUT &= ~BIT6;
			*/

	}

	return 0;
}

