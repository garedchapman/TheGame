TheGame
=======

The program in this repository will be able to implement a simple game in which the "player", an asterisk, can be 
moved across the LCD up, down, left, and right using four of the buttons in the geekbox.  Starting from the top left, 
when the asterisk reaches the bottom right of the screen, a message will appear, "YOU WON!" Likewise, if the player
waits more than 2 seconds to make a move, the screen will display "GAME OVER". The player cannot move out of the 
bounds of the LCD, and the buttons must be debounced properly.

The program will use interrupts to execute the short timer and the button presses.


