#include <AFMotor.h>

AF_Stepper stepper(48, 1);
String command;

int pollution = 0;
int frequence = 0;


void setup() {
	Serial.begin(9600);
	///////////////////////////
	// modifier la vitesse si besoin
	stepper.setSpeed(500);
	///////////////////////////
}

void loop() {
	if (Serial.available()) {
		char recieved = Serial.read();
		if (recieved == '#') {
			int value = command.toInt();
			///////////////////////////
			// modifier le ration si besoin
			pollution = 1000/value;
			frequence = 1000/pollution;
			///////////////////////////
			command = "";
		}
		else {
			command += recieved;
		}
	}
	///////////////////////////
	// modifier le nombre de steps si besoin en changeant le coeff de multiplication
	stepper.step(pollution*5/2, BACKWARD,SINGLE);
	delay(frequence);
	stepper.step(pollution*5, FORWARD, SINGLE);
	delay(frequence);
	stepper.step(pollution*5/2, BACKWARD,SINGLE);
	///////////////////////////
}
