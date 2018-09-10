char morseCodeString[] = "HELLO WORLD AR "; // AR -> End of message. always append a SPACE to have a pause inserted.

int morseIndex, morseListIndex = 0;
int lastMorseListIndex = -1;
long morseUpdateMs = 0;
int activeArraySize = 0;
int activeCode[5];

int DOT = 250; // ms
int DASH= DOT*3;
int SHORT=DOT*5;
int MEDIUM=DOT*7;

void MODE_morsecode() {
  if (modeChanged) {
    morseUpdateMs = 0;
    morseIndex = 0;
    morseListIndex = 0;
    lastMorseListIndex = -1;
  }
  if (millis() > morseUpdateMs) {
    animateMorseCode();
  }
}

void animateMorseCode() {
  if (morseIndex < strlen(morseCodeString)) {
    if (morseCodeString[morseIndex] == ' ') {
      resetLeds();
      morseUpdateMs = (millis()+MEDIUM);
      morseIndex++;
    } else {
      getMorseCodeForChar(morseCodeString[morseIndex]); // Call here to set activeArraySize variable

      if (morseListIndex < activeArraySize && activeArraySize != 0) {
        if (lastMorseListIndex == morseListIndex) {
          resetLeds();
          morseUpdateMs = (millis()+DOT);
          morseListIndex++;
        } else {
          morseLedsOn();
          morseUpdateMs = (millis()+getMorseCodeForChar(morseCodeString[morseIndex])[morseListIndex]);
          lastMorseListIndex = morseListIndex;
        }
      } else {
        morseIndex++;
        morseListIndex = 0;
        lastMorseListIndex = -1;
        resetLeds();
        morseUpdateMs = (millis() + DASH);
      }
    }

  } else {
    morseIndex = 0;
    resetLeds();
  }
}

void morseLedsOn() {
  setColor(redPin, maxBrightness);
  setColor(greenPin, maxBrightness);
  setColor(bluePin, maxBrightness);
}

int *getMorseCodeForChar(char str) {
  switch(str) {
    case 'A':{
      activeArraySize = 2;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      return activeCode;
      break;
    }
    case 'B':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'C':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'D':{
      activeArraySize = 3;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      return activeCode;
      break;
    }
    case 'E':{
      activeArraySize = 1;
      activeCode[0] = DOT;

      return activeCode;
      break;
    }
    case 'F':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'G':{
      activeArraySize = 3;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      return activeCode;
      break;
    }
    case 'H':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'I':{
      activeArraySize = 2;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      return activeCode;
      break;
    }
    case 'J':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      return activeCode;
      break;
    }
    case 'K':{
      activeArraySize = 3;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      return activeCode;
      break;
    }
    case 'L':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'M':{
      activeArraySize = 2;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      return activeCode;
      break;
    }
    case 'N':{
      activeArraySize = 2;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      return activeCode;
      break;
    }
    case 'O':{
      activeArraySize = 3;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      return activeCode;
      break;
    }
    case 'P':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }
    case 'Q':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      activeCode[3] = DASH;
      return activeCode;
      break;
    }
    case 'R':{
      activeArraySize = 3;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      return activeCode;
      break;
    }
    case 'S':{
      activeArraySize = 3;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      return activeCode;
      break;
    }
    case 'T':{
      activeArraySize = 1;
      activeCode[0] = DASH;
      return activeCode;
      break;
    }
    case 'U':{
      activeArraySize = 3;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      return activeCode;
      break;
    }
    case 'V':{
      activeArraySize = 4;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DASH;
      return activeCode;
      break;
    }
    case 'W':{
      activeArraySize = 3;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      return activeCode;
      break;
    }
    case 'X':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DASH;
      return activeCode;
      break;
    }
    case 'Y':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      return activeCode;
      break;
    }
    case 'Z':{
      activeArraySize = 4;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      return activeCode;
      break;
    }

    case '1':{
      activeArraySize = 5;
      activeCode[0] = DOT;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      activeCode[4] = DASH;
      return activeCode;
      break;
    }
    case '2':{
      activeArraySize = 5;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      activeCode[4] = DASH;
      return activeCode;
      break;
    }
    case '3':{
      activeArraySize = 5;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DASH;
      activeCode[4] = DASH;
      return activeCode;
      break;
    }
    case '4':{
      activeArraySize = 5;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      activeCode[4] = DASH;
      return activeCode;
      break;
    }
    case '5':{
      activeArraySize = 5;
      activeCode[0] = DOT;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      activeCode[4] = DOT;
      return activeCode;
      break;
    }
    case '6':{
      activeArraySize = 5;
      activeCode[0] = DASH;
      activeCode[1] = DOT;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      activeCode[4] = DOT;
      return activeCode;
      break;
    }
    case '7':{
      activeArraySize = 5;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DOT;
      activeCode[3] = DOT;
      activeCode[4] = DOT;
      return activeCode;
      break;
    }
    case '8':{
      activeArraySize = 5;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DOT;
      activeCode[4] = DOT;
      return activeCode;
      break;
    }
    case '9':{
      activeArraySize = 5;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      activeCode[4] = DOT;
      return activeCode;
      break;
    }
    case '0':{
      activeArraySize = 5;
      activeCode[0] = DASH;
      activeCode[1] = DASH;
      activeCode[2] = DASH;
      activeCode[3] = DASH;
      activeCode[4] = DASH;
      return activeCode;
      break;
    }

    default:
      activeArraySize = 0;
      return activeCode;
      break;
  }
}