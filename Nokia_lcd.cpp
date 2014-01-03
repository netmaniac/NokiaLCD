// a wrapper class for PCF8838.c , Nokia 6610 Color LCD (Philips Variant)
// Bascom image format display add-on by Piotr Rzeszut

extern "C" {
  #include "PCF8833.h"
}

#include "Nokia_lcd.h"

size_t Nokia_lcd::write(const uint8_t *buffer, size_t size)
{
  size_t sentBytes;
  byte fontWidth = pgm_read_byte(_font);
  byte y = _y;
  for (size_t i=0; i<size; i++)
  {
    y += fontWidth;
    if (y > (131 - fontWidth))
      break;

    LCD_Char(&buffer[i], _x, _color, _background, _font);
    sentBytes = i;
  }

  return sentBytes;
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

void Nokia_lcd::setCursor(byte x, byte y){
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

void Nokia_lcd::pixel(unsigned char x, unsigned char y, int color){
  LCD_Pixel(x,y,color);

}
void Nokia_lcd::line(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, int color) { 
  LCD_Line(x0,y0, x1,y1, color); 

}

void Nokia_lcd::rect(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char fill, int color) { 
  LCD_Box(x0, y0, x1, y1, fill, color);
}

void Nokia_lcd::circle(unsigned char x0, unsigned char y0, unsigned char radius, int color) { 
  LCD_Circle(x0,y0, radius,color);
} 

void Nokia_lcd::bitmap(unsigned char start_x, unsigned char start_y,const unsigned char *bitmap_data) {
  LCD_Bitmap (start_x, start_y, pgm_read_byte(bitmap_data+1), pgm_read_byte(bitmap_data+2), bitmap_data+5);
} 
