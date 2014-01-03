/*
 *  FrameBuffer.h
 *  DisplayMe
 *
 *  Created by Daniel on 11-01-11.
 *  Copyright 2011 Macoscope. All rights reserved.
 *
 */

void clearBuffer();
void drawBuffer(int fgColor, int bgColor);
void drawPixel(unsigned char x, unsigned char y);
void drawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1);