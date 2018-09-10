char morseCodeString[] = "HELLO WORLD AR "; // AR -> End of message. always append a SPACE to have a pause inserted.

int morseIndex, morseListIndex = 0;
int lastMorseListIndex = -1;
long morseUpdateMs = 0;
int activeArraySize = 0;

int DOT = 250; // ms
int DASH= DOT*3;
int SHORT=DOT*5;
int MEDIUM=DOT*7;

int morseCode_0[] = {DASH, DASH, DASH, DASH, DASH};

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
          morseUpdateMs = (millis() + getMorseCodeForChar(morseCodeString[morseIndex])[morseListIndex]);
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

int morseSize(char *list)
{
  int size = 0;

  for (int i = 0; i < 16; i++)
  {
    if (list[i] == '.') {
      break;
    }
    else
    {
      size++;
    }
  }

  return size;
}

int *getMorseCodeForChar(char str) {
  switch(str) {
    case 'A': {
      activeArraySize = 2;
      int code[] = {DOT, DASH};
      return code;
      break;
    }
    case 'B':{
      activeArraySize = 4;
      int code[] = {DASH, DOT, DOT, DOT};
      return code;
    }
    case 'C':{
      activeArraySize = 4;
      int code[] = {DASH, DOT, DASH, DOT};
      return code;
    }
    case 'D':{
      activeArraySize = 3;
      int code[] = {DASH, DOT, DOT};
      break;
    }
    case 'E':{
      activeArraySize = 1;
      int code[] = {DOT};
      break;
    }
    case 'F':{
      activeArraySize = 4;
      int code[] = {DOT, DOT, DASH, DOT};
      break;
    }
    case 'G':{
      activeArraySize = 3;
      int code[] = {DASH, DASH, DOT};
      break;
    }
    case 'H':{
      activeArraySize = 4;
      int code[] = {DOT, DOT, DOT, DOT};
      break;
    }
    case 'I':{
      activeArraySize = 2;
      int code[] = {DOT, DOT};
      break;
    }
    case 'J':{
      activeArraySize = 4;
      int code[] = {DOT, DASH, DASH, DASH};
      break;
    }
    case 'K':{
      activeArraySize = 3;
      int code[] = {DASH, DOT, DASH};
      break;
    }
    case 'L':{
      activeArraySize = 4;
      int code[] = {DOT, DASH, DOT, DOT};
      break;
    }
    case 'M':{
      activeArraySize = 2;
      int code[] = {DASH, DASH};
      break;
    }
    case 'N':{
      activeArraySize = 2;
      int code[] = {DASH, DOT};
      break;
    }
    case 'O':{
      activeArraySize = 3;
      int code[] = {DASH, DASH, DASH};
      break;
    }
    case 'P':{
      activeArraySize = 4;
      int code[] = {DOT, DASH, DASH, DOT};
      break;
    }
    case 'Q':{
      activeArraySize = 4;
      int code[] = {DASH, DASH, DOT, DASH};
      break;
    }
    case 'R':{
      activeArraySize = 3;
      int code[] = {DOT, DASH, DOT};
      break;
    }
    case 'S':{
      activeArraySize = 3;
      int code[] = {DOT, DOT, DOT};
      break;
    }
    case 'T':{
      activeArraySize = 1;
      int code[] = {DASH};
      break;
    }
    case 'U':{
      activeArraySize = 3;
      int code[] = {DOT, DOT, DASH};
      break;
    }
    case 'V':{
      activeArraySize = 4;
      int code[] = {DOT, DOT, DOT, DASH};
      break;
    }
    case 'W':{
      activeArraySize = 3;
      int code[] = {DOT, DASH, DASH};
      break;
    }
    case 'X':{
      activeArraySize = 4;
      int code[] = {DASH, DOT, DOT, DASH};
      break;
    }
    case 'Y':{
      activeArraySize = 4;
      int code[] = {DASH, DOT, DASH, DASH};
      break;
    }
    case 'Z':{
      activeArraySize = 4;
      int code[] = {DASH, DASH, DOT, DOT};
      break;
    }

    case '1':{
      activeArraySize = 5;
      int code[] = {DOT, DASH, DASH, DASH, DASH};
      break;
    }
    case '2':{
      activeArraySize = 5;
      int code[] = {DOT, DOT, DASH, DASH, DASH};
      break;
    }
    case '3':{
      activeArraySize = 5;
      int code[] = {DOT, DOT, DOT, DASH, DASH};
      break;
    }
    case '4':{
      activeArraySize = 5;
      int code[] = {DOT, DOT, DOT, DOT, DASH};
      break;
    }
    case '5':{
      activeArraySize = 5;
      int code[] = {DOT, DOT, DOT, DOT, DOT};
      break;
    }
    case '6':{
      activeArraySize = 5;
      int code[] = {DASH, DOT, DOT, DOT, DOT};
      break;
    }
    case '7':{
      activeArraySize = 5;
      int code[] = {DASH, DASH, DOT, DOT, DOT};
      break;
    }
    case '8':{
      activeArraySize = 5;
      int code[] = {DASH, DASH, DASH, DOT, DOT};
      break;
    }
    case '9':{
      activeArraySize = 5;
      int code[] = {DASH, DASH, DASH, DASH, DOT};
      break;
    }
    case '0':{
      activeArraySize = 5;
      int code[] = {DASH, DASH, DASH, DASH, DASH};
      break;
    }

    default:
      activeArraySize = 0;
      return {};
      break;
  }
}