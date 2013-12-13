/*
 * Maze.h
 *
 *  Created on: Dec 8, 2013
 *      Author: C15Gared.Chapman
 */

#ifndef MAZE_H_
#define MAZE_H_

void initializeMotors(void);
void ADC10init(void);

unsigned int detectCenter();

unsigned int detectLeft();

unsigned int detectRight();

void moveForward(void);

void moveBackward(void);

void LeftTurn(void);

void RightTurn(void);

void Stop(void);


#endif /* MAZE_H_ */

