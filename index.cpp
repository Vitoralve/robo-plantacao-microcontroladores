// Definindo os pinos
const int sensorUmidadePin = A0;  // Pino analógico para o sensor de umidade
const int relePin = 7;            // Pino digital para controlar o relé
const int ledStatus = 13;         // Pino do LED indicador (opcional)

int umidadeMinima = 500;          // Valor de umidade mínima para ativar o motor (ajuste conforme necessário)
int leituraUmidade;               // Variável para armazenar a leitura do sensor

void setup() {
  Serial.begin(9600);             // Inicializa a comunicação serial para monitoramento
  pinMode(sensorUmidadePin, INPUT);
  pinMode(relePin, OUTPUT);
  pinMode(ledStatus, OUTPUT);
  
  digitalWrite(relePin, LOW);     // Garante que o motor esteja desligado no início
  digitalWrite(ledStatus, LOW);   // LED indicador desligado
}

void loop() {
  leituraUmidade = analogRead(sensorUmidadePin); // Lê o valor do sensor de umidade
  Serial.print("Umidade do solo: ");
  Serial.println(leituraUmidade);
  
  if (leituraUmidade < umidadeMinima) { // Verifica se a umidade está abaixo do limite
    Serial.println("Solo seco - Ativando irrigação");
    digitalWrite(relePin, HIGH);    // Liga o motor (abre a torneira)
    digitalWrite(ledStatus, HIGH);  // Liga o LED indicador
    
    delay(5000);                    // Mantém a irrigação por 5 segundos (ajuste conforme necessário)
  } else {
    Serial.println("Solo úmido - Irrigação desativada");
    digitalWrite(relePin, LOW);     // Desliga o motor (fecha a torneira)
    digitalWrite(ledStatus, LOW);   // Desliga o LED indicador
  }
  
  delay(1000);                      // Atraso de 1 segundo antes da próxima leitura
}
