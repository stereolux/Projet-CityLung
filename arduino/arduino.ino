#include <AFMotor.h>

AF_Stepper shanghai(48, 1);
AF_Stepper rennes(48, 2);
String command;
int pollution;
int frequence;

void setup() {
	Serial.begin(9600);
	rennes.setSpeed(500);
	shanghai.setSpeed(500);
	pinMode(13, OUTPUT);
}

void loop() {
	while (Serial.available() > 0) {
		char recieved = Serial.read();
		// si le caractère recu est le caractère de stop
		if (recieved == '#') {
			String town = command.substring(0,1);
			int value = command.substring(1).toInt();
			int pollution = 1000/value;
			int frequence = 1000/pollution;
			if(town == "r") {
				digitalWrite(13, HIGH);
				rennes.step(pollution*5/2, BACKWARD,SINGLE);
				delay(frequence);
				rennes.step(pollution*5, FORWARD, SINGLE);
				delay(frequence);
				rennes.step(pollution*5/2, BACKWARD,SINGLE);
			}
			else if (town == "s") {
				digitalWrite(13, LOW);
				shanghai.step(pollution*5/2, BACKWARD,SINGLE);
				delay(frequence);
				shanghai.step(pollution*5, FORWARD, SINGLE);
				delay(frequence);
				shanghai.step(pollution*5/2, BACKWARD,SINGLE);
			}
			command = "";
		}
		else {
			command += recieved;
		}
	}
}
