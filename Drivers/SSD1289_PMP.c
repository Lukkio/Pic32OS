/*
*************************************************************************************************
*		Inserimento header 
*************************************************************************************************
*/

#include"../Drivers/SSD1289_PMP.h"

/*
*************************************************************************************************
*                                     PMP INIT
*
* Description : Inizializza la porta PMP in modalitÃ  16 bit      
* Arguments   : none
*         
* Returns     : none
* Note        : Chiamare una volta prima di inizializzare il display
*************************************************************************************************
*/

void PMP_InitHW(void){
	DelayUs(30000);
    IEC1CLR 	= 0x0004;   // Disable PMP interrupt
    PMCON 		= 0x0000;   // Stop PMP module and clear control register
    PMCONSET	= 0x0340;   // Configure the addressing and polarities
    //PMMODE 		= 0x0600;   // Configure the mode
    PMMODE 		= 0x0645;   // Configure the mode 0x0045 impostata la lettura/scrittura a ogni 2tpb
    PMAEN 		= 0xC000;   // Enable all address and Chip Select lines
    PMCONSET 	= 0x8000;   // Enable the PMP module
    DelayUs(50000);
}

/*
*************************************************************************************************
*                                     INVIA COMANDO
*
* Description : Invia comando al display     
* Arguments   : none
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void SSD1289_sendCommand( unsigned short int command )
{
    PMPSetAddress( SSD1289_COMMAND_ADDRESS );
    PMPMasterWrite( command );
}

/*
*************************************************************************************************
*                                     INVIA DATO
*
* Description : Invia dati al display     
* Arguments   : none
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void SSD1289_sendData(unsigned short int data )
{
    PMPSetAddress( SSD1289_DATA_ADDRESS );
    PMPMasterWrite( data );
}

/*
*************************************************************************************************
*                                     INVIA REGISTRO
*
* Description : Invia reistro al display     
* Arguments   : none
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void SSD1289_writeResgiter(unsigned short int reg, unsigned short int data )
{
    SSD1289_sendCommand( reg );
    SSD1289_sendData( data );
}

/*
*************************************************************************************************
*                                     READ DATA
*
* Description : Legge la ram del display     
* Arguments   : none
*         
* Returns     : none
* Note        : da testare!
*************************************************************************************************
*/

unsigned short int SSD1289_ReadData(unsigned short int x , unsigned short int y)
{
    unsigned short int var1=0,var2=0,var3=0,var4=0;
    //char TextBuffer[20];
    
    SSD1289_writeResgiter( 0x004E, x );
    SSD1289_writeResgiter( 0x004F, y );
    SSD1289_sendCommand(0x0022); //set the RAM register for writing

    PMPSetAddress( SSD1289_DATA_ADDRESS );

    var1=PMPMasterRead();///Ritorna registro!
    var2=PMPMasterRead();///Ritorna registro!
    var3=PMPMasterRead();///Ritorna registro!
    var4=PMPMasterRead();///Ritorna registro!
    //var5=PMPMasterRead();///Ritorna registro!
   
    //DelayUs(10);

    //var=PMPMasterRead();///Ritorna registro!
    //var=PMPMasterRead();///Ritorna registro!
    //var=PMPMasterRead();///Ritorna registro!
   // var=PMPMasterRead();///Ritorna registro!
    
    //var5=PMPMasterRead();///Ritorna i dati!
    //var5=PMPMasterRead();
    return var4;
	
	//Debug
   // sprintf(TextBuffer,"Colore:%04x, %04x, %04x, %04x, %04x",var1,var2,var3,var4,var5);	// %04 -> obbliga a stampare 4 cifre(compresi zeri)
   // LCD_Text57(1,180,TextBuffer,1,RED,NONE);
}

/*
*************************************************************************************************
*                                     INIZIALIZZA IL DISPLAY
*
* Description : Attiva il display
* Arguments   : none
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void SSD1289_on(void)
{

    SSD1289_writeResgiter( 0x0007, 0x0021 );
    SSD1289_writeResgiter( 0x0000, 0x0001 );
    SSD1289_writeResgiter( 0x0007, 0x0023 );   
    SSD1289_writeResgiter( 0x0010, 0x0000 );// set R10h at 0000h = exit sleep mode
    DelayUs(30000);
    SSD1289_writeResgiter( 0x0007, 0x0033 );
    SSD1289_writeResgiter( 0x0011, 0x6830 );// entry mode setting
    SSD1289_writeResgiter( 0x0002, 0x1000 );// LCD drive AC setting
    SSD1289_writeResgiter( 0x000f, 0x0000 );//GATE SCAN POSITION

    ////scroll
    SSD1289_writeResgiter( 0x0041, 0x0000 );
    SSD1289_writeResgiter( 0x0042, 0x0000 );
    SSD1289_writeResgiter( 0x0048, 0x0000 );
    SSD1289_writeResgiter( 0x0049, 0x013F );
    SSD1289_writeResgiter( 0x0044, 0xEF00 );
    SSD1289_writeResgiter( 0x0045, 0x0000 );
    SSD1289_writeResgiter( 0x0046, 0x013F );
    SSD1289_writeResgiter( 0x004A, 0x0000 );
    SSD1289_writeResgiter( 0x004B, 0x0000 );
    ///end sroll

    SSD1289_writeResgiter( 0x0001, 0x2B3F  );//Driver Output Control (R01h) (POR = [0XXXX0X1]3Fh)
    SSD1289_writeResgiter( 0x000B, 0x5308 );//Frame Cycle Control (R0Bh) (POR = 5308h)
    SSD1289_writeResgiter( 0x0028, 0x0006 );//Setting R28h as 0x0006 is required before setting R25h and R29h registers.  
    SSD1289_writeResgiter( 0x0025, 0xE000 );//Frame Frequency Control (R25h) (POR = 8000h)
}

/*
*************************************************************************************************
*                                     CLEAN SCREEN
*
* Description : Pulisce il display     
* Arguments   : none
*         
* Returns     : none
* Note        : Da fare!
*************************************************************************************************
*/

void LCD_CLS(unsigned short int colore)
{
	unsigned short int i,j;
    SSD1289_writeResgiter( 0x004E, 0 );
    SSD1289_writeResgiter( 0x004F, 0 );
    SSD1289_sendCommand(0x0022); //set the RAM register for writing
    for(i=0; i<320; i++){
        for (j=0; j<240; j++)
            SSD1289_sendData(colore);
    }
}

/*
*************************************************************************************************
*                                     STAMPA UN PIXEL
*
* Description : Stampa un pixel     
* Arguments   : none
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_Pixel(unsigned short int x , unsigned short int y , unsigned short int colore_unico)
{
   // checks whether the pixel is inside the display
   if ((x>GCLCDX) || (y>GCLCDY));
   else
   {
		SSD1289_writeResgiter( 0x004E, x );
		SSD1289_writeResgiter( 0x004F, y );
		SSD1289_sendCommand(0x0022); //set the RAM register for writing
		SSD1289_sendData(colore_unico);
   }
}

/*
*************************************************************************************************
*                                     DISEGNA UNA LINEA
*
* Description : Disegna una linea     
* Arguments   : draw_line(X inizio, Y inizio, X fine, Y fine, Colore);
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void draw_line(unsigned short int x1 , unsigned short int y1 ,unsigned short int x2 , unsigned short int y2 , unsigned short int colore)
{
   short int        dy, dx;
   signed char  addx=1, addy=1;
   signed short int P, diff;

   short int i=0;
   dx = abs((signed short int)(x2 - x1));
   dy = abs((signed short int)(y2 - y1));

   if(x1 > x2)
      addx = -1;
   if(y1 > y2)
      addy = -1;

   if(dx >= dy)
   {
      dy *= 2;
      P = dy - dx;
      diff = P - dx;

      for(; i<=dx; ++i)
      {
         LCD_Pixel(x1, y1, colore);

         if(P < 0)
         {
            P  += dy;
            x1 += addx;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
   else
   {
      dx *= 2;
      P = dx - dy;
      diff = P - dy;

      for(; i<=dy; ++i)
      {
         LCD_Pixel(x1, y1, colore);

         if(P < 0)
         {
            P  += dx;
            y1 += addy;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
}

/*
*************************************************************************************************
*                                     STAMPA UN QUADRATO
*
* Description : Stampa un quadrato     
* Arguments   : LCD_Rect(X inizio, Y inizio, X fine, Y fine, PIENO/VUOTO, COLORE);
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_Rect(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned char plein, unsigned short int colore)
{
   unsigned char i,TempX;
   unsigned short int j,TempY;
   // Tester si x1 et y1 sont inferieures a x2 et y2
   if (x1 > x2)
      {
         TempX = x2;
         x2 = x1;
         x1 = TempX;
      }
   if (y1 > y2)
      {
         TempY = y2;
         y2 = y1;
         y1 = TempY;
      }
   if(plein)
      for(i=x1; i<=x2; i++)
         for(j=y1; j<=y2; j++)
            LCD_Pixel(i , j , colore);
   else
      {
         draw_line(x1, y1, x2, y1, colore);
         draw_line(x1, y2, x2, y2, colore);
         draw_line(x1, y1, x1, y2, colore);
         draw_line(x2, y1, x2, y2, colore);
      }
}

/*
*************************************************************************************************
*                                     STAMPA UN QUADRATO PIENO
*
* Description : Stampa un quadrato     
* Arguments   : LCD_Fillscreen(X inizio, Y inizio, X fine, Y fine, COLORE);
*         
* Returns     : none
* Note        : Da testare
*************************************************************************************************
*/

void LCD_Fillscreen(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2,unsigned short int colore)
{
   short int i;

   for(i=y1; i<y2; i++)
   {
      draw_line(x1 , i , x2 , i , colore);
   }
}

/*
*************************************************************************************************
*                                     STAMPA UN CERCHIO
*
* Description : Stampa un cerchio     
* Arguments   : LCD_Cercle(X, Y, RAGGIO, PIENO/VUOTO(1,0), COLORE);
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_Cercle(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned char plein, unsigned short int colore)
{
	signed short int a, b, P;
	a = 0;
	b = rayon;
	P = 1 - rayon;
	do
	{
		if(plein)
		{
            ///Prototipo per ottimizzazione in velocità
            LCD_FastRect(x-a, y+b, x+a, y+b, colore);
			LCD_FastRect(x-a, y-b, x+a, y-b, colore);
			LCD_FastRect(x-b, y+a, x+b, y+a, colore);
			LCD_FastRect(x-b, y-a, x+b, y-a, colore);
		}
		else
		{
			LCD_Pixel(a+x, b+y, colore);
			LCD_Pixel(b+x, a+y, colore);
			LCD_Pixel(x-a, b+y, colore);
			LCD_Pixel(x-b, a+y, colore);
			LCD_Pixel(b+x, y-a, colore);
			LCD_Pixel(a+x, y-b, colore);
			LCD_Pixel(x-a, y-b, colore);
			LCD_Pixel(x-b, y-a, colore);
		}
		if(P < 0) P+= 3 + 2*a++;
		else P+= 5 + 2*(a++ - b--);
	} while(a <= b);
}

/*
*************************************************************************************************
*                                     STAMPA CARATTERI
*
* Description : Stampa un carattere, stringa     
* Arguments   : LCD_Text57(X, Y, ARRAY, MOLTIPLICATORE, COLORE, COLORE DI SFONDO(NONE-> nessun colore));
*         
* Returns     : none
* Note        : Esempio di utilizzo
*
*				char TextBuffer[20];
*				sprintf(TextBuffer,"Stringa da stampare");
*        		LCD_Text57(12,63,TextBuffer,2,GREEN,RED);
*
*				unsigned short int var1,var2;
*				sprintf(TextBuffer,"X:%04d Y:%04d",var1,var2);	// %04 -> obbliga a stampare 4 cifre(compresi zeri)
*				LCD_Text57(1,2,TextBuffer,2,RED,GREEN);
*
*
*************************************************************************************************
*/

void LCD_Text57(unsigned char x, unsigned short int y, char* textptr, char Dimension, unsigned short int colore, unsigned short int BackColor)
{
   unsigned char j, k, l, m;
   unsigned char pixelData[5];
   Xcursor=x;
   Ycursor=y;


   do{
       if(*textptr=='\0') {Xcursor += 5*Dimension + 1; goto SALTO;}
      if(*textptr < 'S')
         memcpy(pixelData, FONT[*textptr - ' '], 5);
      else if(*textptr <= '~') 
         memcpy(pixelData, FONT2[*textptr - 'S'], 5);
      else
         memcpy(pixelData, FONT[0], 5);

       
      switch(*textptr)
      {
         case '\n'://aumenta il cursore di una riga
            Ycursor += 7*Dimension + 1;
            goto SALTO;
            continue;
         case '\r':
            Xcursor = 2;///setta a posizione zero il cursore(sinistra)
            goto SALTO;
            continue;
      }

      if(Xcursor+5*Dimension > X_END)
      {
         Xcursor = 2;
         Ycursor += 7*Dimension + 1;
      }
      for(j=0; j<5; ++j, Xcursor+=Dimension)
      {
         for(k=0; k < 7; ++k)                                  
         {
            //if(bit_test(pixelData[j], k))                         
             //if((pixelData[j] & (1<<k)) != 0)
             if(BitTest(pixelData[j], k))
            {
               for(l=0; l < Dimension; ++l)                           
               {
                  for(m=0; m < Dimension; ++m)
                  {
                     LCD_Pixel(Xcursor+m, Ycursor+k*Dimension+l, colore);
                  }
               }
            }
            else if (BackColor != NONE)
            {
               for(l=0; l < Dimension; ++l) 
               {                          
                  for(m=0; m < Dimension; ++m)
                  {
                     LCD_Pixel(Xcursor+m, Ycursor+k*Dimension+l, BackColor);
                  }
               }
            }
         }
      }
      Xcursor++;
      SALTO:
      textptr++;
   }while(*textptr != 0);
}

/*
*************************************************************************************************
*                                     STAMPA UNA STRINGA
*
* Description : Stampa una stringa     
* Arguments   : fonts(X, Y, ARRAY, COLORE)
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void fonts(unsigned char x, unsigned short int y, char *c, unsigned short int colore){
   unsigned short int index=0x0000;
   char i=0x00,b=0x00,data=0x00;
   do{
		index = 5 * (unsigned char)(*c - 32);
		for(i=0; i<5; i++){
			data= lcd_font[index++];
			for(b=0; b<8; b++){
				if(data & 0x01) {
					LCD_Pixel(x,++y,colore);
				}
				else{
					y++;
				}
				data >>= 1;
			}
			y=y-8;
			x++;
		}
		x++;
		c++;
		if(x>230) {y=y+10; x=5;}
	}while(*c != 0);
}

/*
*************************************************************************************************
*                                     STAMPA UN QUADRATO PIENO
*
* Description : Stampa un QUADRATO  
* Arguments   : fonts(X, Y, ARRAY, COLORE)
*         
* Returns     : none
* Note        : Utilizza l'auto incremento dell'LCD, ottimizzato per tempi brevi.
*************************************************************************************************
*/

void LCD_FastRect(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned short int colore)
{	
	unsigned short int i,j,k;
        
    if(x1<x2){
        SSD1289_writeResgiter( 0x004E, x1 );       
    }
    else     SSD1289_writeResgiter( 0x004E, x2 );
    j=abs((signed short int)(x2 - x1));    
    SSD1289_writeResgiter( 0x004F, y1 );
    SSD1289_sendCommand(0x0022); //set the RAM register for writing
	
    for(i=y1; i<=y2; i++){
        //for (j=x1; j<=x2; j++) SSD1289_sendData(colore);
        for (k=0; k<=j; k++) SSD1289_sendData(colore);
		y1++;
		//SSD1289_writeResgiter( 0x004E, x1 );
		SSD1289_writeResgiter( 0x004F, y1 );
		SSD1289_sendCommand(0x0022); //set the RAM register for writing		
    }
}

/*
*************************************************************************************************
*                                     SCROLL DISPLAY ON
*
* Description : none
* Arguments   : none
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_ScrollOn(void)
{
    SSD1289_writeResgiter( 0x0007, 0x0233 );
}

/*
*************************************************************************************************
*                                     SCROLL DISPLAY OFF
*
* Description : none
* Arguments   : none
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_ScrollOff(void)
{
    SSD1289_writeResgiter( 0x0007, 0x0033 );
}

/*
*************************************************************************************************
*                                     SCROLL DISPLAY AREA
*
* Description : none
* Arguments   : none
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_ScrollArea(unsigned short int VL1, unsigned short int VL2)
{
    SSD1289_writeResgiter( 0x0041, VL1 );
    SSD1289_writeResgiter( 0x0042, VL2 );
}

/*
*************************************************************************************************
*                                     STAMPA TESTO LANDSCAPE
*
* Description : Stampa testo in orizzontale, ottiizzato per il terminale
* Arguments   : none
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_Text57Land(unsigned char x, unsigned short int y, char* textptr, char Dimension, unsigned short int colore, unsigned short int BackColor)
{
   unsigned char j, k, l, m;
   unsigned char pixelData[5];

   Xcursor=x;
   Ycursor=y;
   do{
      if(*textptr < 'S') // controlla se il carattere è sul primo array
         memcpy(pixelData, FONT[*textptr - ' '], 5);
      else if(*textptr <= '~') // controlla se il carattere è sul secondo array
         memcpy(pixelData, FONT2[*textptr - 'S'], 5);
      else
         memcpy(pixelData, FONT[0], 5);   // se non trova il carattere setta uno spazio, ' '.

      switch(*textptr)
      {
         case '\n':
            Xcursor -= 7*Dimension + 1;
            goto SALTO2;
            continue;
         case '\r':
            Ycursor = 2;
            goto SALTO2;
            continue;
      }

      if(Ycursor+5*Dimension > 319) // se cursore maggiore di 320 incrementa riga
      {
         Ycursor = 2;
         Xcursor -= 7*Dimension + 1;
      }
      for(j=0; j<5; ++j, Ycursor+=Dimension)
      {
         for(k=0; k < 7; ++k)                                       
         {
            //if(bit_test(pixelData[j], k))                          
             //if((pixelData[j] & (1<<k)) != 0)
             if(BitTest(pixelData[j], k))
            {
               for(l=0; l < Dimension; ++l)                            
               {
                  for(m=0; m < Dimension; ++m)
                  {
                     LCD_Pixel(Xcursor-k*Dimension+l,Ycursor+m, colore);
                  }
               }
            }
            else if (BackColor != NONE)
            {
               for(l=0; l < Dimension; ++l)                            
               {                                                    
                  for(m=0; m < Dimension; ++m)
                  {
                     LCD_Pixel( Xcursor-k*Dimension+l, Ycursor+m, BackColor);
                  }
               }
            }
         }
      }
      Ycursor++;
      SALTO2:
      textptr++;
   }while(*textptr != 0);
}

/*
*************************************************************************************************
*                                     STAMPA UN QUADRATO CON BACKGROUND
*
* Description : Stampa un quadrato
* Arguments   : LCD_RectWithBackGround(X inizio, Y inizio, X fine, Y fine, R, G, B, OPACITà);
*
* Returns     : none
* Note        : Opacità -> valore tra 0 e 1.
*************************************************************************************************
*/
    
void LCD_RectWithBackGround(unsigned char x1, unsigned short int y1, unsigned char x2, unsigned short int y2, unsigned char R, unsigned char G, unsigned char B, float Opacity)
{
    unsigned short int counti=0,countb=0;
    unsigned short int ColorRead=0,colorreadback=0;
    float R1=0,G1=0,B1=0,R2=0,G2=0,B2=0,R3=0,G3=0,B3=0;
    unsigned char R5=0,G5=0,B5=0,R8=0,G8=0,B8=0;

    ///Inizia ciclo
    for(counti=y1; counti<y2; counti++)
    {
        for(countb=x1; countb<x2; countb++)
        {
            ///Read color from display
            colorreadback=SSD1289_ReadData(countb,counti);

            ///Convert rgb565 to rgb888
            R5=(colorreadback & 0xF800) >> 11;
            G5=(colorreadback & 0x07E0) >> 5;
            B5=colorreadback & 0x001F;
            R8 = (unsigned char) floor( (float)R5 * 255.0 / 31.0 + 0.5);
            G8 = (unsigned char) floor( (float)G5 * 255.0 / 63.0 + 0.5);
            B8 = (unsigned char) floor( (float)B5 * 255.0 / 31.0 + 0.5);

            //Background
            R2=(float)R8/255.0;
            G2=(float)G8/255.0;
            B2=(float)B8/255.0;

            //Upper element
            R1=(float)R/255.0;
            G1=(float)G/255.0;
            B1=(float)B/255.0;

            //Multiply method
            R3=R2*R1;
            G3=G2*G1;
            B3=B1*B2;

            ///Opacità 70%
            //R3=Opacity*R3+(1.0-Opacity)*R2;
            //G3=Opacity*G3+(1.0-Opacity)*G2;
            //B3=Opacity*B3+(1.0-Opacity)*B2;

            //Prova
            R3=Opacity*R1+(1.0-Opacity)*R3;
            G3=Opacity*G1+(1.0-Opacity)*G3;
            B3=Opacity*B1+(1.0-Opacity)*B3;

            //ritorna valori tra 0 e 255
            R8=(unsigned char)(R3*255.0);
            G8=(unsigned char)(G3*255.0);
            B8=(unsigned char)(B3*255.0);

            //Converte in RGB565
            ColorRead=RGB16(R8, G8, B8);
            
            //Stampa pixel
            LCD_Pixel(countb,counti,(unsigned short int)ColorRead);
        }
    }
}

/*
*************************************************************************************************
*                                     Legge UN CERCHIO
*
* Description : Stampa un cerchio     
* Arguments   : LCD_Cercle(X, Y, RAGGIO, PIENO/VUOTO(1,0), COLORE);
*         
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_CercleRead(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned short int * colore)
{
    signed short int a, b, P;
    unsigned short int i=0;
    unsigned short int * tempcolore = (unsigned short int *) colore;//NOn so cosa fa precisamente ma serve per leggere/modificare l'array passato...
    a = 0;
    b = rayon;
    P = 1 - rayon;
    do
    {
        tempcolore[i]=LCD_PixelRead(a+x, b+y);
        i++;
	tempcolore[i]=LCD_PixelRead(b+x, a+y);
        i++;
	tempcolore[i]=LCD_PixelRead(x-a, b+y);
        i++;
	tempcolore[i]=LCD_PixelRead(x-b, a+y);
        i++;
	tempcolore[i]=LCD_PixelRead(b+x, y-a);
        i++;
	tempcolore[i]=LCD_PixelRead(a+x, y-b);
        i++;
	tempcolore[i]=LCD_PixelRead(x-a, y-b);
        i++;
	tempcolore[i]=LCD_PixelRead(x-b, y-a);
        i++;
	if(P < 0) P+= 3 + 2*a++;
	else P+= 5 + 2*(a++ - b--);
    } while(a <= b);
}

/*
*************************************************************************************************
*                                     LEGGE UN PIXEL
*
* Description : Legge un pixel dal display
* Arguments   : Color16=LCD_PixelRead(X,Y);
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

unsigned short int LCD_PixelRead(unsigned short int x, unsigned short int y)
{
    unsigned short int colore;
    colore=SSD1289_ReadData(x,y);
    return colore;
}

/*
*************************************************************************************************
*                                     STAMPA UN CERCHIO
*
* Description : Stampa un cerchio
* Arguments   : LCD_Cercle(X, Y, RAGGIO, PIENO/VUOTO(1,0), COLORE);
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/

void LCD_CercleBackGround(unsigned char x, unsigned short int y, unsigned short int rayon, unsigned short int * colore)
{
    signed short int a, b, P;
    unsigned short int i=0;
    //unsigned short int * tempcolore = (unsigned short int *) colore;//NOn so cosa fa precisamente ma serve per leggere/modificare l'array passato...

    a = 0;
    b = rayon;
    P = 1 - rayon;
    do
    {
        LCD_Pixel(a+x, b+y, colore[i]);
        i++;
	LCD_Pixel(b+x, a+y, colore[i]);
        i++;
	LCD_Pixel(x-a, b+y, colore[i]);
        i++;
	LCD_Pixel(x-b, a+y, colore[i]);
        i++;
	LCD_Pixel(b+x, y-a, colore[i]);
        i++;
	LCD_Pixel(a+x, y-b, colore[i]);
        i++;
	LCD_Pixel(x-a, y-b, colore[i]);
        i++;
	LCD_Pixel(x-b, y-a, colore[i]);
        i++;
        if(P < 0) P+= 3 + 2*a++;
	else P+= 5 + 2*(a++ - b--);
    } while(a <= b);
}

/*
*************************************************************************************************
*                                     ALLINEAMENTO TESTO
*
* Description : Stampa un cerchio
* Arguments   : Valore=CenterX(X, moltiplicatore, ALIGNMENT_CENTER/ALIGNMENT_RIGHT, (unsigned short int * )&TextBuffer[0]));
*
* Returns     : none
* Note        : none
*************************************************************************************************
*/
unsigned short int CenterX(unsigned short int x, unsigned char mul, char Position, unsigned short int * Testo)
{
    unsigned char * temptesto = (unsigned char *) Testo;
    unsigned char i=0;

    while(TRUE)
    {
        if(temptesto[i]==0x00) break;
        i++;
    }

    if(Position==1)///center position
    {
        x=x-(5*i*mul+i)/2;
    }

    if(Position==2)///Left position
    {
        x=x;
    }

    if(Position==3)///right position(posizione - lunghezza parola(allineamento a destra))
    {
        x=x-(5*i*mul+i);
    }

    if(Position==4)///Ritorna lunghezza della frase in pixel + x
    {
        x=x+(5*i*mul+i);
    }
    return x;
}

char atobcd(char* bcds)
{
  char pbcd=0,n;
  for(n=0; bcds[n]>='0'&& bcds[n]<='9'; n++){
                                   pbcd= (pbcd<<4)+(bcds[n]-0x30);}
  return (pbcd);
}