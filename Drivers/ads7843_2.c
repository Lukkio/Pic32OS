/*
  UTouch.cpp - Arduino/chipKit library support for Color TFT LCD Touch screens 
  Copyright (C)2010-2013 Henning Karlsen. All right reserved
  
  Basic functionality of this library are based on the demo-code provided by
  ITead studio. You can find the latest version of the library at
  http://www.henningkarlsen.com/electronics

  If you make any modifications or improvements to the code, I would appreciate
  that you share the code with me so that I might include it in the next release.
  I can be contacted through http://www.henningkarlsen.com/electronics/contact.php

  This library is free software; you can redistribute it and/or
  modify it under the terms of the CC BY-NC-SA 3.0 license.
  Please see the included documents for further information.
*/
#include<stdint.h>
#define CAL_X 0x00378F66
#define CAL_Y 0x03C34155
#define CAL_S 0x000EF13F

#define PORTRAIT			0
#define LANDSCAPE			1

#define PREC_LOW			1
#define PREC_MEDIUM			2
#define PREC_HI				3
#define PREC_EXTREME		4
#define PREC_ULTRA 5

//#define T_CLK	 PORTDbits.RD1
//#define T_CS       PORTDbits.RD2
//#define T_DIN      PORTDbits.RD4
//#define T_DOUT     PORTDbits.RD5
//#define T_IRQ      PORTDbits.RD6

#define T_CLK      PORTDbits.RD15
#define T_CS       PORTBbits.RB15
#define T_DIN      PORTFbits.RF8
#define T_DOUT     PORTFbits.RF2
//#define T_IRQ      PORTFbits.RF4
#define T_IRQ      PORTDbits.RD14

signed short int	TP_X ,TP_Y;
signed int TP_X_REAL, TP_Y_REAL;
		//char	T_CLK, T_CS, T_DIN, T_DOUT, T_IRQ;
		long int	_default_orientation;
		char	orient;
		char	prec;
		char	display_model;
		signed long int	disp_x_size, disp_y_size, default_orientation;
		signed long int	touch_x_left, touch_x_right, touch_y_top, touch_y_bottom;

float _ax, _bx, _dx, _ay, _by, _dy;

void InitTouch(unsigned char orientation);
void touch_WriteData(unsigned char data);
unsigned short int touch_ReadData();
void read();
_Bool dataAvailable();
int getX();
int getY();
void setPrecision(char precision);



//#include "UTouch.h"
//#include "UTouchCD.h"

/*UTouch::UTouch(byte tclk, byte tcs, byte din, byte dout, byte irq)
{
    T_CLK        = tclk;
    T_CS         = tcs;
    T_DIN        = din;
    T_DOUT       = dout;
    T_IRQ        = irq;
}*/

void InitTouch(unsigned char orientation)
{
	orient					= orientation;
	_default_orientation	= CAL_S>>31;//0
	touch_x_left			= (CAL_X>>14) & 0x3FFF;//222
	touch_x_right			= CAL_X & 0x3FFF;

	touch_y_top				= (CAL_Y>>14) & 0x3FFF;
	touch_y_bottom			= CAL_Y & 0x3FFF;

	disp_x_size				= (CAL_S>>12) & 0x0FFF;
	disp_y_size				= CAL_S & 0x0FFF;
	prec					= 10;

	
	//TRISDCLR = 0xffff;
    //PORTDCLR = 0xffff;
        //TRISDbits.TRISD6=1;//IRQ
    //TRISDbits.TRISD5=1;//DOUT
    //TRISDbits.TRISD3=1;//BUTTON

    TRISDbits.TRISD14=1;//IRQ
    TRISFbits.TRISF2=1;//DOUT

	T_CS=1;
	T_CLK=1;
	T_DIN=1;
	T_CLK=1;
	
	/*pinMode(T_CLK,  OUTPUT);
    pinMode(T_CS,   OUTPUT);
    pinMode(T_DIN,  OUTPUT);
    pinMode(T_DOUT, INPUT);
    pinMode(T_IRQ,  OUTPUT);

	digitalWrite(T_CS,  HIGH);
	digitalWrite(T_CLK, HIGH);
	digitalWrite(T_DIN, HIGH);
	digitalWrite(T_CLK, HIGH);*/
	
	
	
}

void touch_WriteData(unsigned char data)
{
	unsigned char temp,count=0;
	unsigned char nop;

	temp=data;
	//digitalWrite(T_CLK,LOW);
	T_CLK=0;
	for(count=0; count<8; count++)
	{
		if(temp & 0x80)
			T_DIN=1;
		else
			T_DIN=0;
		temp = temp << 1; 
		T_CLK=0;                
		nop++;
		T_CLK=1;
		nop++;
	}
}

unsigned short int touch_ReadData()
{
	unsigned char nop,count=0;
	unsigned short int data = 0;
	for(count=0; count<12; count++)
	{
		data <<= 1;
		T_CLK=1;               
		nop++;
		T_CLK=0;
		nop++;
		if (T_DOUT)
			data++;
	}
	return(data);
}

void read()
{
	signed long int tx=0, temp_x=0;
	signed long int ty=0, temp_y=0;
	signed char datacount=0;
        unsigned char i=0;

	T_CS=0;                    

	for (i=0; i<prec; i++)
	{
		touch_WriteData(0x90);        
		T_CLK=1;
		T_CLK=0; 
		temp_x=touch_ReadData();

		touch_WriteData(0xD0);      
		T_CLK=1;
		T_CLK=0;
		temp_y=touch_ReadData();

		if (!((temp_x>max(touch_x_left, touch_x_right)) || (temp_x==0) || (temp_y>max(touch_y_top, touch_y_bottom)) || (temp_y==0)))
		{
			ty+=temp_x;
			tx+=temp_y;
			datacount++;
		}
	}

	T_CS=1;
	if (datacount>0)
	{
		if (orient == _default_orientation)
		{
			TP_X=tx/datacount;
			TP_Y=ty/datacount;
		}
		else
		{
			TP_X=ty/datacount;
			TP_Y=tx/datacount;
		}
	}
	else
	{
		TP_X=-1;
		TP_Y=-1;
	}
        TP_X_REAL=TP_X;
        TP_Y_REAL=TP_Y;
}

_Bool dataAvailable()
{
	_Bool avail;
	TRISDbits.TRISD6=1;
        if(PORTDbits.RD6==0) avail=1;
        else avail=0;
	TRISDbits.TRISD6=0;
	return avail;
}

int getX()
{
	signed long int c;

	if (orient == _default_orientation)
	{
		c = (long int)((TP_X - touch_x_left) * (disp_x_size)) / (long int)(touch_x_right - touch_x_left);
		if (c<0)
			c = 0;
		if (c>disp_x_size)
			c = disp_x_size;
	}
	else
	{
		if (_default_orientation == PORTRAIT)
			c = (long int)((long int)(TP_X - touch_y_top) * (-disp_y_size)) /  (long int)(touch_y_bottom - touch_y_top) +  (long int)(disp_y_size);
		else
			c = (long int)((long int)(TP_X - touch_y_top) * (disp_y_size)) / (long int)(touch_y_bottom - touch_y_top);
		if (c<0)
			c = 0;
		if (c>disp_y_size)
			c = disp_y_size;
	}
	return c;
}

int getY()
{
	signed long int c;

	if (orient == _default_orientation)
	{
		c = (long int)((long int)(TP_Y - touch_y_top) * (disp_y_size)) / (long int)(touch_y_bottom - touch_y_top);
		if (c<0)
			c = 0;
		if (c>disp_y_size)
			c = disp_y_size;
	}
	else
	{
		if (_default_orientation == PORTRAIT)
			c = (long int)((long int)(TP_Y - touch_x_left) * (disp_x_size)) / (long int)(touch_x_right - touch_x_left);
		else
			c = (long int)((long int)(TP_Y - touch_x_left) * (-disp_x_size)) / (long int)(touch_x_right - touch_x_left) + (long int)(disp_x_size);
		if (c<0)
			c = 0;
		if (c>disp_x_size)
			c = disp_x_size;
	}
	return c;
}

void setPrecision(char precision)
{
	switch (precision)
	{
		case PREC_LOW:
			prec=1;
			break;
		case PREC_MEDIUM:
			prec=10;
			break;
		case PREC_HI:
			prec=25;
			break;
		case PREC_EXTREME:
			prec=100;
			break;
                case PREC_ULTRA:
			prec=250;
			break;
		default:
			prec=10;
			break;
	}
}