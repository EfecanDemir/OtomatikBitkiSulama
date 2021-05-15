
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "//kart için oluşturulan token";
char agAdi[] = "//modem ismi"; 
char agSifre[] = "//modem şifre";
#define sensor A0
int deger;
int donusum;

void setup() {
Serial.begin(9600);
Blynk.begin(token, agAdi, agSifre);
}

void loop() {
deger = analogRead(sensor);
donusum=map(deger ,0,1023,0,100);
Blynk.virtualWrite (V1, donusum);
Blynk.run();

if(donusum>80)
{
  Blynk.notify("Kuruluk oranı arttı. Bitkiye yeterli suyu veriniz.");
  }
}
