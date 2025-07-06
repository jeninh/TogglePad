const int BUT1 = 26;
const int BUT2 = 27;
const int BUT3 = 28;

const int LED1 = 29;
const int LED2 = 6;
const int LED3 = 7;

bool blink1 = false;
bool blink2 = false;
bool blink3 = false;

bool led1State = false;
bool led2State = false;
bool led3State = false;

unsigned long lastBlink1 = 0;
unsigned long lastBlink2 = 0;
unsigned long lastBlink3 = 0;

unsigned long lastDebounce1 = 0;
unsigned long lastDebounce2 = 0;
unsigned long lastDebounce3 = 0;
const int debounceDelay = 50;

bool prevBut1 = false;
bool prevBut2 = false;
bool prevBut3 = false;

void setup() {
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  bool currBut1 = digitalRead(BUT1);
  bool currBut2 = digitalRead(BUT2);
  bool currBut3 = digitalRead(BUT3);

  unsigned long now = millis();

  if (currBut1 && !prevBut1 && (now - lastDebounce1 > debounceDelay)) {
    blink1 = !blink1;
    lastDebounce1 = now;
  }

  if (currBut2 && !prevBut2 && (now - lastDebounce2 > debounceDelay)) {
    blink2 = !blink2;
    lastDebounce2 = now;
  }

  if (currBut3 && !prevBut3 && (now - lastDebounce3 > debounceDelay)) {
    blink3 = !blink3;
    lastDebounce3 = now;
  }

  prevBut1 = currBut1;
  prevBut2 = currBut2;
  prevBut3 = currBut3;

  if (blink1 && (now - lastBlink1 >= 500)) {
    led1State = !led1State;
    digitalWrite(LED1, led1State);
    lastBlink1 = now;
  }

  if (blink2 && (now - lastBlink2 >= 500)) {
    led2State = !led2State;
    digitalWrite(LED2, led2State);
    lastBlink2 = now;
  }

  if (blink3 && (now - lastBlink3 >= 500)) {
    led3State = !led3State;
    digitalWrite(LED3, led3State);
    lastBlink3 = now;
  }

  if (!blink1) digitalWrite(LED1, LOW);
  if (!blink2) digitalWrite(LED2, LOW);
  if (!blink3) digitalWrite(LED3, LOW);
}
