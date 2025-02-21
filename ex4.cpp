
//3. Modificar el programa perquè actuï directament sobre els registres dels ports d'entrada i sortida
#include <Arduino.h>
#define LED_PIN 2 // Definir el pin del LED
#define DELAY 1000 // Temps d'espera de 1000 ms


/* 
void setup() {
  // Establir el pin com a sortida directament a través dels registres
  pinMode(LED_PIN, OUTPUT); // Això segueix sent necessari
  Serial.begin(115200);     // Inicialitzar la comunicació sèrie
}

void loop() {
  // Engegar el LED utilitzant el registre GPIO
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  *gpio_out |= (1 << LED_PIN);  // Activar el bit corresponent al pin 2
  Serial.println("ON");         // Enviar "ON" pel port sèrie
  
  
  // Apagar el LED utilitzant el registre GPIO
  *gpio_out &= ~(1 << LED_PIN); // Desactivar el bit corresponent al pin 2
  Serial.println("OFF");        // Enviar "OFF" pel port sèrie
  }
  

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


  // Apagar el LED
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("OFF");           // Enviar "OFF" por el puerto serial

}


#include <Arduino.h>
#define LED_BUILTIN 2
#define DELAY_TIME 500  // Cambié el nombre de la constante para evitar confusión con la función delay()

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definir el pin del LED como salida
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encender el LED
    
    digitalWrite(LED_BUILTIN, LOW);   // Apagar el LED
    
}

*/

#define LED_PIN 2 // Definir el pin del LED


void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configurar el pin como salida
}

void loop() {
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  
  *gpio_out |= (1 << LED_PIN);  // Encender el LED (accediendo directamente a los registros)
 
  
  *gpio_out &= ~(1 << LED_PIN); // Apagar el LED (accediendo directamente a los registros)

}

