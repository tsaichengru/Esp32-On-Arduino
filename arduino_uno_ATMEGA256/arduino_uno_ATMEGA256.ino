
// 引用 LiquidCrystal Library
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_PCF8574.h>

const int SENSOR_PIN = 4; // 溫度(橘)


OneWire oneWire(SENSOR_PIN);        
DallasTemperature sensors(&oneWire);
LiquidCrystal_PCF8574 lcd(0x27);

float temp;


void setup() {
  // 設定 LCD 的行列數目 (2 x 16)
  Serial.begin(9600);
  lcd.begin(16, 2);
  sensors.begin();
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(9,0);
  lcd.print((char)223);
  lcd.print("C");
 

  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

}
void loop() {
  
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  lcd.setCursor(3, 0);
  lcd.print(temp);

  Serial.print("T:");
  Serial.print(temp);
  Serial.print("°C\t");

  delay(1000);
}
