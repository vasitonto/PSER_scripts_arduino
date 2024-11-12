
  int PER = 50;
  int NTC;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(NTC, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(PER);
  analogRead(NTC);
  printf(NTC);
}
