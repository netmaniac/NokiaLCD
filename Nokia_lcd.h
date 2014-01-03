/*
  Nokia_lcd.h
*/

#ifndef NOKIALCD_H
#define NOKIALCD_H

#include "Arduino.h"
#include "Print.h"

#include "PCF8833.h"


class Nokia_lcd : public Print
{
private:
  byte _x;
  byte _y;
  word _color;
  word _background;
  byte *_font;

public:
  virtual size_t write(const uint8_t *buffer, size_t size);
  void begin(void);
  void backlight(unsigned char on);
  void clear(int color=0xFFF);
  void setCursor(byte x, byte y);
  void setColor(word color);
  void setBackground(word color);
  void setFont(byte *font);
  void pixel(unsigned char x, unsigned char y, int color);
  void line(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, int color);
  void rect(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char fill, int color);
  void circle(unsigned char x0, unsigned char y0, unsigned char radius, int color);
  void write(char c, unsigned char x, unsigned char y, int fColor, int bColor, unsigned char *font);
  void string(char *pString, unsigned char  x, unsigned char  y,  int fColor, int bColor, unsigned char *font);
  void bitmap(unsigned char start_x, unsigned char start_y,const unsigned char *bitmap_data);
};  
    
#endif

