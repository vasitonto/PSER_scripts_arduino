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
  lcd.print("Lectura: ");
  lcd.print(analogRead(cny70));
  delay(100);
}
