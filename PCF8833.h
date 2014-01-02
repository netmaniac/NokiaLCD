// 12-bit color definitions 
#ifndef PCF8833_H
#define PCF8833_H
 
#define WHITE    0xFFF
#define BLACK    0x000
#define RED    0xF00
#define GREEN    0x0F0
#define BLUE    0x00F
#define CYAN    0x1FF
#define MAGENTA  0xF0F
#define YELLOW   0xFF0
#define GRAY		 0x222
#define LIGHTBLUE 0xADE
#define PINK   0xF6A

/* 8x8 font */
#define FONT_HEIGHT 8


#define LCDCommand      0
#define LCDData         1


/*Fill a box or not */
#define NOFILL	0
#define FILL 1

/* Pin definition for Arduino boards */
#define CS	10
#define CLK 13
#define DATA 11
#define RESET 9
#define BL_ON  3
#define LCD_CS(x)           digitalWrite(CS, x)
#define LCD_CLK(x)          digitalWrite(CLK, x)
#define LCD_DATA(x)         digitalWrite(DATA, x)
#define LCD_RESET(x)        digitalWrite(RESET, x)
#define LCD_BACKLIGHT(x)    digitalWrite(BL_ON,x)
/*
#define LCD_CS(x)           PORTB= (x)? (PORTB|(1<<PB2)) : (PORTB&~(1<<PB2))
#define LCD_CLK(x)          PORTB= (x)? (PORTB|(1<<PB5)) : (PORTB&~(1<<PB5))
#define LCD_DATA(x)         PORTB= (x)? (PORTB|(1<<PB3)) : (PORTB&~(1<<PB3))
#define LCD_RESET(x)        PORTB= (x)? (PORTB|(1<<PB1)) : (PORTB&~(1<<PB1))
#define LCD_BACKLIGHT(x)    PORTD= (x)? (PORTD|(1<<PD0)) : (PORTD&~(1<<PD0))
*/

void SendLcd(unsigned char type, unsigned char dat); 

void LCD_Init(void);
void LCD_GotoXY(unsigned char x, unsigned char y);
void LCD_Backlight(unsigned char bl_state);
void LCD_ClearScreen(void);
void LCD_Pixel(unsigned char x, unsigned char y, int color);
void LCD_Fill (unsigned char xs,unsigned char ys,unsigned char w,unsigned char h,int color);
void LCD_Box(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, int color);
void LCD_Char(char ch, unsigned char x, unsigned char y, int fcolor, int bcolor, unsigned char *font);
void LCD_String (char *the_string,unsigned char x, unsigned char y, int fcolor, int bcolor, unsigned char *font);
void LCD_Line(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, int color);
void LCD_Circle(unsigned char center_x, unsigned char center_y, unsigned char rad, int color);
void LCD_Bitmap (unsigned char start_x, unsigned char start_y, unsigned char h_size, unsigned char v_size,const unsigned char *bitmap_data);
//void LCD_Bitmap_bas (unsigned char start_x, unsigned char start_y, unsigned char h_size, unsigned char v_size, unsigned char *bitmap_data);

// Epson S1D15G10 Command Set 
#define DISON       0xaf
#define DISOFF      0xae
#define DISNOR      0xa6
#define DISINV      0xa7
#define COMSCN      0xbb
#define DISCTL      0xca
#define SLPIN       0x95
#define SLPOUT      0x94
#define PASET       0x75
#define CASET       0x15
#define DATCTL      0xbc
#define RGBSET8     0xce
#define RAMWR       0x5c
#define RAMRD       0x5d
#define PTLIN       0xa8
#define PTLOUT      0xa9
#define RMWIN       0xe0
#define RMWOUT      0xee
#define ASCSET      0xaa
#define SCSTART     0xab
#define OSCON       0xd1
#define OSCOFF      0xd2
#define PWRCTR      0x20
#define VOLCTR      0x81
#define VOLUP       0xd6
#define VOLDOWN     0xd7
#define TMPGRD      0x82
#define EPCTIN      0xcd
#define EPCOUT      0xcc
#define EPMWR       0xfc
#define EPMRD       0xfd
#define EPSRRD1     0x7c
#define EPSRRD2     0x7d
#define NOP         0x25

#define RGB_8BIT   2
#define RGB_12BIT	 3

#endif
