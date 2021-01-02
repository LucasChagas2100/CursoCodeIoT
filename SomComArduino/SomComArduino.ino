/*
  Melody
  Conecte um buzzer ou alto falante ao pino 11

  criado em 21 Jan 2010
  modificado 30 Ago 2011
  por Tom Igoe
  modificado em 24 de Agosto
  pela Equipe Code IoT

  Este exemplo é de domínio público
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "alturas.h"

// notas da melodia
int melodia[] = {
  E5, E5, PAUSA, E5, PAUSA, C5, E5, PAUSA, G5, PAUSA, PAUSA, PAUSA, G4
};

// duração das notas: 4 = semínima (ou 1/4 seg), 8 = colcheia (ou 1/8 seg), etc.:
int duracaoDasNotas[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  // pino no qual está conectado o alto-falante/buzzer
  const int pinoSom = 8;

  // Calcula o tamanho da melodia, tomando o tamanho do vetor que armazena
  // os n números inteiros equivalentes à melodia e dividindo pelo tamanho
  // que um número inteiro ocupa na memória
  int tamanhoDaMelodia = sizeof(melodia)/sizeof(int);

  // itera pelas notas da melodia
  for (int essaNota = 0; essaNota < tamanhoDaMelodia; essaNota++) {

    // para calcular a duração da nota, divida 1 segundo (ou 1000 ms) pelo tipo da nota
    // por ex.: semínima = 1000 / 4, colcheia = 1000/8, etc.
    int duracaoDessaNota = 1000 / duracaoDasNotas[essaNota];
    tone(pinoSom, melodia[essaNota], duracaoDessaNota);

    // para distinguir as notas, defina um intervalo mínimo entre elas
    // a duração da nota + 10% funciona bem (ou 1,1 vezes a nota):
    delay(duracaoDessaNota);

    // parar de tocar a nota
    noTone(pinoSom);
  }
}

void loop() {
  // a melodia não se repete: toca apenas uma vez no setup.
}
