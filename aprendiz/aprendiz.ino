//Codigo para um robô que consegue desviar de obstáculos e se mover por um labirinto, usando sua ultima posicao como referencia


#include <ROBOEDU.h>

/*Light levels
 * top:
 *  high:0-150
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

int estimulo_ultrassom = 0;
int estimulo_ir = 0;
int estimulo_luz_baixa = 0;
int estimulo_luz_alta = 0;

int maior_estimulo = 0;
int sensor = ULTRASSOM;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //LED_color(1,1,1);
  //servo_left_front(75);
  //servo_right_front(75);
  LED_color(1,1,1);
}

void loop() {

  if(aprendendo()){
    if(irsensor_left()==0 || irsensor_right==0){
      estimulo_ir += 1;
    }
    if(ultrasound_sensor()>10){
      estimulo_ultrassom += 1;
    }
    if(LDR_top()<200){
      estimulo_luz_alta += 1;
    }
    if(LDR_top()>=900){
      estimulo_luz_baixa += 1;
    }
  } else {
    if(sensor==ULTRASSOM || sensor==IR){
      visao = ver_sensores();
      moverse(visao);
    } else if (sensor==LUZ_BAIXA && LDR_top()>=900){
      visao = ver_sensores();
      moverse(visao);
    } else if (sensor==LUZ_ALTA && LDR_top()<200){
      visao = ver_sensores();
      moverse(visao);
    }
  }
  
  //Serial.println(irsensor_right());
  //Serial.print(ultrasound_sensor());

}

bool aprendendo(){
  if(tempo_aprendizagem>0){
    tempo_aprendizagem--;
    Serial.println(tempo_aprendizagem);
    return true;
  }
  if(tempo_aprendizagem==0){
    if(estimulo_ultrassom>maior_estimulo){
      maior_estimulo = estimulo_ultrassom;
      sensor = ULTRASSOM;
      LED_color(1,0,0);
    }
    if(estimulo_ir>maior_estimulo){
      maior_estimulo = estimulo_ir;
      sensor = IR;
      LED_color(1,0,0);
    }
    if(estimulo_luz_baixa>maior_estimulo){
      maior_estimulo = estimulo_luz_baixa;
      sensor = LUZ_BAIXA;
      LED_color(0,1,0);
    }
    if(estimulo_luz_alta>maior_estimulo){
      maior_estimulo = estimulo_luz_alta;
      sensor = LUZ_ALTA;
      LED_color(0,0,1);
    }
    tempo_aprendizagem--;
  }
  return false;
}

int ver_sensores() {
  int distancia;
  distancia = ultrasound_sensor();

  if(distancia < 15) {
	// obstáculo frontal
	LED_color(1,0,0);
	return 0;
  }
  else if(irsensor_left()) {
	// obstaculo a esquerda
	LED_color(0,1,0);
	return 1;
  }
  else if(irsensor_right()){
	// obstaculo a direita
	LED_color(0,0,1);
	return 2;
  }
  else if(distancia >=15)
	return 3;
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

