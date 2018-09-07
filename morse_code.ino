char morseCodeString[] = "HELLO WORLD AR "; // AR -> End of message. always append a SPACE to have a pause inserted.

int morseIndex, morseListIndex = 0;
int lastMorseListIndex = -1;
long morseUpdateMs = 0;
int activeArraySize = 0;

int DOT = 250; // ms
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
    case 'A':
      activeArraySize = (sizeof(morseCode_A)/sizeof(morseCode_A[0]));
      return morseCode_A;
      break;
    case 'B':
      activeArraySize = (sizeof(morseCode_B) / sizeof(morseCode_B[0]));
      return morseCode_B;
    case 'C':
      activeArraySize = (sizeof(morseCode_C) / sizeof(morseCode_C[0]));
      return morseCode_C;
      break;
    case 'D':
      activeArraySize = (sizeof(morseCode_D) / sizeof(morseCode_D[0]));
      return morseCode_D;
      break;
    case 'E':
      activeArraySize = (sizeof(morseCode_E) / sizeof(morseCode_E[0]));
      return morseCode_E;
      break;
    case 'F':
      activeArraySize = (sizeof(morseCode_F) / sizeof(morseCode_F[0]));
      return morseCode_F;
      break;
    case 'G':
      activeArraySize = (sizeof(morseCode_G) / sizeof(morseCode_G[0]));
      return morseCode_G;
      break;
    case 'H':
      activeArraySize = (sizeof(morseCode_H) / sizeof(morseCode_H[0]));
      return morseCode_H;
      break;
    case 'I':
      activeArraySize = (sizeof(morseCode_I) / sizeof(morseCode_I[0]));
      return morseCode_I;
      break;
    case 'J':
      activeArraySize = (sizeof(morseCode_J) / sizeof(morseCode_J[0]));
      return morseCode_J;
      break;
    case 'K':
      activeArraySize = (sizeof(morseCode_K) / sizeof(morseCode_K[0]));
      return morseCode_K;
      break;
    case 'L':
      activeArraySize = (sizeof(morseCode_L) / sizeof(morseCode_L[0]));
      return morseCode_L;
    case 'M':
      activeArraySize = (sizeof(morseCode_M) / sizeof(morseCode_M[0]));
      return morseCode_M;
      break;
    case 'N':
      activeArraySize = (sizeof(morseCode_N) / sizeof(morseCode_N[0]));
      return morseCode_N;
      break;
    case 'O':
      activeArraySize = (sizeof(morseCode_O) / sizeof(morseCode_O[0]));
      return morseCode_O;
    case 'P':
      activeArraySize = (sizeof(morseCode_P) / sizeof(morseCode_P[0]));
      return morseCode_P;
      break;
    case 'Q':
      activeArraySize = (sizeof(morseCode_Q) / sizeof(morseCode_Q[0]));
      return morseCode_Q;
      break;
    case 'R':
      activeArraySize = (sizeof(morseCode_R) / sizeof(morseCode_R[0]));
      return morseCode_R;
      break;
    case 'S':
      activeArraySize = (sizeof(morseCode_S) / sizeof(morseCode_S[0]));
      return morseCode_S;
      break;
    case 'T':
      activeArraySize = (sizeof(morseCode_T) / sizeof(morseCode_T[0]));
      return morseCode_T;
      break;
    case 'U':
      activeArraySize = (sizeof(morseCode_U) / sizeof(morseCode_U[0]));
      return morseCode_U;
      break;
    case 'V':
      activeArraySize = (sizeof(morseCode_V) / sizeof(morseCode_V[0]));
      return morseCode_V;
      break;
    case 'W':
      activeArraySize = (sizeof(morseCode_W) / sizeof(morseCode_W[0]));
      return morseCode_W;
      break;
    case 'X':
      activeArraySize = (sizeof(morseCode_X) / sizeof(morseCode_X[0]));
      return morseCode_X;
      break;
    case 'Y':
      activeArraySize = (sizeof(morseCode_Y) / sizeof(morseCode_Y[0]));
      return morseCode_Y;
      break;
    case 'Z':
      activeArraySize = (sizeof(morseCode_Z) / sizeof(morseCode_Z[0]));
      return morseCode_Z;
      break;

    case '1':
      activeArraySize = (sizeof(morseCode_1) / sizeof(morseCode_1[0]));
      return morseCode_1;
      break;
    case '2':
      activeArraySize = (sizeof(morseCode_2) / sizeof(morseCode_2[0]));
      return morseCode_2;
      break;
    case '3':
      activeArraySize = (sizeof(morseCode_3) / sizeof(morseCode_3[0]));
      return morseCode_3;
      break;
    case '4':
      activeArraySize = (sizeof(morseCode_4) / sizeof(morseCode_4[0]));
      return morseCode_4;
      break;
    case '5':
      activeArraySize = (sizeof(morseCode_5) / sizeof(morseCode_5[0]));
      return morseCode_5;
      break;
    case '6':
      activeArraySize = (sizeof(morseCode_6) / sizeof(morseCode_6[0]));
      return morseCode_6;
      break;
    case '7':
      activeArraySize = (sizeof(morseCode_7) / sizeof(morseCode_7[0]));
      return morseCode_7;
      break;
    case '8':
      activeArraySize = (sizeof(morseCode_8) / sizeof(morseCode_8[0]));
      return morseCode_8;
      break;
    case '9':
      activeArraySize = (sizeof(morseCode_9) / sizeof(morseCode_9[0]));
      return morseCode_9;
      break;
    case '0':
      activeArraySize = (sizeof(morseCode_0) / sizeof(morseCode_0[0]));
      return morseCode_0;
      break;

    default:
      activeArraySize = 0;
      return {};
      break;
  }
}