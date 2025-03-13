#include <Arduino.h>
#include "esp_adc_cal.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
}
  
void loop() {
    
    float tempC = temperatureRead();  // Llegir la temperatura interna de l'ESP32-S3
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.println(" °C");
    delay(5000);
}
