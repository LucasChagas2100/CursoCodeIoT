/*
Código de leitura em pino analógico: potenciômetro e LED
A frequência na qual o LED pisca depende da leitura de A0.
*/

int pinoPot = A0;   // pino de entrada do potenciômetro
int pinoGreen = 31;   // pino de saída no LED
int pinoYellow = 30;
int pinoRed = 32;
int valorPot = 0;   // variável c/ valor lido do potenciômetro
//int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(pinoGreen, OUTPUT);   // declarando o pino do LED como saída (OUTPUT)
  pinMode(pinoYellow, OUTPUT);
  pinMode(pinoRed, OUTPUT);
}

void loop() {
  Serial.println(valorPot);        // imprime o valor lido:
  valorPot = analogRead(pinoPot);     // lendo o valor do sensor
  if (valorPot < 340){
    digitalWrite(pinoGreen, HIGH);        
    digitalWrite(pinoYellow, LOW);
    digitalWrite(pinoRed, LOW);
  }
  else if (valorPot > 340 && valorPot < 680){
      digitalWrite(pinoGreen, HIGH);        
      digitalWrite(pinoYellow, HIGH);
      digitalWrite(pinoRed, LOW);
  }
  else if (valorPot > 680){
        digitalWrite(pinoGreen, HIGH);        
        digitalWrite(pinoYellow, HIGH);
        digitalWrite(pinoRed, HIGH);
   }
}
