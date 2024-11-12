  int verde = 3;
  int rojo = 2;
  int pulsador = 4;
  int PER = 50;
  int PER2 = 10;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(PER);
  digitalWrite(verde, LOW);
  digitalWrite(rojo, HIGH);
  delay(PER);
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  if(digitalRead(pulsador)){
    PER -= 1;
    Serial.println(PER);
  }
}
