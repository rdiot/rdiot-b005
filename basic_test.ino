/* L298N Dual Motor Driver H Bridge (L298N) [B005] : http://rdiot.tistory.com/289 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9;
int speed1;
int dir;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(dir1PinA,OUTPUT); // IN1
  pinMode(dir2PinA,OUTPUT); // IN2
  pinMode(speedPinA,OUTPUT); // ENA
  speed1 = 200;
  dir = 1;

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("B005:L298N Driver");

  //analogWrite(speedPinA, speed1); // 200 -> ENA 
  if(dir == 1)
  {
    digitalWrite(speedPinA, HIGH);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    lcd.setCursor(0,1);
    lcd.print("ENA=" + (String)speedPinA + " HIGH");   
    lcd.setCursor(0,2);
    lcd.print("IN1=" + (String)dir1PinA + " LOW ");
    lcd.setCursor(0,3);
    lcd.print("IN2=" + (String)dir2PinA + " HIGH ");
    delay(5000);

    digitalWrite(speedPinA, HIGH);
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    lcd.setCursor(0,1);
    lcd.print("ENA=" + (String)speedPinA + " HIGH");   
    lcd.setCursor(0,2);
    lcd.print("IN1=" + (String)dir1PinA + " HIGH ");
    lcd.setCursor(0,3);
    lcd.print("IN2=" + (String)dir2PinA + " LOW ");
    delay(5000);

    digitalWrite(speedPinA, LOW);
    lcd.setCursor(0,1);
    lcd.print("ENA=" + (String)speedPinA + " LOW ");   
    
    lcd.setCursor(0,2);
    lcd.print("IN1= STOP  ");   
  
    lcd.setCursor(0,3);
    lcd.print("IN2= STOP  ");   

    dir = 0;
  }
}
