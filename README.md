# ATTINY[85] Multi Mode LED Blinker/Pulser

## Pins
``` text
RESET [*    ] VCC
3     [     ] 2
4     [     ] 1
GND   [     ] 0
```

* Pin 3 -> Button Input
* Pin 4 -> PWM Output for Blue LED(s)
* Pin 1 -> PWM Output for Green LED(s)
* Pin 0 -> PWM Output for Red LED(s)

## Button
### Press and Release
Switches to next mode
### Press and Hold
Change max brightness of LEDs (Red LED(s) will cycle up and down from 1 to 254 and back, to indictate brightness)

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
Flash morse code. Non-blocking :smile:

Message can be set in `morse_code.ino` in `morseCodeString[]` variable

## Thanks
Reference for > 2 PWM on ATTINY85 - http://www.technoblogy.com/show?LE0
