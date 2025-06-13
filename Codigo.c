// Define os pinos utilizados
const int sensorPin = A0; // Sensor conectado à porta analógica A0
const int ledAlerta1 = 5; // LED de alerta 1
const int ledAlerta2 = 6; // LED de alerta 2
const int buzzerPin = 7; // Buzzer (alarme sonoro)

// Limiar de ativação do alarme (ajuste conforme o sensor)
const int limiarSensor = 100;

// Duração do alarme em milissegundos(30 segundos)
const unsigned long duracaoAlarme = 30000;

void setup() {
 Serial.begin(9600);
 Serial.println("Sistema de alarme iniciado.");
 pinMode(ledAlerta1, OUTPUT);
 pinMode(ledAlerta2, OUTPUT);
 pinMode(buzzerPin, OUTPUT);
}

void loop() {
 // Lê o valor do sensor analógico
 int valorSensor = analogRead(sensorPin);
 Serial.print("Valor do sensor: ");
 Serial.println(valorSensor);
 // Verifica se o valor ultrapassa o limite
 if (valorSensor > limiarSensor) {
 Serial.println("ALERTA! Alguma movimentacao supeita foi detectada!");
 // Marca o tempo em que o alarme foi ativado
 unsigned long tempoInicio = millis();
 // Mantém o alarme ativo por 30 segundos
 while (millis() - tempoInicio < duracaoAlarme) {
 // LED1 aceso, LED2 apagado, buzzer ligado
 digitalWrite(ledAlerta1, HIGH);
 digitalWrite(ledAlerta2, LOW);
 tone(buzzerPin, 1000); // Apita com frequência de 1000 Hz
 delay(500);
 // LED1 apagado, LED2 aceso, buzzer desligado
 digitalWrite(ledAlerta1, LOW);
 digitalWrite(ledAlerta2, HIGH);
 noTone(buzzerPin);
 delay(500);
 }
 // Após 30 segundos, desliga tudo
 digitalWrite(ledAlerta1, LOW);
 digitalWrite(ledAlerta2, LOW);
 noTone(buzzerPin);
 Serial.println("Alarme encerrad0.");
 } else {
 // Nenhum alerta — mantêm os dispositivos desligados
 digitalWrite(ledAlerta1, LOW);
 digitalWrite(ledAlerta2, LOW);
 noTone(buzzerPin);
 }
 delay(200); // Pequeno atraso entre as leituras do sensor
}
