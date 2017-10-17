# Button Blink
## Objective
The goal here was to implement functionality so that the LED would turn on with the press of a button, and the LED would be off upon the second button press.
## Summary 
This implementation was the first that involved initalizing an input so far to date. This is done using the &= as opposed to the |=. This also involves enabling the pull up resistor for the input. A similar process is used, including an infinite loop with an if statement checking for when the button is pressed. When the button is pressed the LED turns on when it is pressed again it turns off.
## Board Differences
In the 2311, and 6989 the line of code "PM5CTL0 &= ~LOCKLPM5;"is required in order to disable the GPIO power-on default high-impedance mode.
                                       