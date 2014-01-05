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
  Display.println(F("PROGRESS:"));
  for (byte i=0; i<100; i++)
  {
    Display.setColor(RED);
    Display.fillRect(17, 9, map(i, 0, 99, 17, 131), 16);
    Display.setColor(BLUE);
    Display.moveTo(1, 9);
    Display.print(i);
    delay(500);
  }
  Display.clear();
}