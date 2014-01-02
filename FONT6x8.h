/**********************************************/
/*         Created by LCD Font Maker          */
/*               www.krzoska.tk               */
/*              janusz@krzoska.tk             */
/**********************************************/
#include <avr/pgmspace.h>
#define FONT6x8_included
const unsigned char FONT6x8[97][8]= {
0x06,0x08,0x08,0x00,0x00,0x00,0x00,0x00, // columns, rows, num_bytes_per_char
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 32 :  
0x04,0x04,0x04,0x04,0x00,0x04,0x00,0x00, // 33 : !
0x0A,0x0A,0x00,0x00,0x00,0x00,0x00,0x00, // 34 : "
0x0A,0x1F,0x0A,0x0A,0x0A,0x1F,0x0A,0x00, // 35 : #
0x0A,0x0F,0x10,0x0E,0x01,0x1E,0x0A,0x00, // 36 : $
0x00,0x12,0x04,0x08,0x12,0x00,0x00,0x00, // 37 : %
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 38 : &
0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00, // 39 : '
0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x00, // 40 : (
0x04,0x02,0x02,0x02,0x02,0x02,0x04,0x00, // 41 : )
0x00,0x15,0x0E,0x1F,0x0E,0x15,0x00,0x00, // 42 : *
0x00,0x00,0x04,0x0E,0x04,0x00,0x00,0x00, // 43 : +
0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x00, // 44 : ,
0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00, // 45 : -
0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00, // 46 : .
0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00, // 47 : /
0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00, // 48 : 0
0x02,0x06,0x02,0x02,0x02,0x02,0x07,0x00, // 49 : 1
0x0E,0x11,0x02,0x04,0x08,0x10,0x1F,0x00, // 50 : 2
0x0E,0x11,0x01,0x02,0x01,0x11,0x0E,0x00, // 51 : 3
0x02,0x06,0x0A,0x12,0x1F,0x02,0x02,0x00, // 52 : 4
0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E,0x00, // 53 : 5
0x0F,0x10,0x1E,0x11,0x11,0x11,0x0E,0x00, // 54 : 6
0x1F,0x01,0x02,0x04,0x08,0x10,0x10,0x00, // 55 : 7
0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00, // 56 : 8
0x0E,0x11,0x11,0x11,0x0F,0x01,0x0E,0x00, // 57 : 9
0x00,0x00,0x04,0x00,0x04,0x00,0x00,0x00, // 58 : :
0x00,0x00,0x04,0x00,0x00,0x04,0x04,0x00, // 59 : ;
0x00,0x02,0x04,0x08,0x04,0x02,0x00,0x00, // 60 : <
0x00,0x00,0x0E,0x00,0x0E,0x00,0x00,0x00, // 61 : =
0x00,0x08,0x04,0x02,0x04,0x08,0x00,0x00, // 62 : >
0x0E,0x11,0x02,0x04,0x04,0x00,0x04,0x00, // 63 : ?
0x0E,0x11,0x15,0x17,0x10,0x11,0x0E,0x00, // 64 : @
0x0E,0x11,0x11,0x11,0x1F,0x11,0x11,0x00, // 65 : A
0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00, // 66 : B
0x0E,0x11,0x10,0x10,0x10,0x11,0x0E,0x00, // 67 : C
0x1E,0x09,0x09,0x09,0x09,0x09,0x1E,0x00, // 68 : D
0x1F,0x10,0x10,0x1C,0x10,0x10,0x1F,0x00, // 69 : E
0x1F,0x10,0x10,0x1C,0x10,0x10,0x10,0x00, // 70 : F
0x0E,0x11,0x10,0x17,0x11,0x11,0x0E,0x00, // 71 : G
0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00, // 72 : H
0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00, // 73 : I
0x01,0x01,0x01,0x01,0x01,0x11,0x0E,0x00, // 74 : J
0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00, // 75 : K
0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00, // 76 : L
0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00, // 77 : M
0x11,0x19,0x15,0x13,0x11,0x11,0x11,0x00, // 78 : N
0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00, // 79 : O
0x1E,0x11,0x11,0x11,0x1E,0x10,0x10,0x00, // 80 : P
0x0E,0x11,0x11,0x11,0x11,0x15,0x0E,0x01, // 81 : Q
0x1E,0x11,0x11,0x11,0x1E,0x12,0x11,0x00, // 82 : R
0x0E,0x11,0x10,0x0E,0x01,0x11,0x0E,0x00, // 83 : S
0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00, // 84 : T
0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00, // 85 : U
0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00, // 86 : V
0x11,0x11,0x11,0x15,0x15,0x15,0x0A,0x00, // 87 : W
0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,0x00, // 88 : X
0x11,0x11,0x0A,0x04,0x04,0x04,0x04,0x00, // 89 : Y
0x1F,0x01,0x02,0x04,0x08,0x10,0x1F,0x00, // 90 : Z
0x0C,0x08,0x08,0x08,0x08,0x08,0x0C,0x00, // 91 : [
0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00, // 92 : Backslash
0x06,0x02,0x02,0x02,0x02,0x02,0x06,0x00, // 93 : ]
0x04,0x0A,0x11,0x00,0x00,0x00,0x00,0x00, // 94 : ^
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00, // 95 : _
0x08,0x04,0x00,0x00,0x00,0x00,0x00,0x00, // 96 : `
0x00,0x00,0x0E,0x01,0x0F,0x11,0x0F,0x00, // 97 : a
0x10,0x10,0x1E,0x11,0x11,0x11,0x1E,0x00, // 98 : b
0x00,0x00,0x0F,0x10,0x10,0x10,0x0F,0x00, // 99 : c
0x01,0x01,0x0F,0x11,0x11,0x11,0x0F,0x00, // 100 : d
0x00,0x00,0x0E,0x11,0x1F,0x10,0x0E,0x00, // 101 : e
0x06,0x09,0x08,0x08,0x1C,0x08,0x08,0x08, // 102 : f
0x00,0x00,0x0F,0x11,0x11,0x1F,0x01,0x0E, // 103 : g
0x10,0x10,0x1E,0x11,0x11,0x11,0x11,0x00, // 104 : h
0x04,0x00,0x04,0x04,0x04,0x04,0x04,0x00, // 105 : i
0x04,0x00,0x04,0x04,0x04,0x04,0x04,0x08, // 106 : j
0x10,0x10,0x12,0x14,0x18,0x14,0x12,0x00, // 107 : k
0x10,0x10,0x10,0x10,0x10,0x10,0x0C,0x00, // 108 : l
0x00,0x00,0x1A,0x15,0x11,0x11,0x11,0x00, // 109 : m
0x00,0x00,0x1E,0x11,0x11,0x11,0x11,0x00, // 110 : n
0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00, // 111 : o
0x00,0x00,0x1E,0x11,0x11,0x1E,0x10,0x10, // 112 : p
0x00,0x00,0x0F,0x11,0x11,0x0F,0x01,0x01, // 113 : q
0x00,0x00,0x16,0x19,0x10,0x10,0x10,0x00, // 114 : r
0x00,0x00,0x0F,0x10,0x0E,0x01,0x1E,0x00, // 115 : s
0x08,0x08,0x1E,0x08,0x08,0x08,0x06,0x00, // 116 : t
0x00,0x00,0x11,0x11,0x11,0x11,0x0F,0x00, // 117 : u
0x00,0x00,0x11,0x09,0x05,0x03,0x01,0x00, // 118 : v
0x00,0x00,0x11,0x15,0x15,0x15,0x0B,0x00, // 119 : w
0x00,0x00,0x11,0x0A,0x04,0x0A,0x11,0x00, // 120 : x
0x00,0x00,0x11,0x11,0x11,0x0F,0x01,0x0E, // 121 : y
0x00,0x00,0x1F,0x02,0x04,0x08,0x1F,0x00, // 122 : z
0x02,0x04,0x04,0x08,0x04,0x04,0x02,0x00, // 123 : {
0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00, // 124 : |
0x08,0x04,0x04,0x02,0x04,0x04,0x08,0x00, // 125 : }
0x00,0x00,0x00,0x0D,0x12,0x00,0x00,0x00, // 126 : ~
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 // 127 : 
};
