#include <Arduino.h>

int redPin    = 0;
int greenPin  = 1;
int bluePin   = 2;
int buttonPin = 4;

int delayInterval = 20;
// COMMENT;


int redBrightness  = 0;
int greenBrightness= 0;
int blueBrightness = 0;
int maxBrightness  = 50;
boolean maxBrightnessClimbing = true;
boolean brightnessChanged = false;

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
  pinMode(redPin,    OUTPUT);
  pinMode(greenPin,  OUTPUT);
  pinMode(bluePin,   OUTPUT);
  pinMode(buttonPin, INPUT);
}

void handleButton(int button) {
  if (digitalRead(button) == HIGH) {
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
  buttonLastState = digitalRead(button);
}

void resetButtonData() {
   if (digitalRead(buttonPin) == LOW) {
    buttonHighMs = 0;
    buttonHeld   = false;
  }
  buttonPressed = false;
}

void resetLeds() {
  analogWrite(redPin,   0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin,  0);
  redBrightness, greenBrightness, blueBrightness = 0;
}

void resetLeds(boolean soft) {
  analogWrite(redPin,   0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin,  0);
  if (!soft) {
    redBrightness, greenBrightness, blueBrightness = 0;
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
      if (redBrightness <= 0) {
        modeClimbing = true;
        redBrightness, greenBrightness, blueBrightness = maxBrightness;
      } else {
        redBrightness--;
        greenBrightness--;
        blueBrightness--;
      }
    }

    analogWrite(redPin,   redBrightness);
    analogWrite(greenPin, greenBrightness);
    analogWrite(bluePin,  blueBrightness);
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

      analogWrite(redPin,   redBrightness);
      analogWrite(greenPin, greenBrightness);
      analogWrite(bluePin,  blueBrightness);
      modeCycleLastChangeMs = millis();
    }
  }
}

void MODE_redOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    redBrightness = maxBrightness;
    analogWrite(redPin, redBrightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}

void MODE_greenOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    greenBrightness = maxBrightness;
    analogWrite(redPin,   0);
    analogWrite(greenPin, greenBrightness);
    analogWrite(bluePin,  0);
  }
}

void MODE_blueOnly() {
  if (modeChanged) {
    resetLeds();
  } else {
    blueBrightness = maxBrightness;
    analogWrite(redPin,   0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin,  blueBrightness);
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

    analogWrite(redPin, maxBrightness);
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
        analogWrite(redPin, 255);
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