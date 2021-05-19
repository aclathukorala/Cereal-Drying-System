int ledpin1=13;
int ledpin2=11;

#define trig 2  //ultra sonic
#define echo 4  //ultra sonic

#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // Digital DHT sensor (temp)
DHT dht(DHTPIN, DHTTYPE); // Digital DHT sensor (temp)


void setup() {
Serial.begin(9600);

Serial.println(F("DHTxx test!")); // Digital DHT sensor (temp)
dht.begin();  // Digital DHT sensor (temp)

pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);

pinMode(trig, OUTPUT);//ultra sonic
pinMode(echo, INPUT);//ultra sonic

pinMode(5, OUTPUT);//relay mod (vibration moter)

pinMode(6,OUTPUT); //realy mod (hitters)

// under load cell code start


  //load cell code end

  pinMode(7, OUTPUT); //motor driver
  pinMode(8, OUTPUT); //motor driver
  
  pinMode(9, OUTPUT); //motor driver
  pinMode(10, OUTPUT); //motor driver

  pinMode(11, OUTPUT); //door 1 moter
  pinMode(12, OUTPUT); //door 2 moter

  
}

void loop() {

if(Serial.available() > 0)
{
  char data;

  data = Serial.read();
 // Serial.write(Serial.read());

  switch (data)
  {
    case '1':

   // wight sensor 1

    
   
    
    break;

    case '3':
    {

    digitalWrite(10, HIGH);
    Serial.println("door moter left"); 
    delay(800);
    digitalWrite(11, LOW);
    delay(100);
  
    digitalWrite(10,HIGH);
    Serial.println("door moter right"); 
    delay(800);
    digitalWrite(11, LOW);
    delay(100);

    digitalWrite(10,LOW);
    Serial.println("door moter off..!!"); 
    delay(800);
    digitalWrite(11, LOW);
    delay(100);
  
    // digitalWrite(8, HIGH);
   // digitalWrite(7, LOW);
  //  delay(1000);
  
   // digitalWrite(8, LOW);
   // digitalWrite(7, LOW);
   // delay(1000);
  
  }

    break;
    
    case '4':
    {
    digitalWrite(5,HIGH); //relay mod (vm)
    Serial.print("Relay vibration moter on..!!"); 
    delay(400); //relay mod (vm)
    digitalWrite(5,LOW); //relay mod (vm)
    delay(400); //relay mod (vm)
    }
    break;

    case '5':
{
    digitalWrite(6,HIGH);  //realy mod (hitters)
    Serial.println("hitters  On! ");
    delay(400); //realy mod (hitters)
    digitalWrite(6,LOW); //realy mod (hitters) 
    Serial.println("hitters  off!");
    delay(400); //realy mod (hitters)

    

}
    break;

    case '6': // Digital DHT sensor (temp)

{
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

}
    break;

    case '7':{
    
//wight sense 2
  

    }
    break;

    case '8':
    {

//door 2



    }
    break;
    
    }
  }
}
