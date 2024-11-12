
#define TERMISTOR_NTC_PIN A0

  int PER = 200;
  int resistencia = 10000;

  
void setup() {
  // put your setup code here, to run once:
  pinMode(TERMISTOR_NTC_PIN, INPUT);
  Serial.begin(9600);
  printf("hola");
}

void loop() {
  delay(PER);
  long valor = analogRead(TERMISTOR_NTC_PIN);
  uint32_t valorRes = getResistencia(valor);
  uint32_t temperatura = getTemperatura(valorRes);
  Serial.println(valor);
  Serial.println(valorRes);
  Serial.println(temperatura);
}

// Ecuacion de STEINHART-HART
uint32_t getResistencia(long value){
  uint32_t hola = resistencia*(1024-value)/value;
  return hola;
}

uint32_t getTemperatura(uint32_t res){
  uint32_t temp = 1/(0.002108508173 + 0.00007979204727*log(res) + .0000006535076315*(log(res)*log(res)*log(res)));
  return temp-273;
}