/*
 * touchscreen.h
 *
 *  Created on: Jan 14, 2013
 *      Author: MMM
 */

#include"../Touch/ads7843drv.h"
#define RESCALE_FACTOR 1000000
typedef struct Point
{
        int x;
        int y;
} POINT;

typedef struct Matrix
{
        long An;
        long Bn;
        long Cn;
        long Dn;
        long En;
        long Fn;
        long Divider;
} MATRIX;

POINT screenPoint;              // touch screen point
POINT displayPoint;             // display(LCD) view point
MATRIX matrix;


int xAvg, yAvg;
int xRealpos, yRealpos;
int TouchScreenIScalibrated;
void TS_Calibration(void);
uint16_t getDisplayCoordinateX(uint16_t x_touch, uint16_t y_touch);
uint16_t getDisplayCoordinateY(uint16_t x_touch, uint16_t y_touch);
void Touch_getAvarage(void);
void markPoint(uint16_t x, uint16_t y);
void printCalibrationValues(void);
