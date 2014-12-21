#define tftX 240
#define tftY 320

#define nn 10
#define m 30
#define CERCLE_BACKGROUND
void collision();
void setup();
void borders();
void draw();
void BallRand(void);
void ChangeBackground(void);
short int colorconv(char r, char g, char b);
unsigned char i,Screen_Saver=0;
unsigned char j;

float x[m];
float y[m];
unsigned char r[m];

float oldX[m];
float oldY[m];

float velX[m];
float velY[m];

unsigned char red[m];
unsigned char green[m];
unsigned char blue[m];
#ifdef CERCLE_BACKGROUND
unsigned short int CercleTemp[10][200];
unsigned short int TempoBall=0;
char BackgroundBall[] = {'c',0x00,'o',0x00,'n',0x00,'v',0x00,'(',0x00,'0',0x00,'1',0x00,')',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
unsigned char NumBall=0x31,DecBall=0x30;
#endif

void setup() {
 float circle;
 const float phase1 = 2 * M_PI / 3;
 const float phase2 = 4 * M_PI / 3;

#ifdef CERCLE_BACKGROUND
 const	char str5[] = {'\\',0x00,'s',0x00,'e',0x00,'d',0x00,'\0',0x00};
 char str1[] = {'c',0x00,'o',0x00,'n',0x00,'v',0x00,'(',0x00,'0',0x00,'7',0x00,')',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
 wFSchdir ((unsigned short int *)&str5[0]);
 DrawBmp(0,319,(unsigned short int * )&str1[0],0);
#else
 LCD_Rect(0,0,239,319,1,BLACK);
#endif
 for(i = 0; i < nn; i++) {
     
 #ifndef CERCLE_BACKGROUND    
  x[i] = tftX / 2;
  y[i] = tftY / 2;
  oldX[i] = x[i];
  oldY[i] = y[i];
#endif
r[i] = i * 2 + 10;

    if(Screen_Saver==200)
    {
        velX[i] = 1.0;
        velY[i] = 1.0;
    }
    else
    {
        velX[i] = 2.0;
        velY[i] = 2.0;
    }

  circle = i * 2 * M_PI / nn;
  red[i] = cos(circle) * 127 + 127;
  green[i] = cos(circle + phase2) * 127 + 127;
  blue[i] = cos(circle + phase1) * 127 + 127;
//#ifdef CERCLE_BACKGROUND
//  LCD_CercleRead((signed char)oldX[i],(signed short int)oldY[i], r[i],(unsigned short int * )&CercleTemp[i][0]);
//endif
 }
#ifdef CERCLE_BACKGROUND
 oldX[0] = x[0] = 50;
 oldX[1] = x[1] = 50;
 oldX[2] = x[2] = 50;
 oldX[3] = x[3] = 50;
 oldX[4] = x[4] = 50;
 oldX[5] = x[5] = 150;
 oldX[6] = x[6] = 150;
 oldX[7] = x[7] = 150;
 oldX[8] = x[8] = 150;
 oldX[9] = x[9] = 150;

 oldY[0] = y[0] = 50;
 oldY[1] = y[1] = 100;
 oldY[2] = y[2] = 150;
 oldY[3] = y[3] = 200;
 oldY[4] = y[4] = 250;
 oldY[5] = y[5] = 50;
 oldY[6] = y[6] = 100;
 oldY[7] = y[7] = 150;
 oldY[8] = y[8] = 200;
 oldY[9] = y[9] = 250;
 for(i = 0; i < nn; i++)
 {
    LCD_CercleRead((signed char)oldX[i],(signed short int)oldY[i], r[i]-4,(unsigned short int * )&CercleTemp[i][0]);
 }
#endif


 
}

void loop() {
 for(i = 0; i < nn; i++) {

  x[i] += velX[i];
  y[i] += velY[i];

  for(j = i + 1; j < nn; j++) collision();

  borders();

  //if(((signed int32)(x[i]) != (signed int32)(oldX[i])) || ((signed int32)(y[i]) != (signed int32)(oldY[i])))
  if((x[i]) != oldX[i])draw();
  if((y[i]) != (oldY[i]))draw();

 }
}

void collision() {
 float disX = x[j] - x[i];
 float disY = y[j] - y[i];
 float d2 = disX * disX + disY * disY;

 if(d2 != 0) {
  float rij = r[i] + r[j];
  float rij2 = rij * rij;

  if(d2 < rij2) {
   float ii = (disX * velX[i] + disY * velY[i]) / d2;
   float ji = (disX * velY[i] - disY * velX[i]) / d2;
   float ij = (disX * velX[j] + disY * velY[j]) / d2;
   float jj = (disX * velY[j] - disY * velX[j]) / d2;
   float ratio = rij / sqrt(d2);

   velX[i] = ij * disX - ii * disY;
   velY[i] = ij * disY + ii * disX;
   velX[j] = ji * disX - jj * disY;
   velY[j] = ji * disY + jj * disX;

   disX *= ((ratio - 1) / 2);
   disY *= ((ratio - 1) / 2);

   x[j] += disX;
   y[j] += disY;
   x[i] -= disX;
   y[i] -= disY;
  }
 }
}

void borders() {
 if(x[i] >= tftX - r[i] - 1) {
  x[i] = tftX - r[i] - 1;
  velX[i] = -velX[i];
 } else if(x[i] <= r[i]) {
  x[i] = r[i];
  velX[i] = -velX[i];
 }

 if(y[i] >= tftY - r[i] - 1) {
  y[i] = tftY - r[i] - 1;
  velY[i] = -velY[i];
 } else if(y[i] <= r[i]) {
  y[i] = r[i];
  velY[i] = -velY[i];
 }
}

void draw() {
 //tft.setColor(0, 0, 0);
 //tft.drawCircle(oldX[i], oldY[i], r[i]);

#ifdef CERCLE_BACKGROUND

    LCD_CercleBackGround((signed char)oldX[i],(signed short int)oldY[i], r[i]-4,(unsigned short int * )&CercleTemp[i][0]);

    if(Screen_Saver==200)
    {
        if(UpdateTime()==1)
        {
            StampaOra(220,10,3,0,0);
            StampaDate(190,10,1,0,0);
        }

    }
    else{
        if(TempoBall==15000)
        {
            ChangeBackground();
            TempoBall=0;
        }
    }
    LCD_CercleRead((signed char)x[i],(signed short int)y[i], r[i]-4,(unsigned short int * )&CercleTemp[i][0]);
    TempoBall++;
#else
LCD_Cercle((signed char)oldX[i],(signed short int)oldY[i], r[i],0,BLACK);//Prototipo
#endif

 //tft.setColor(red[i], green[i], blue[i]);
 //tft.drawCircle(x[i], y[i], r[i]);
// colore=RGB16(12, 12, 12);
//LCD_Cercle((signed char)x[i],(signed short int)y[i], r[i],0,colorconv(red[i], green[i], blue[i]));//Prototipo   
 LCD_Cercle((signed char)x[i],(signed short int)y[i], r[i]-4,0,RGB16(red[i], green[i], blue[i]));//Prototipo
 oldX[i] = x[i];
 oldY[i] = y[i];

 //if(Screen_Saver==200) DelayMs(3);
 
}

short int colorconv(char r, char g, char b)
{
    unsigned  short int color16 = (((unsigned short int)r<<11)+(unsigned short int)g<<5)+(unsigned char)b;
    return color16;
}

void BallRand(void)
{
    
    if(Screen_Saver==200)
    {
        UpdateTime();
        UpdateDate();
    }

    setup();
    while(TRUE)
    {
        loop();
        if(PORTDbits.RD14==0) break;
    }
}

void ChangeBackground(void)
{
    NumBall=NumBall+0x01;
    if(NumBall==0x3a)
    {
        NumBall=0x30;
        DecBall=DecBall+0x01;
        if(DecBall==0x3a) DecBall=0x30;
     }
     BackgroundBall[12]=NumBall;
     BackgroundBall[10]=DecBall;
    DrawBmp(0,319,(unsigned short int * )&BackgroundBall[0],1);
    
     oldX[0] = x[0] = 50;
 oldX[1] = x[1] = 50;
 oldX[2] = x[2] = 50;
 oldX[3] = x[3] = 50;
 oldX[4] = x[4] = 50;
 oldX[5] = x[5] = 150;
 oldX[6] = x[6] = 150;
 oldX[7] = x[7] = 150;
 oldX[8] = x[8] = 150;
 oldX[9] = x[9] = 150;

 oldY[0] = y[0] = 50;
 oldY[1] = y[1] = 100;
 oldY[2] = y[2] = 150;
 oldY[3] = y[3] = 200;
 oldY[4] = y[4] = 250;
 oldY[5] = y[5] = 50;
 oldY[6] = y[6] = 100;
 oldY[7] = y[7] = 150;
 oldY[8] = y[8] = 200;
 oldY[9] = y[9] = 250;
 for(i = 0; i < nn; i++)
 {
    LCD_CercleRead((signed char)oldX[i],(signed short int)oldY[i], r[i]-4,(unsigned short int * )&CercleTemp[i][0]);
 }
 i=0;
}
