#include <stdlib.h>
#include "matrix_lib.h"

matrix_objekt hintergrund = {zeichen_FULL,farbe_schwarz,matrix_breite,matrix_hohe,1,1,0,0};
matrix_objekt wand_oben = {"11111111111111111111111111111111111111111111111111111111111111111111111111111111",farbe_weis,80,1,1,1,0,0};
matrix_objekt wand_unten = {"11111111111111111111111111111111111111111111111111111111111111111111111111111111",farbe_weis,80,1,1,22,0,0};
matrix_objekt wand_links = {"1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1",farbe_weis,1,22,1,1,0,0};
matrix_objekt wand_rechts = {"1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1n1",farbe_weis,1,22,80,1,0,0};

void config_x_y(matrix_objekt* objekt){
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
void throw_back_one(matrix_objekt* objekt_1,matrix_objekt* objekt_2){
  if(colision(objekt_1,objekt_2))
  {
    if(objekt_1->position_x < objekt_2->position_x)
    {
      objekt_1->bewegungsrichtung_x = -1;
    }
    else if(objekt_1->position_x > objekt_2->position_x)
    {
      objekt_1->bewegungsrichtung_x = 1;
    }
    if(objekt_1->position_y < objekt_2->position_y)
    {
      objekt_1->bewegungsrichtung_y = -1;
    }
    else if(objekt_1->position_y > objekt_2->position_y)
    {
      objekt_1->bewegungsrichtung_y = 1;
    }
  }
}
void reg_mover(matrix_objekt* mover){
  if(mover->position_x == 3 && mover->position_y == 3)
  {
    mover->bewegungsrichtung_x = 1;
    mover->bewegungsrichtung_y = 0;
  }
  else if(mover->position_x == 73 && mover->position_y == 3)
  {
    mover->bewegungsrichtung_x = 0;
    mover->bewegungsrichtung_y = 1;
  }
  else if(mover->position_x == 73 && mover->position_y == 19)
  {
    mover->bewegungsrichtung_x = -1;
    mover->bewegungsrichtung_y = 0;
  }
  else if(mover->position_x == 3 && mover->position_y == 19)
  {
    mover->bewegungsrichtung_x = 0;
    mover->bewegungsrichtung_y = -1;
  }
}
#define reg_objekt(objekt) config_x_y(&objekt);objekt.position_x += objekt.bewegungsrichtung_x;objekt.position_y += objekt.bewegungsrichtung_y;schreibe_objekt(objekt);

int main()
{
  matrix_objekt ball_1 = {"1111n1111",farbe_blau,4,2,(rand() % 75) + 2,(rand() % 17) + 2,1,-1};
  matrix_objekt ball_2 = {ball_1.code,farbe_blau,ball_1.breite,ball_1.hohe,(rand() % 75) + 2,(rand() % 17) + 2,-1,1};
  matrix_objekt ball_3 = {ball_1.code,farbe_blau,ball_1.breite,ball_1.hohe,(rand() % 75) + 2,(rand() % 17) + 2,-1,1};
  matrix_objekt ball_4 = {ball_1.code,farbe_blau,ball_1.breite,ball_1.hohe,(rand() % 75) + 2,(rand() % 17) + 2,1,1};
  
  matrix_objekt mover_1 = {"111111n111111",farbe_grun,6,2,3,3,0,1};
  matrix_objekt mover_2 = {"111111n111111",farbe_grun,6,2,73,19,0,1};
  while(1)
  {
    schreibe_objekt(hintergrund);
    
    schreibe_objekt(wand_oben);
    schreibe_objekt(wand_unten);
    schreibe_objekt(wand_links);
    schreibe_objekt(wand_rechts);
    
    throw_back(&ball_1,&ball_2);
    throw_back(&ball_1,&ball_3);
    throw_back(&ball_1,&ball_4);
    throw_back_one(&ball_1,&mover_1);
    throw_back_one(&ball_1,&mover_2);
    
    throw_back(&ball_2,&ball_3);
    throw_back(&ball_2,&ball_4);
    throw_back_one(&ball_2,&mover_1);
    throw_back_one(&ball_2,&mover_2);
    
    throw_back(&ball_3,&ball_4);
    throw_back_one(&ball_3,&mover_1);
    throw_back_one(&ball_3,&mover_2);
    
    throw_back_one(&ball_4,&mover_1);
    throw_back_one(&ball_4,&mover_2);
    
    reg_objekt(ball_1);
    reg_objekt(ball_2);
    reg_objekt(ball_3);
    reg_objekt(ball_4);
    
    reg_mover(&mover_1);
    reg_objekt(mover_1);
    reg_mover(&mover_2);
    reg_objekt(mover_2);
    
    gebeaus();
    Sleep(50);
  }
  return 0;
}