/*
 * game.c
 *
 *  Created on: Nov 4, 2013
 *      Author: C15Gared.Chapman
 */
#include <msp430g2553.h>
#include "game.h"
#include "LCD_game.h"

unsigned char initPlayer()
{
        return 0x80;
}

void printPlayer(unsigned char player)
{
        writeCommandByte(player);
        writeDataByte('*');
}

void clearPlayer(unsigned char player)
{
        writeCommandByte(player);
        writeDataByte(' ');
}

unsigned char movePlayer(unsigned char player, unsigned char direction)
{
        switch (direction) {
                //
                // update player position based on direction of movement
                //
        case RIGHT:
                if((player & 0x0f) < 7){
                player += 0x01;
                }
                break;
        case LEFT:
                if((player & 0x0f) > 0){
                player -= 0x01;
                }
                break;
        case UP:
                player &= ~ROW_MASK;
                break;
        case DOWN:
                player |= ROW_MASK;

                break;



        }

        return player;
}
char didPlayerWin(unsigned char player)
{
        return player == 0xC7;
}





