#include "DHT.h"
#include <Wire.h>
#include "rgb_lcd.h"

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

void setup() {
  Serial.begin( 9600 );
  dht.begin();
  pinMode( LIGHT_SIG, INPUT );

  //lcd set
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  // Print a message to the LCD.
  lcd.print("Otomo");
  delay(1000);
}

void loop() {

  float hum = dht.readHumidity();     // humidity val
  float tem = dht.readTemperature();  // temperature
  float lig = analogRead( LIGHT_SIG );  // light val

  //consol debug
  if( isnan(tem) || isnan(hum) || isnan(lig) ){
    Serial.println( "Failed to read from DHT" );
  }else{
    Serial.print( "Humidity: " );
    Serial.print( hum );
    Serial.print( " %\t" );
    Serial.print( "Temperature: " );
    Serial.print( tem );
    Serial.print( " *C" );
    Serial.print( " %\t" );
    Serial.print( "Light: " );
    Serial.println( lig );
  }
  

}
