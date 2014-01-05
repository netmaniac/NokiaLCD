#include <Nokia_lcd.h>
#include <FONT8x8.h>
#include <FONT12x16.h>

void setup() {
  Display.begin();
  Display.clear();
  Display.backlight(1);
  Display.setBackground(WHITE);
  Display.setFont(F8x8);
}

void loop() {
  Display.moveTo(1, 2);
  Display.println(F("PROGRESS:"));
  for (byte i=0; i<100; i++)
  {
    Display.setColor(RED);
    Display.fillRect(17, 10, map(i, 0, 99, 0, 114), 7);
    Display.setColor(BLUE);
    Display.moveTo(1, 10);
    Display.print(i);
    delay(200);
  }
  Display.clear();

}
