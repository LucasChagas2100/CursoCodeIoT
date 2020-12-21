/* Leitura de entrada digital com botão
Se o botão estiver apertado, o monitor serial imprimirá 1.
Senão, ele imprimirá 0.
*/

const int botao = 53;         // pino no qual o botao está conectado
int estadoBotao = 0;         // variável para guardar o valor do estado do botão (pressionado ou não)      

void setup() {               // configuração inicial
  Serial.begin(9600);        // inicialização do monitor serial na baudrates de 9600 
  pinMode(botao, INPUT);     // inicialização do pino do botão como entrada (INPUT)
}

void loop() {                         //loop: tudo que estiver dentro se repetirá indefinidamente 
   estadoBotao = digitalRead(botao);  // Lê o estado do botão (que pode ser 0 ou 1)
   Serial.println(estadoBotao);       // imprime o estado do botão no monitor serial
}
