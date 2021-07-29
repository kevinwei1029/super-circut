#include <LiquidCrystal_PCF8574.h>
#include "DHT.h"

LiquidCrystal_PCF8574 lcd(0x27);
DHT dht(9, DHT11);

float h;
float t;

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();  //初始化DHT
  
  lcd.begin(16, 2); // 初始化LCD
  lcd.setBacklight(255);
  lcd.clear();
  lcd.setCursor(0, 0);  //設定游標位置 (字,行)
  lcd.print("*~ first line.");
  lcd.setCursor(0, 1);
  lcd.print("~* second line.");
}

void loop()
{
  delay(100);
  h = dht.readHumidity();   //取得濕度
  t = dht.readTemperature();  //取得溫度C
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  lcd.clear();
  lcd.setCursor(0, 0);  //設定游標位置 (字,行)
  lcd.print("Tem:");
  lcd.setCursor(6, 1);  
  lcd.print(t);
  lcd.setCursor(12, 1);
  lcd.print((char)223); //用特殊字元顯示符號的"度"
  lcd.setCursor(13, 1);
  lcd.print("C");
 
  lcd.setCursor(0, 1);  //設定游標位置 (字,行)
  lcd.print("Hum:");  //Relative Humidity 相對濕度簡寫
  lcd.setCursor(6, 0);  
  lcd.print(h);
  lcd.setCursor(13, 0);
  lcd.print("%");

}
