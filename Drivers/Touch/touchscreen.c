/*
 * touchscreen.c
 *
 *  Created on: Jan 14, 2013
 *      Author: MMM
 */


#include "../Touch/touchscreen.h"
#include<stdlib.h>

/* Private variables ---------------------------------------------------------*/

///Tabella costanti presa dalla calibrazione
int32_t A2 = -98077;
int32_t B2 = -1196;
int32_t C2 = 372934944;
int32_t D2 = -1025;
int32_t E2 = 65418;
int32_t F2 = -11187455;
uint32_t TSC_Value_X;
uint32_t TSC_Value_Y;

/**
  * @brief  Calibrate TouchScreen coordinates by LCD touch in 5 points
  * @param  None
  * @retval None
  */
void TS_Calibration(void)
{
  char StringBuffer[20];
  uint32_t coordinate_X1a = 0, coordinate_X2a = 0, coordinate_X3a = 0, coordinate_X4a = 0, coordinate_X5a = 0;
  uint32_t coordinate_Y1a = 0, coordinate_Y2a = 0, coordinate_Y3a = 0, coordinate_Y4a = 0, coordinate_Y5a = 0;
  uint32_t coordinate_X1b = 0, coordinate_X2b = 0, coordinate_X3b = 0, coordinate_X4b = 0, coordinate_X5b = 0;
  uint32_t coordinate_Y1b = 0, coordinate_Y2b = 0, coordinate_Y3b = 0, coordinate_Y4b = 0, coordinate_Y5b = 0;
  uint32_t coordinate_X1 = 0, coordinate_X2 = 0, coordinate_X3 = 0, coordinate_X4 = 0, coordinate_X5 = 0;
  uint32_t coordinate_Y1 = 0, coordinate_Y2 = 0, coordinate_Y3 = 0, coordinate_Y4 = 0, coordinate_Y5 = 0;
  uint16_t Xd1 = (LCD_Width2 / 2), Xd2 = 1 * (LCD_Width2 / 5), Xd3 = 4 * (LCD_Width2 / 5), Xd4 = 4 * (LCD_Width2 / 5), Xd5 = 1 * (LCD_Width2 / 5);
  uint16_t Yd1 = (LCD_Height2 / 2), Yd2 = 1 * (LCD_Height2 / 5), Yd3 = 1 * (LCD_Height2 / 5), Yd4 = 4 * (LCD_Height2 / 5), Yd5 = 4 * (LCD_Height2 / 5);
  float A = 0.0, B = 0.0, C = 0.0, D = 0.0, E = 0.0, F = 0.0;
  float d = 0.0, dx1 = 0.0, dx2 = 0.0, dx3 = 0.0, dy1 = 0.0, dy2 = 0.0, dy3 = 0.0;
  uint32_t X2_1 = 0, X2_2 = 0, X2_3 = 0, X2_4 = 0, X2_5 = 0;
  uint32_t Y2_1 = 0, Y2_2 = 0, Y2_3 = 0, Y2_4 = 0, Y2_5 = 0;
  uint32_t XxY_1 = 0, XxY_2 = 0, XxY_3 = 0, XxY_4 = 0, XxY_5 = 0;
  uint32_t XxXd_1 = 0, XxXd_2 = 0, XxXd_3 = 0, XxXd_4 = 0, XxXd_5 = 0;
  uint32_t YxXd_1 = 0, YxXd_2 = 0, YxXd_3 = 0, YxXd_4 = 0, YxXd_5 = 0;
  uint32_t XxYd_1 = 0, XxYd_2 = 0, XxYd_3 = 0, XxYd_4 = 0, XxYd_5 = 0;
  uint32_t YxYd_1 = 0, YxYd_2 = 0, YxYd_3 = 0, YxYd_4 = 0, YxYd_5 = 0;
  uint32_t alfa = 0, beta = 0, chi = 0, Kx = 0, Ky = 0, Lx = 0, Ly = 0;
  uint16_t epsilon = 0, fi = 0, Mx = 0, My = 0;

  
  LCD_CLS(WHITE);
  sprintf(StringBuffer,"Touch Screen Calibrator");
  LCD_Text57Land(230,30,StringBuffer,2,BLACK,NONE);
	

  LCD_Cercle((LCD_Height / 2), (LCD_Width / 2) , 4, 1, RED);
  /* Absolute Central Point */
  while(PORTDbits.RD14==1) {} //wait for touch
  //read touch values
  Touch_getAvarage();
  coordinate_X1a = TSC_Value_X;
  coordinate_Y1a = TSC_Value_Y;
  coordinate_X1b = TSC_Value_X;
  coordinate_Y1b = TSC_Value_Y;
  markPoint((LCD_Height / 2), (LCD_Width / 2));
  while(PORTDbits.RD14==0) {}// wait until touch is released
  DelayMs(90); /* This is to catch only one touch event */


  LCD_Cercle(1*(LCD_Height / 5), 1*(LCD_Width / 5) , 4, 1, RED);
  while(PORTDbits.RD14==1) {} //wait for touch
  Touch_getAvarage();
  coordinate_X2a = TSC_Value_X;
  coordinate_Y2a = TSC_Value_Y;
  coordinate_X2b = TSC_Value_X;
  coordinate_Y2b = TSC_Value_Y;
  markPoint(1*(LCD_Height / 5), 1*(LCD_Width / 5));
  while(PORTDbits.RD14==0) {}// wait until touch is released
  DelayMs(90); /* This is to catch only one touch event */

  
  LCD_Cercle(1*(LCD_Height / 5), 4*(LCD_Width / 5) , 4, 1, RED);
  while(PORTDbits.RD14==1) {} //wait for touch
  Touch_getAvarage();
  coordinate_X3a = TSC_Value_X;
  coordinate_Y3a = TSC_Value_Y;
  coordinate_X3b = TSC_Value_X;
  coordinate_Y3b = TSC_Value_Y;
  markPoint(1*(LCD_Height / 5), 4*(LCD_Width / 5));
  while(PORTDbits.RD14==0) {}// wait until touch is released
  DelayMs(90); /* This is to catch only one touch event */


  LCD_Cercle(4*(LCD_Height / 5), 4*(LCD_Width / 5) , 4, 1, RED);
  while(PORTDbits.RD14==1) {} //wait for touch
  Touch_getAvarage();
  coordinate_X4a = TSC_Value_X;
  coordinate_Y4a = TSC_Value_Y;
  coordinate_X4b = TSC_Value_X;
  coordinate_Y4b = TSC_Value_Y;
  markPoint(4*(LCD_Height / 5), 4*(LCD_Width / 5));
  while(PORTDbits.RD14==0) {}// wait until touch is released
  DelayMs(90); /* This is to catch only one touch event */


  LCD_Cercle(4*(LCD_Height / 5), 1*(LCD_Width / 5) , 4, 1, RED);
  while(PORTDbits.RD14==1) {} //wait for touch
  Touch_getAvarage();
  coordinate_X5a = TSC_Value_X;
  coordinate_Y5a = TSC_Value_Y;
  coordinate_X5b = TSC_Value_X;
  coordinate_Y5b = TSC_Value_Y;
  markPoint(4*(LCD_Height / 5), 1*(LCD_Width / 5));
  while(PORTDbits.RD14==0) {}// wait until touch is released
  DelayMs(90); /* This is to catch only one touch event */

  /* Average between X and Y coupled Touchscreen values */
  coordinate_X1 = (coordinate_X1a + coordinate_X1b) / 2;
  coordinate_X2 = (coordinate_X2a + coordinate_X2b) / 2;
  coordinate_X3 = (coordinate_X3a + coordinate_X3b) / 2;
  coordinate_X4 = (coordinate_X4a + coordinate_X4b) / 2;
  coordinate_X5 = (coordinate_X5a + coordinate_X5b) / 2;

  coordinate_Y1 = (coordinate_Y1a + coordinate_Y1b) / 2;
  coordinate_Y2 = (coordinate_Y2a + coordinate_Y2b) / 2;
  coordinate_Y3 = (coordinate_Y3a + coordinate_Y3b) / 2;
  coordinate_Y4 = (coordinate_Y4a + coordinate_Y4b) / 2;
  coordinate_Y5 = (coordinate_Y5a + coordinate_Y5b) / 2;

  X2_1 = (coordinate_X1 * coordinate_X1);
  X2_2 = (coordinate_X2 * coordinate_X2);
  X2_3 = (coordinate_X3 * coordinate_X3);
  X2_4 = (coordinate_X4 * coordinate_X4);
  X2_5 = (coordinate_X5 * coordinate_X5);

  Y2_1 = (coordinate_Y1 * coordinate_Y1);
  Y2_2 = (coordinate_Y2 * coordinate_Y2);
  Y2_3 = (coordinate_Y3 * coordinate_Y3);
  Y2_4 = (coordinate_Y4 * coordinate_Y4);
  Y2_5 = (coordinate_Y5 * coordinate_Y5);

  XxY_1 = (coordinate_X1 * coordinate_Y1);
  XxY_2 = (coordinate_X2 * coordinate_Y2);
  XxY_3 = (coordinate_X3 * coordinate_Y3);
  XxY_4 = (coordinate_X4 * coordinate_Y4);
  XxY_5 = (coordinate_X5 * coordinate_Y5);

  XxXd_1 = ( coordinate_X1 * Xd1 );
  XxXd_2 = ( coordinate_X2 * Xd2 );
  XxXd_3 = ( coordinate_X3 * Xd3 );
  XxXd_4 = ( coordinate_X4 * Xd4 );
  XxXd_5 = ( coordinate_X5 * Xd5 );

  YxXd_1 = ( coordinate_Y1 * Xd1 );
  YxXd_2 = ( coordinate_Y2 * Xd2 );
  YxXd_3 = ( coordinate_Y3 * Xd3 );
  YxXd_4 = ( coordinate_Y4 * Xd4 );
  YxXd_5 = ( coordinate_Y5 * Xd5 );

  XxYd_1 = ( coordinate_X1 * Yd1 );
  XxYd_2 = ( coordinate_X2 * Yd2 );
  XxYd_3 = ( coordinate_X3 * Yd3 );
  XxYd_4 = ( coordinate_X4 * Yd4 );
  XxYd_5 = ( coordinate_X5 * Yd5 );

  YxYd_1 = ( coordinate_Y1 * Yd1 );
  YxYd_2 = ( coordinate_Y2 * Yd2 );
  YxYd_3 = ( coordinate_Y3 * Yd3 );
  YxYd_4 = ( coordinate_Y4 * Yd4 );
  YxYd_5 = ( coordinate_Y5 * Yd5 );

  alfa = X2_1 + X2_2 + X2_3 + X2_4 + X2_5;
  beta = Y2_1 + Y2_2 + Y2_3 + Y2_4 + Y2_5;
  chi = XxY_1 + XxY_2 + XxY_3 + XxY_4 + XxY_5;
  epsilon = coordinate_X1 + coordinate_X2 + coordinate_X3 + coordinate_X4 + coordinate_X5;
  fi = coordinate_Y1 + coordinate_Y2 + coordinate_Y3 + coordinate_Y4 + coordinate_Y5;
  Kx = XxXd_1 + XxXd_2 + XxXd_3 + XxXd_4 + XxXd_5;
  Ky = XxYd_1 + XxYd_2 + XxYd_3 + XxYd_4 + XxYd_5;
  Lx = YxXd_1 + YxXd_2 + YxXd_3 + YxXd_4 + YxXd_5;
  Ly = YxYd_1 + YxYd_2 + YxYd_3 + YxYd_4 + YxYd_5;
  Mx = Xd1 + Xd2 + Xd3 + Xd4 + Xd5;
  My = Yd1 + Yd2 + Yd3 + Yd4 + Yd5;

  d = 5 * ( ((double)alfa * beta) - ((double)chi * chi) ) + 2 * ((double)chi * epsilon * fi) - ((double)alfa * fi * fi ) - ( (double)beta * epsilon * epsilon );
  dx1 = 5 * ( ((double)Kx * beta) - ((double)Lx * chi) ) + ((double)fi * ( ((double)Lx * epsilon) - ((double)Kx * fi) )) + ((double)Mx * ( ((double)chi * fi) - ((double)beta * epsilon) ));
  dx2 = 5 * ( ((double)Lx * alfa) - ((double)Kx * chi) ) + ((double)epsilon * ( ((double)Kx * fi) - ((double)Lx * epsilon) )) + ((double)Mx * ( ((double)chi * epsilon) - ((double)alfa * fi) ));
  dx3 = ((double)Kx * ( ((double)chi * fi) - ((double)beta * epsilon) )) + ((double)Lx * ( ((double)chi * epsilon) - ((double)alfa * fi) )) + ((double)Mx * ( ((double)alfa * beta) - ((double)chi * chi) ));
  dy1 = 5 * ( ((double)Ky * beta) - ((double)Ly * chi) ) + ((double)fi * ( ((double)Ly * epsilon) - ((double)Ky * fi) )) + ((double)My * ( ((double)chi * fi) - ((double)beta * epsilon) ));
  dy2 = 5 * ( ((double)Ly * alfa) - ((double)Ky * chi) ) + ((double)epsilon * ( ((double)Ky * fi) - ((double)Ly * epsilon) )) + ((double)My * ( ((double)chi * epsilon) - ((double)alfa * fi) ));
  dy3 = ((double)Ky * ( ((double)chi * fi) - ((double)beta * epsilon) )) + ((double)Ly * ( ((double)chi * epsilon) - ((double)alfa * fi) )) + ((double)My * ( ((double)alfa * beta) - ((double)chi * chi) ));

  A = dx1 / d;
  B = dx2 / d;
  C = dx3 / d;
  D = dy1 / d;
  E = dy2 / d;
  F = dy3 / d;

  /* To avoid computation with "double" variables A, B, C, D, E, F, we use the s32 variables
     A2, B2, C2, D2, E2, F2, multiplied for a Scale Factor equal to 100000 to retain the precision*/
  A2 = (int32_t)(A * RESCALE_FACTOR);
  B2 = (int32_t)(B * RESCALE_FACTOR);
  C2 = (int32_t)(C * RESCALE_FACTOR);
  D2 = (int32_t)(D * RESCALE_FACTOR);
  E2 = (int32_t)(E * RESCALE_FACTOR);
  F2 = (int32_t)(F * RESCALE_FACTOR);

  //printCalibrationValues();
  
  sprintf(StringBuffer,"Calibration completed. Tap to exit!");
  LCD_Text57Land(30,40,StringBuffer,1,BLACK,WHITE);
  while(PORTDbits.RD14==1){}
}

/**
  * @brief  Returns the Display y-axis Coordinate corresponding to Touch y-axis coordinate.
  *         X and Y are inverted because the display is meant in Landscape
  * @param  x_touch: X coordinate of the Touch Panel
  * @param  y_touch: Y coordinate of the Touch Panel
  * @retval uint16_t - Xd: Coordinate X of the LCD Panel (X-axis Coordinate)
  */
uint16_t getDisplayCoordinateX(uint16_t x_touch, uint16_t y_touch)
{
  uint16_t Xd;
  double temp;
  temp = (A2 * x_touch + B2 * y_touch + C2) / RESCALE_FACTOR;
  Xd = (uint16_t)(temp);
  if (Xd > 60000)
  {
    /* this to avoid negative value */
   Xd = 0;
  }
  return Xd;
}

/**
  * @brief  Returns the Display x-axis Coordinate corresponding to Touch x-axis coordinate.
  *         X and Y are inverted because the display is meant in Landscape
  * @param  x_touch: X coordinate of the Touch Panel
  * @param  y_touch: Y coordinate of the Touch Panel
  * @retval uint16_t - Yd: Coordinate X of the LCD Panel (Y-axis Coordinate)
  */
uint16_t getDisplayCoordinateY(uint16_t x_touch, uint16_t y_touch)
{
  uint16_t Yd;
  double temp;
  temp = (D2 * x_touch + E2 * y_touch + F2) / RESCALE_FACTOR;
  Yd = (uint16_t)(temp);
  if (Yd > 60000)
  {
    /*  this to avoid negative value */
    Yd = 0;
  }
  return Yd;
}



void markPoint(uint16_t x, uint16_t y)
{
  // mark complete point

  LCD_Cercle(x, y,3, 1, BLUE);
  DelayMs(100);
  LCD_Cercle(x, y,2, 1, RED);
  DelayMs(100);
  LCD_Cercle(x, y,0, 1, BLACK);

}


void Touch_getAvarage(void)
{
  uint8_t count;
uint32_t xAvg;
uint32_t yAvg;
  TP_GetMedianAdXY(&xAvg, &yAvg);
  count = 0;
  while((PORTDbits.RD14==0) && count <= 5)
    {
      TP_GetMedianAdXY(&xAvg, &yAvg);
      TSC_Value_X += xAvg;
      TSC_Value_X >>= 1;
      TSC_Value_Y += yAvg;
      TSC_Value_Y >>= 1;
      DelayUs(100);
      count++;
    }
}


void printCalibrationValues(void)
{
char buffer[40];
sprintf(buffer, "A2 = %d", (int)A2);
LCD_Text57Land(90,10,buffer,1,BLACK,WHITE);
sprintf(buffer, "B2 = %d", (int)B2);
LCD_Text57Land(80,10,buffer,1,BLACK,WHITE);
sprintf(buffer, "C2 = %d", (int)C2);
LCD_Text57Land(70,10,buffer,1,BLACK,WHITE);
sprintf(buffer, "D2 = %d", (int)D2);
LCD_Text57Land(60,10,buffer,1,BLACK,WHITE);
sprintf(buffer, "E2 = %d", (int)E2);
LCD_Text57Land(50,10,buffer,1,BLACK,WHITE);
sprintf(buffer, "F2 = %d", (int)F2);
LCD_Text57Land(40,10,buffer,1,BLACK,WHITE);
}

