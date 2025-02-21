#include <Arduino.h>

#define LED_BUILTIN 2      // Definir el pin del LED
#define DELAY_TIME 1000   // Tiempo de espera de 1000 ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configurar el pin como salida
  Serial.begin(115200);          // Inicializar la comunicación serial
}

void loop() {
  // Encender el LED
  digitalWrite(LED_BUILTIN, HIGH);  
  Serial.println("ON");            // Enviar "ON" por el puerto serial
  delay(DELAY_TIME);               // Esperar 1000 ms

  // Apagar el LED
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("OFF");           // Enviar "OFF" por el puerto serial
  delay(DELAY_TIME);               // Esperar 1000 ms
}





