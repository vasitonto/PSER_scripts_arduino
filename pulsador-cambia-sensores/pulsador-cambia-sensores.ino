#include <LiquidCrystal.h>
#include <HCSR04.h>
#define NTC_PIN A0
#define LDR_PIN A1
#define LM35_PIN A2
//no se si era digital o analog
#define CNY70_PIN A3
int ntcResistencia = 10000;
int HCSR04_trigger = 13;
int HCSR04_echo = 5;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6); 
int verde = 4;
int rojo = 2;
int pulsador = 3;
int PER = 300;
int sensor = 1;
//para los infrarrojos de momento usaremos esto
//uint8_t cny70 = 3;

void imprimeLEDS(){
  lcd.print("LUCES LED");
}

void usaLEDS(){
  digitalWrite(verde, LOW);
  digitalWrite(rojo, HIGH);
  delay(PER);
  digitalWrite(verde, HIGH);
  digitalWrite(rojo, LOW);
}

int usaNTC(){
    long valorNTC = analogRead(NTC_PIN);
    uint32_t valorRes = ntcResistencia*(1024-valorNTC)/valorNTC;
    uint32_t temp_aux = 1/(0.002108508173 + 0.00007979204727*log(valorRes) + .0000006535076315*(log(valorRes)*log(valorRes)*log(valorRes)));
    int temp_NTC = temp_aux - 273;
    return temp_NTC;
}

void imprimeNTC(int temp_NTC){
  lcd.print("NTC: ");
  lcd.print(temp_NTC);
  lcd.print(" grados");
}

void setup() {
  Serial.begin(9600);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  lcd.begin(16, 2);
  pinMode(pulsador, INPUT);
  pinMode(NTC_PIN, INPUT);
  pinMode(LM35_PIN, INPUT);
  pinMode(HCSR04_trigger, OUTPUT);
  pinMode(HCSR04_echo, INPUT);
  digitalWrite(HCSR04_trigger, LOW);
  pinMode(CNY70_PIN, INPUT);
}

void loop() {
  lcd.clear();
  if(digitalRead(pulsador)){
    sensor += 1;
  }
  /*
  Serial.print("modulo ");
  Serial.println(sensor % 6 + 1);
  Serial.print("after mod ");
  */
  int valorswitch = sensor%6 + 1;
  Serial.println(valorswitch);
  if(valorswitch ==1){
      //PER = 16;
      usaLEDS();
      imprimeLEDS();  
  }
  else if(valorswitch == 2){
      imprimeNTC(usaNTC());

  }
  else if(valorswitch == 3){
      //LM35
      lcd.setCursor(0,0);
      lcd.println("LM35: ");
      long valorLM35 = analogRead(LM35_PIN);
      float mv = valorLM35*(5000/1024);
      float temp_LM35 = (mv / 10)-44;
      lcd.setCursor(0,1);
      lcd.print((String) temp_LM35);
      lcd.print(" grados");
  }
  else if(valorswitch == 4){
    lcd.setCursor(0,0);
    lcd.print("LDR: luminosidad ");
    lcd.setCursor(0,1);
    lcd.print(analogRead(LDR_PIN));
  }
  else if (valorswitch == 5){
    //SENSOR ULTRASONIDOS
      //lcd.clear();
      
      digitalWrite(HCSR04_trigger, HIGH);
      delayMicroseconds(10);          //Enviamos un pulso de 10us
      digitalWrite(HCSR04_trigger, LOW);
      long t = pulseIn(HCSR04_echo, HIGH);
      long d = t/59;             //escalamos el tiempo a una distancia en cm
      
      lcd.setCursor(0,0);
      lcd.print("HCSR04: ");
      lcd.setCursor(0,1);
      lcd.print(d);      //Enviamos serialmente el valor de la distancia
      lcd.print(" cm");
      //delay(PER);
  }
  else if(valorswitch == 6){
      lcd.print("CNY70: ");
      lcd.print(analogRead(CNY70_PIN));
  }

  delay(PER);
}

