/*
 *  FrameBuffer.c
 *  DisplayMe
 *
 *  Created by Daniel on 11-01-11.
 *  Copyright 2011 Macoscope. All rights reserved.
 *
 */

#include "FrameBuffer.h"
#include "PCF8833.h"


#define FRAME_WIDTH_IN_BYTES	10
// np 80x80 px + 1 bit na kolor daje razem 80*80/8 bajtow;
#define FRAME_BUFFER_LEN (FRAME_WIDTH_IN_BYTES*FRAME_WIDTH_IN_BYTES*8) 
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
unsigned char frameBuffer[FRAME_BUFFER_LEN];

void clearBuffer(){
  int i;
  for (i=0; i<(FRAME_BUFFER_LEN); i++) {
    frameBuffer[i] = 0x00;// 0xAA;//(i%2)?0x00:0xFF;
  }
}
void drawBuffer(int fg, int bg){
	unsigned char   xmin, xmax, ymin, ymax; 
	unsigned char   x0, x1, y0, y1; 
	int   i,j; 
  unsigned char w = FRAME_WIDTH_IN_BYTES*8;
  
  unsigned char offset = (132-w)/2;
  x0=offset+0; x1=offset+(w-1);
  y0=offset+0; y1=offset+(w-1);
  
  xmin = (x0 <= x1) ? x0 : x1;  
  xmax = (x0 > x1) ? x0 : x1; 
  ymin = (y0 <= y1) ? y0 : y1; 
  ymax = (y0 > y1) ? y0 : y1; 
  
  // specify the controller drawing box according to those limits 
  // Row address set  (command 0x2B) 
  SendLcd(LCDCommand,PASET); 
  SendLcd(LCDData,xmin); 
  SendLcd(LCDData, xmax); 
  // Column address set  (command 0x2A) 
  SendLcd(LCDCommand,CASET); 
  SendLcd(LCDData,ymin); 
  SendLcd(LCDData,ymax); 
  
  // WRITE MEMORY 
  SendLcd(LCDCommand,RAMWR); 
  
  
  // VALAR - NO! (8bitcol) loop on total number of pixels / 2 
  unsigned char x,y;
  x=y=0;
  
  int frameBufferIndex = 0;
  unsigned char pixels = frameBuffer[frameBufferIndex];
	unsigned char bitIndex = 0;
  int color;
 
  int numberOfBytes = ((((xmax - xmin + 1) * (ymax - ymin + 1)) ) )/8;
  	  LCD_CS(0);
  for (i=0; i<numberOfBytes; i++) {
    pixels = frameBuffer[i];
    for (j=0; j<8; j++) {
   	  SendLcd_color(CHECK_BIT(pixels, j) ? fg : bg); 
    }
  }
	    LCD_CS(1);   

  SendLcd(LCDCommand,NOP);   
}
void drawPixel(unsigned char x, unsigned char y){
  unsigned char byteInRow = x>>3;
  unsigned char bitToSet = x-(byteInRow<<3);
	int frameBufferIndex = byteInRow+y*FRAME_WIDTH_IN_BYTES;
  frameBuffer[frameBufferIndex] |= 1<<(bitToSet);
  
}
void drawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1) { 
 
  int dy = y1 - y0; 
  int dx = x1 - x0; 
  int stepx, stepy; 
	if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; } 
  if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; } 
 
  dy <<= 1;        // dy is now 2*dy 
  dx <<= 1;        // dx is now 2*dx 
 
 
  drawPixel(x0, y0); 
 
  if (dx > dy) { 
 		int fraction = dy - (dx >> 1);  // same as 2*dy - dx 
    while (x0 != x1) { 
 	    if (fraction >= 0) { 
 				y0 += stepy; 
        fraction -= dx;    // same as fraction -= 2*dx 
 			} 
 			x0 += stepx; 
 
      fraction += dy;    // same as fraction -= 2*dy 
		  drawPixel(x0, y0); 
    } 
 	} 
 	else { 
 		int fraction = dx - (dy >> 1); 
    while (y0 != y1) { 
 			if (fraction >= 0) { 
 				x0 += stepx; 
 				fraction -= dy; 
      } 
      y0 += stepy; 
 			fraction += dx; 
		  drawPixel(x0, y0); 
    } 
 	} 
 
} 
