#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
uint8_t cny70 = 3;
const byte interruptPin = 2;
bool interrupt = false;
int threshold = 200;
int counter = 0;
int lecturaCNY;
                                    
void setup() {
  // PERIODO DEL CHIP NE555 ES DE 220MS, 5 periodos = 1 seg aprox
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(cny70, INPUT);
  attachInterrupt(interruptPin, ISRa, RISING);
  // put your setup code here, to run once:

}

void loop() {
  lcd.clear();
  lecturaCNY = analogRead(cny);
  Serial.print(lecturaCNY);
  if(analogRead(cny70) > threshold)){
    ISRa();
  }
  if(interrupt){
    lcd.print("Interrupcion");
  }
    Serial.println(counter); 
  delay(1000);
}

void ISRa(){
  digitalWrite(4, HIGH);
  interrupt = true;
  counter++;
}
