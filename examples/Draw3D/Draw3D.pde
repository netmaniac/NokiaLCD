/* test program to demonstration LCD & Joystick, using a menu */
//#include "PCF8833.h"
#include "New3D.h"
#include "image.h"
//#include <avr/pgmspace.h>
#include <NettigoKeypad.h>
#include "NokiaJoystick.h"
Nokia_Joystick joystick = Nokia_Joystick();

extern "C" {
#include "FrameBuffer.h"
#include "PCF8833.h"
#include <avr/pgmspace.h>
#include <math.h>
}

#define byte unsigned char	
#define u16 unsigned short	
#define u32 unsigned long	
#define s16 signed short	
#define i32 signed long		

#define abs(x)	(x<0)?	(0-x):(x)
//////////////


//////////////

#define CUBE_VERTICES			8
#define CUBE_EDGES				12

#define TETRAHEDRON_VERTICES	4
#define TETRAHEDRON_EDGES		6

#define OCTAHEDRON_VERTICES		6
#define OCTAHEDRON_EDGES		12

#define PYRAMID_VERTICES		5
#define PYRAMID_EDGES			8

#define PRISM_VERTICES			6
#define PRISM_EDGES				9


/***	HEXAHEDRON (CUBE)	***/
Vertex cube_vectices[CUBE_VERTICES]  ={
	{-10, -10, -10},	//0
	{ 10, -10, -10},	//1
	{ 10,  10, -10},	//2
	{-10,  10, -10},	//3
	{-10, -10,  10},	//4
	{ 10, -10,  10},	//5
	{ 10,  10,  10},	//6
	{-10,  10,  10}		//7
};
Edge cube_edges[CUBE_EDGES]  =	// two vertices connected
{
	{0, 1}, {1, 2}, {2, 3}, {0, 3},
	{4, 5}, {5, 6}, {6, 7}, {4, 7},
	{0, 4}, {1, 5}, {2, 6}, {3, 7},
};

/***	TETRAHEDRON		***/
Vertex tetrahedron_vectices[TETRAHEDRON_VERTICES]={
#if 0
  ( 0, Sqr(3) - 1/Sqr(3),            0)
  (-1,        - 1/Sqr(3),            0)
  ( 1,        - 1/Sqr(3),            0)
  ( 0,                 0, 2 * Sqr(2/3))
#else
  { 0, 14, 0},
  {-12,-7, 0},
  { 12,-7, 0},
  { 0, 0, 20}
#endif
};
Edge tetrahedron_edges[TETRAHEDRON_EDGES] =
{
	{1, 0}, {1, 2}, {1, 3},
	{0, 2}, {2, 3}, {0, 3}
};

/***	OCTAHEDRON		***/
Vertex octahedron_vectices[OCTAHEDRON_VERTICES]={
	{ 17,  0,  0},	//0
	{  0, 17,  0},	//1
	{  0,  0, 17},	//2
	{-17,  0,  0},	//3
	{  0,-17,  0},	//4
	{  0,  0,-17}	//5
};

Edge octahedron_edges[OCTAHEDRON_EDGES] =
{
	{0, 1}, {0, 2}, {0, 4}, {0, 5},
	{1, 2}, {2, 4}, {4, 5}, {1, 5},
	{3, 1}, {3, 2}, {3, 4}, {3, 5},
};

/***	PYRAMID		***/
Vertex pyramid_vectices[PYRAMID_VERTICES]={
	{  0,  0, 12},	//0
	{-10, 10, -8},	//1
	{ 10, 10, -8},	//2
	{ 10,-10, -8},	//3
	{-10,-10, -8},	//4
};

Edge pyramid_edges[PYRAMID_EDGES] =
{
	{0, 1}, {0, 2}, {0, 3}, {0, 4},
	{1, 2}, {2, 3}, {3, 4}, {1, 4}
};

/***	TRIANGULAR PRISM		***/
Vertex prism_vectices[PRISM_VERTICES]={
	{  0, 10, 10},	//0
	{ 10, -7, 10},	//1
	{-10, -7, 10},	//2
	{  0, 10,-10},	//3
	{ 10, -7,-10},	//4
	{-10, -7,-10},	//5
};

Edge prism_edges[PRISM_EDGES] =
{
	{0, 1}, {1, 2}, {0, 2},
	{3, 4}, {4, 5}, {3, 5},
	{0, 3}, {1, 4}, {2, 5}
};


signed short sin_table(unsigned char angle);
signed short cos_table(unsigned char angle);


// quarter sine
unsigned char sine_table[64] = 
{
  0,6,13,19,25,31,37,44,
  50,56,62,68,74,80,86,92,
  98,103,109,115,120,126,131,136,
  142,147,152,157,162,167,171,176,
  180,185,189,193,197,201,205,208,
  212,215,219,222,225,228,231,233,
  236,238,240,242,244,246,247,249,
  250,251,252,253,254,254,255,255
};

signed short sin_table(unsigned char angle)
{
	unsigned char b;
	signed short i;
	if ((angle & 0x7F) == 0)
    return 0;
  b = angle & 0x3F;
  if (angle & 0x40)
    b = 0x3F - b;
	i = sine_table[b];
  if (angle & 0x80)
    return -i;
  return i;
}

signed short cos_table(unsigned char angle)
{
  return sin_table(angle + 64);
}


#define SCALE_FACTOR	2
#define OFFSETX			40//66	// LCD width/2
#define OFFSETY			40//66	// LCD height/2
#define MAX_VERTICES	20

#define LINE_COLOR		LCD_DARKRED	// edge color - e.g.LCD_RED
#define BG_COLOR LCD_GRAY

//////////////////////////////////////////////////////////////////

void draw_3D( Vertex * V,  Edge * E, unsigned char nVertices, unsigned char nEdges, unsigned char xRot, unsigned char yRot, unsigned char zRot);


//////////////////////////////////////////////////////////////////
#define draw_tetrahedron(xrot, yrot, zrot)	\
draw_3D(tetrahedron_vectices, tetrahedron_edges, TETRAHEDRON_VERTICES, TETRAHEDRON_EDGES, xrot, yrot, zrot)

#define draw_cube(xrot, yrot, zrot)	\
draw_3D(cube_vectices, cube_edges, CUBE_VERTICES, CUBE_EDGES, xrot, yrot, zrot)

#define draw_octahedron(xrot, yrot, zrot)	\
draw_3D(octahedron_vectices, octahedron_edges, OCTAHEDRON_VERTICES, OCTAHEDRON_EDGES, xrot, yrot, zrot)

#define draw_pyramid(xrot, yrot, zrot)	\
draw_3D(pyramid_vectices, pyramid_edges, PYRAMID_VERTICES, PYRAMID_EDGES, xrot, yrot, zrot)

#define draw_prism(xrot, yrot, zrot)	\
draw_3D(prism_vectices, prism_edges, PRISM_VERTICES, PRISM_EDGES, xrot, yrot, zrot)

static Point new_points[MAX_VERTICES] = {0};
static Point old_points[MAX_VERTICES] = {0};

/**********************************************************/

void draw_3D(Vertex * V,  Edge * E, unsigned char nVertices, unsigned char nEdges, unsigned char xRot, unsigned char yRot, unsigned char zRot)
{
  unsigned char i;
  float tempX,tempY,tempZ;				// temporary coordinates
  float sinX,sinY,sinZ,cosX,cosY,cosZ;	// precomputed sin and cos values
  float px,py,pz;							// projected
  
  // sin and cos values
  sinX = sin_table( xRot ) / 255.0;
  sinY = sin_table( yRot ) / 255.0;
  sinZ = sin_table( zRot ) / 255.0;
  
  cosX = cos_table( xRot ) / 255.0;
  cosY = cos_table( yRot ) / 255.0;
  cosZ = cos_table( zRot ) / 255.0;
  
  // calculate the new coordinates of points
  for (i=0; i<nVertices; i++)
  {
    tempX = V[i].x;
    tempY = V[i].y;
    tempZ = V[i].z;
    
    // store previous coordinates
    old_points[i] = new_points[i];
    
    // rotation on X axis
    py = tempY * cosX - tempZ * sinX;
    pz = tempY * sinX + tempZ * cosX;
    tempY =py; tempZ = pz;
    
    // rotation on Z axis
    px = tempX * cosZ - tempY * sinZ;
    py = tempX * sinZ + tempY * cosZ;
    tempX = px; tempY = py;
    
    // rotation on Y axis
    px = tempX * cosY - tempZ * sinY;
    pz = tempX * sinY + tempZ * cosY;
    
    // save the screen coordinates
    //    Serial.println((unsigned char)px,10);
    //    Serial.println((unsigned char)py,10);
    
    new_points[i].x = (unsigned char)px * SCALE_FACTOR + OFFSETX;
    new_points[i].y = (unsigned char)py * SCALE_FACTOR + OFFSETY;
    //    Serial.println(new_points[i].x,10);
    //    Serial.println(new_points[i].y,10);
  }
  // lcd plot
  
  //  Serial.println("Points:");
  //  for (i=0; i<20; i++) {
  //    Serial.print("NEW: x,y: ");
  //    Serial.print(new_points[i].x, DEC);
  //    Serial.print(":");
  //    Serial.println(new_points[i].y, DEC);
  //
  //    Serial.print("OLD: x,y: ");
  //    Serial.print(old_points[i].x, DEC);
  //    Serial.print(":");
  //    Serial.println(old_points[i].y, DEC);
  //  }
  
  //  Serial.println("Edges: ");
  //  Serial.print(nEdges, DEC);
  for (i=0; i<nEdges; i++)
  {
    //    Serial.println("Edge number:");
    //    Serial.println(E[i].start, DEC);
    //    Serial.println(E[i].end, DEC);
    
    // erase old edges
    //    drawLine(
    //             old_points[E[i].start].x, old_points[E[i].start].y,
    //             old_points[E[i].end].x, old_points[E[i].end].y);
    // draw new edges
    drawLine(
             new_points[E[i].start].x, new_points[E[i].start].y,
             new_points[E[i].end].x, new_points[E[i].end].y);
		// erase old edges
    //		LCD_Line(
    //			old_points[E[i].start].x, old_points[E[i].start].y,
    //			old_points[E[i].end].x, old_points[E[i].end].y,
    //			BG_COLOR);
    //		// draw new edges
    //		LCD_Line(
    //			new_points[E[i].start].x, new_points[E[i].start].y,
    //			new_points[E[i].end].x, new_points[E[i].end].y,
    //			LINE_COLOR);
    ////		Serial.println("Edge: ");
    ////    Serial.println(i, DEC);
    ////    
    ////    Serial.println(new_points[E[i].start].x,10);
    ////    Serial.println(new_points[E[i].start].y,10);
    ////
    ////    Serial.println(new_points[E[i].end].x,10);
    ////    Serial.println(new_points[E[i].end].y,10);
    
  }
}


/* 0-0-0-0-0-0-0 */

#define BL_PIN 3
void InitPort(){
  DDRB=0x2F;
}

void handleInput();

unsigned long int counter;
unsigned long int axisYRotation;
unsigned long int axisXRotation;
unsigned long int shapeToDraw = 0;

void setup(void){
  Serial.begin(9600);
  Serial.println("SETUP-------------------");
  LCD_BACKLIGHT(0);
  digitalWrite(BL_PIN, HIGH); 
  InitPort();
  
  LCD_Init();
  LCD_Box(0, 0, 131, 131, FILL, BG_COLOR);
  counter = 0;
  ////
  // Setup timer2 -- Prescaler/256
  TCCR2A &= ~((1<<WGM21) | (1<<WGM20));
  TCCR2B &= ~(1<<WGM22);
  TCCR2B = (1<<CS22)|(1<<CS21);      
  
  ASSR |=(0<<AS2);
  
  // Use normal mode  
  TCCR2A =0;    
  //Timer2 Overflow Interrupt Enable  
  TIMSK2 |= (0<<OCIE2A);
  TCNT2=0x6;  // counting starts from 6;  
  TIMSK2 = (1<<TOIE2);    
  
  SREG|=1<<SREG_I;
  
  Serial.println("SETUP DONE-------------------");
}

#define NUM_KEYS 5

// joystick number
#define UP_KEY 1
#define LEFT_KEY 2
#define CENTER_KEY 4
#define DOWN_KEY 3
#define RIGHT_KEY 0


// debounce counters
byte button_count[NUM_KEYS];
// button status - pressed/released
byte button_status[NUM_KEYS];
// button on flags for user program 
byte button_flag[NUM_KEYS];

// Convert ADC value to key number
char get_key(unsigned int input);
void update_adc_key();
  

char pressed_key(){
  byte i;
  
  for(i=0; i<NUM_KEYS; i++){
    if(button_flag[i] !=0){
      button_flag[i]=0;  // reset button flag
      return i;
    }
  }
  
  return -1;
  
}


unsigned char xRot = 0;
unsigned char yRot = 0;
unsigned char zRot = 0;


unsigned long startTime,stopTime;
void loop(void){
  //FBoff -> 
  startTime = millis();
  clearBuffer();
  
  unsigned char rot = counter%256;
  
  char step = 8;
  
  char key = joystick.key_pressed(analogRead(0));
  
  switch(key){
    case JOYSTICK_UP:
      xRot-=step;
      break;
    case JOYSTICK_DOWN:          
      xRot+=step;
      break;
    case JOYSTICK_LEFT:          
      yRot-=step;
      break;
    case JOYSTICK_RIGHT:
      yRot+=step;
      break;
    case JOYSTICK_SELECT:
      xRot=0;
      yRot=0;
      shapeToDraw++;
      break;
  }  
  
  switch (shapeToDraw%5) {
    case 0:
      zRot=20;
      zRot=0;
     	draw_tetrahedron(xRot,yRot,zRot); 
      break;
    case 1:
      zRot=50;
      zRot=0;
     	draw_cube(xRot,yRot,zRot); 
      break;
    case 2:
      zRot=90;
      zRot=0;
     	draw_octahedron(xRot,yRot,zRot); 
      break;
    case 3:
      zRot=50;
      zRot=0;
     	draw_pyramid(xRot,yRot,zRot); 
      break;
    case 4:
      zRot=20;
      zRot=0;
     	draw_prism(xRot,yRot,zRot); 
      break;
  }
  /*  
   drawLine(counter%80,0, counter%80,79);
   drawLine(79-counter%80,0, 79-counter%80,79);
   
   float s=1.23f;
   double _sin = sin(3.1415/2.3);
   double _cos = cos(3.1415/2.23122);
   double r = _cos/_sin;
   
   drawLine(0, counter%80,	79,counter%80);
   drawLine(0,79-counter%80, 79, 79-counter%80);
   */
  //  frameBuffer[0]=0x07;
  //  frameBuffer[FRAME_WIDTH_IN_BYTES]=0x01;
  //  frameBuffer[FRAME_WIDTH_IN_BYTES*2]=0x01;
  
  //FBoff ->
  drawBuffer(LINE_COLOR, BG_COLOR);
  //counter+=4;
  stopTime = millis();
  // printount FPS :)
  Serial.println(1000/float(stopTime-startTime),DEC);
  
  //handleInput();
}

////////////////////////////////////////////////
//keypad debounce parameter
#define DEBOUNCE_MAX 5	//15
#define DEBOUNCE_ON  1	//10
#define DEBOUNCE_OFF 1	//3 

int  adc_key_val[NUM_KEYS] ={10, 155, 341, 517, 751};

char get_key(unsigned int input){
	char k;
  
	for (k = 0; k < NUM_KEYS; k++){
		if (input < adc_key_val[k]){
      return k;
    }
	}
  
  if (k >= NUM_KEYS){
    k = -1;     // No valid key pressed
  }
  
  return k;
}

void update_adc_key(){
  int adc_key_in;
  char key_in;
  byte i;
  
  
  
  adc_key_in = analogRead(0);
  key_in = get_key(adc_key_in);
  for(i=0; i<NUM_KEYS; i++)  {
    if(key_in==i){
      //one key is pressed 
      
      //debouncement only for center button
      if (key_in==CENTER_KEY) {
        if(button_count[i]<DEBOUNCE_MAX) {
          button_count[i]++;
          if(button_count[i]>DEBOUNCE_ON){
            if(button_status[i] == 0){
              button_flag[i] = 1;
              button_status[i] = 1; //button debounced to 'pressed' status
              //Serial.println(i,HEX);
            }
          }
        }
      }else {
        button_flag[i] = 1;
        button_status[i] = 1; //button debounced to 'pressed' status
      }
      
      
      
    }else {
	    // no button pressed
      if (button_count[i] >0) {  
        button_flag[i] = 0;	
        button_count[i]--;
        if(button_count[i]<DEBOUNCE_OFF){
          button_status[i]=0;   //button debounced to 'released' status
          //Serial.println(0xF000+i,HEX);          
        }
      }
    }
  }
}


ISR(TIMER2_OVF_vect) {  
  TCNT2  = 6;
  update_adc_key();
}
