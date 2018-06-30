//Codigo para um robô que consegue desviar de obstáculos e se mover por um labirinto, usando sua ultima posicao como referencia


#include <ROBOEDU.h>

/*Light levels
 * top:
 *  high:0-150-
 *  medium: 200-800
 *  low: 900-1100
 * right/left:
 *  high:0-150
 *  medium: 200-600
 *  low: 700-900
 *  
 *Ultrasound
 * 0-80 (200+ se estiver colado)
 * 
 *IR:
 *  0 - Obstáculo
 *  1 - Livre

*/
#define ULTRASSOM 0
#define IR 1
#define LUZ_BAIXA 2
#define LUZ_ALTA 3

int mem = 0; // Memoria do ultimo obstaculo, 0 para frente, 1 esquerda, 2 direita
int visao = 0;
int atraso = 750; // Delay para dar uma volta(controle por tempo)
long tempo_aprendizagem = 1000;
int energia = 20;
bool recarregando = false;
int estimulo_luz_baixa = 0;
int estimulo_luz_alta = 0;


int estimulo_ultrassom = 0;
int estimulo_ir = 0;
int maior_estimulo = 0;
int sensor = ULTRASSOM;


void setup() {
  Serial.begin(9600);
  LED_color(1,1,1);
}

void recarregar(){
  energia = energia +2;
  if(energia>=20){
    recarregando = false;
  }
}

void loop() {
  servo_left_stop ();
  servo_right_stop();
  if(recarregando==true){
    if(maior_estimulo==LUZ_ALTA){
      if(LDR_top()>400){
        recarregar();
      }
    } else {
      if(LDR_top()<400){
        recarregar();
      }
    }
    delay(750);
  } else {
    energia = energia -1;
    if(LDR_top()<400){
      estimulo_luz_alta = estimulo_luz_alta +1;
    } else {
      estimulo_luz_baixa = estimulo_luz_baixa +1;
    }
    mov_avanca();
    if(energia==0){
      recarregando = true;
      if(estimulo_luz_alta>=estimulo_luz_baixa){
        maior_estimulo = LUZ_ALTA;
      } else {
        maior_estimulo = LUZ_BAIXA;
      }
      estimulo_luz_baixa = 0;
      estimulo_luz_alta = 0;
    }
  }
  Serial.println(energia);

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

void moverse(int visao){
  switch(visao) {
	case 0:
  	if(mem = 0) {
    	servo_left_back(75);
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 1) {
    	servo_left_back(75);
    	servo_right_stop();
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 2) {
    	servo_left_stop();
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}
  	mem = visao;
  	break;
	case 1:
  	if(mem = 0) {
    	servo_left_stop();
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 1) {
    	servo_left_stop();
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 2) {
    	servo_left_back(75);
    	servo_right_stop();
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}
  	mem = visao;
  	break;
	case 2:
  	if(mem = 0) {
    	servo_left_back(75);
    	servo_right_stop();
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 1) {
    	servo_left_stop();
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}

  	else if(mem = 2) {
    	servo_left_stop();
    	servo_right_back(75);
    	delay(atraso);
    	servo_left_front(75);
    	servo_right_front(75);
  	}
  	mem = visao;
  	break;
	case 3:
  	servo_left_front(75);
  	servo_right_front(75);
  }
}

