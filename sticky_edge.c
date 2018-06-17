#include <stdlib.h>
#include "matrix_lib.h"

matrix_objekt hintergrund = {zeichen_FULL,farbe_schwarz,matrix_breite,matrix_hohe,1,1,0,0};
matrix_objekt rahmen = {"11111111111111111111111111111111111111111111111111111111111111111111111111111111n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n10000000000000000000000000000000000000000000000000000000000000000000000000000001n11111111111111111111111111111111111111111111111111111111111111111111111111111111",farbe_weis,1,1,1,1,0,0};
matrix_objekt kleber = {"001n111",farbe_gelb,3,2,78,21,0,0};

void config_x_y(matrix_objekt* objekt){
  if(objekt->position_x == matrix_breite - objekt->breite && objekt->position_y == matrix_hohe - objekt->hohe)
  {
    objekt->bewegungsrichtung_x = 0;
    objekt->bewegungsrichtung_y = 0;
    return;
  }
  if(objekt->position_x > matrix_breite - objekt->breite - rahmen.breite)
  {
    objekt->bewegungsrichtung_x = -1;
  }
  else if(objekt->position_x < + rahmen.breite + 2)
  {
    objekt->bewegungsrichtung_x = 1;
  }
  if(objekt->position_y > matrix_hohe - objekt->hohe - rahmen.hohe)
  {
    objekt->bewegungsrichtung_y = -1;
  }
  else if(objekt->position_y < rahmen.hohe + 2)
  {
    objekt->bewegungsrichtung_y = 1;
  }
}
#define reg_objekt(objekt)config_x_y(&objekt);objekt.position_x += objekt.bewegungsrichtung_x;objekt.position_y += objekt.bewegungsrichtung_y;;schreibe_objekt(objekt);

int main()
{
  matrix_objekt ball_1 = {"01n101n01",farbe_blau,3,3,20,6,-1,-1};
  matrix_objekt ball_1_fill = {"n01",farbe_grun,3,3,20,6,-1,-1};
  matrix_objekt ball_2 = {"01n101n01",farbe_lila,3,3,4,16,1,-1};
  matrix_objekt ball_3 = {"1n111n001",farbe_blau,3,3,5,5,-1,1};
  matrix_objekt ball_4 = {"01n111n01",farbe_grun,3,3,72,2,-1,1};
  matrix_objekt ball_5 = {"1n1n1",farbe_turkis,1,3,45,15,1,1};
  matrix_objekt ball_6 = {"11n11n11",farbe_rot,2,3,36,7,1,1};
  matrix_objekt ball_7 = {"1111",farbe_blau,4,1,25,10,-1,-1};
  matrix_objekt ball_8 = {"01n101n101n01",farbe_rot,3,4,6,17,-1,1};
  matrix_objekt ball_8_fill = {"n01n01",farbe_lila,3,4,6,17,-1,1};
  matrix_objekt ball_9 = {"0111n10001n0111",farbe_lila,5,3,15,15,1,-1};
  matrix_objekt ball_9_fill = {"n0111",farbe_blau,5,3,15,15,1,-1};
  matrix_objekt ball_10 = {"1n01n001n0001",farbe_lila,4,4,35,5,-1,-1};
  matrix_objekt wort_a = {zeichen_A,farbe_gelb,5,5,4,2,1,1};
  matrix_objekt bug = {"10001n0111n10101n11111n10101",farbe_turkis,5,5,20,10,1,1};
  matrix_objekt bug_eye = {"nn0101",farbe_rot,5,5,20,10,1,1};
  matrix_objekt viereck = {"111n101n111",farbe_grun,3,3,55,15,-1,-1};
  while(ball_1.bewegungsrichtung_x != 0 ||
        ball_2.bewegungsrichtung_x != 0 ||
        ball_3.bewegungsrichtung_x != 0 ||
        ball_4.bewegungsrichtung_x != 0 ||
        ball_5.bewegungsrichtung_x != 0 ||
        ball_6.bewegungsrichtung_x != 0 ||
        ball_7.bewegungsrichtung_x != 0 ||
        ball_8.bewegungsrichtung_x != 0 ||
        ball_9.bewegungsrichtung_x != 0 ||
        ball_10.bewegungsrichtung_x != 0 ||
        wort_a.bewegungsrichtung_x != 0 ||
        bug.bewegungsrichtung_x != 0 ||
        viereck.bewegungsrichtung_x != 0)
  {
    schreibe_objekt(hintergrund);
    schreibe_objekt(rahmen);
    schreibe_objekt(kleber);
    
    reg_objekt(ball_8);
    reg_objekt(ball_8_fill);
    reg_objekt(ball_4);
    reg_objekt(ball_1);
    reg_objekt(ball_1_fill);
    reg_objekt(ball_2);
    reg_objekt(ball_3);
    reg_objekt(ball_5);
    reg_objekt(ball_6);
    reg_objekt(ball_7);
    reg_objekt(ball_9);
    reg_objekt(ball_9_fill);
    reg_objekt(ball_10);
    reg_objekt(wort_a);
    reg_objekt(bug);
    reg_objekt(bug_eye);
    reg_objekt(viereck);
    gebeaus();
    Sleep(50);
  }
  return 0;
}