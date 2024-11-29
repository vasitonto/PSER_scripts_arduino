#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);
const int cny70 = A5;
const int interruptPin = 3;
const int oscilador = 2;
const int pinSalida = 4;
int threshold = 400;
int periodos = 0;
int lecturaCNY;
int lecturaCircuito;
int lecturaPin3;
int contadorVueltas;
                                    
void setup() {
  // PERIODO DEL CHIP NE555 ES DE 220MS, 5 periodos = 1 seg aprox
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(cny70, INPUT);
  pinMode(interruptPin, INPUT);
  pinMode(oscilador, INPUT);
  pinMode(pinSalida, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISRa, RISING);
  attachInterrupt(digitalPinToInterrupt(oscilador), ISRb, RISING);
  // put your setup code here, to run once:

}

void loop() {
  lcd.clear();
  lcd.print(contadorVueltas);
  if(periodos == 5){
    periodos = 0;
    Serial.println(contadorVueltas);
    contadorVueltas = 0;
  }

  if(analogRead(cny70) > threshold){
    digitalWrite(pinSalida, HIGH);
    digitalWrite(pinSalida, LOW);
  }

  delay(60);
}

void ISRa(){
  contadorVueltas++;
}

void ISRb(){
  periodos++;
}
