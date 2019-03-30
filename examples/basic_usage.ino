#include "Button.h"



Button but1(A0); // Connect your button between pin 2 and GND
Button but2(A1); // Connect your button between pin 3 and GND
Button but3(A2); // Connect your button between pin 4 and GND

void setup() {
	but1.begin();
	but2.begin();
	but3.begin();
	
	while (!Serial) { }; // for Leos
	Serial.begin(9600);
}

void loop() {
	if (but1.pressed())
  {
		Serial.println("Button 1 pressed");
  }

  unsigned long how_long;
	if (how_long = but1.pressedFor())
  {
    Serial.print("Button 1 pressed  for : "); Serial.println(how_long / 1000);
  }
  
	if (but2.released())
  {
		Serial.println("Button 2 released");
    Serial.print("Button 1 released for : "); Serial.println(but1.releasedFor() / 1000);
  }
	
	if (but3.toggled()) {
		if (but3.read() == PRESSED)
			Serial.println("Button 3 has been pressed");
		else
			Serial.println("Button 3 has been released");
	}
}
