#include <msp430.h> 
#include "game.h"
#include "button_game.h"
#include "LCD_game.h"
/*
 * C2C Gared Chapman
 *
 */

unsigned char player = 0;
unsigned char LOSE = 0;
unsigned char RESET = 0;
unsigned char TIMER = 0;

void init_timer()
{		// initialize timer
        TACTL &= ~(MC1|MC0);
        TACTL |= TACLR;
        TACTL |= TASSEL1;
        TACTL |= ID1|ID0;
        TACTL &= ~TAIFG;
        TACTL |= MC1;
        TACTL |= TAIE;
}

void init_buttons()
{		// initialize buttons
       configureP1toButton(BIT1|BIT2|BIT3|BIT4);
       P1IES |= BIT1 | BIT2 | BIT3 | BIT4;
       P1IFG &= ~(BIT1 | BIT2 | BIT3 | BIT4);
       P1IE |= BIT1 | BIT2 | BIT3 | BIT4;


}
void timerCLR()
{
	TIMER = 0;
	TACTL |= TACLR;
}

void main(void)
{
        WDTCTL = (WDTPW|WDTHOLD);


        INITSPI();
        LCDINIT();
        LCDCLR();					//what needs to be done for every LCD program, initialize and clear

        player = initPlayer();
        init_timer();
        init_buttons();				//initialize player, timer and buttons

        timerCLR();
        printPlayer(player);		//draws the player asterisk
        __enable_interrupt();		//enables the interrupts below

        while(1)					//ongoing loop to keep game running
        {

        	//checks if player location is bottom right square
        	if(didPlayerWin(player)){
        		LCDCLR();
        		print("YOU");
        		secondLine();
        		print("WON!");

        		RESET = 0;

        		//traps message on screen until button is pressed (when RESET is set high)
				while(RESET == 0){

				}

				//important values are reset for gameplay, screen is cleared, player is redrawn
    			LOSE=0;
    			RESET=0;
    			TIMER=0;
    			LCDCLR();
    			player = initPlayer();
    			printPlayer(player);
        	}


        	//if the timer runs out, lose is set high, GAME OVER appears on screen
        	if(LOSE ==1){
				LCDCLR();
				print("GAME");
				secondLine();
				print("OVER");

				RESET = 0;

				//same loop trap until a button is pressed
				while(RESET == 0){

				}
    			LOSE=0;
    			RESET=0;
    			TIMER=0;
    			LCDCLR();
    			player = initPlayer();
    			printPlayer(player);
        		}




        	}


        	}

/*function used for the button interrupt, if a button is pushed, player is cleared,
 * moved in a direction depending on which button, and redrawn in the new location
 * timer is cleared because a movement was made
*/
void PressedButton(char whichButton) {
        if (whichButton & P1IFG) {
                if (whichButton & P1IES) {
                        clearPlayer(player);
                        player = movePlayer(player, whichButton);
                        printPlayer(player);
                        timerCLR();
                        RESET = 1;

                }
                else {
                       debounce();
                }

			P1IES ^= whichButton;
			P1IFG &= ~whichButton;
        }
}

//button interrupt dependent on above function and timer interrupt
#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void) {
        PressedButton(BIT1);
        PressedButton(BIT2);
        PressedButton(BIT3);
        PressedButton(BIT4);
}



#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR()

{	TACTL &= ~TAIFG;
	TIMER += 1;

	if (TIMER == 4){
		LOSE =1;
	}
}






