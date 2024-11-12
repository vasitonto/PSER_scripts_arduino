#include <LiquidCrystal.h>
#include <HCSR04.h>
int trigger = 5;
int echo = 4; 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.print("Distancia: ");
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trigger, LOW);
  long t = pulseIn(echo, HIGH);
  long d = t*0.034/2;             //escalamos el tiempo a una distancia en cm

  Serial.println(d);
  lcd.print(d);      //Enviamos serialmente el valor de la distancia
  delay(100);
}
