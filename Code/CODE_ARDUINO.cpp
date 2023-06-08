#include "DHT.h"
#include <SoftwareSerial.h>
#define DHTPIN 4  
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

int sensor3 = A2; 

int sdata1 = 0; 
int sdata2 = 0; 
 
String cdata; 
 
void setup()
{
Serial.begin(9600); 
 
dht.begin();
 
}
 
void loop()
{
  
    sdata1 = (int) dht.readHumidity();
    sdata2 = (int) dht.readTemperature();

   cdata = cdata + sdata1+","+sdata2;
   Serial.println(cdata); 
   delay(2000); // 100 milli seconds
   cdata = ""; 

}
