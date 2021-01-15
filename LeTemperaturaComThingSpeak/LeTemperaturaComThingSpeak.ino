// Bibliotecas ThingSpeak e ESP8266 
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include "DHT.h"

// Dados da sua rede: nome e senha
char ssid[] = "sem internet";          //  Nome da rede SSID 
char pass[] = "lucascunha";   // Nome da senha

int status = WL_IDLE_STATUS;
WiFiClient  client;

#define DHTPIN 4 // GPIo4 ou porta D2 do NodeMCU
int tipoDHT =  DHT11;   // Estamos usando o sensor DHT11

// Inicializa o sensor
DHT dht(DHTPIN, tipoDHT);
// A leitura de umidade e temperatura leva cerca de 250ms
float h;
//Lê a temperatura como graus Celsius
float t;

// Informações disponiveis no ThingSpeak: número do canal e chave de escrita
unsigned long canal = 1282980;
const char * ChaveEscritaAPI = "17H61U0S7LXSQYWJ";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass); 
  ThingSpeak.begin(client);
  Serial.println("Teste do DHT11");
  dht.begin();
  delay(10);
}

void loop() {
  // Lê o valor da entrada no pino analógico 0
  //sensorValue = analogRead(A0);
  h = dht.readHumidity();
  t = dht.readTemperature();
  // verifica se alguma das leituras falhou (para tentar novamente).
  if (isnan(h) || isnan(t)) {
    
  }
  // Escreve no ThingSpeak: 
  // (número do canal, número do campo, valor, chave de escrita)
  ThingSpeak.writeField(canal, 2, h, ChaveEscritaAPI);
  delay(5000);
  ThingSpeak.writeField(canal, 1, t, ChaveEscritaAPI);
  
 // imprime os resultados
  Serial.print("Umidade relativa do ar: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C ");
  delay(5000); // ThingSpeak aceita atualizações dos valores cada 5 segundos.
}
