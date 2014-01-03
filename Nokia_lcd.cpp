// a wrapper class for PCF8838.c , Nokia 6610 Color LCD (Philips Variant)
// Bascom image format display add-on by Piotr Rzeszut

extern "C" {
  #include "PCF8833.h"
}

#include "Nokia_lcd.h"

size_t Nokia_lcd::write(uint8_t c)
{
  byte fontWidth = pgm_read_byte(_font);
  if (c == '\n')
  {
    byte fontHeight = pgm_read_byte(_font+1);
    _y += fontHeight;
    _x = 0;
    return 0;
  }

  else if (c == '\r')
  {
    return 0;
  }

  if (_x > (131 - fontWidth))
    return 0;

  LCD_Char(c, _x, _y, _color, _background, _font);
  _x += fontWidth;
  return 1;
}

void Nokia_lcd::begin(void){
  LCD_Init();
}

void Nokia_lcd::backlight(unsigned char on){
  digitalWrite(BL_ON,on);
}

void Nokia_lcd::clear(int color){
  LCD_Box(0, 0, 131, 131, FILL, color);
}

void Nokia_lcd::moveTo(byte x, byte y){
  _x = x;
  _y = y;
}

void Nokia_lcd::setColor(word color){
  _color = color;
}

void Nokia_lcd::setBackground(word color){
  _background = color;
}

void Nokia_lcd::setFont(byte *font){
  _font = font;
}

void Nokia_lcd::pixel(){
  LCD_Pixel(_x, _y, _color);

}
void Nokia_lcd::lineTo(unsigned char x, unsigned char y) { 
  LCD_Line(_x,_y, x, y, _color);
  _x = x;
  _y = y;
}

void Nokia_lcd::fillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h) { 
  LCD_Box(x, y, x+w, y+h, FILL, _color);
}

void Nokia_lcd::circle(unsigned char x, unsigned char y, unsigned char radius) { 
  LCD_Circle(x, y, radius, _color);
} 

void Nokia_lcd::bitmap(unsigned char start_x, unsigned char start_y,const unsigned char *bitmap_data) {
  LCD_Bitmap (start_x, start_y, pgm_read_byte(bitmap_data+1), pgm_read_byte(bitmap_data+2), bitmap_data+5);
} 

Nokia_lcd Display;