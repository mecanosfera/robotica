#include <ROBOEDU.h>

bool memoria = 0; // Lembra pra que lado virou da ultima vez, 0 para esquerda, 1 para direita
int visao = 0;
int atraso = 750; // Delay para dar uma volta (controle por tempo)

void setup() {
  // put your setup code here, to run once:
  LED_color (1,1,1);
  servo_left (75);
  servo_right (25);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  visao = ver_sensores ();
  moverse(visao);

}

int ver_sensores() {
  int distancia;
  distancia = ultrasound_sensor ();
  
  if (distancia < 15) {
    // obstáculo frontal
    LED_color (1,0,0);
    return 0;
  }
  else if (irsensor_left()) {
    // obstaculo a esquerda
    LED_color (0,1,0);
    return 1;
  }
  else if (irsensor_right ()){
    // obstaculo a direita
    LED_color (0,0,1);
    return 2;
  }
  else if (distancia >=15)
    return 3;
}

void moverse(int visao){
  switch (visao) {
    case 0:
      if (visao = 0) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }

      else if (visao = 1) {
        servo_left_back (75);
        servo_right_stop ();
        delay (atraso);
        servo_left (75);
        servo_right (25);        
      }

      else if (visao = 2) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }
      mem = visao;
      break;
    case 1:
      if (visao = 0) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }

      else if (visao = 1) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }

      else if (visao = 2) {
        servo_left_back (75);
        servo_right_stop ();
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }
      mem = visao;
      break;
    case 2:
      if (visao = 0) {
        servo_left_back (75);
        servo_right_stop ();
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }

      else if (visao = 1) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }

      else if (visao = 2) {
        servo_left_stop ();
        servo_right_back (25);
        delay (atraso);
        servo_left (75);
        servo_right (25);
      }
      mem = visao;
      break;
    case 3:
      servo_left (75);
      servo_right (25);
  }
}
