#include "ROBOEDU.h"
#include "Servo.h"

/*
	//Servo creation
	Servo Servo1; 
	Servo Servo2;
	Servo Servo3;
	Servo Servo4;
	




void setup(){
	//Servos Attachment
	Servo1.attach(pinServo1);
	Servo2.attach(pinServo2);
	Servo3.attach(pinServo3);
	Servo4.attach(pinServo4); 
}*/




Servo leftServo;
Servo rightServo;

void LED_color (bool red, bool green, bool blue) {
	pinMode (11, OUTPUT);
	pinMode (12, OUTPUT);
	pinMode (13, OUTPUT);
	if (red) {
		digitalWrite (13, HIGH);
	}
	else {
		digitalWrite (13,LOW);
	}
	if (blue) {
		digitalWrite (12, HIGH);
	}
	else {
		digitalWrite (12,LOW);
	}
	if (green) {
		digitalWrite (11, HIGH);
	}
	else {
		digitalWrite (11,LOW);
	}
}

void buzzer_blip (int frequency) {
	tone (2, frequency);
	delay (100);
	noTone (2);
}

void buzzer (int frequency, int time) {
	if (time <= 1000) {
		pinMode (2, OUTPUT);
		tone (2, frequency);
		delay (time);
		noTone (2);
	}
}

bool button_switch () {
	delay (10);
	if (analogRead(A3) == 0)
		return HIGH;
	else return LOW;
}


bool linesensor_right () {
	pinMode (4, INPUT);
	if (digitalRead (4)) {
		return (1);
	}
	else {
		return (0);
	}
}


bool linesensor_left () {
	pinMode (3, INPUT);
	if (digitalRead (3)) {
		return (1);
	}
	else {
		return (0);
	}
}

bool irsensor_right () {
	pinMode (7, INPUT);
	if (digitalRead (7)) {
		return (1);
	}
	else {
		return (0);
	}
}

bool irsensor_left () {
	pinMode (8, INPUT);
	if (digitalRead (8)) {
		return (1);
	}
	else {
		return (0);
	}
}


int ultrasound_sensor () {
	int duration;
	pinMode(9, INPUT);
	pinMode (10, OUTPUT);

//activate emmiter
	digitalWrite(10, LOW);
	delayMicroseconds(2);
	digitalWrite(10, HIGH);
	delayMicroseconds(10);
	digitalWrite(10, LOW);

//read receiver
	duration = pulseIn(9, HIGH);
	if (200 < duration <= 8700) {
		return (duration /58);
	}
	else {
		return 0;
	}
}


int LDR_right () {
	return (analogRead(A2));
}

int LDR_left () {
	return (analogRead(A1));
}

int LDR_top () {
	return (analogRead(A0));
}

void servo_left_front (int velocity) {
	if (velocity <=100) {
		leftServo.detach();
		leftServo.attach (5);
		velocity = ((9*velocity)/10)+90;
		leftServo.write (velocity);
	}
}

void servo_right_front (int velocity) {
	if (velocity <=100) {
		rightServo.detach ();
		rightServo.attach (6);
		velocity = ((9*velocity)/10);
		rightServo.write (velocity);
	}
	
}

void servo_left_back (int velocity) {
	if (velocity <=100) {
		leftServo.detach();
		leftServo.attach (5);
		velocity = ((9*velocity)/10);
		leftServo.write (velocity);
	}
}

void servo_right_back (int velocity) {
	if (velocity <=100) {
		rightServo.detach ();
		rightServo.attach (6);
		velocity = ((9*velocity)/10)+90;
		rightServo.write (velocity);
	}
	
}

void servo_left_stop () {
	leftServo.detach ();
}


void servo_right_stop () {
	rightServo.detach ();
}

