#include <msp430.h> 
#include "MovingAverages_header.h"
/*
 * C2C Gared Chapman
 * Moving Averages Main.c
 * 16 October 2013
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


    char inputArray[] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
    char arrayLength = sizeof(inputArray);
    char movingAverageArray[N_AVG_SAMPLES] = {0};
    char outputArray[sizeof(inputArray)] = {0};
    char inputTracker = 0; 												//tracks progress through averaging inputs
    char littleAverageTracker = 0;
    char minimum = min(inputArray,arrayLength);
    char maximum = max(inputArray,arrayLength);
    char range = getRange(inputArray,arrayLength);									//Get max, min, range


//Do-While loop in case N_AVG_SAMPLES is 2, ensures it runs at least once.
    while(inputTracker < sizeof(inputArray)){

    	do{
    		movingAverageArray[littleAverageTracker] = movingAverageArray[littleAverageTracker+1];
    		littleAverageTracker++;
    	}while(littleAverageTracker < N_AVG_SAMPLES - 1);

    	littleAverageTracker = 0;

    	movingAverageArray[N_AVG_SAMPLES-1] = inputArray[inputTracker];

    	outputArray[inputTracker] = getAverage(movingAverageArray);

    	inputTracker++;

    }
    while(1){
    	}
}

