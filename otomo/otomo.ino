//connect light sensor - A1
#define LIGHT_SIG A1 

void setup() {
  pinMode( LIGHT_SIG, INPUT );
}

void loop() {
  
  float lig = analogRead( LIGHT_SIG );  // light val

  //consol debug
  if( isnan(tem) || isnan(hum) || isnan(lig) ){
    Serial.println( "Failed to read from DHT" );
  }else{
    Serial.print( "Light: " );
    Serial.println( lig );
  }
  

}
