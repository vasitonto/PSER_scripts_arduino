
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
  float voltaje = valor*(5000/1024);
  float temperatura = (voltaje / 10)-48;
  Serial.println(String(voltaje) + ", " + String(temperatura) + ", " + String(segundos));
  delay(PER);
  segundos += 1;
}