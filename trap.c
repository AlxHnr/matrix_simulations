#include <stdlib.h>
#include "matrix_lib.h"

matrix_objekt hintergrund = {zeichen_FULL,farbe_schwarz,matrix_breite,matrix_hohe,1,1,0,0};
matrix_objekt wand_oben = {"11111111111111111111111111111111111111111111111111111111111111111111111111111111",farbe_weis,80,1,1,1,0,0};
matrix_objekt wand_unten = {"11111111111111111111111111111111111111111111111111111111111111111111111111111111",farbe_weis,80,1,1,22,0,0};
matrix_objekt wand_links = {"1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1",farbe_weis,1,22,1,1,0,0};
matrix_objekt wand_rechts = {"1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1",farbe_weis,1,22,80,1,0,0};

matrix_objekt little_wall_1_left = {"1n1n1n1n1n1n1",farbe_weis,1,7,68,15,0,0};
matrix_objekt little_wall_1_right = {"1n1n1n1n1n1n1",farbe_weis,1,7,69,15,0,0};
matrix_objekt little_wall_1_gate = {"1111111111",farbe_rot,10,1,70,15,0,0};

void config_x_y(matrix_objekt* objekt){
  if(colision(objekt,&little_wall_1_gate))
  {
    objekt->bewegungsrichtung_y = 1;
  }
  if(colision(objekt,&little_wall_1_left) && colision(objekt,&little_wall_1_right))
  {
    objekt->bewegungsrichtung_y = -1;
  }
  else if(colision(objekt,&little_wall_1_left))
  {
    objekt->bewegungsrichtung_x = -1;
  }
  else if(colision(objekt,&little_wall_1_right))
  {
    objekt->bewegungsrichtung_x = 1;
  }
  
  if(colision(objekt,&wand_rechts))
  {
    objekt->bewegungsrichtung_x = -1;
  }
  else if(colision(objekt,&wand_links))
  {
    objekt->bewegungsrichtung_x = 1;
  }
  if(colision(objekt,&wand_oben))
  {
    objekt->bewegungsrichtung_y = 1;
  }
  else if(colision(objekt,&wand_unten))
  {
    objekt->bewegungsrichtung_y = -1;
  }
}
#define reg_objekt(objekt) config_x_y(&objekt);objekt.position_x += objekt.bewegungsrichtung_x;objekt.position_y += objekt.bewegungsrichtung_y;schreibe_objekt(objekt);

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
  while(1)
  {
    schreibe_objekt(hintergrund);
    
    schreibe_objekt(wand_oben);
    schreibe_objekt(wand_unten);
    schreibe_objekt(wand_links);
    schreibe_objekt(wand_rechts);
    
    schreibe_objekt(little_wall_1_left);
    schreibe_objekt(little_wall_1_right);
    schreibe_objekt(little_wall_1_gate);
        
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