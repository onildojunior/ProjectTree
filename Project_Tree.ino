#include <dht.h>
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
#define dhtpin A1
#define sensor A0
int ldr = A2;
int valor_umi;
int valor_ldr = 0;
float luminosidade = 0;
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
dht DHT;

void setup() {
 Serial.begin (9600);
 lcd.begin(16, 2);
 pinMode(sensor, INPUT);
}


void loop() {
DHT.read11(dhtpin);
valor_ldr = analogRead(ldr);
valor_umi = analogRead(sensor);
luminosidade = map (valor_ldr, 0, 1023, 0, 255);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("humidade: ");
lcd.println(valor_umi);
lcd.setCursor(0,1);
lcd.print("temp: ");
lcd.println(DHT.temperature);

Serial.print ("Sensor value:");
Serial.println (valor_umi);
Serial.print ("Temperatura: ");
Serial.println (DHT.temperature);
Serial.print ("Umidade: ");
Serial.println (DHT.humidity);
Serial.print ("Luminosidade: ");
Serial.println (luminosidade);
delay(500);


} 
