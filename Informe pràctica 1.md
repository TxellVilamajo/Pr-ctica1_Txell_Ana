# PRÀCTICA 1: BLINK

## 1. INTRODUCCIÓ:
**OBJECTIU:**

L’objectiu principal d’aquesta pràctica és aprendre a programar el microcontrolador ESP32-S3 per tal de produir el parpelleig periòdic d’un led. Utilitzarem la sortida sèrie per depurar el programa. Realitzar aquesta pràctica ens permetrà comprovar que el microprocessador funciona correctement i indroduïrnos en la programació d’aquests tipus de components. 

Inicialment, implementarem el codi bàsic proporcionat per poder encendre i apagar el LED cada 500 ms. Posteriorment, afegirem la comunicació per port sèrie i optimitzarem l'eficiència mitjançant accessos directes als registres del microcontrolador.

**MATERIAL UTILITZAT:**
- Microcontrolador ESP32-S3
- Protoboard
- Led
- Oscil·loscopi
- PC amb connexió sèrie
- PlatformIO

## 2. DESENVOLUPAMENT I IMPLEMENTACIÓ

<!-- ECIDIR QUINA OPCIÓ POSAR! --> 
Per poder veure els codis realitzats per la pràctica, accediu al següent enllaç:  
👉 [GitHub - Txell Vilamajo i Ana Fernández](https://github.com/TxellVilamajo/Pr-ctica1_Txell_Ana.git)

### 1. Generar el codi proporcionat i pujar-lo al GitHub
Per poder començar la pràctica ens hem basat en el codi bàsic que ens proporcionava la guia de la pràctica. Aquest codi fa que un LED connectat al microcontrolador ESP32-S3 parpellegi de manera contínua. Per aconseguir-ho, s'encén el LED, es manté així durant un instant de temps (500 ms), després s'apaga i es torna a esperar el mateix temps abans de repetir el cicle. Aquest procés es repeteix indefinidament, d’aquesta manera es crea l’efecte de parpelleig.

```cpp
#include <Arduino.h>
#define LED_BUILTIN 2 // Definim el pin del microprocesador on situarem el led
#define DELAY_TIME 500  // Definim el temps d’espera (delay). Per tal que no hi hagi confusions amb la funció delay hem anomenat la variable delay_time. 

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definim el pin LED com a sortida
}

void loop() { 
    digitalWrite(LED_BUILTIN, HIGH);  // Encendre el LED
    delay(DELAY_TIME);  // Esperem el temps definit (500 ms)
    digitalWrite(LED_BUILTIN, LOW);   // Apagar el LED 
    delay(DELAY_TIME);  // Esperem el temps definit (500 ms) 
}
```

Un cop executat el codi hem pogut veure que, efectivament, el codi compleix les instruccions demanades, és a dir, el codi crea un bucle infinit que encén el LED, espera 500ms, apaga el LED i torna a esperar 500ms. 


### 2. Modificar el programa per tal que inclogui l'enviament de dades (ON i OFF) al port serie.

El següent pas que hem realitzat és modificar el programa per tal que aquest enviï dades (ON i OFF) al port sèrie. És a dir, volem poder visualitzar a l’ordinador si el led està apagat o encès i canviar el temps d’espera a 1000 ms (1000 ms = 1 s). 

Per tant necessitem seguir les instruccions següents:


<div style="background-color: pink; padding: 10px; border-radius: 10px; color: black;">
    <pre style="background-color: transparent; margin: 0; padding: 0;">
    Bucle infinit
        - Engegar LED
        - Enviar per port sèrie missatge "ON"
        - Espera de 1000 mil·lisegons
        - Apagar LED
        - Enviar per port sèrie missatge "OFF"
        - Espera de 1000 mil·lisegons
    </pre>
</div>


Per poder enviar els missatges desitjats pel port sèrie necessitem utilitzar les següents funcions:


```cpp
Serial.begin(115200); // Velocitat del monitor 
Serial.println("ON"); // Imprimim pel port serie el missatge "ON"
Serial.println("OFF"); // Imprimim pel port serie el missatge "OFF"
```

Així doncs esperem que el programa ens mostri ON, OFF, ON, OFF …  Amb un espai de temps de aproximadament 1s entre cada missatge. 

```cpp
#include <Arduino.h>

#define LED_BUILTIN 2    // Definim el pin del LED
#define DELAY_TIME 1000   // Definim un temps d’espera de 1000 ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  //  Configurem el pin per tal que sigui de sortida
  Serial.begin(115200);    //  Inicialitzem la comunicació amb el port serie
}

void loop() { // CREEM UN BUCLE
  digitalWrite(LED_BUILTIN, HIGH);   // Encenem el LED
  Serial.println("ON");     // Enviem “ON” pel port sèrie
  delay(DELAY_TIME);    // Esperem 1000 ms (temps d’espera definit a l’inici del programa). 
  digitalWrite(LED_BUILTIN, LOW);  // Apaguem el led
  Serial.println("OFF");           // Enviem “OFF” pel port sèrie
  delay(DELAY_TIME);         // Esperem 1000 ms
}
```

Un cop posat en marxa el programa hem pogut comprovar que, efectivament, el microcontrolador envia un missatge pel port sèrie que permet que el PC ens mostri si el LED està obert (ON) o apagat (OFF).

### 3. Modificar el programa per tal que actui sobre els registres dels ports d'entrada i sortida

El següent pas que hem realitzat és modificar el programa per tal que actuï directament sobre els registres dels ports d’entrada i de sortida. Per fer-ho utilitzem les següents funcions (proporcionades a la guia de la pràctica):

```cpp
uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG; // Estebleix un punter al registre de I/O
*gpio_out |= (1 << 2); // AActiva el bit corresponent al pin 2
*gpio_out ^= (1 << 2); // Alterna l'estat del bit corresponent al pin 2
```
Així doncs, el codi modificat per tal que el programa actui directament sobre els registres els ports d'entrada i de sortida és el següent:

```cpp 
#include <Arduino.h>

#define LED_PIN 2    // Definim el pin del LED
#define DELAY_TIME 1000   // Definim un temps d’espera de 1000 ms

void setup() {
  // Establir el pin com a sortida directament a travÃ©s dels registres
  pinMode(LED_PIN, OUTPUT);   // Seguim necessitant definir el pin 2 com a pin de sortida. 
  Serial.begin(115200);   // Inicialitzem la comunicació sèrie
}

void loop() {   // CREEM UN BUCLE
       // Engaguem el LED utilitzant el registre GPIO
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;  
  *gpio_out |= (1 << LED_PIN);  // Activem el pin que correspon al pin 2
  Serial.println("ON");     //  Enviem el missatge  “ON” pel port sèrie
  delay(DELAY_TIME);         // Esperem 1000 ms (temps d’espera definit) 
  
       // Apaga¡uem el LED utilitzant el registre GPIO
  *gpio_out &= ~(1 << LED_PIN);   // Desectivem el bit corresponent al pin       
  Serial.println("OFF");        //  Enviem el missatge  “OFF” pel port sèrie
  delay(DELAY_TIME);       // Esperem 1000 ms (temps d’espera definit) 
}
```

En aquest cas no podem veure una diferència visualment parlant comparat amb el programa anterior, però si que podem afirmar que aquest mètode permet un control més eficient del LED a nivell de registre, en lloc d’utilitzar digitalWrite(), de manera que obtenim un millor rendiment. 

### 4. Eliminar els delays i modificar el pin de sortida a qualsevol dels que estan disponibles i analitzar els següents quatre casos
Finalment se’ns demana que eliminem els delays i observem per l’oscil·loscopi el comportament del led en 4 casos diferents:

**1. Amb l’enviament del missatge pel port sèrie i utilitzant les funcions d’Arduino:**
```cpp
#include <Arduino.h>
#define LED_PIN 2 // Definimr el pin del LED
#define DELAY 1000 // Definim un temps d'espera de 1000 ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   //  Definim que el pin 2 és un pin de  sortida
  Serial.begin(115200);  //  Inicialitzem la comunicació al port sèrie
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);    //  Encenem el LED
  Serial.println("ON");       //   Enviem el missatge “ON” pel port sèrie
 
  digitalWrite(LED_BUILTIN, LOW);   //  Apaguem el LED
  Serial.println("OFF");    //   Enviem el missatge “OFF” pel port sèrie
}
```
RESULTAT OBTINGUT A L'OSCIL·LOSCOPI:
<!-- Inserim la imatge del primer apartat -->
<img src="https://i.imgur.com/lLrMZo7.jpg" width="500"> 

Podem veure que passa el mateix que el cas anterior. És a dir a la representació de l’oscil·loscopi es pot veure el canvi de valor de 1 (ON) i 0 (OFF) i el temps que tarda el serial a enviar pel port sèrie el missatge per tal que el PC ho mostri per pantalla. 

**2. Amb l’enviament del missatge pel port sèrie i accedint directament als registres**
```cpp
#include <Arduino.h>
#define LED_PIN 2 // Definimr el pin del LED
#define DELAY 1000 // Definim un temps d'espera de 1000 ms

void setup() {
  // Establir el pin com a sortida directament a través dels registres
  pinMode(LED_PIN, OUTPUT);  //  Seguim necessitat definir que el pin 2 és un pin de sortida
  Serial.begin(115200);  // Inicialitzem la comunicació amb el port sèrie 
} 

void loop() {
  // Engeguem el LED utilitzant el registre GPIO
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  *gpio_out |= (1 << LED_PIN);  // Activem el bit corresponent al pin 2
  Serial.println("ON");         // Enviem el missatge "ON" pel port serie
  
  // Apaguem el LED utilitzant el registre GPIO
  *gpio_out &= ~(1 << LED_PIN); // Desactivem el bit corresponent al pin 2
  Serial.println("OFF");        // Enviem el missatge "OFF" pel port serie
  }
```

RESULTAT OBTINGUT A L'OSCIL·LOSCOPI:

<img src="https://i.imgur.com/BO3V03U.jpg" width="500">

A la representació de l'oscil·loscopi podem veure el temps que tarda el serial a enviar el missatge pel port sèrie per tal que per pantalla es mostri si el led està encès (ON) o apagat (OFF). Per això a la imatge es veu els punts on prenen el valor 1, però el temps que triga a enviar el missatge es manté a 0.



<p><span style="color:red;">Per tant, podem afirmar que enviant el missatge pel port sèrie el rendiment és molt similar utilitzant les funcions d’Arduino o accedint directament als registres, ja que si ens en la freqüència en que pren el valor 1, és la mateixa.</span></p>

**3. Sense l’enviament del missatge pel port sèrie i utilitzant les funcions d’Arduino**
```cpp
#include <Arduino.h>
#define LED_PIN 2 // Definimr el pin del LED
#define DELAY 1000 // Definim un temps d'espera de 1000 ms

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  // Definim el pin del LED como salida
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encenem el LED
    
    digitalWrite(LED_BUILTIN, LOW);   // Apaguem el LED
    
}
```

RESULTAT OBTINGUT A L'OSCIL·LOSCOPI:

<img src="https://i.imgur.com/Ye4aZMX.jpg" width="500">

Podem veure que el canvi de 1 a 0 (de ON a OFF) ara és molt més freqüent. Això molt probablement és degut a que el microprocessador no ha d’enviar el missatge a través del port sèrie per tal de mostrar per pantalla si el LED està encès o apagat. Això ens fa adonar-nos que realment, tot i que visualment no ho sembli perquè estem parlant de fraccions de temps molt petites, l’enviament del missatge cap a l’ordinador necessita un temps força gran.

**4. Sense l’enviament del missatge pel port sèrie i accedint directment als registres**
```cpp
#include <Arduino.h>
#define LED_PIN 2 // Definimr el pin del LED
#define DELAY 1000 // Definim un temps d'espera de 1000 ms

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configurem el pin com a sortida 
}

void loop() {
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;  // Apuntem a l'adreça del registre GPIO
  *gpio_out |= (1 << LED_PIN);  // Encenem el LED accedint directament als registres   
  *gpio_out &= ~(1 << LED_PIN);  // Apaguem el LED accedint directament als registres 
}
```

RESULTAT OBTINGUT A L'OSCIL·LOSCOPI:
<p><span style="color:red;">D’aquest apartat no disposem de cap fotografia ja que el programa realitzat no sabem per què però no ens va funcionar a cap dels grups del laboratori. </span></p>

### Generar un diagrama de fluxe i un diagrama de temps
```mermaid
flowchart TD
    A[Inici del programa] --> B[Configurar el pin LED_BUILTIN com a sortida]
    B --> C[Entra a la funció loop()]
    C --> D[Encendre el LED (HIGH)]
    D --> E[Esperar 500 ms (delay)]
    E --> F[Apagar el LED (LOW)]
    F --> G[Esperar 500 ms (delay)]
    G --> C
```

## 3. ACTIVITATS DE MILLORA DE NOTA


## 4. CONCLUSIONS

Un cop finalitzada la pràctica, podem afirmar que ens ha permès introduir-nos en la programació del microcontrolador ESP32-S3 i comprovar el seu funcionament mitjançant el parpelleig (blinking”) del LED. Hem après a utilitzar tant les funcions d’Arduino com l’accés directe als registres del microcontrolador, i hem pogut identificar les diferències que hi ha, eficientment parlant, entre aquestes dues tècniques.  

L’ús del port sèrie per monitoritzar l’estat del LED ens ha fet adonar que aquest procés introdueix un retard significatiu en l’execució del programa. Això ho hem pogut veure quan hem realitzat les mesures amb l'oscil·loscopi,  ja que hem vist que es necessita un temps força gran per tal d’enviar el missatge de “ON” o “OFF” pel port sèrie. 

A més, hem pogut comprovar que, quan es treballa directament sobre els registres, tot i que visualment el comportament del LED sigui el mateix, el control del microcontrolador és més eficient. Tot i això, en l’últim apartat de la pràctica, en què havíem d’eliminar els retards i treballar directament amb registres sense enviar dades pel port sèrie, no hem aconseguit obtenir resultats correctes. Això ens indica que podríem haver comès algún error en la implementació del codi o en la configuració del microcontrolador, tot i que a classe no vam ser capaços de trobar aquest error. 
