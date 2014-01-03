#include <Nokia_lcd.h>
#include <FONT8x8.h>

void setup() {
  // put your setup code here, to run once:
  Display.begin();
  Display.clear();
  Display.backlight(1);
  Display.setBackground(WHITE);
  Display.setFont(F8x8);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte i=0; i<64; i++)
  {
    Display.setColor(RED);
    Display.fillRect(0, 0, map(i, 0, 63, 0, 131), 10);
    Display.setColor(BLUE);
    Display.moveTo(1, 1);
    Display.print(i, BIN);
    delay(500);
  }
  Display.clear();
}
