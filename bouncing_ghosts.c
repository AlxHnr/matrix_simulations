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
void throw_back(matrix_objekt* objekt_1,matrix_objekt* objekt_2){
  if(colision(objekt_1,objekt_2))
  {
    if(objekt_1->position_x < objekt_2->position_x)
    {
      objekt_1->bewegungsrichtung_x = -1;
      objekt_2->bewegungsrichtung_x = 1;
    }
    else if(objekt_1->position_x > objekt_2->position_x)
    {
      objekt_1->bewegungsrichtung_x = 1;
      objekt_2->bewegungsrichtung_x = -1;
    }
    if(objekt_1->position_y < objekt_2->position_y)
    {
      objekt_1->bewegungsrichtung_y = -1;
      objekt_2->bewegungsrichtung_y = 1;
    }
    else if(objekt_1->position_y > objekt_2->position_y)
    {
      objekt_1->bewegungsrichtung_y = 1;
      objekt_2->bewegungsrichtung_y = -1;
    }
  }
}
#define reg_objekt(objekt_1,objekt_2) config_x_y(&objekt_1);objekt_1.position_x += objekt_1.bewegungsrichtung_x;objekt_1.position_y += objekt_1.bewegungsrichtung_y;objekt_2.position_x = objekt_1.position_x;objekt_2.position_y = objekt_1.position_y;objekt_2.bewegungsrichtung_x = objekt_1.bewegungsrichtung_x;objekt_2.bewegungsrichtung_y = objekt_1.bewegungsrichtung_y;schreibe_objekt(objekt_1);schreibe_objekt(objekt_2);

int main()
{
  matrix_objekt bug = {"0111n10101n11111n10101",farbe_blau,5,4,20,4,1,-1};
  matrix_objekt bug_eye = {"n0101",farbe_grun,bug.breite,bug.hohe,bug.position_x,bug.position_y,bug.bewegungsrichtung_x,bug.bewegungsrichtung_y};
  
  matrix_objekt bug_2 = {"0111n10101n11111n10101",farbe_turkis,5,4,70,3,-1,-1};
  matrix_objekt bug_2_eye = {"n0101",farbe_rot,bug_2.breite,bug_2.hohe,bug_2.position_x,bug_2.position_y,bug_2.bewegungsrichtung_x,bug_2.bewegungsrichtung_y};
  
  matrix_objekt bug_3 = {"0111n10101n11111n10101",farbe_rot,5,4,10,16,-1,1};
  matrix_objekt bug_3_eye = {"n0101",farbe_gelb,bug_3.breite,bug_3.hohe,bug_3.position_x,bug_3.position_y,bug_3.bewegungsrichtung_x,bug_3.bewegungsrichtung_y};
  
  matrix_objekt bug_4 = {"0111n10101n11111n10101",farbe_grun,5,4,14,17,1,1};
  matrix_objekt bug_4_eye = {"n0101",farbe_lila,bug_4.breite,bug_4.hohe,bug_4.position_x,bug_4.position_y,bug_4.bewegungsrichtung_x,bug_4.bewegungsrichtung_y};
  
  matrix_objekt bug_5 = {"0111n10101n11111n10101",farbe_weis,5,4,64,8,1,1};
  matrix_objekt bug_5_eye = {"n0101",farbe_blau,bug_5.breite,bug_5.hohe,bug_5.position_x,bug_5.position_y,bug_5.bewegungsrichtung_x,bug_5.bewegungsrichtung_y};
  
  matrix_objekt bug_6 = {"0111n10101n11111n10101",farbe_gelb,5,4,39,15,1,1};
  matrix_objekt bug_6_eye = {"n0101",farbe_rot,bug_6.breite,bug_6.hohe,bug_6.position_x,bug_6.position_y,bug_6.bewegungsrichtung_x,bug_6.bewegungsrichtung_y};
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
    
    throw_back(&bug,&bug_2);
    throw_back(&bug,&bug_3);
    throw_back(&bug,&bug_4);
    throw_back(&bug,&bug_5);
    throw_back(&bug,&bug_6);
    
    throw_back(&bug_2,&bug_3);
    throw_back(&bug_2,&bug_4);
    throw_back(&bug_2,&bug_5);
    throw_back(&bug_2,&bug_6);
    
    throw_back(&bug_3,&bug_4);
    throw_back(&bug_3,&bug_5);
    throw_back(&bug_3,&bug_6);
    
    throw_back(&bug_4,&bug_5);
    throw_back(&bug_4,&bug_6);
    
    throw_back(&bug_5,&bug_6);
    
    reg_objekt(bug,bug_eye);
    reg_objekt(bug_2,bug_2_eye);
    reg_objekt(bug_3,bug_3_eye);
    reg_objekt(bug_4,bug_4_eye);
    reg_objekt(bug_5,bug_5_eye);
    reg_objekt(bug_6,bug_6_eye);
    
    gebeaus();
    Sleep(50);
  }
  return 0;
}