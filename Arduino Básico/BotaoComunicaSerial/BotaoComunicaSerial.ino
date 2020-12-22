/* Leitura de entrada digital com botão
Se o botão estiver apertado, o monitor serial imprimirá 1.
Senão, ele imprimirá 0.
*/

const int botao1 = 43;         // pino no qual o botao está conectado
const int botao2 = 51;
const int led = 30;           // pino no qual o led está conectado
int estadoBotao1 = 0;          // variável para guardar o valor do estado do botão1 (pressionado ou não)      
int estadoBotao2 = 0;          // variável para guardar o valor do estado do botão2 (pressionado ou não) 
int estadoLed = 0;

void setup() {               // configuração inicial
  Serial.begin(9600);        // inicialização do monitor serial na baudrates de 9600 
  pinMode(botao1, INPUT);     // inicialização do pino do botão como entrada (INPUT)
  pinMode(botao2, INPUT);     // inicialização do pino do botão como entrada (INPUT)
  pinMode(led, OUTPUT);     // inicialização do pino do led como saida (OUTPUT)
}

void loop() {                         //loop: tudo que estiver dentro se repetirá indefinidamente 
  delay(200);
  //condicional se e senao
  //Serial.println(digitalRead(botao1));
  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);
  if (estadoBotao1 == 1){
    estadoLed = 1;              
    Serial.println("\nestadoLed On");      
  }
  if (estadoBotao2 == 1){
    estadoLed = 0;              
    Serial.println("\nestadoLed off");      
  } 
  if (estadoLed == 1){
    digitalWrite(led,1);
  }
  else{
    digitalWrite(led,0);
  }
}
