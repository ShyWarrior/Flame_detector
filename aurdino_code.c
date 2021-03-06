#include<LiquidCrystal.h>
int buzzer = 13;
int LED = 7;
int flame_sensor = 8;
int flame_detected;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
  
}

void loop()
{
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
     
      lcd.begin(16, 2);
      lcd.print("Flame detected...! take action immediately.");
     delay(500);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
     
     
   
  else
  {
     lcd.begin(16, 2);
  lcd.print("No Flame detected...!");
     delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
