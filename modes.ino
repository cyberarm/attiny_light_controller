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