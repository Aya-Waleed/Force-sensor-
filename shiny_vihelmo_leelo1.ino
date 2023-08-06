#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd=LiquidCrystal_I2C (0x27,16,2);
LiquidCrystal_I2C lcd (0x27,16,2);
int fs=A0;
int pm=A2;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("LOADING FORCE ...");
  
}
void loop(){
int force=analogRead(fs);
int pot=analogRead(pm);
map(force,0,1023,0,255);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Force=");
lcd.print(force);
map(pot,0,1023,0,255);
 lcd.setCursor(6, 1);
  lcd.print("Pot: ");
  lcd.print(pot);  
  delay(200);
}