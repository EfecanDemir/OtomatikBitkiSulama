
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char token[] = "othfk6PKKeD0MG-hHhIMJzE093velTL0";
char agAdi[] = "Kablonet Netmaster-1C9E-G"; 
char agSifre[] = "9fdfdeac";
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
