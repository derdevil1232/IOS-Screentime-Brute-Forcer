#include <KeyboardBLE.h>

const int LED = LED_BUILTIN;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  KeyboardBLE.begin("PicoKey");

  for (int i = 0; i < 30; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
  digitalWrite(LED, HIGH);

  for (int i = 0; i < 10000; i++) {
    char combo[5];
    snprintf(combo, sizeof(combo), "%04d", i);
    KeyboardBLE.print(combo);
    KeyboardBLE.write(KEY_RETURN);
    Serial.println(combo);
    delay(500);
  }
  digitalWrite(LED, LOW);
}

void loop() {
  delay(1000);
}