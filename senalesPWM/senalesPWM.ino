  int verde = 6;
  int rojo = 5;
  int pulsador = 4;
  int PER = 300;
  int PER2 = 10;
  int PWM =0;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(PER);
  analogWrite(verde, PWM);
  analogWrite(rojo, PWM);
  if(digitalRead(pulsador)){
      PWM += 30;
    }
  analogWrite(verde, PWM);
  Serial.println(PWM);
}

