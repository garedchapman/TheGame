#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	

#include <msp430.h>
#include "game.h"
#include "button/buttons.h"
#include "LCD/LCD.h"

void init_timer();
void init_buttons();

int main(void)
{
        WDTCTL = (WDTPW|WDTHOLD);

        unsigned char player = initPlayer();

        init_timer();
        init_buttons();
        __enable_interrupt();

        while(1)
        {
                /*
                 * while (game is on)
                 * {
                 *                 check if button is pushed (you don't want to block here, so don't poll!)
                 *                 if button is pushed:
                 *                         clear current player marker
                 *                         update player position based on direction
                 *                         print new player
                 *                         clear two second timer
                 *                         wait for button release (you can poll here)
                 * }
                 *
                 * print game over or you won, depending on game result
                 *
                 * wait for button press to begin new game (you can poll here)
                 * wait for release before starting again
                 */
        }

        return 0;
}


#pragma vector=TIMER_A_VECTOR

_interrupt void TIMER_A_ISR()

{	TACTL &= ~TAIFG;
	TIMER += 1;

	if (TIMER == 4){
		LOSE =1;
	}
}

void init_timer()
{
        // do timer initialization work
}

void init_buttons()
{
        // do button initialization work
}






	return 0;
}
