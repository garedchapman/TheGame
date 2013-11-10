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

void init_timer();
void init_buttons();
void timerCLR()
{
	TIMER = 0;
	TACTL |= TACLR;
}

int main(void)
{
        WDTCTL = (WDTPW|WDTHOLD);

        INITSPI();
        LCDINIT();
        LCDCLR();

        player = initPlayer();

        init_timer();
        init_buttons();

        timerCLR();

        printPlayer(player);

        __enable_interrupt();

        while(1)
        {

        	if(didPlayerWin(player)){
        		LCDCLR();
        		print("YOU");
        		secondLine();
        		print("WON!");

        		RESET = 1;

        		waitForP1ButtonRelease(BIT1|BIT2|BIT3|BIT4);
        		debounce();

        	}

        	if(LOSE ==1){
				LCDCLR();
				print("GAME");
				secondLine();
				print("OVER");

				RESET = 1;

				waitForP1ButtonRelease(BIT1|BIT2|BIT3|BIT4);
				debounce();
        		}

        	if(RESET){
        		char buttonpoll[4]={BIT1,BIT2,BIT3,BIT4};

        		while(pollP1Buttons(buttonpoll, 4)){
        			LOSE=0;
        			RESET=0;
        			TIMER=0;
        			LCDCLR();
        			player = initPlayer();
        			printPlayer(player);
        		}

        	}


        	return 0;
        		}
        	}

void testAndRespondToButtonPush(char buttonToTest) {
        if (buttonToTest & P1IFG) {
                if (buttonToTest & P1IES) {
                        clearPlayer(player);
                        player = movePlayer(player, buttonToTest);
                        printPlayer(player);
                        timerCLR();
                        RESET = 1;

                } else {
                        debounce();
                }

                P1IES ^= buttonToTest;
                P1IFG &= ~buttonToTest;
        }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void) {
        testAndRespondToButtonPush(BIT1);
        testAndRespondToButtonPush(BIT2);
        testAndRespondToButtonPush(BIT3);
        testAndRespondToButtonPush(BIT4);
}



#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR()

{	TACTL &= ~TAIFG;
	TIMER += 1;

	if (TIMER == 4){
		LOSE =1;
	}
}

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





