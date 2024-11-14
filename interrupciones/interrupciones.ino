#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
uint8_t cny70 = 3;
                                    
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(cny70, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  lcd.clear();
  attachInterrupt(2, ISRa, CHANGE);
  delay(100);
}

void ISRa(){
  lcd.print("Interrupcion");
  
}
