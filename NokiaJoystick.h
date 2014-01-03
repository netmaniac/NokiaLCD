/*
 * Does not work - Arduino preprocesor does not allow to include library from library
 * Fix from http://forum.arduino.cc/index.php/topic,42818.0.html#5 does not work
 * 
#ifndef _NG_Keypad_h_
#include "../NettigoKeypad/NettigoKeypad.h"
#endif
*/

#define JOYSTICK_SELECT		NG_Keypad::SELECT 
#define JOYSTICK_LEFT		NG_Keypad::UP
#define JOYSTICK_RIGHT  	NG_Keypad::LEFT
#define JOYSTICK_UP		NG_Keypad::RIGHT
#define JOYSTICK_DOWN		NG_Keypad::DOWN
#define JOYSTICK_NONE		NG_Keypad::NONE

class Nokia_Joystick : public NG_Keypad {
  public:
	Nokia_Joystick() {
	int b[5] = {72, 237, 417, 622, 882};
	setBoundaries(b);
  }
};
