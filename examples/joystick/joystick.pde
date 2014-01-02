#include <NettigoKeypad.h>
#include <joystick.h>

Nokia_Joystick joystick = Nokia_Joystick();

void setup () {
  Serial.begin(9600);
}

void loop(){
  int rd=analogRead(0);
  switch (joystick.key_pressed(rd)) {
	case JOYSTICK_DOWN:
	  Serial.println(F("DOWN"));
	  break;
	case JOYSTICK_RIGHT:
	  Serial.println(F("RIGHT"));
	  break;
	case JOYSTICK_LEFT:
	  Serial.println(F("LEFT"));
	  break;
	case JOYSTICK_UP:
	  Serial.println(F("UP"));
	  break;
	case JOYSTICK_SELECT:
	  Serial.println(F("SELECT"));
	  break;
  };
};