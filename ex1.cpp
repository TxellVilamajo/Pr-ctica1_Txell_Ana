#include <Arduino.h>
#define LED_BUILTIN 2
#define DELAY_TIME 500  // Canviem el nom de la constant per evitar possibles confusions

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definim el pin on situem el LED com a pin de sortida
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encenem el LED
    delay(DELAY_TIME);  // Esperem el temps determinat (500 ms)
    digitalWrite(LED_BUILTIN, LOW);   // Apaguem el LED
    delay(DELAY_TIME);  // Esperem el temps determinat (500 ms)
}
