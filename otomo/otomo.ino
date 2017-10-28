#include "DHT.h"

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
}

void loop() {

  float hum = dht.readHumidity();     // humidity val
  float tem = dht.readTemperature();  // temperature
  float lig = analogRead( LIGHT_SIG );  // light val

  //consol debug
  if( isnan(tem) || isnan(hum) || isnan(lig) ){
    Serial.println( "Failed to read from DHT" );
  }else{
    Serial.print( "Light: " );
    Serial.println( lig );
  }
  

}
