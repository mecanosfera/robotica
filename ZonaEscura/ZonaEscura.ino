// ROBO+EDU - Encontrar area escura
// O robo procura a zona mais escura

#include <ROBOEDU.h>

int claridade;

void setup() {
  // iniciar a claridade maxima
  claridade = 1024;
  Serial.begin (9600);
}

void loop() {
  // Primeiro: ler a claridade atual
  
  servo_left_stop ();
  servo_right_stop();
  Serial.println ("top");
  Serial.println (LDR_top());
  if (claridade <= LDR_top()){
    // Claridade atual e menor que a anterior
    claridade = LDR_top();  
    // Procurar outra zona
    Serial.println ("sensores");
    Serial.println (LDR_left());
    Serial.println (LDR_right());
    if (LDR_left () > LDR_right()) {
      mov_esquerda();
      mov_avanca();
    }
    else {
      mov_direita();
      mov_avanca ();
    }
}

else {
  // chegamos em uma zona de maior claridade, retornar
  mov_retorna();
  // encerrar o programa, parar o robo por dois minutos
  servo_left_stop ();
  servo_right_stop();
  LED_color (1,0,0);
  delay (2000);
  LED_color (0,0,0);
  }
}

int mov_esquerda() {
//Funcao para o robo girar cerca de 90 graus a esquerda
  servo_left_front(75);
  servo_right_back(75);
  delay (750);
  return 0;
}

int mov_direita() {
//Funcao para o robo girar cerca de 90 graus a direita
//Grosseiramente controlada com um timer, manda girar as rodas em sentido contrario e espera 750 milis
  servo_left_back(75);
  servo_right_front(75);
  delay (750);
  return 0;
}


int mov_avanca(){
  //Funcao para o robo avancar "uma casa"
  servo_left_front(75);
  servo_right_front(75);
  delay (750);
  return 0;
}

int mov_retorna(){
  servo_left_back (75);
  servo_right_back (75);
  delay (750);
  return 0;
}
 

