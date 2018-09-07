# ATTINY[85] Multi Mode LED Blinker/Pulser

## Pins
``` text
RESET [*    ] VCC
3     [     ] 2
4     [     ] 1
GND   [     ] 0
```

* Pin 3 -> Button Input
* Pin 4 -> PWM Blue LED(s)
* Pin 2 -> PWM Red LED(s)
* Pin 1 -> PWM Green LED(s)

## Modes
### Pulse
Fades leds in and out.
### Cycle
"Randomly" chooses colors
### Red Only
Non-animated, only has red LED on.
### Green Only
Non-animated, only has green LED on.
### Blue Only
Non-animated, only has blue LED on.
### Morse Code
Flash morse code. Non-blocking :happy:

Message can be set in `morse_code.ino` in `morseCodeString[]` variable

## Thanks
Reference for > 2 PWM on ATTINY85 - http://www.technoblogy.com/show?LE0