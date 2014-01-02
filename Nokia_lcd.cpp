// a wrapper class for PCF8838.c , Nokia 6610 Color LCD (Philips Variant)
// Bascom image format display add-on by Piotr Rzeszut

extern "C" {
	#include "PCF8833.h"
	/*#include <avr/pgmspace.h>
	#include <avr/io.h>*/
	#ifndef Arduino_h
	//#include "Arduino.h"
	#endif
}
#include "Nokia_lcd.h"

//constructor
Nokia_lcd::Nokia_lcd(){
}

void Nokia_lcd::cLCD_Init(void){
	LCD_Init();
}

void Nokia_lcd::cLCD_Backlight(unsigned char on){
	digitalWrite(BL_ON,on);
}

void Nokia_lcd::cLCD_CLS(int color){
	LCD_Box(0, 0, 131, 131, FILL, color);
}

void Nokia_lcd::cLCD_GotoXY(unsigned char x, unsigned char y){
	LCD_GotoXY(x, y);
}


void Nokia_lcd::cLCD_Pixel(unsigned char x, unsigned char y, int color){
	LCD_Pixel(x,y,color);

}
void Nokia_lcd::cLCD_Line(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, int color) { 
	LCD_Line(x0,y0, x1,y1, color); 

}

void Nokia_lcd::cLCD_Box(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char fill, int color) { 
	LCD_Box(x0, y0, x1, y1, fill, color);
}



void Nokia_lcd::cLCD_Circle(unsigned char x0, unsigned char y0, unsigned char radius, int color) { 
	LCD_Circle(x0,y0, radius,color);
} 

void Nokia_lcd::cLCD_Char(char c, unsigned char x, unsigned char y, int fColor, int bColor, unsigned char *font) { 
 	LCD_Char(c, y,x, fColor, bColor, font);
} 

void Nokia_lcd::cLCD_String(char *pString, unsigned char  x, unsigned char  y,  int fColor, int bColor, unsigned char *font) { 
	LCD_String(pString, y,x, fColor, bColor, font);
}

void Nokia_lcd::cLCD_Int(int n, unsigned char  x, unsigned char  y,  int fColor, int bColor, unsigned char *font) { 
	char buf[10];
	LCD_String(itoa(n,buf,10), y,x, fColor, bColor, font);
}

void Nokia_lcd::cLCD_Float(float f, int p, unsigned char  x, unsigned char  y,  int fColor, int bColor, unsigned char *font) { 
	char buf[10];
	char *ct=buf;
	int n=(int)f;
	unsigned char nCols;
    nCols = pgm_read_byte(font);
	LCD_String(itoa(n,buf,10), y,x, fColor, bColor, font);
	for(ct=buf;(*ct)>0;ct++)x+=nCols;
	//LCD_Char('.', y,x, fColor, bColor, font);
	int m=1;
	for(n=0;n<p;n++)m*=10;
	if(m!=1){
		LCD_Char('.', y,x, fColor, bColor, font);
		x+=nCols;
		f*=(float)m;
		n=(int)f%m;
		for(m/=10;m>1;m/=10)if(n<m){
			LCD_Char('0', y,x, fColor, bColor, font);
			x+=nCols;
		}
		LCD_String(itoa(n,buf,10), y,x, fColor, bColor, font);
	}
}

void Nokia_lcd::cLCD_Bitmap(unsigned char start_x, unsigned char start_y, unsigned char *bitmap_data) {
	LCD_Bitmap (start_x, start_y, pgm_read_byte(bitmap_data+1), pgm_read_byte(bitmap_data+2), bitmap_data+5);
} 

void Nokia_lcd::cLCD_Contrast(unsigned char contrast) {
	
} 
/*void Nokia_lcd::cLCD_Bitmap_bas(unsigned char start_x, unsigned char start_y, unsigned char *bitmap_data) {
	LCD_Bitmap_bas(start_x, start_y, pgm_read_byte(bitmap_data+1), pgm_read_byte(bitmap_data+2), bitmap_data+5);
} */
 