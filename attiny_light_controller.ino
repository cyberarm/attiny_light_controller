#include <Arduino.h>

// array indices, not pinouts
int redPin    = 0;
int greenPin  = 1;
int bluePin   = 2;

int buttonPin = 2; // pinout

// http://www.technoblogy.com/show?LE0
volatile uint8_t* port[] = {&OCR0A, &OCR0B, &OCR1B};
int pin[] = {0, 1, 4};

int delayInterval = 20;

int redBrightness  = 0;
int greenBrightness= 0;
int blueBrightness = 0;
int maxBrightness  = 50;
boolean maxBrightnessClimbing = true;
boolean brightnessChanged = false;
int off = 0;

const int MODE_PULSE     = 0;
const int MODE_CYCLE     = 1;
const int MODE_REDONLY   = 2;
const int MODE_GREENONLY = 3;
const int MODE_BLUEONLY  = 4;
int modes[5] = {MODE_PULSE, MODE_CYCLE, MODE_REDONLY, MODE_GREENONLY, MODE_BLUEONLY};
int modeIndex= 0;
boolean modeChanged = false;
boolean modeClimbing= true;
long modeCycleLastChangeMs = 0;
int modeCycleChangeAfterMs = 500;

int buttonLastState   = LOW;
int buttonIsHeldAfterMs = 200;
long buttonHighMs   = 0;
boolean buttonHeld, buttonPressed, buttonReleased  = false;

void setup() {
  pinMode(pin[redPin],    OUTPUT);
  pinMode(pin[greenPin],  OUTPUT);
  pinMode(pin[bluePin],   OUTPUT);
  pinMode(buttonPin, INPUT);

  // http://www.technoblogy.com/show?LE0
  // Configure counter/timer0 for fast PWM on PB0 and PB1
  TCCR0A = 3<<COM0A0 | 3<<COM0B0 | 3<<WGM00;
  TCCR0B = 0<<WGM02 | 3<<CS00; // Optional; already set
  // Configure counter/timer1 for fast PWM on PB4
  GTCCR = 1<<PWM1B | 3<<COM1B0;
  TCCR1 = 3<<COM1A0 | 7<<CS10;
}

void setColor(int pin, int brightness) {
  *port[pin] = 255 - brightness;
}

void handleButton(int button) {
  int buttonCurrentState = digitalRead(button);
  if (buttonCurrentState == HIGH) {
    if (buttonLastState == HIGH) {
      if (millis()-buttonHighMs > buttonIsHeldAfterMs) {
        buttonHeld = true;
      }
    } else {
      buttonPressed = true;
      buttonHighMs  = millis();
    }
  } else {
    if (buttonLastState == HIGH) {
      buttonReleased = true;
    } else {
      buttonReleased = false;
    }
  }

  buttonLastState = buttonCurrentState;
}

void resetButtonData() {
   if (digitalRead(buttonPin) == LOW) {
    buttonHighMs = 0;
    buttonHeld   = false;
  }
  buttonPressed = false;
}

void resetLeds() {
  setColor(redPin,   off);
  setColor(greenPin, off);
  setColor(bluePin,  off);
  redBrightness, greenBrightness, blueBrightness = off;
}

void resetLeds(boolean soft) {
  setColor(redPin,   off);
  setColor(greenPin, off);
  setColor(bluePin,  off);
  if (!soft) {
    redBrightness, greenBrightness, blueBrightness = off;
  }
}
// START MODES
void MODE_pulse() {
  if (modeChanged) {
    resetLeds();
  } else {
    if (modeClimbing) {
      if (redBrightness >= maxBrightness) {
        modeClimbing = false;
        redBrightness, greenBrightness, blueBrightness = maxBrightness;
      } else {
        redBrightness++;
        greenBrightness++;
        blueBrightness++;
      }

    } else {
      if (redBrightness <= 1) {
        modeClimbing = true;
        redBrightness, greenBrightness, blueBrightness = maxBrightness;
      } else {
        redBrightness--;
        greenBrightness--;
        blueBrightness--;
      }
    }

    setColor(redPin,   redBrightness);
    setColor(greenPin, greenBrightness);
    setColor(bluePin,  blueBrightness);
  }
}

void MODE_cycle() {
  if (modeChanged) {
    resetLeds();
  } else {
    if (millis()-modeCycleLastChangeMs > modeCycleChangeAfterMs) {
      redBrightness   = random(1, maxBrightness);
      greenBrightness = random(1, maxBrightness);
      blueBrightness  = random(1, maxBrightness);

      setColor(redPin,   redBrightness);
      setColor(greenPin, greenBrightness);
      setColor(bluePin,  blueBrightness);
      modeCycleLastChangeMs = millis();
    }
  }
}

void MODE_redOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    redBrightness = maxBrightness;
    setColor(redPin, redBrightness);
    setColor(greenPin, off);
    setColor(bluePin, off);
  }
}

void MODE_greenOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    greenBrightness = maxBrightness;
    setColor(redPin,   off);
    setColor(greenPin, greenBrightness);
    setColor(bluePin,  off);
  }
}

void MODE_blueOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    blueBrightness = maxBrightness;
    setColor(redPin,   off);
    setColor(greenPin, off);
    setColor(bluePin,  blueBrightness);
  }
}
// END MODES

void runMode() {
  // CHANGE BRIGHTNESS
  if (buttonHeld) {
    brightnessChanged = true;
    resetLeds(true);

    if (maxBrightnessClimbing) {
      if (maxBrightness+1 >= 255) {
        maxBrightnessClimbing = false;
      } else {
        maxBrightness++;
      }
    } else {
      if (maxBrightness-1 <= 0) {
        maxBrightnessClimbing = true;
      } else {
        maxBrightness--;
      }
    }

    setColor(redPin, maxBrightness);
  } else {
    brightnessChanged = false;
  }

  // UNKNOWN
  if (buttonPressed && !buttonHeld) {
  }

  // CHANGE MODE
  if (buttonReleased && !buttonHeld) {
    modeIndex++;
    modeChanged = true;
  }

  if (modeIndex >= (sizeof(modes) / sizeof(modes[0]))) {
    modeIndex = 0;
  }

  if (!brightnessChanged) {
    switch(modes[modeIndex]) {
      case MODE_PULSE:
        MODE_pulse();
        break;
      case MODE_CYCLE:
        MODE_cycle();
        break;
      case MODE_REDONLY:
        MODE_redOnly();
        break;
      case MODE_GREENONLY:
        MODE_greenOnly();
        break;
      case MODE_BLUEONLY:
        MODE_blueOnly();
        break;
      default:
        setColor(redPin, 255);
        break;
    }
  }

  if (modeChanged) { modeChanged = false; }
}

void loop() {
  handleButton(buttonPin);
  runMode();
  resetButtonData();
  delay(delayInterval);
}