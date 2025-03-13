#include <Arduino.h>

// Definició de pins
const int pin_DAC = 25;  // Simulació de DAC amb PWM
const int pin_LED = 2;    // Pin del LED integrat de l'ESP32 (GPIO2) --> Necessitem declarar-lo ja que hem d'indicar que es mantingui apagat, si no durant l'execució del programa es mantindrà encès. 

void setup() {
    Serial.begin(115200);  // Inicialitzem la comunicació sèrie
    analogReadResolution(12); // Configurem la resolució de l'ADC (0-4095)
    
    // Configurem el canal PWM per simular DAC
    ledcSetup(0, 5000, 8);  // Canal 0, freqüència 5kHz, resolució de 8 bits (0-255)
    ledcAttachPin(pin_DAC, 0); // Assignem el pin al canal PWM
    
    // Configurem el pin del LED com a sortida
    pinMode(pin_LED, OUTPUT);  
    digitalWrite(pin_LED, LOW);  // Assefurem que el LED integrat estigui apagat
}

void loop() {
    unsigned long temps = millis();  // Obtenim el temps en mil·lisegons des de l'inici

    // Generem un valor de simulació que depengui del temps (sinusoidal, o altre tipus de canvi) ja que no tenim potenciometre
    int valorSimulat = (sin(temps * 0.001) * 2048) + 2048;  // Sinusoidal de 0 a 4095
    int valorMapejat = map(valorSimulat, 0, 4095, 0, 255);  // Mapeig per PWM (8 bits)
    
    // Escriure valors al "DAC" (PWM)
    ledcWrite(0, valorMapejat); // Escriu valor al PWM (DAC simulat)

    // Mostrem per sèrie
    Serial.print("Valor PWM (DAC): ");
    Serial.print(valorMapejat);
    Serial.print(" -> Valor ADC simulat: ");
    Serial.println(valorMapejat);

    delay(100);  // Retard per permetre una lectura més estable
}
