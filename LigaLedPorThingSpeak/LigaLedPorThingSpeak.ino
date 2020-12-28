#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
 
// Substitua suas credenciais wifi aqui
const char* ssid = "sem internet"; 
const char* password = "lucascunha"; 
 
// altere o número do seu canal aqui
unsigned long channel = 1261301; //altere para seu número de canal
 
// campos do canal. Você não precisa mudar se estiver seguindo este tutorial. No entanto, você pode modificá-lo de acordo com sua aplicação
unsigned int led1 = 1;
int led1Pin = 13;
unsigned int led2 = 2;
int led2Pin = 12;
unsigned int led3 = 3;
int led3Pin = 14;
 
WiFiClient  client;
 
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  digitalWrite(led1Pin, 0);
  digitalWrite(led2Pin, 0);
  digitalWrite(led3Pin, 0);
// Começamos conectando a uma rede WiFi
 
  Serial.println();
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi conectado");  
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);
 
}

void loop() {
//Configuração do estado do led
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  if(led_1 == 1){
    digitalWrite(led1Pin, 1);
    Serial.println("led1 ligado..!");
  }
  else if(led_1 == 0){
    digitalWrite(led1Pin, 0);
    Serial.println("led1 desligado..!");
  }
    
  Serial.println(led_1);

  int led_2 = ThingSpeak.readFloatField(channel, led2);
  if(led_2 == 1){
    digitalWrite(led2Pin, 1);
    Serial.println("led2 ligado..!");
  }
  else if(led_2 == 0){
    digitalWrite(led2Pin, 0);
    Serial.println("led2 desligado..!");
  }
    
  Serial.println(led_2);

  int led_3 = ThingSpeak.readFloatField(channel, led3);
  if(led_3 == 1){
    digitalWrite(led3Pin, 1);
    Serial.println("led3 ligado..!");
  }
  else if(led_3 == 0){
    digitalWrite(led3Pin, 0);
    Serial.println("led3 desligado..!");
  }
    
  Serial.println(led_3);
  
  delay(5000);

}
