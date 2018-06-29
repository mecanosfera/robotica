#ifndef ROBOEDU_H
#define ROBOEDU_H

#include <Servo.h>
#include <Arduino.h>

// Using "Define" command to simplify the code

// Analog ports

# define A0 0
# define A1 1  
# define A2 2
# define A3 3
# define A4 4
# define A5 5

// Servos ports

# define SA 7
# define SB 8 
# define SC 9 
# define SD 10

// Arduino pins where each connector port is plugged

# define digitalPinC1 4
# define digitalPinC2 3
# define digitalPinC3 2
# define digitalPinC4 5
# define digitalPinC5 6
# define digitalPinC6 7

# define analogPinC1 17
# define analogPinC2 18
# define analogPinC3 19
# define analogPinC4 16
# define analogPinC5 15
# define analogPinC6 14

// Arduino pins where each servo port is plugged

# define pinServo1 9
# define pinServo2 8
# define pinServo3 11
# define pinServo4 10


// ----------- Servos -------------------

extern Servo leftServo;
extern Servo rightServo;


// ------------ SENSORS -----------------

void LED_color (bool red, bool green, bool blue);
void buzzer_blip (int frequency);
void buzzer (int frequency, int time);

bool button_switch ();

bool linesensor_right ();
bool linesensor_left ();
bool irsensor_right ();
bool irsensor_left ();

int ultrasound_sensor ();

int LDR_right ();
int LDR_left ();
int LDR_top ();

void servo_left_front (int velocity);
void servo_right_front (int velocity);

void servo_left_back (int velocity);
void servo_right_back (int velocity);

void servo_left_stop ();
void servo_right_stop ();


#endif
