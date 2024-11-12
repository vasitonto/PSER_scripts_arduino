
#define LM35_PIN A2
  int PER = 1000;
  int TBASE = 28;
  float aux = 25;
  int segundos = 0;
  
void setup() {
  // put your setup code here, to run once:

  pinMode(LM35_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(LM35_PIN);
  float mv = valor*(5000/1024);
  float temperatura = (mv / 10)-44;
  Serial.println(String(mv) + ", " + String(temperatura) + ", " + String(segundos));
  delay(PER);
  segundos += 1;
}