char morseCodeString[] = "HELLO WORLD ";
boolean morseCodeDie = false;

int morseIndex, morseListIndex = 0;
int lastMorseListIndex = -1;
long morseUpdateMs = 0;

int DOT = 100; // ms
int DASH= DOT*3;
int SHORT=DOT*5;
int MEDIUM=DOT*7;

int morseCode_A[] = {DOT, DASH};
int morseCode_B[] = {DASH, DOT, DOT, DOT};
int morseCode_C[] = {DASH, DOT, DASH, DOT};
int morseCode_D[] = {DASH, DOT, DOT};
int morseCode_E[] = {DOT};
int morseCode_F[] = {DOT, DOT, DASH, DOT};
int morseCode_G[] = {DASH, DASH, DOT};
int morseCode_H[] = {DOT, DOT, DOT, DOT};
int morseCode_I[] = {DOT, DOT};
int morseCode_J[] = {DOT, DASH, DASH, DASH};
int morseCode_K[] = {DASH, DOT, DASH};
int morseCode_L[] = {DOT, DASH, DOT, DOT};
int morseCode_M[] = {DASH, DASH};
int morseCode_N[] = {DASH, DOT};
int morseCode_O[] = {DASH, DASH, DASH};
int morseCode_P[] = {DOT, DASH, DASH, DOT};
int morseCode_Q[] = {DASH, DASH, DOT, DASH};
int morseCode_R[] = {DOT, DASH, DOT};
int morseCode_S[] = {DOT, DOT, DOT};
int morseCode_T[] = {DASH};
int morseCode_U[] = {DOT, DOT, DASH};
int morseCode_V[] = {DOT, DOT, DOT, DASH};
int morseCode_W[] = {DOT, DASH, DASH};
int morseCode_X[] = {DASH, DOT, DOT, DASH};
int morseCode_Y[] = {DASH, DOT, DASH, DASH};
int morseCode_Z[] = {DASH, DASH, DOT, DOT};

int morseCode_1[] = {DOT, DASH, DASH, DASH, DASH};
int morseCode_2[] = {DOT, DOT, DASH, DASH, DASH};
int morseCode_3[] = {DOT, DOT, DOT, DASH, DASH};
int morseCode_4[] = {DOT, DOT, DOT, DOT, DASH};
int morseCode_5[] = {DOT, DOT, DOT, DOT, DOT};
int morseCode_6[] = {DASH, DOT, DOT, DOT, DOT};
int morseCode_7[] = {DASH, DASH, DOT, DOT, DOT};
int morseCode_8[] = {DASH, DASH, DASH, DOT, DOT};
int morseCode_9[] = {DASH, DASH, DASH, DASH, DOT};
int morseCode_0[] = {DASH, DASH, DASH, DASH, DASH};

void MODE_morsecode() {

  // for(int i = 0; i < sizeof(morseCodeString); i++) {
  //   if (morseCodeString[i] == ' ') {
  //     // color off
  //     sleep(MEDIUM);
  //     continue;
  //   }

  //   int *list = getMorseCodeForChar(morseCodeString[i]);


  //   for(int j = 0; j < sizeof(list); j++) {
  //     // color on
  //     sleep(list[j]);
  //     // color off
  //     sleep(DOT);
  //   }

  //   // color off
  //   sleep(DASH);
  // }
  if (millis() > morseUpdateMs) {
    animateMorseCode();
  }
}

void animateMorseCode() {
  if (morseIndex < sizeof(morseCodeString)) {
    if (morseCodeString[morseIndex] == ' ') {
      resetLeds();
      morseUpdateMs = (millis()+MEDIUM);
      morseIndex++;
    } else {

      int *list = getMorseCodeForChar(morseCodeString[morseIndex]);
      if (morseListIndex < sizeof(list)) {
        if (lastMorseListIndex == morseListIndex) {
          resetLeds();
          morseUpdateMs = (millis()+DOT);
          morseListIndex++;
        } else {
          morseLedsOn();
          morseUpdateMs = (millis() + list[morseListIndex]);
          lastMorseListIndex = morseListIndex;
        }
      } else {
        morseListIndex = 0;
        lastMorseListIndex = -1;
      }
    }

  } else {
    morseIndex = 0;
  }
}

void morseLedsOn() {
  setColor(redPin, maxBrightness);
  setColor(greenPin, maxBrightness);
  setColor(bluePin, maxBrightness);
}

// void sleep(long ms) {
//   handleButton(buttonPin);
  // morseCodeString[morseIndex];//   delay(ms);
//   if (true) {} // detect if mode changed
//   morseCodeDie = false;
//   resetButtonData();
// }

int* getMorseCodeForChar(char str) {
  switch(str) {
    case 'A':
      return morseCode_A;
      break;
    case 'B':
      return morseCode_B;
    case 'C':
      return morseCode_C;
      break;
    case 'D':
      return morseCode_D;
      break;
    case 'E':
      return morseCode_E;
      break;
    case 'F':
      return morseCode_F;
      break;
    case 'G':
      return morseCode_G;
      break;
    case 'H':
      return morseCode_H;
      break;
    case 'I':
      return morseCode_I;
      break;
    case 'J':
      return morseCode_J;
      break;
    case 'K':
      return morseCode_K;
      break;
    case 'L':
      return morseCode_L;
    case 'M':
      return morseCode_M;
      break;
    case 'N':
      return morseCode_N;
      break;
    case 'O':
      return morseCode_O;
    case 'P':
      return morseCode_P;
      break;
    case 'Q':
      return morseCode_Q;
      break;
    case 'R':
      return morseCode_R;
      break;
    case 'S':
      return morseCode_S;
      break;
    case 'T':
      return morseCode_T;
      break;
    case 'U':
      return morseCode_U;
      break;
    case 'V':
      return morseCode_V;
      break;
    case 'W':
      return morseCode_W;
      break;
    case 'X':
      return morseCode_X;
      break;
    case 'Y':
      return morseCode_Y;
      break;
    case 'Z':
      return morseCode_Z;
      break;

    case '1':
      return morseCode_1;
      break;
    case '2':
      return morseCode_2;
      break;
    case '3':
      return morseCode_3;
      break;
    case '4':
      return morseCode_4;
      break;
    case '5':
      return morseCode_5;
      break;
    case '6':
      return morseCode_6;
      break;
    case '7':
      return morseCode_7;
      break;
    case '8':
      return morseCode_8;
      break;
    case '9':
      return morseCode_9;
      break;
    case '0':
      return morseCode_0;
      break;

    default:
      return {};
      break;
  }
}