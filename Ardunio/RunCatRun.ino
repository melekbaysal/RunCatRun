#include <LiquidCrystal.h>
#include <Servo.h>

Servo sg90;
int Contrast=75;
char isGameOver;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() {
  sg90.attach(10);
  analogWrite(6, Contrast);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  sg90.write(0);
        lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("MAMA VERILIYOR");
}

void loop() {


  if(Serial.available()){
    isGameOver = Serial.read();
    if(isGameOver == 'T'){
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("MAMA VERILIYOR");
      digitalWrite(9, HIGH);
      sg90.write(45);
      delay(1400);
      digitalWrite(9, LOW);
      sg90.write(0);
      lcd.clear();
      isGameOver == 'F';
    }
  }
}
