
typedef struct
{	
  signed char x;
  signed char y;
  signed char z;
} Vertex;

typedef struct
{	// two vertex_index connected
  unsigned char start;
  unsigned char end;
}Edge;

typedef struct
{	// LCD 2D coordinate
  unsigned char x;
  unsigned char y;
}Point;
