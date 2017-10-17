# Multiple Blink
## Objective
The objective here was to blink multiple LEDs simultaneously, although at a different rate that can be visibily verified.
## Summary
The code is very similar to the blinking LED, however instead two LED pins were initalized and enabled for use as an output. An infinite loop is used again in conjunction with the exlusive or to toggle both pins, although the delay that we use is applied once to the first LED and twice to the second LED in order to provide a different blink rate.