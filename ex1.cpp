#include <Arduino.h>
#define LED_BUILTIN 2
#define DELAY_TIME 500  // Cambié el nombre de la constante para evitar confusión con la función delay()

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definir el pin del LED como salida
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encender el LED
    delay(DELAY_TIME);  // Esperar un tiempo
    digitalWrite(LED_BUILTIN, LOW);   // Apagar el LED
    delay(DELAY_TIME);  // Esperar un tiempo
}
