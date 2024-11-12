int LDRPin = A1;
int PER = 300;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(LDRPin);
  Serial.print(0);
  Serial.print(" ");
  Serial.print(1023);
  Serial.print(" ");
  Serial.println(lectura);
  delay(PER);
}

