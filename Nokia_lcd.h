/*
  Nokia_lcd.h
*/

#ifndef NOKIALCD_H
#define NOKIALCD_H

#include "Arduino.h"
//#include "Print.h"

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
  virtual size_t write(uint8_t);
  void begin(void);
  void backlight(unsigned char on);
  void clear(int color=0xFFF);
  void moveTo(byte x, byte y);
  void setColor(word color);
  void setBackground(word color);
  void setFont(byte *font);
  void pixel();
  void lineTo(unsigned char x, unsigned char y);
  void fillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h);
  void circle(unsigned char x, unsigned char y, unsigned char radius);
  void bitmap(unsigned char start_x, unsigned char start_y,const unsigned char *bitmap_data);
};  

extern Nokia_lcd Display;
#endif

