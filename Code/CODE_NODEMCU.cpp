#define BLYNK_TEMPLATE_ID "TMPLGZtKhe0k"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "ye6sq2VmUxoVa8H9ttFDQiB9--01KVMO"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <Simpletimer.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "Quynh 1_2.4G";
char pass[] = "123456789";
 
SimpleTimer timer;
 
String myString; 
char rdata; 
 
int firstVal, secondVal,thirdVal; // sensors 
void myTimerEvent()
{

  Blynk.virtualWrite(V1, millis() / 1000);
  
}
 
void setup()
{
  
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
    timer.setInterval(1000L,sensorvalue1); 
    timer.setInterval(1000L,sensorvalue2); 
 
}
 
void loop()
{
   if (Serial.available() == 0 ) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
   }
   
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata; 
    if( rdata == '\n')
    {

      String l = getValue(myString, ',', 0);
      String m = getValue(myString, ',', 1);
      firstVal = l.toInt();
      secondVal = m.toInt();

      myString = "";
    }
  }
 
}
 
void sensorvalue1()
{
int sdata = firstVal;
Blynk.virtualWrite(V2, sdata);
 
}

void sensorvalue2()
{
int sdata = secondVal;
Blynk.virtualWrite(V1, sdata);
}
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
