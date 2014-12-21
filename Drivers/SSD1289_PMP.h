/*
*************************************************************************************************
*		Inserimento tabella caratteri
*************************************************************************************************
*/

#include "../FONT57.c"
#include "../Times_fonts.c"

/*
*************************************************************************************************
*                                 Definizione display 
*************************************************************************************************
*/

#define  GCLCDX         239
#define  GCLCDY         319
#define  X_START        0
#define  Y_START        0
#define  X_END          GCLCDX + 1
#define  Y_END          GCLCDY + 1

#define ALIGNMENT_CENTER 1
#define ALIGNMENT_LEFT 2
#define ALIGNMENT_RIGHT 3

/*
*************************************************************************************************
*                                 Definizione registri display
*************************************************************************************************
*/

#define OSC_START            0x0000
#define DRIVER_OUT           0x0001
#define LCD_DRIVE_AC         0x0002
#define POWER_CONTROL1       0x0003
#define POWER_CONTROL2       0x000C
#define POWER_CONTROL3       0x000D
#define POWER_CONTROL4       0x000E
#define POWER_CONTROL5       0x001E
#define DISPLAY_CONTROL      0x0007
#define ENTRY_MODE           0x0011
#define SLEEP_MODE           0x0010
#define HORIZONTAL_RAM_START 0x0044
#define VERTICAL_RAM_START   0x0045
#define VERTICAL_RAM_END     0x0046
#define RAM_WRITE            0x0022

#define LCD_X                0x004E
#define LCD_Y                0x004F

/*
***********************************************************************************************
* Converte colore 24 bit in 16 bit RGB
* [R4R3R2R1R0G5G4G3][G2G1G0B4B3B2B1B0]
***********************************************************************************************
*/

//#define RGB16(r,g,b)   ((unsigned short int)r<<11)+(unsigned short int)g<<5)+(unsigned char)b
#define RGB16(R,G,B) (((R << 8) & 0xF800) | ((G << 3) & 0x7E0) | (B >> 3))

/*
***********************************************************************************************
*                        Definizione colori a 16 bit
***********************************************************************************************
*/

#define  NONE        0x0001
#define BLUE         0x001F
#define YELLOW       0xFFE0
#define RED          0xF800
#define GREEN        0x07E0
#define BLACK        0x0000
#define WHITE        0xffff
#define LIGHTGREEN   0xEFE0
#define DARKGREEN    0XE0E0
#define MAROON       0XF200
#define DARKBLUE     0X000F
#define CLAIRBLUE    0X07FF
#define ORANGE       0XFD20
#define PURPLE       0XF81F
#define GRAY         0xD69A
//#define AZZURRO      0xAE7D
#define AZZURRO      0x9EDD
#define CIANO        0x07FF

/*
***********************************************************************************************
*                           Variabili Globali
***********************************************************************************************
*/

#define BitTest(Var, Pos)  ((Var) & (1 << (Pos)))
#define SSD1289_COMMAND_ADDRESS         0x8000
#define SSD1289_DATA_ADDRESS            0xC000
unsigned short int Xcursor,Ycursor;
/*
***********************************************************************************************
*                           Definizione delle funzioni
***********************************************************************************************
*/

void PMP_InitHW(void);
void SSD1289_sendCommand( unsigned short int command );
void SSD1289_sendData(unsigned short int data );
void SSD1289_writeResgiter(unsigned short int reg, unsigned short int data );
void SSD1289_on(void);
unsigned short int SSD1289_ReadData(unsigned short int x , unsigned short int y);
void LCD_CLS(unsigned short int colore);
void LCD_Fillscreen(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2,unsigned short int colore);
void LCD_Pixel(unsigned short int x , unsigned short int y , unsigned short int colore_unico);
void draw_line(unsigned short int x1 , unsigned short int y1 ,unsigned short int x2 , unsigned short int y2 , unsigned short int colore);
void LCD_Rect(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned char plein, unsigned short int colore);
void LCD_Cercle(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned char plein, unsigned short int colore);
void LCD_Text57(unsigned char x, unsigned short int y, char* textptr, char Dimension, unsigned short int colore, unsigned short int BackColor);
void fonts(unsigned char x, unsigned short int y, char *c, unsigned short int colore);
void LCD_FastRect(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned short int colore);
void LCD_ScrollOn(void);
void LCD_ScrollOff(void);
void LCD_ScrollArea(unsigned short int VL1, unsigned short int VL2);
void LCD_Text57Land(unsigned char x, unsigned short int y, char* textptr, char Dimension, unsigned short int colore, unsigned short int BackColor);
void LCD_RectWithBackGround(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned char R, unsigned char G, unsigned char B, float Opacity);
void LCD_CercleRead(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned short int * colore);
unsigned short int LCD_PixelRead(unsigned short int x, unsigned short int y);
void LCD_CercleBackGround(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned short int * colore);
unsigned short int CenterX(unsigned short int x, unsigned char mul, char Position, unsigned short int * Testo);
char atobcd(char* bcds);