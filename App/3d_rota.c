typedef unsigned char	byte;
typedef unsigned char	u8;
typedef signed char		i8;
typedef unsigned short	u16;
typedef signed short	i16;
typedef unsigned long	u32;
typedef signed long		i32;

//typedef enum { FALSE = 0, TRUE } BOOL;

#define abs(x)	(x<0)?	(0-x):(x)

typedef struct
{	// 2D coordinates
    i16 x;
    i16 y;
}Point;

typedef struct
{	// 3D coordinates
    i16 x;
    i16 y;
    i16 z;
}Vertex;

typedef struct
{	//  Triangular face
  u8 A;	// indices of projected vertices (2d points)
    u8 B;
    u8 C;
	u16 color;	// render color
} Triangle;

typedef struct
{	// 3D angular rotations
    float x;
    float y;
    float z;
}rotation;

/*************************************/
i16 sin_table(u8 angle);
i16 cos_table(u8 angle);

/*************************************/
#define TETRAHEDRON_VERTICES	4
#define TETRAHEDRON_TRIANGLES	4

#define CUBE_VERTICES			8
#define CUBE_TRIANGLES			(6*2)

#define OCTAHEDRON_VERTICES		6
#define OCTAHEDRON_TRIANGLES	8

#define PYRAMID_VERTICES		5
#define PYRAMID_TRIANGLES		5+1

#define PRISM_VERTICES			6
#define PRISM_TRIANGLES			2+(3*2)

#define ICOSAHEDRON_VERTICES	12
#define ICOSAHEDRON_TRIANGLES	20

/*************************************/
extern const Vertex		tetrahedron_vectices[TETRAHEDRON_VERTICES];
extern const Triangle	tetrahedron_triangles[TETRAHEDRON_TRIANGLES];

extern const Vertex		cube_vectices[CUBE_VERTICES];
extern const Triangle	cube_triangles[CUBE_TRIANGLES];

extern const Vertex		octahedron_vectices[OCTAHEDRON_VERTICES];
extern const Triangle	octahedron_triangles[OCTAHEDRON_TRIANGLES];

extern const Vertex		pyramid_vectices[PYRAMID_VERTICES];
extern const Triangle	pyramid_triangles[PYRAMID_TRIANGLES];

extern const Vertex		prism_vectices[PRISM_VERTICES];
extern const Triangle	prism_triangles[PRISM_TRIANGLES];

extern const Vertex		icosahedron_vectices[ICOSAHEDRON_VERTICES];
extern const Triangle	icosahedron_triangles[ICOSAHEDRON_TRIANGLES];

unsigned short int DisplayBuffer[120][120];

void WriteBuffer(u16 sx, u16 h, u16 ex, u16 color);
void WriteDisplayBuffer(void);
void ClearBufferDisplay(void);
// quarter sine
const u8 sine_table[64] = 
{
    0,6,13,19,25,31,37,44,
    50,56,62,68,74,80,86,92,
    98,103,109,115,120,126,131,136,
    142,147,152,157,162,167,171,176,
    180,185,189,193,197,201,205,208,
    212,215,219,222,225,228,231,233,
    236,238,240,242,244,246,247,249,
    250,251,252,253,254,254,255,255
};

i16 sin_table(u8 angle)
{
	u8 b;
	i16 i;
	if ((angle & 0x7F) == 0)
        return 0;
    b = angle & 0x3F;
    if (angle & 0x40)
        b = 0x3F - b;
	i = sine_table[b];
    if (angle & 0x80)
        return -i;
    return i;
}

i16 cos_table(u8 angle)
{
    return sin_table(angle + 64);
}

/***	TETRAHEDRON		***/
const Vertex tetrahedron_vectices[TETRAHEDRON_VERTICES]={
#if 0
	( 0, Sqr(3) - 1/Sqr(3),            0)
    (-1,        - 1/Sqr(3),            0)
    ( 1,        - 1/Sqr(3),            0)
    ( 0,                 0, 2 * Sqr(2/3))
#else
	{ 0, 14, 0},
    {-12,-7, 0},
    { 12,-7, 0},
    { 0, 0, 20}
#endif
};

const Triangle tetrahedron_triangles[TETRAHEDRON_TRIANGLES]={
	{ 0, 1, 2, YELLOW },
	{ 0, 2, 3, RED },
	{ 0, 3, 1, DARKGREEN },
    { 1, 3, 2, BLUE }
};

/***	HEXAHEDRON (CUBE)	***/
const Vertex cube_vectices[CUBE_VERTICES]={
	{-10, -10, -10},	//0
	{ 10, -10, -10},	//1
	{ 10,  10, -10},	//2
	{-10,  10, -10},	//3
	{-10, -10,  10},	//4
	{ 10, -10,  10},	//5
	{ 10,  10,  10},	//6
	{-10,  10,  10}		//7
};

const Triangle cube_triangles[CUBE_TRIANGLES]={
	{ 0, 1, 5, CIANO },
	{ 5, 4, 0, CIANO },
	{ 1, 2, 6, ORANGE },
    { 6, 5, 1, ORANGE },
    { 2, 3, 7, GREEN },
    { 7, 6, 2, GREEN },
    { 3, 0, 4, DARKGREEN },
    { 4, 7, 3, DARKGREEN },
    { 0, 3, 2, GRAY },
    { 2, 1, 0, PURPLE },
    { 4, 5, 6, YELLOW },
    { 6, 7, 4, YELLOW }
};

/***	OCTAHEDRON		***/
const Vertex octahedron_vectices[OCTAHEDRON_VERTICES]={
	{ 17,  0,  0},	//0
	{  0, 17,  0},	//1
	{  0,  0, 17},	//2
	{-17,  0,  0},	//3
	{  0,-17,  0},	//4
	{  0,  0,-17}	//5
};

const Triangle octahedron_triangles[OCTAHEDRON_TRIANGLES]={
	{ 2, 0, 1, RED },
	{ 2, 1, 3, YELLOW },
	{ 2, 3, 4, DARKGREEN },
    { 2, 4, 0, BLUE },
	{ 5, 1, 0, CIANO },
	{ 5, 3, 1, DARKGREEN },
	{ 5, 4, 3, YELLOW },
    { 5, 0, 4, RED }
};

/***	PYRAMID		***/
const Vertex pyramid_vectices[PYRAMID_VERTICES]={
	{  0,  0, 12},	//0
	{-10, 10, -8},	//1
	{ 10, 10, -8},	//2
	{ 10,-10, -8},	//3
	{-10,-10, -8},	//4
};

const Triangle pyramid_triangles[PYRAMID_TRIANGLES]={
	{ 0, 1, 4, RED },
	{ 0, 2, 1, YELLOW },
	{ 0, 3, 2, DARKGREEN },
	{ 0, 4, 3, ORANGE },
    { 1, 2, 3, BLUE },
	{ 3, 4, 1, BLUE }
};


/***	TRIANGULAR PRISM		***/
const Vertex prism_vectices[PRISM_VERTICES]={
	{  0, 10, 10},	//0
	{ 10, -7, 10},	//1
	{-10, -7, 10},	//2
	{  0, 10,-10},	//3
	{ 10, -7,-10},	//4
	{-10, -7,-10},	//5
};

const Triangle prism_triangles[PRISM_TRIANGLES]={
	{ 0, 2, 1, DARKGREEN },
	{ 3, 4, 5, PURPLE },
	{ 0, 1, 4, ORANGE },
	{ 4, 3, 0, ORANGE },
    { 1, 2, 5, BLUE },
	{ 5, 4, 1, BLUE },
	{ 2, 0, 3, RED },
    { 3, 5, 2, RED }
};

/***	TRIANGULAR PRISM		***/
const Vertex icosahedron_vectices[ICOSAHEDRON_VERTICES]={
	{  0,  0, 10},
	{ 15,  0,  8}, 
	{  5, 14,  8},
	{-12,  9,  8}, 
	{-12, -9,  8},
	{  5,-14,  8},
	{ 12,  9, -8},
	{ -5, 14, -8},
	{-15,  0, -8},
	{ -5,-14, -8},
	{ 12, -9, -8},
	{  0,  0,-24}
};

const Triangle icosahedron_triangles[ICOSAHEDRON_TRIANGLES]={
	{  0,  2,  1, BLUE},		//0
	{  0,  3,  2, YELLOW},		//1
	{  0,  4,  3, RED},			//2
	{  0,  5,  4, 0XA1C4},		//3
	{  0,  1,  5, PURPLE},		//4
	{ 11,  6,  7, 0XAEEA},		//5
	{ 11,  7,  8, PURPLE},	//6
	{ 11,  8,  9, DARKGREEN},	//7
	{ 11,  9, 10, CLAIRBLUE},		//8
	{ 11, 10,  6, DARKBLUE},	//9
	{  1,  2,  6, ORANGE},		//10
	{  2,  3,  7, BLUE},		//11
	{  3,  4,  8, YELLOW},		//12
	{  4,  5,  9, RED},			//13
	{  5,  1, 10, 0XA4B2},		//14
	{  6,  2,  7, AZZURRO},		//15
	{  7,  3,  8, GRAY},		//16
	{  8,  4,  9, GREEN},	//17
	{  9,  5, 10, DARKGREEN},	//18
	{  10, 1,  6, 0XB125}//LCD_ORANGE}		//19
};

void fill_triangle2(Point A, Point B, Point C, u16 color);
#define SCALE_FACTOR	3
#define OFFSETX			60	// LCD width/2
#define OFFSETY			60	// LCD height/2
#define MAX_TRIANGLES	20


#define LINE_COLOR		0X0000	// edge color - e.g.LCD_RED
#define BG_COLOR		0XFFFF	// background color - e.g.LCD_BRIGHTBLUE

/******************************************************************************************/

void draw_3D(const Vertex * V, const Triangle * T, u8 nVertices, u8 nTriangles, rotation R);

/******************************************************************************************/
#define draw_tetrahedron(R)		\
		draw_3D(tetrahedron_vectices, tetrahedron_triangles,	\
			TETRAHEDRON_VERTICES, TETRAHEDRON_TRIANGLES, R)

#define draw_cube(R)		\
		draw_3D(cube_vectices, cube_triangles,	\
			CUBE_VERTICES, CUBE_TRIANGLES, R)

#define draw_octahedron(R)		\
		draw_3D(octahedron_vectices, octahedron_triangles,	\
			OCTAHEDRON_VERTICES, OCTAHEDRON_TRIANGLES, R)

#define draw_pyramid(R)		\
		draw_3D(pyramid_vectices, pyramid_triangles,	\
			PYRAMID_VERTICES, PYRAMID_TRIANGLES, R)

#define draw_prism(R)		\
		draw_3D(prism_vectices, prism_triangles,	\
			PRISM_VERTICES, PRISM_TRIANGLES, R)

#define draw_icosahedron(R)		\
		draw_3D(icosahedron_vectices, icosahedron_triangles,	\
			ICOSAHEDRON_VERTICES, ICOSAHEDRON_TRIANGLES, R)
			
			
#define	mul(n1,n2)		__builtin_mulss(n1, n2)
#define	div(num,den)	__builtin_divsd(num,den) 

// LCD plot coordinates
static Point new_points[MAX_TRIANGLES];
static Point old_points[MAX_TRIANGLES];

void fill_triangle(Point A, Point B, Point C, u16 color);
BOOL Backface(Point A, Point B, Point C);

/*****	DRAW 3D MODELS	*****/
void draw_3D(const Vertex * V, const Triangle * T, u8 nVertices, u8 nTriangles, rotation R)
{
	u8 i;

	float tempX,tempY,tempZ;				// temporary coordinates
	float sinX,sinY,sinZ,cosX,cosY,cosZ;	// precomputed sin and cos values
	float px,py,pz;							// projected

	// sin and cos values
	sinX = sin( R.x ) ;
	sinY = sin( R.y );
	sinZ = sin( R.z );

	cosX = cos( R.x );
	cosY = cos( R.y );
	cosZ = cos( R.z );

	// calculate the new coordinates of points
   	for (i=0; i<nVertices; i++)
	{
		tempX = V[i].x;
		tempY = V[i].y;
		tempZ = V[i].z;

		// store previous coordinates
		old_points[i] = new_points[i];

		// rotation on X axis
		py = tempY * cosX - tempZ * sinX;
		pz = tempY * sinX + tempZ * cosX;
		tempY =py; tempZ = pz;

		// rotation on Z axis
		px = tempX * cosZ - tempY * sinZ;
		py = tempX * sinZ + tempY * cosZ;
		tempX = px; tempY = py;

		// rotation on Y axis
		px = tempX * cosY - tempZ * sinY;
		pz = tempX * sinY + tempZ * cosY;

		// save the screen coordinates
		new_points[i].x = px * SCALE_FACTOR + OFFSETX;
		new_points[i].y = py * SCALE_FACTOR + OFFSETY;
	}

	// erase previous triangles
	/*for (i=0; i<nTriangles; i++)
	{
		if( !Backface( old_points[T[i].A], old_points[T[i].B], old_points[T[i].C] ) )
			fill_triangle(old_points[T[i].A], old_points[T[i].B], old_points[T[i].C], BLACK);
	}*/
       // SSD1289_writeResgiter( 0x0049, 0x000E );///fine della finestra a 14 in y
       // LCD_FastRect(10,10,150,150,WHITE);
        
	// lcd plot new triangles
	for (i=0; i<nTriangles; i++)
	{
		if( !Backface( new_points[T[i].A], new_points[T[i].B], new_points[T[i].C] ) )
			fill_triangle(new_points[T[i].A], new_points[T[i].B], new_points[T[i].C], T[i].color);
                                               
	}
        WriteDisplayBuffer();
        ClearBufferDisplay();
        
        //SSD1289_writeResgiter( 0x0049, 0x013F );
        //DelayMs(10);

}

//#define hline(x1,x2,y,color)	drawline(x1,y,x2,y,color)

/*****	TRIANGLE COLOR FILL		******/
#if ciao	// use hardware multiplier/divider
void fill_triangle(Point A, Point B, Point C, u16 color)
{
#define kSCALE (1<<9)	// (1<<15)

	Point P;	// swap temp 
	i16 dx1=0, dx2=0, dx3=0;	  
	i16 h, sx, ex;	// horizontal line
	
	// bubble sort points
	if(B.y<A.y){ P=A; A=B; B=P; }
	if(C.y<B.y){ P=B; B=C; C=P; }
	if(C.y<A.y){ P=A; A=C; C=P;	}
	if(B.y<A.y){ P=A; A=B; B=P; }

	// compute dx's
	if (B.y-A.y > 0) dx1 =  ((B.x-A.x)*kSCALE)/(B.y-A.y);
	if (C.y-B.y > 0) dx2 =  ((C.x-B.x)*kSCALE)/(C.y-B.y);
	if (C.y-A.y > 0) dx3 =  ((C.x-A.x)*kSCALE)/(C.y-A.y);

	for(h = (i16) A.y; h < B.y; h++) {
		sx = A.x + (((h - A.y)*dx3)/kSCALE);
		ex = A.x + (((h - A.y)*dx1)/kSCALE);
		//draw_line(sx,ex,h,color);
                draw_line(sx,h,ex,h,color);
	}
	for(h = (i16) B.y; h < C.y; h++) {
		sx = A.x + (((h - A.y)*dx3)/kSCALE);
		ex = B.x + (((h - B.y)*dx2)/kSCALE);
		draw_line(sx,h,ex,h,color);
	}
}

#else // use floating point operations

void fill_triangle(Point A, Point B, Point C, u16 color)
{
	Point P;	// swap temp 
	float dx1=0, dx2=0, dx3=0;	  
	i16 h, sx, ex;	// horizontal line
	
	// bubble sort points
	if(B.y<A.y){ P=A; A=B; B=P; }
	if(C.y<B.y){ P=B; B=C; C=P; }
	if(C.y<A.y){ P=A; A=C; C=P;	}
	if(B.y<A.y){ P=A; A=B; B=P; }

	// compute dx's
	if (B.y-A.y > 0) dx1 = (float)(B.x-A.x)/(B.y-A.y);
	if (C.y-B.y > 0) dx2 = (float)(C.x-B.x)/(C.y-B.y);
	if (C.y-A.y > 0) dx3 = (float)(C.x-A.x)/(C.y-A.y);

	for(h = (i16) A.y; h < B.y; h++) {
		sx = A.x + ((h - A.y) * dx3);
		ex = A.x + ((h - A.y) * dx1);
		//hline(sx,ex,h,color);
		//draw_line(sx,h,ex,h,color);
                //LCD_FastRect(sx,h,ex,h,color);

                WriteBuffer(sx,h,ex,color);

                //LCD_Pixel(sx,h,WHITE);
                //LCD_Pixel(ex,h,WHITE);
	}
	for(h = (i16) B.y; h < C.y; h++) {
		sx = A.x + ((h - A.y) * dx3);
		ex = B.x + ((h - B.y) * dx2);
		//hline(sx,ex,h,color);
		//draw_line(sx,h,ex,h,color);
                //LCD_FastRect(sx,h,ex,h,color);

                WriteBuffer(sx,h,ex,color);
                
               // LCD_Pixel(sx,h,WHITE);
               // LCD_Pixel(ex,h,WHITE);
	}
}
#endif

void fill_triangle2(Point A, Point B, Point C, u16 color)
{
	Point P;	// swap temp
	float dx1=0, dx2=0, dx3=0;
	i16 h, sx, ex;	// horizontal line

	// bubble sort points
	if(B.y<A.y){ P=A; A=B; B=P; }
	if(C.y<B.y){ P=B; B=C; C=P; }
	if(C.y<A.y){ P=A; A=C; C=P;	}
	if(B.y<A.y){ P=A; A=B; B=P; }

	// compute dx's
	if (B.y-A.y > 0) dx1 = (float)(B.x-A.x)/(B.y-A.y);
	if (C.y-B.y > 0) dx2 = (float)(C.x-B.x)/(C.y-B.y);
	if (C.y-A.y > 0) dx3 = (float)(C.x-A.x)/(C.y-A.y);

	for(h = (i16) A.y; h < B.y; h++) {
		sx = A.x + ((h - A.y) * dx3);
		ex = A.x + ((h - A.y) * dx1);
		//hline(sx,ex,h,color);
		//draw_line(sx,h,ex,h,color);
                LCD_Pixel(sx,h,color);
                LCD_Pixel(sx+1,h,color);
                LCD_Pixel(ex,h,color);
                LCD_Pixel(ex-1,h,color);
	}
	for(h = (i16) B.y; h < C.y; h++) {
		sx = A.x + ((h - A.y) * dx3);
		ex = B.x + ((h - B.y) * dx2);
		//hline(sx,ex,h,color);
		//draw_line(sx,h,ex,h,color);
                LCD_Pixel(sx,h,color);
                LCD_Pixel(sx+1,h,color);
                LCD_Pixel(ex,h,color);
                LCD_Pixel(ex-1,h,color);
	}
}


/*****	BACKFACE CULLING		******/
BOOL Backface(Point A, Point B, Point C)
{
	Point L1, L2;	// lines/edges

	L1.x = A.x - B.x;
	L1.y = A.y - B.y;
	L2.x = C.x - B.x;
	L2.y = C.y - B.y;

	//if( ((L1.x * L2.y)  - (L1.y * L2.x)) < 0 )
	if( ((L1.x*L2.y) - (L1.y*L2.x) ) < 0 )
		return TRUE;
	return FALSE;
}

void demo()
{
	u8 angle, keypad;
	rotation r;
        float ruota=0,ruotay=0;

/**/DelayMs(100);
	LCD_CLS(BLACK);
	//lcd_text2( "Tetrahedron", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                ruota=ruota+0.06;
                if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruota; r.z = ruota;
		draw_tetrahedron(r); 	DelayMs(20);
                if(PORTDbits.RD14==0) break;
	}	
	LCD_CLS(BLACK);
        DelayMs(100);
	//lcd_text2( "Hexahedron (Cube)", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                ruota=ruota+0.02;
                if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruota; r.z = ruota;
		draw_cube(r);		//delay(0x7FF);
                if(PORTDbits.RD14==0) break;
	}

	LCD_CLS(BLACK);
        DelayMs(100);
	//lcd_text2( "Octahedron", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                ruota=ruota+0.06;
                if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruota; r.z = ruota;
		draw_octahedron(r); 	//delay(0x7FFF);
                if(PORTDbits.RD14==0) break;
	}

	LCD_CLS(BLACK);
        DelayMs(100);
	//lcd_text2( "Square Pyramid", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                ruota=ruota+0.06;
                if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruota; r.z = ruota;
		draw_pyramid(r); 	DelayMs(20);
                if(PORTDbits.RD14==0) break;
	}
        DelayMs(100);
	LCD_CLS(BLACK);
	//lcd_text2( "Triangular Prism", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                ruota=ruota+0.06;
                if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruota; r.z = ruota;
		draw_prism(r); 		DelayMs(20);
                if(PORTDbits.RD14==0) break;
	}
 
DelayMs(100);
	LCD_CLS(BLACK);
            LCD_FastRect(60,285,80,305,BLUE);//left
    LCD_FastRect(85,285,105,305,GREEN);//Down
    LCD_FastRect(110,285,130,305,RED);//right
    LCD_FastRect(85,260,105,280,PURPLE);//up
    
	//lcd_text2( "Icosahedron", 10, 7, LCD_RED, LCD_WHITE);
	for(angle=0; angle<150;)
	{
                //ruota=ruota+0.02;
                //if(ruota==360.00) ruota=0.02;
		r.x = ruota; r.y = ruotay; r.z = 0;
		draw_icosahedron(r); 	//delay(0x7FFF);
                //if(PORTDbits.RD14==0) break;
                keypad=ReadTouch();

                if(keypad==Left) ruota+=0.02;
                if(keypad==Right) ruota-=0.02;
                if(ruota==360.00) ruota=0.02;
                if(ruota<=0) ruota=359.98;

                if(keypad==Up) ruotay+=0.02;
                if(keypad==Down) ruotay-=0.02;
                if(ruotay==360.00) ruotay=0.02;
                if(ruotay<=0) ruotay=359.98;               
	}

}

void WriteBuffer(u16 sx, u16 h, u16 ex, u16 color)
{
    u16 swap;
    u16 conta;

    if(sx>ex)
    {
        swap=sx;
        sx=ex;
        ex=swap;
    }
  //  sx+=60;
  //  ex+=60;
  //  h+=60;

    for(conta=sx; conta<ex; conta++) DisplayBuffer[(u8)h][(u8)conta]=color;

}

void WriteDisplayBuffer(void)
{
    u8 xloop, yloop, ypos=100;


    SSD1289_writeResgiter( 0x004E, 60 );//la x di partenza
    SSD1289_writeResgiter( 0x004F, 100 );//la y di partenza
    SSD1289_sendCommand(0x0022); //set the RAM register for writing

    for(yloop=0; yloop<=119; yloop++)
    {
        for(xloop=0; xloop<=119; xloop++) SSD1289_sendData(DisplayBuffer[yloop][xloop]);
        ypos++;
        SSD1289_writeResgiter( 0x004F, ypos );
	SSD1289_sendCommand(0x0022); //set the RAM register for writing
    }
}

void ClearBufferDisplay(void)
{
 u8 xloop, yloop;
    for(yloop=0; yloop<=119; yloop++)
    {
        for(xloop=0; xloop<=119; xloop++) DisplayBuffer[yloop][xloop]=0xffff;
    }
}
			