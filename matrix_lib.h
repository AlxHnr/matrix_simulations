#ifndef MATRIX_LIB
#define MATRIX_LIB
  #include <stdio.h>
  #include <string.h>
  #include <unistd.h>
  #define Sleep(TIME) usleep(TIME * 1000)

  #ifndef matrix_breite
    #define matrix_breite 80
    #define matrix_hohe 22
    #define matrix_pixel 1862
  #endif

  /*Hier Befindet sich eine Codesammlung für codes, die der "Binaerfunktion" eine Anweisung geben, zeichen in die Matrix zu schreiben*/
  /*Auf diese Codes kann von ueberall zugegriffen werden*/
  /*Grose Buchstaben*/
  #define zeichen_A "11111n10001n11111n10001n10001"
  #define zeichen_B "1111n10001n1111n10001n1111"
  #define zeichen_C "0111n10001n1n10001n0111"
  #define zeichen_D "1111n10001n10001n10001n1111"
  #define zeichen_E "11111n1n11111n1n11111"
  #define zeichen_F "11111n1n11111n1n1"
  #define zeichen_G "01111n1n10011n10001n01111"
  #define zeichen_H "10001n10001n11111n10001n10001"
  #define zeichen_I "11111n001n001n001n11111"
  #define zeichen_J "01111n00001n00001n10001n0111"
  #define zeichen_K "10001n1001n111n1001n10001"
  #define zeichen_L "1n1n1n1n11111"
  #define zeichen_M "10001n11011n10101n10001n10001"
  #define zeichen_N "10001n11001n10101n10011n10001"
  #define zeichen_O "0111n10001n10001n10001n0111"
  #define zeichen_P "1111n10001n1111n1n1"
  #define zeichen_Q "0111n10001n10001n1001n01101"
  #define zeichen_R "1111n10001n1111n10001n10001"
  #define zeichen_S "01111n1n0111n00001n1111"
  #define zeichen_T "11111n001n001n001n001"
  #define zeichen_U "10001n10001n10001n10001n0111"
  #define zeichen_V "10001n10001n10001n0101n001"
  #define zeichen_W "10001n10001n10101n11011n10001"
  #define zeichen_X "10001n0101n001n0101n10001"
  #define zeichen_Y "10001n10001n0101n001n001"
  #define zeichen_Z "11111n0001n001n01n11111"
  /*Kleine Buchstaben*/
  #define zeichen_a "nn01111n10001n01111"
  #define zeichen_b "1n1n1111n10001n1111"
  #define zeichen_c "nn0111n1n0111"
  #define zeichen_d "00001n00001n01111n10001n01111"
  #define zeichen_e "0111n10001n11111n1n0111"
  #define zeichen_f "0011n01n111n01n01"
  #define zeichen_g "0111n10001n01111n00001n0111"
  #define zeichen_h "1n1n1111n10001n10001"
  #define zeichen_i "001nn001n001n001"
  #define zeichen_j "001nn001n101n11"
  #define zeichen_k "1n1n101n11n101"
  #define zeichen_l "1n1n1n1n0111"
  #define zeichen_m "nn11011n10101n10001"
  #define zeichen_n "nn1111n10001n10001"
  #define zeichen_o "nn0111n10001n0111"
  #define zeichen_p "n0111n10001n1111n1"
  #define zeichen_q "n0111n10001n01111n00001"
  #define zeichen_r "n1011n11001n1n1"
  #define zeichen_s "n011n1n001n11"
  #define zeichen_t "01n111n01n0101n001"
  #define zeichen_u "nn10001n10001n0111"
  #define zeichen_v "nn10001n0101n001"
  #define zeichen_w "nn10101n11011n10001"
  #define zeichen_x "nn101n01n101"
  #define zeichen_y "nn101n01n1"
  #define zeichen_z "n1111n001n01n1111"
  /*Zahlen*/
  #define zeichen_0 "0111n10011n10101n11001n0111"
  #define zeichen_1 "00011n00101n00001n00001n00001"
  #define zeichen_2 "0111n10001n0011n01n11111"
  #define zeichen_3 "0111n10001n0011n10001n0111"
  #define zeichen_4 "0011n0101n1001n11111n0001"
  #define zeichen_5 "11111n1n1111n00001n1111"
  #define zeichen_6 "01111n1n1111n10001n0111"
  #define zeichen_7 "11111n0001n001n01n1"
  #define zeichen_8 "0111n10001n0111n10001n0111"
  #define zeichen_9 "0111n10001n01111n00001n0111"
  /*Sonderzeichen*/
  #define zeichen_SPACE ""
  #define zeichen_ausrufezeichen "001n001n001nn001"
  #define zeichen_anfuehrungszeichen "0101"
  #define zeichen_raute "0101n11111n0101n11111n0101n"
  #define zeichen_peso "01111n101n0111n00101n1111"
  #define zeichen_prozent "00001n1001n001n01001n1"
  #define zeichen_und "0111n1n01101n1001n01101"
  #define zeichen_anfuehrungsstrich "001"
  #define zeichen_klammerauf "0011n11n11n11n0011"
  #define zeichen_klammerzu "11n0011n0011n0011n11"
  #define zeichen_sternchen "n10101n0111n10101"
  #define zeichen_plus "n001n11111n001"
  #define zeichen_minus "nn11111"
  #define zeichen_komma "nnn011n001"
  #define zeichen_punkt "nnnn011"
  #define zeichen_slash "00001n0001n001n01n1"
  #define zeichen_doppelpunkt "n011nn011"
  #define zeichen_semikolon "n011nn011n001"
  #define zeichen_kleiner "00011n011n1n011n00011"
  #define zeichen_gleich "n11111nn11111"
  #define zeichen_groser "11n0011n00001n0011n11"
  #define zeichen_frage "0111n10001n0001nn0001"
  #define zeichen_FULL "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
  /*Farben*/
  #define farbe_schwarz 40
  #define farbe_rot 41
  #define farbe_grun 42
  #define farbe_gelb 43
  #define farbe_blau 44
  #define farbe_lila 45
  #define farbe_turkis 46
  #define farbe_weis 47

  void matrix(unsigned short spalte,unsigned short zeile,unsigned char farbe);
  void gebeaus();

  void binaer(char* bigbuchstabe,unsigned char stelle,unsigned char spalte,unsigned char farbe);
  void satz(char* buchstabe,unsigned char stelle,unsigned char spalte,unsigned char farbe);

  /*Hier Befindet sich der Datentyp, der alle Informationen über das Objekt bereitstellt*/
  typedef struct{
    char *code;
    unsigned char farbe;
    unsigned char breite;
    unsigned char hohe;
    unsigned char position_x;
    unsigned char position_y;
    char bewegungsrichtung_x;
    char bewegungsrichtung_y;
  }matrix_objekt;
  /*Diese funktion kehrt die Farben in einem matrix_objekt um. die funktion wird mit "farbe_umkehren(&objektname);" aufgerufen*/
  void farbe_umkehren(matrix_objekt* zeiger);
  #define schreibe_objekt(objekt) binaer(objekt.code,objekt.position_x,objekt.position_y,objekt.farbe)
  
  int colision(matrix_objekt* objekt_1,matrix_objekt* objekt_2);
#endif