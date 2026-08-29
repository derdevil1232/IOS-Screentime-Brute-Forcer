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
    for (int j = 0; j < 4; j++) {
      KeyboardBLE.write(combo[j]);
      delay(50);
    }
    Serial.println(combo);
    delay(50);
  }
  digitalWrite(LED, LOW);
}
void loop() {
  delay(1000);
}