						 //=========================================================================================================================================

#include "ads7843drv.h"

//averaging value
unsigned char Precision = 20;

//====================================================================================
void TP_Init(void)
{
	TRISDbits.TRISD14=1;//IRQ
    TRISFbits.TRISF2=1;//DOUT
	T_CS=1;
	T_CLK=1;
	T_DIN=1;
	T_CLK=1;
}
//====================================================================================
static void WR_CMD (unsigned char cmd) 
{

    unsigned char buf;
    unsigned char i;
    unsigned char nop;
    
    T_CS=1;
    T_DIN=0;
    T_CLK=0;
    T_CS=0;
    for(i=0;i<8;i++)
    {
        buf=(cmd>>(7-i))&0x1;
        T_DIN=buf;
        //DelayUs(5);
        nop++;
        T_CLK=1;
        //DelayUs(5);
        nop++;
        T_CLK=0; 
    }
    /*
	unsigned char temp,count=0;
	unsigned char nop;

	temp=cmd;
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
	}*/
}
//====================================================================================
static unsigned short RD_AD(void) 
{
    unsigned short buf=0,temp;
    unsigned char i;
    unsigned char nop;

    T_DIN=0;
    T_CLK=1;
    for(i=0;i<12;i++) 
    {
        //DelayUs(5);
        nop++;
        T_CLK=0;         
        //DelayUs(5);
        nop++;
        temp= (T_DOUT) ? 1:0;
        buf|=(temp<<(11-i));
        
        //DelayUs(5);
        nop++;
        T_CLK=1;
    }
    T_CS=1;
    buf&=0x0fff;
    return(buf);
    /*
    
	unsigned char nop,count=0;
	unsigned short int data = 0x0000;
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
	
	//data&=0x0fff;
	return(data);*/
}
//====================================================================================
int Read_X(void)
{ 
    int i;
    //T_CS=0;
    WR_CMD(CHX);
   // while(TP_BUSY);
    //T_CLK=1;
    //T_CLK=0;
    //DelayUs(10); //changed from 5
    i=RD_AD();
   // T_CS=1;
    return i;   
}
//====================================================================================
int Read_Y(void)
{ 
    int i;
   // T_CS=0;
    WR_CMD(CHY);
   // T_CLK=1;
   // T_CLK=0;
    //while(TP_BUSY);
    //DelayUs(10);//changed from 5
    i=RD_AD();
   // T_CS=1;
    return i;    
}
//====================================================================================
void TP_GetAdXY(uint16_t *x, uint16_t *y) //reads touch screen ADC value
{
    uint16_t adx,ady;
    adx=Read_X();
    ady=Read_Y();
    *x=adx;
    *y=ady;
}


//reading adc values and averaging
void TP_GetAVGAdXY(uint32_t *x, uint32_t *y)
{
 uint32_t adx = 0;
  uint32_t ady = 0;
  int i;
  //let it settle
 // DelayUs(5);
  //first garbage read
  i=Read_X();
  i=Read_Y();
  for (i=0; i<Precision; i++)
    {
      adx +=Read_X();
      ady +=Read_Y();
    }
  *x= (uint16_t)(adx/Precision);
  *y= (uint16_t)(ady/Precision);
}

void TP_GetMedianAdXY(uint32_t *x, uint32_t *y)
{
   uint32_t madx[MEDIAN];
   uint32_t mady[MEDIAN];
   int i;

   for (i=0; i<MEDIAN; i++)
     {
       TP_GetAVGAdXY(&madx[i],  &mady[i]);
     }
   *x= median(madx);
   *y= median(mady);
}

int median(uint32_t x[]) {
    uint32_t temp;
    int i, j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<MEDIAN-1; i++) {
        for(j=i+1; j<MEDIAN; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(MEDIAN%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[MEDIAN/2] + x[MEDIAN/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[MEDIAN/2];
    }
}


