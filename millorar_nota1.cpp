#include <Arduino.h>

// Definició de pins
const int pin_DAC = 25;  // Simulació de DAC amb PWM
const int pin_LED = 2;    // Pin del LED integrat de l'ESP32 (GPIO2)

void setup() {
    Serial.begin(115200);  // Inicialitza comunicació sèrie
    analogReadResolution(12); // Configura resolució de l'ADC (0-4095)
    
    // Configurar canal PWM per simular DAC
    ledcSetup(0, 5000, 8);  // Canal 0, freqüència 5kHz, resolució de 8 bits (0-255)
    ledcAttachPin(pin_DAC, 0); // Assigna el pin al canal PWM
    
    // Configurar el pin del LED com a sortida
    pinMode(pin_LED, OUTPUT);  
    digitalWrite(pin_LED, LOW);  // Assegura que el LED integrat estigui apagat
}

void loop() {
    unsigned long temps = millis();  // Obtenim el temps en mil·lisegons des de l'inici

    // Generar un valor de simulació que depengui del temps (sinusoidal, o altre tipus de canvi)
    int valorSimulat = (sin(temps * 0.001) * 2048) + 2048;  // Sinusoidal de 0 a 4095
    int valorMapejat = map(valorSimulat, 0, 4095, 0, 255);  // Mapeig per PWM (8 bits)
    
    // Escriure valors al "DAC" (PWM)
    ledcWrite(0, valorMapejat); // Escriu valor al PWM (DAC simulat)

    // Mostra per sèrie
    Serial.print("Valor PWM (DAC): ");
    Serial.print(valorMapejat);
    Serial.print(" -> Valor ADC simulat: ");
    Serial.println(valorMapejat);

    delay(100);  // Retard per permetre una lectura més estable
}
