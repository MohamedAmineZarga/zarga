// Smart Weeding Reception Arduino Code 
// Projet C++ 2A


// Declaration des variables necessaires pour Le capteur de temperature
#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

// declaration des variables necessaires pour le capteur de buzzer
const int buzzer = 9 ; // buzzer connect to arduino pin 9


// Variable contenant la caractére lu
char data ;



DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  dht.begin();
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT) ; // set buzzer pin 1 as an output 
}

void loop() {
 

  
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
  
// Buzzer CODE 



 if ( Serial.available()>0) 
{

  data = Serial.read(); 

  if (data=='1')
  {
      tone(buzzer, 1000); // Send 1KHz sound signal...
      Serial.write("Climatiseur/Chauufage Active\n") ;
      
     delay(1000);        // ...for 1 sec
    
  }

  else if ( data =='0')
  {
      
      noTone(buzzer);     // Stop sound...
      Serial.write("Climatiseur/Chauufage Desactive \n") ;
      
      delay(1000);        // ...for 1sec
    
  }
 
}

  
}
