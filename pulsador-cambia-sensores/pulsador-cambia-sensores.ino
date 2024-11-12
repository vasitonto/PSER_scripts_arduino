#include <LiquidCrystal.h>
#include <HCSR04.h>
#define NTC_PIN A0
#define LDR_PIN A1
#define LM35_PIN A2
int ntcResistencia = 10000;
//int trigger = 5;
//int echo = 4; 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6); 
int verde = 3;
int rojo = 2;
int pulsador = 4;
int PER = 300;
int sensor = 1;
uint8_t cny70 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  lcd.begin(16, 2);
  pinMode(pulsador, INPUT);
  pinMode(NTC_PIN, INPUT);
  pinMode(LM35_PIN, INPUT);
  //pinMode(trigger, OUTPUT);
  //pinMode(echo, INPUT);
  //digitalWrite(trigger, LOW);
}

void loop() {
  lcd.clear();
  switch(sensor){
    case 1:
      PER = 16;
      lcd.print("LUCES LED");
      digitalWrite(verde, LOW);
      digitalWrite(rojo, HIGH);
      delay(PER);
      digitalWrite(rojo, LOW);
      digitalWrite(verde, HIGH);
      delay(PER);
      break;
    case 2:
      PER = 500;

      long valorNTC = analogRead(NTC_PIN);
      uint32_t valorRes = ntcResistencia*(1024-valorNTC)/valorNTC;
      uint32_t temp_aux = 1/(0.002108508173 + 0.00007979204727*log(valorRes) + .0000006535076315*(log(valorRes)*log(valorRes)*log(valorRes)));
      uint32_t temp_NTC = temp_aux - 273;
      lcd.clear();
      lcd.println("NTC: ");
      lcd.print(temp_NTC);
      lcd.print(" grados");

      delay(PER);
      break;
    case 3: 
      PER = 300;

      long valorLM35 = analogRead(LM35_PIN);
      float mv = valorLM35*(5000/1024);
      float temp_LM35 = (mv / 10)-44;
      lcd.clear();
      lcd.print("LM35: ");
      lcd.print(temp_LM35);
      lcd.print(" grados");

      delay(PER);
      break;
    case 4:
      lcd.clear();
      lcd.println("LDR: luminosidad");
      lcd.print(analogRead(LDR_PIN));
      break;

    default:
      delay(PER);
      break;
  }
  Serial.println(sensor);
  
  if(digitalRead(pulsador)){
    sensor += 1;
    if (sensor == 5){
      sensor = 1;
    }
  }
}

