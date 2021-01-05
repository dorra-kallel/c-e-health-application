
#include <LiquidCrystal_I2C.h>

#include <DHT.h>

#include<Wire.h>

#define dht_pin 12
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2);
DHT D(dht_pin, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  lcd.backlight();
lcd.begin();
  D.begin();

}
void loop()
{
  
 int h=D.readHumidity();
  int t=D.readTemperature();
  String ch=String(t);
  String ch1=String(h);
  String humtemp=ch+ch1;
  Serial.print(humtemp);
  Serial.flush();
  
   lcd.setCursor(0,0);
   lcd.print("temp:");
   lcd.print(t);
   lcd.print(" c");
      lcd.setCursor(0,1);
   lcd.print("hum:");
   lcd.print(h);
   lcd.print(" gm3");
 

  delay(1000);
lcd.clear();
    
}
