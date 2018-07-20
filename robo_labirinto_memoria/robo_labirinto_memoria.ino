#include <ROBOEDU.h>
#define dmin 25
//distancia minima do quadro do robo e quinze centimetros

bool alternativa;
int distancia;
int distancia_max;
int direcao;
/* Direcao define a direcao que o robo ira seguir.
 * 1 - frente
 * 3- esquerda
 * 5- direita
 *  soma +1 se o numero tiver uma alternativa
 */

int pilha[200];
int pilha_top;

void setup() {
  Serial.begin(9600);
  alternativa = 0;
  distancia_max = 0;
  pilha_top == 1;
}

void loop() {
  direcao = sensoriamento(0);
  if (direcao == 0)  {
      LED_color (0,0,1);
      retorna ();
      direcao = sensoriamento (1);
      mover(direcao);
      LED_color (0,0,0);
  }
  mover(direcao);
  
}

// Funcao sensoriamento
int sensoriamento(int opcao){
  int dir1, dir2;
  int maximo;
  dir1 = 0;
  dir2 = 0;
  direcao = 0;
  distancia = ultrasound_sensor();
  maximo = distancia;
  if(distancia > dmin) {
    dir1 = 1;
  }

  // olhar a esquerda
  mov_esquerda();
  distancia = ultrasound_sensor();
  if(distancia > dmin) {
    if (distancia > maximo) {
      maximo = distancia;
      if (dir1 !=0){
        dir2 = dir1;
        dir1 = 3 + 1;
      }
      else dir1 = 3;
    }  
    else {
      if (dir1 == 1)
        dir1 = 2;
      dir2 = 3;
    }
  }
  
  mov_direita();
  //olhar a direita
  mov_direita();
  distancia = ultrasound_sensor();
 if(distancia > dmin) {
    if (distancia > maximo) {
      maximo = distancia;
      if (dir1 !=0){
        dir2 = dir1;
        dir1 = 5 + 1;
      }
      else dir1 = 5;
    }
    else {
      if (dir1 == 1)
        dir1 = 2;
      dir2 = 5;
    }
  }
  
  mov_esquerda();
  if ((opcao == 1) && (dir2 !=0))
    return dir2;
  return dir1;
}
// Funcao retorna

int retorna (){
  int dir;
  dir = pop();
  mover_reverso (dir);
  if (dir/2 == 0)
    return 0;
}


// funcao Mover
int mover (int dir){
  push (dir);
  switch(dir){
  case 1:
  case 2:
    break;
  case 3:
  case 4:
    mov_esquerda();
    break;
  case 5:
  case 7:
    mov_direita();
  case 0:
    break;
  }
  mov_avanca();
}


int mover_reverso (int dir) {
  switch(dir){
  case 1:
  case 2:
    break;

  case 3:
  case 4:
    mov_direita();
    break;
  case 5:
  case 7:
    mov_esquerda();
  }
  mov_retorna();
}

// Funcao de memoria
int push(int inserir){
  pilha[pilha_top] = inserir;
  pilha_top ++;
  if (pilha_top == 201) {
    LED_color (0,1,0);
    while(true);
  }
  return 0;
}

int pop(){
  pilha_top --;
    if (pilha_top < 0) {
    LED_color (0,1,0);
    while(true);
  }
  return pilha[pilha_top + 1];
}

// Funcoes basicas de movimento do robo
int mov_esquerda() {
//Funcao para o robo girar cerca de 90 graus a esquerda
  servo_left_front(75);
  servo_right_back(75);
  delay (1250);
  servo_left_stop ();
  servo_right_stop();
  delay (200);
  return 0;
}

int mov_direita() {
//Funcao para o robo girar cerca de 90 graus a direita
//Grosseiramente controlada com um timer
  servo_left_back(75);
  servo_right_front(75);
  delay (1250);  
  servo_left_stop ();
  servo_right_stop();
  delay (200);
  return 0;
}


int mov_avanca(){
  //Funcao para o robo avancar "uma casa"
  servo_left_back(75);
  servo_right_back(75);
  delay (1250);
  servo_left_stop();
  servo_right_stop();
  delay (200);
  distancia_max ++;
  return 0;
}

int mov_retorna(){
  servo_left_back(75);
  servo_right_back(75);
  delay(1250);
  servo_left_stop ();
  servo_right_stop();
  delay(200);
  return 0;
}
