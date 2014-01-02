#include <Nokia_lcd.h>
#include <FONT8x8.h>

#include "logo.h"

#include <NettigoKeypad.h>
#include "NokiaJoystick.h"

Nokia_Joystick joystick = Nokia_Joystick();
Nokia_lcd lcd=Nokia_lcd();



const int menu_num=4;//ilość elementów w menu
const int max_text_len=9;//maksymalna długość tekstu w menu
const char menu [menu_num][max_text_len+1]={"Pozycja 1","Logo","Kolorki","Info"};//nazwy pozycji w menu
void (*menu_function[menu_num])(void)={nic,logoshow,kolorki,autor};//tablica wskaźników na funkcje wykonywane przy wyborze pozycji w menu
const byte menu_start_x=15,menu_start_y=2;//pozycja od której ma zostać utworzone menu
const int menu_fg=0x000;//kolor czcionki w menu 
const int menu_bg=0x0F0;//tło tekstu w menu
const int menu_fg_sel=0xFFF;//jak wyżej, tyle, że dla elementu aktualnie wybranego
const int menu_bg_sel=0x000;
const int debounce_time=50;//czas eliminacji drgań styków (ms)
const int debounce_time_raw=debounce_time/4;//przeliczamy czas dla przerwania co 4ms
const int rep_debounce_time=500;//czas powtarzania działania przy przytrzymaniu joysticka w danej pozycji
const int rep_debounce_time_raw=rep_debounce_time/4;//jak wyżej przeliczamy czas

volatile byte selected=0;//zmienna przechowująca aktualnie wybeany element (ze zmiennych korzystamy w różnych funkcjach poza funkcją main zatem oznaczamy je jako volatile)
volatile byte joystick_sel=0;//zmienna przechowująca ostatnio wciśnięty klawisz joysticka
volatile byte flag=0;//zmienna przechowująca stan eliminacji drgań styków

const byte j_none=0,j_up=4,j_down=2,j_left=3,j_right=5,j_press=1;//stałe ułątwiające odczyt pozycji z joysticka


void menu_show(byte sel=0){//funkcja wyświetlająca menu
  lcd.cLCD_Box(menu_start_x,menu_start_y,menu_start_x+8*max_text_len-1,menu_start_y+8*menu_num-1,FILL,menu_bg);//rysujemy tło menu
  for(int i=0;i<menu_num;i++){//wyświetlamy elementy
    if(sel==i){//jeśli element ma być zaznaczony to stosujemy odpowiednie tło i kolor z konfiguracji
      lcd.cLCD_String((char*)menu[i],menu_start_x,menu_start_y+8*i,menu_fg_sel,menu_bg_sel,F8x8);
    }else{
      lcd.cLCD_String((char*)menu[i],menu_start_x,menu_start_y+8*i,menu_fg,menu_bg,F8x8);
    }
  }
}

void menu_select(byte sel){//zaznaczamy element o danym numerze
  lcd.cLCD_String((char*)menu[sel],menu_start_x,menu_start_y+8*sel,menu_fg_sel,menu_bg_sel,F8x8);
}

void menu_deselect(byte sel){//odznczamy element o danym nuemrze
  lcd.cLCD_String((char*)menu[sel],menu_start_x,menu_start_y+8*sel,menu_fg,menu_bg,F8x8);
}

void setup(void){
  lcd.cLCD_Backlight(1);
  lcd.cLCD_Init();
  lcd.cLCD_Contrast(58);
  lcd.cLCD_CLS();//inicjalizujemy i czyścimy LCD
  logoshow();
  //menu_show();//wyświetlamy menu
  
}

void loop(void)
{
  if(flag==2){//jeśli joystick został przyciśnięty
    flag=3;//ustawiamy flagę do powtarzania czynności
     switch(joystick_sel){//w zależności od pozycji joysticka wykonukjemy różne działania
      case j_down://menu w dół
        menu_deselect(selected);
        selected++;
        if(selected==menu_num)selected=0;
        menu_select(selected);
      break;
      case j_up://menu w górę
        menu_deselect(selected);
        selected--;
        if(selected==255)selected=menu_num-1;
        menu_select(selected);
      break;
      case j_press://przyciśniecie
        menu_function[selected]();//wywołujemy odpowiednią funkcję
      break;
    }
  }
}

void nic(){//pusty ekran
  lcd.cLCD_CLS();
  lcd.cLCD_String("<-",1,123,0xFFF,0x000,F8x8);
  while(joystick_sel!=j_left||flag!=2);//oczekujemy na wciśnięcie przycisku w lewo
  lcd.cLCD_CLS();//czyścimy ekran i ponownie rysujemy menu
  menu_show(selected);
}

void autor(){//wyświetlamy informacje o programie
  lcd.cLCD_CLS();
  lcd.cLCD_String("Piotr  Rzeszut",10,10,0x000,0xFFF,F8x8);
  lcd.cLCD_String(" Kurs Arduino",10,21,0x000,0xFFF,F8x8);
  lcd.cLCD_String(" ARD GRAPH132",10,30,0x000,0xFFF,F8x8);
  lcd.cLCD_String("<-",1,123,0xFFF,0x000,F8x8);
  while(joystick_sel!=j_left||flag!=2);//oczekujemy na wciśnięcie przycisku w lewo
  lcd.cLCD_CLS();//czyścimy ekran i ponownie rysujemy menu
  menu_show(selected);
}

void kolorki(){//wyświetlamy cieniowane paski
  lcd.cLCD_CLS();
  int kolor;
  float procent;
  for(int i=0;i<44;i++){
    procent=(float)i/44.0;
    procent*=15.0;
    kolor=(int)procent;
    kolor*=0x100;
    lcd.cLCD_Line(i,0,i,131,kolor);
  }
  for(int i=0;i<44;i++){
    procent=(float)i/44.0;
    procent*=15.0;
    kolor=(int)procent;
    kolor*=0x10;
    lcd.cLCD_Line(i+44,0,i+44,131,kolor);
  }
  for(int i=0;i<43;i++){
    procent=(float)i/44.0;
    procent*=15.0;
    kolor=(int)procent;
    kolor*=0x1;
    lcd.cLCD_Line(i+88,0,i+88,131,kolor);
  }
  lcd.cLCD_String("<-",1,123,0xFFF,0x000,F8x8);
  while(joystick_sel!=j_left||flag!=2);//oczekujemy na wciśnięcie przycisku w lewo
  lcd.cLCD_CLS();//czyścimy ekran i ponownie rysujemy menu
  menu_show(selected);
}

void logoshow(){
  lcd.cLCD_CLS();
  lcd.cLCD_Bitmap(41,49,logo);
  lcd.cLCD_String("<-",1,123,0xFFF,0x000,F8x8);
  while(joystick_sel!=j_left||flag!=2);//oczekujemy na wciśnięcie przycisku w lewo
  lcd.cLCD_CLS();//czyścimy ekran i ponownie rysujemy menu
  menu_show(selected);
}

