#include <Arduino.h>

#define LED_BUILTIN 2      // Definim el pin del LED
#define DELAY_TIME 1000   // Definim un temps d'epera de 1000 ms = 1s

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configurem el pin del LED com a pin de sortida
  Serial.begin(115200);          // Iniciem la comunicació amb el port sèrie
}

void loop() {
  // Encender el LED
  digitalWrite(LED_BUILTIN, HIGH);  
  Serial.println("ON");            // Enviem "ON" pel port serial
  delay(DELAY_TIME);               // Esperem 1000 ms (temps definit a l'inici del programa)

  // Apagar el LED
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("OFF");           // Enviem "OFF" pel port serial
  delay(DELAY_TIME);               // Esperem 1000 ms (temps definit a l'inici del programa)
}



