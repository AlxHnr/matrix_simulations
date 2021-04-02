#include "matrix_lib.h"

unsigned char matrixvariable[matrix_pixel];/*Hauptvariable, die die Farbe für jeden Pixel enthält*/

void matrix(unsigned short spalte,unsigned short zeile,unsigned char farbe){
  if(spalte > matrix_breite)
    return;
  else if(spalte < 1)
    return;
  if(zeile > matrix_hohe)
    return;
  else if(zeile < 1)
    return;
  matrixvariable[--spalte + (--zeile * (matrix_breite + 1))] = farbe;
}
void gebeaus(){
  unsigned short ii = 0;
  unsigned short cc = 0;
  while(ii <= matrix_pixel)
  {
    if(cc == matrix_breite){
      cc = 0;
      printf("\033[0;%im\n",matrixvariable[ii]);
    }
    else{
      printf("\033[0;%im ",matrixvariable[ii]);
      cc++;
    }
    ii++;
  }
}

void binaer(char* bigbuchstabe,unsigned char stelle,unsigned char spalte,unsigned char farbe){/*Optimiert*/
  unsigned short ii = 0;
  unsigned short ic = strlen(bigbuchstabe);
  unsigned char cc = 0;
  if(ic > matrix_pixel)
    ic = matrix_pixel;
  while(ii <= ic){
    if(bigbuchstabe[ii] == '1')
    {
      matrix(stelle + cc,spalte,farbe);
    }
    else if(bigbuchstabe[ii] == 'n')
      cc = matrix_breite;
    if(cc == matrix_breite){
      cc = 0;spalte++;}
    else
      cc++;
    ii++;
  }
}
void satz(char* buchstabe,unsigned char stelle,unsigned char spalte,unsigned char farbe){/*Optimiert*/
  unsigned char ii = 0;
  unsigned char cc = 0;
  unsigned char lange = strlen(buchstabe);
  char* pointer;
  if(lange > 52)
    lange = 52;
  while(ii < lange){
    switch(buchstabe[ii]){
      case 'A':pointer = zeichen_A;break;
      case 'B':pointer = zeichen_B;break;
      case 'C':pointer = zeichen_C;break;
      case 'D':pointer = zeichen_D;break;
      case 'E':pointer = zeichen_E;break;
      case 'F':pointer = zeichen_F;break;
      case 'G':pointer = zeichen_G;break;
      case 'H':pointer = zeichen_H;break;
      case 'I':pointer = zeichen_I;break;
      case 'J':pointer = zeichen_J;break;
      case 'K':pointer = zeichen_K;break;
      case 'L':pointer = zeichen_L;break;
      case 'M':pointer = zeichen_M;break;
      case 'N':pointer = zeichen_N;break;
      case 'O':pointer = zeichen_O;break;
      case 'P':pointer = zeichen_P;break;
      case 'Q':pointer = zeichen_Q;break;
      case 'R':pointer = zeichen_R;break;
      case 'S':pointer = zeichen_S;break;
      case 'T':pointer = zeichen_T;break;
      case 'U':pointer = zeichen_U;break;
      case 'V':pointer = zeichen_V;break;
      case 'W':pointer = zeichen_W;break;
      case 'X':pointer = zeichen_X;break;
      case 'Y':pointer = zeichen_Y;break;
      case 'Z':pointer = zeichen_Z;break;
      case 'a':pointer = zeichen_a;break;
      case 'b':pointer = zeichen_b;break;
      case 'c':pointer = zeichen_c;break;
      case 'd':pointer = zeichen_d;break;
      case 'e':pointer = zeichen_e;break;
      case 'f':pointer = zeichen_f;break;
      case 'g':pointer = zeichen_g;break;
      case 'h':pointer = zeichen_h;break;
      case 'i':pointer = zeichen_i;break;
      case 'j':pointer = zeichen_j;break;
      case 'k':pointer = zeichen_k;break;
      case 'l':pointer = zeichen_l;break;
      case 'm':pointer = zeichen_m;break;
      case 'n':pointer = zeichen_n;break;
      case 'o':pointer = zeichen_o;break;
      case 'p':pointer = zeichen_p;break;
      case 'q':pointer = zeichen_q;break;
      case 'r':pointer = zeichen_r;break;
      case 's':pointer = zeichen_s;break;
      case 't':pointer = zeichen_t;break;
      case 'u':pointer = zeichen_u;break;
      case 'v':pointer = zeichen_v;break;
      case 'w':pointer = zeichen_w;break;
      case 'x':pointer = zeichen_x;break;
      case 'y':pointer = zeichen_y;break;
      case 'z':pointer = zeichen_z;break;
      case '0':pointer = zeichen_0;break;
      case '1':pointer = zeichen_1;break;
      case '2':pointer = zeichen_2;break;
      case '3':pointer = zeichen_3;break;
      case '4':pointer = zeichen_4;break;
      case '5':pointer = zeichen_5;break;
      case '6':pointer = zeichen_6;break;
      case '7':pointer = zeichen_7;break;
      case '8':pointer = zeichen_8;break;
      case '9':pointer = zeichen_9;break;
      case '!':pointer = zeichen_ausrufezeichen;break;
      case '"':pointer = zeichen_anfuehrungszeichen;break;
      case '#':pointer = zeichen_raute;break;
      case '$':pointer = zeichen_peso;break;
      case '%':pointer = zeichen_prozent;break;
      case '&':pointer = zeichen_und;break;
      case '\'':pointer = zeichen_anfuehrungsstrich;break;
      case '(':pointer = zeichen_klammerauf;break;
      case ')':pointer = zeichen_klammerzu;break;
      case '*':pointer = zeichen_sternchen;break;
      case '+':pointer = zeichen_plus;break;
      case ',':pointer = zeichen_komma;break;
      case '-':pointer = zeichen_minus;break;
      case '.':pointer = zeichen_punkt;break;
      case '/':pointer = zeichen_slash;break;
      case ':':pointer = zeichen_doppelpunkt;break;
      case ';':pointer = zeichen_semikolon;break;
      case '>':pointer = zeichen_kleiner;break;
      case '=':pointer = zeichen_gleich;break;
      case '<':pointer = zeichen_groser;break;
      case '?':pointer = zeichen_frage;break;
      default:pointer = zeichen_SPACE;break;
    }
    binaer(pointer,stelle + (cc * 6),((spalte - 1) * 6) + 1,farbe);
    if(cc == 12){
      cc = 0;spalte++;}
    else
      cc++;
    ii++;
  }
}

void farbe_umkehren(matrix_objekt* zeiger){
  switch(zeiger->farbe){
    case 40:zeiger->farbe = 47;break;
    case 47:zeiger->farbe = 40;break;
    case 41:zeiger->farbe = 42;break;
    case 42:zeiger->farbe = 41;break;
    case 44:zeiger->farbe = 43;break;
    case 43:zeiger->farbe = 44;break;
    case 46:zeiger->farbe = 45;break;
    case 45:zeiger->farbe = 46;break;
  }
}

int colision(matrix_objekt* objekt_1,matrix_objekt* objekt_2){
  return (objekt_1->position_x + objekt_1->breite >= objekt_2->position_x &&
  objekt_1->position_x <= objekt_2->position_x + objekt_2->breite &&
  objekt_1->position_y + objekt_1->hohe >= objekt_2->position_y &&
  objekt_1->position_y <= objekt_2->position_y + objekt_2->hohe);
}