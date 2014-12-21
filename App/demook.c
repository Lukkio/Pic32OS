//#define N 256 // Number of dots
//#define SCALE 4096
//#define INCREMENT 512
#define N 256// Number of dots
#define SCALE 4096
#define INCREMENT 512
#define SPEED 1
#define PI2 6.283185307179586476925286766559
#define WINDOWX 239
#define WINDOWY 319
#define CERCLE_DRAW

#define RED_COLORS    223
#define GREEN_COLORS  255
#define BLUE_COLORS   223

short int sine[SCALE];
short int cosi[SCALE];

void draws(signed short int xyz[3][N], unsigned char rgb[3][N]);
void initialize();
void MatrixWave(signed short int xyz[3][N], unsigned char rgb[3][N]);
void rotate(signed short int xyz[3][N] , unsigned char rgb[3][N], unsigned short int angleX, unsigned short int angleY, unsigned short int angleZ);
unsigned short int fastsqrt(unsigned long int h);
void BallMatrix(void);

void initialize() {//OK
 unsigned short int i;
 for(i = 0; i < SCALE; i++) {
  sine[i] = (signed short int)(sin(PI2 * i / SCALE) * SCALE);
  cosi[i] = (signed short int)(cos(PI2 * i / SCALE) * SCALE);
 }
}

unsigned short int fastsqrt(unsigned long int h) {
 unsigned short int c = (unsigned short int)0x8000;
 unsigned short int g = (unsigned short int)0x8000;
 for(;;) {
  if(g*g > h)
   g ^= c;
  c >>= 1;
  if(c == 0)
   return g;
  g |= c;
 }
}
void MatrixWave(signed short int xyz[3][N], unsigned char rgb[3][N]) {
 static unsigned long int t = 0;
 unsigned short int i;
 signed short int x = -SCALE;
 signed short int y = -SCALE;
 unsigned short int d;
 unsigned short int s;

 for(i = 0; i < N; i++) {//OK

  xyz[0][i] = x;
  xyz[1][i] = y;

  d = fastsqrt((unsigned long int)(x * x + y * y));
  s = (unsigned short int)sine[(t * 30) % SCALE] + SCALE;

  xyz[2][i] = (signed short int)sine[(d + s) % SCALE] *
              sine[(t * 10) % SCALE] / SCALE / 2;

  rgb[0][i] = (cosi[xyz[2][i] + SCALE / 2] + SCALE) *
              (RED_COLORS - 1) / SCALE / 2;

  rgb[1][i] = (cosi[(xyz[2][i] + SCALE / 2 + 2 * SCALE / 3) % SCALE] + SCALE) *
              (GREEN_COLORS - 1) / SCALE / 2;

  rgb[2][i] = (cosi[(xyz[2][i] + SCALE / 2 + SCALE / 3) % SCALE] + SCALE) *
              (BLUE_COLORS - 1) / SCALE / 2;

  x += INCREMENT;
  if(x >= SCALE) {
   x = -SCALE;
   y += INCREMENT;
  }

 }
 t++;
}
void rotate(signed short int xyz[3][N] , unsigned char rgb[3][N],
            unsigned short int angleX, unsigned short int angleY, unsigned short int angleZ) {//OK
 unsigned short int i;
 signed short int tmpX;
 signed short int tmpY;
 signed short int sinx = sine[angleX];
 signed short int cosx = cosi[angleX];
 signed short int siny = sine[angleY];
 signed short int cosy = cosi[angleY];
 signed short int sinz = sine[angleZ];
 signed short int cosz = cosi[angleZ];

 for(i = 0; i < N; i++) {
  tmpX      = (signed short int)((xyz[0][i] * cosx - xyz[2][i] * sinx) / SCALE);
  xyz[2][i] = (signed short int)((xyz[0][i] * sinx + xyz[2][i] * cosx) / SCALE);
  xyz[0][i] = tmpX;

  tmpY      = (signed short int)((xyz[1][i] * cosy - xyz[2][i] * siny) / SCALE);
  xyz[2][i] = (signed short int)((xyz[1][i] * siny + xyz[2][i] * cosy) / SCALE);
  xyz[1][i] = tmpY;

  tmpX      = (signed short int)((xyz[0][i] * cosz - xyz[1][i] * sinz) / SCALE);
  xyz[1][i] = (signed short int)((xyz[0][i] * sinz + xyz[1][i] * cosz) / SCALE);
  xyz[0][i] = tmpX;
 }
}
void draws(signed short int xyz[3][N], unsigned char rgb[3][N]) {
 static unsigned short int oldProjX[N] = {0};
 static unsigned short int oldProjY[N] = {0};
 static unsigned char oldDotSize[N] = {0};
 unsigned short int i;
 unsigned short int projX;
 unsigned short int projY;
 unsigned short int projZ;
 unsigned short int dotSize;
 for(i = 0; i < N; i++) {
  projZ   = (unsigned short int)(SCALE - (xyz[2][i] + SCALE) / 4);
  projX   = (unsigned short int)(WINDOWX / 2 + (xyz[0][i] * projZ / SCALE) / 25);
  projY   = (unsigned short int)(WINDOWY / 2 + (xyz[1][i] * projZ / SCALE) / 25);
  dotSize = (unsigned short int)(3 - (xyz[2][i] + SCALE) * 2 / SCALE);

  //swim_set_pen_color(&win1, 0);/// carica colore nero(0) dentro win1 

  //swim_put_circle(&win1, oldProjX[i], oldProjY[i], oldDotSize[i], 1); //disegna cerchio (win->colore)

#ifdef CERCLE_DRAW
   LCD_Cercle((char)oldProjX[i],oldProjY[i],oldDotSize[i],1,BLACK);//Prototipo
#endif
#ifdef SQUARE_DRAW
   LCD_FastRect(oldProjX[i],oldProjY[i],oldProjX[i]+(oldDotSize[i]*2),oldProjY[i]+(oldDotSize[i]*2),BLACK);
#endif

   //LCD_Cercle(100,100,30,1,RED);
  if(projX > dotSize &&
     projY > dotSize &&
     projX < WINDOWX - dotSize &&
     projY < WINDOWY - dotSize) {

   //swim_set_pen_color(&win1, (rgb[0][i] << REDSHIFT) +
  //                           (rgb[1][i] << GREENSHIFT) +
    //                         (rgb[2][i] << BLUESHIFT));
//colors=RGB16(rgb[0][i],rgb[1][i],rgb[2][i]);

  // swim_put_circle(&win1, projX, projY, dotSize, 1);

   //LCD_Cercle((char)projX,projY,dotSize,1,colorconv(rgb[0][i], rgb[1][i], rgb[2][i]));//Prototipo

#ifdef CERCLE_DRAW
   LCD_Cercle((char)projX,projY,dotSize,1,RGB16(rgb[0][i], rgb[1][i], rgb[2][i]));//Prototipo
#endif
#ifdef SQUARE_DRAW
   LCD_FastRect(projX,projY,projX+(dotSize*2),projY+(dotSize*2),RGB16(rgb[0][i], rgb[1][i], rgb[2][i]));
#endif
   //LCD_Cercle((char)projX,projY,dotSize,1,REDS);//Prototipo
   //LCD_Cercle(100,100,30,1,RED);//Prototipo
   
   oldProjX[i] = projX;
   oldProjY[i] = projY;
   oldDotSize[i] = dotSize;
  }
 }
}

void BallMatrix(void)
{
    signed short int xyz[3][N];
    unsigned char rgb[3][N];
    signed short int angleX = 0;
    signed short int angleY = 0;
    signed short int angleZ = 0;
    signed short int speedX = 0;
    signed short int speedY = 0;
    signed short int speedZ = 0;
    initialize();
    speedX -= SPEED;
    speedZ -= SPEED;
    speedY -= SPEED;

    LCD_FastRect(0,0,239,319,BLACK);
    while(TRUE)
    {
        MatrixWave(xyz, rgb);
        rotate(xyz, rgb, (unsigned short int)angleX, (unsigned short int)angleY, (unsigned short int)angleZ);
        draws(xyz, rgb);
        #ifdef SQUARE_DRAW
            DelayMs(25);
        #endif
        #ifdef CERCLE_DRAW
            DelayMs(10);
        #endif
        angleX += speedX;
        angleY += speedY;
        angleZ += speedZ;
        if (angleX >= SCALE) angleX -= SCALE;
        else if (angleX < 0) angleX += SCALE;

        if (angleY >= SCALE) angleY -= SCALE;
        else if (angleY < 0) angleY += SCALE;

        if (angleZ >= SCALE) angleZ -= SCALE;
        else if (angleZ < 0) angleZ += SCALE;
        //if(PORTDbits.RD3==0) break;
        if(PORTDbits.RD14==0) break;
    }
}


