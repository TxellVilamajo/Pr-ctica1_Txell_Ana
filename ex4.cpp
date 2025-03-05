
// CODIS UTILITZATS PER PODER RESPONDRE LES PREGUNTES DE L'APARTAT 4 UTILITZANT L'OSCIL·LOSCOPI
     // ELS CODIS ESTAN COMENTATS, JA QUE NOMÉS ES POT UTILITZAR UNA PART DEL CODI A LA VEGADA.
     // SI DESCOMENTEU LA PART DEL CODI QUE VOLEU EXECUTAR, PODREU PROVAR CADA APARTAT SEPARADAMENT.


// Part del codi comuna en tots els apartats de l'exercici
#include <Arduino.h>
#define LED_PIN 2 // Definir el pin del LED
#define DELAY 1000 // Temps d'espera de 1000 ms


// ------------------------------------------------------------------------------------------------------------
// APARTAT 1: Amb l’enviament del missatge pel port sèrie i utilitzant les funcions d’Arduino.
/* 
void setup() {
  // Establir el pin com a sortida directament a travÃ©s dels registres
  pinMode(LED_PIN, OUTPUT); // AixÃ² segueix sent necessari
  Serial.begin(115200);     // Inicialitzar la comunicaciÃ³ sÃ¨rie
}

void loop() {
  // Engegar el LED utilitzant el registre GPIO
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  *gpio_out |= (1 << LED_PIN);  // Activar el bit corresponent al pin 2
  Serial.println("ON");         // Enviar "ON" pel port sÃ¨rie
  
  
  // Apagar el LED utilitzant el registre GPIO
  *gpio_out &= ~(1 << LED_PIN); // Desactivar el bit corresponent al pin 2
  Serial.println("OFF");        // Enviar "OFF" pel port sÃ¨rie
  }

*/


// ----------------------------------------------------------------------------------------------------------------
// APARTAT 2:  Amb l’enviament del missatge pel port sèrie i accedint directament als registres
/*
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configurar el pin como salida
  Serial.begin(115200);          // Inicializar la comunicaciÃ³n serial
}

void loop() {
  // Encender el LED
  digitalWrite(LED_BUILTIN, HIGH);  
  Serial.println("ON");            // Enviar "ON" por el puerto serial


  // Apagar el LED
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("OFF");           // Enviar "OFF" por el puerto serial

}
*/

// ------------------------------------------------------------------------------------------------------------------
// APARTAT 3: Sense l’enviament del missatge pel port sèrie i utilitzant les funcions d’Arduino.
/*
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definir el pin del LED como salida
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encender el LED
    
    digitalWrite(LED_BUILTIN, LOW);   // Apagar el LED
    
}

*/

// ---------------------------------------------------------------------------------------------------------------------
// APARTAT 4: Sense l’enviament del missatge pel port sèrie i accedint directment als registres.

/*
void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configurar el pin como salida
}

void loop() {
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  
  *gpio_out |= (1 << LED_PIN);  // Encender el LED (accediendo directamente a los registros)
 
  
  *gpio_out &= ~(1 << LED_PIN); // Apagar el LED (accediendo directamente a los registros)

}
*/

