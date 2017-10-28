#include "DHT.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <ArduinoJson.h>


//lcd
rgb_lcd lcd;
const int colorR = 0;
const int colorG = 150;
const int colorB = 255;


//connect light temperature & humidity - A0
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht( DHTPIN, DHTTYPE );

//connect light sensor - A1
#define LIGHT_SIG A1 

//node
#define PORT 3000


void setup() {
  Serial.begin( 9600 );
  dht.begin();
  pinMode( LIGHT_SIG, INPUT );

  //lcd set
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  // Print a message to the LCD.
  lcd.print("Otomo");
}

void loop() {
  
  float hum = dht.readHumidity();       // humidity val
  float tem = dht.readTemperature();    // temperature val
  float lig = analogRead( LIGHT_SIG );  // light val

  int hum_i = hum;                      // humidity val (lcd)
  int tem_i = tem;                      // temperature val (lcd)
  int lig_i = lig;                      // light val (lcd)

  //jsonBuffer
  StaticJsonBuffer<200> jsonBuffer;


  if( isnan(tem) || isnan(hum) || isnan(lig) ){
    Serial.println( "Failed to read from DHT" );    
  }else{
    //make json
    StaticJsonBuffer<200> jsonBuffer;
    char buffer[256];
    JsonObject& otomoSensor = jsonBuffer.createObject();

    otomoSensor["hum"] = hum;
    otomoSensor["tem"] = tem;
    otomoSensor["lig"] = lig;
    otomoSensor.printTo(buffer, sizeof(buffer));
    
    Serial.println(buffer); 

  }
  
  //lcd debug
  lcd.setCursor(0, 1);
  lcd.print(hum_i);
  lcd.print( "%, " );
  lcd.print(tem_i);
  lcd.print( "C, " );
  lcd.print(lig_i);
  lcd.print( "L" );

  delay(1000);

  
}

