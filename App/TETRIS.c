#include "TETRIS.h"

//#include <Hardware_IO.c>
//#include <STDLIBRAND.h>
_Bool InitBlock=1,Exit=0;
unsigned char Block=0, Rotation=0, HLine=0,VLine=0, Livello=20,PreBlock=0; //Livello=velocità tempo.
unsigned short int Score=0;
unsigned char blocchi [7 /*kind */ ][4 /* rotation */ ][5 /* horizontal blocks */ ][5 /* vertical blocks */ ] =
{
// Square
{
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 1, 0},
{0, 0, 1, 1, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 1, 0},
{0, 0, 1, 1, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 1, 0},
{0, 0, 1, 1, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 1, 1, 0},
{0, 0, 1, 1, 0},
{0, 0, 0, 0, 0}
}
},

// I
{
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 2, 2, 2, 2},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{2, 2, 2, 2, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 2, 0, 0},
{0, 0, 0, 0, 0}
}
}
,
// L
{
{
{0, 0, 0, 0, 0},
{0, 0, 3, 0, 0},
{0, 0, 3, 0, 0},
{0, 0, 3, 3, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 3, 3, 3, 0},
{0, 3, 0, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 3, 3, 0, 0},
{0, 0, 3, 0, 0},
{0, 0, 3, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 3, 0},
{0, 3, 3, 3, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
}
},
// L mirrored
{
{
{0, 0, 0, 0, 0},
{0, 0, 4, 0, 0},
{0, 0, 4, 0, 0},
{0, 4, 4, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 4, 0, 0, 0},
{0, 4, 4, 4, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 4, 4, 0},
{0, 0, 4, 0, 0},
{0, 0, 4, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 4, 4, 4, 0},
{0, 0, 0, 4, 0},
{0, 0, 0, 0, 0}
}
},
// N
{
{
{0, 0, 0, 0, 0},
{0, 0, 0, 5, 0},
{0, 0, 5, 5, 0},
{0, 0, 5, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 5, 5, 0, 0},
{0, 0, 5, 5, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 5, 0, 0},
{0, 5, 5, 0, 0},
{0, 5, 0, 0, 0},
{0, 0, 0, 0, 0}
},

{
{0, 0, 0, 0, 0},
{0, 5, 5, 0, 0},
{0, 0, 5, 5, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
}
},
// N mirrored
{
{
{0, 0, 0, 0, 0},
{0, 0, 6, 0, 0},
{0, 0, 6, 6, 0},
{0, 0, 0, 6, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 6, 6, 0},
{0, 6, 6, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 6, 0, 0, 0},
{0, 6, 6, 0, 0},
{0, 0, 6, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 6, 6, 0},
{0, 6, 6, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
}
},
// T
{
{
{0, 0, 0, 0, 0},
{0, 0, 7, 0, 0},
{0, 0, 7, 7, 0},
{0, 0, 7, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 7, 7, 7, 0},
{0, 0, 7, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 7, 0, 0},
{0, 7, 7, 0, 0},
{0, 0, 7, 0, 0},
{0, 0, 0, 0, 0}
},
{
{0, 0, 0, 0, 0},
{0, 0, 7, 0, 0},
{0, 7, 7, 7, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
}
}
};


int ArrayBox[19][16]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,0,4,4,4,0,0,1,1,1,1,0},
{0,2,2,3,3,0,4,5,0,0,0,7,7,4,4,0},
{0,0,2,3,0,0,6,5,5,0,0,0,7,4,0,0},
{0,0,2,3,0,0,6,5,0,0,0,0,7,4,0,0},
{0,0,4,4,0,0,6,3,0,0,0,0,6,6,0,0},
{0,0,4,4,0,0,6,3,3,3,0,0,6,6,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,5,7,0,0,0,0,2,2,0,0,0,0,3,3,0},
{0,5,7,7,0,0,0,2,2,0,0,0,4,3,0,0},
{0,5,5,7,0,0,0,0,0,0,0,0,4,4,4,0},
{0,3,3,1,1,0,8,8,7,7,0,0,4,4,4,0},
{0,3,0,0,1,0,8,2,2,7,0,0,0,3,4,0},
{0,3,0,0,1,0,8,2,2,7,0,3,3,3,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
unsigned char TimerOverflow=0, Tempo=0, Collisione=0, comp=0;/*
TimerOverflow=0; Tempo scaduto (incrementa posizione verticale)
TimerOverflow=1; Pulsante UP (Rotazione)
TimerOverflow=2; Pulsante DX (Spostamento  a destra)
TimerOverflow=3; Pulsante SX (Spostamento a sinistra)
TimerOverflow=4; Pulsante DOWN ( Incrementa velocità scorrimento)
*/
#define Down 4
#define Up 3
#define Left 1
#define Right 2
#define OK 5
#define EXIT 6
void TetrisApp(void){
   Eventi();
   RefreshLine();
   DrawNewArray();
}

void Eventi(void){
    char TouchReturned=0;

   do{

      TouchReturned=ReadTouch();
      if(EXIT==TouchReturned) Exit=1;

      if(Down==TouchReturned){
         DelayMs(10);
         TimerOverflow=0;
         break;
      }
      if(Left==TouchReturned){
         TimerOverflow=3;
         for(comp=0; comp<30; comp++){
            DelayUs(5);
            Tempo++;
            if (Tempo==Livello) {
               TimerOverflow=0; 
               break;
            }
         }
         break;
      }
      if(Right==TouchReturned){
         TimerOverflow=2;
         for(comp=0; comp<30; comp++){
            DelayUs(5);
            Tempo++;
            if (Tempo==Livello) {
               TimerOverflow=0; 
               break;
            }
         }
         break;
      }
      if(Up==TouchReturned){
         TimerOverflow=1;
         for(comp=0; comp<30; comp++){
            DelayMs(1);
            Tempo++;
            if (Tempo==Livello) {
               TimerOverflow=0; 
               break;
            }
         }
         break;
      }   
      DelayMs(1);
      Tempo++;
      
   }while(Tempo<Livello);
   
   if(Tempo==Livello) Tempo=0;
    
 
}

void ClearArray(void){
unsigned char ii,i;
for(ii=0; ii<5; ii++){
         for(i=0; i<5; i++){
            if(blocchi[Block][Rotation][ii][i]!=0) ArrayBox[HLine+ii][VLine+i]=0;//Azzera l'array dove è presente una cifra su blocchi(effetto sovrapposizione)
         }
    }
}

void CtrlArray(void){
unsigned char ii, i;
      for(ii=0; ii<5; ii++){
         for(i=0; i<5; i++){
            if(blocchi[Block][Rotation][ii][i]!=0){ 
               if(ArrayBox[HLine+ii][VLine+i]!=0) Collisione=1;//In modalità sovrapposizione controlla se ci sono "collisioni"
            }
         }
      }
}

void UpdateArray(void){
unsigned char ii, i;
         for(ii=0; ii<5; ii++){
            for(i=0; i<5; i++){
               if(blocchi[Block][Rotation][ii][i]!=0){
                  ArrayBox[HLine+ii][VLine+i]=blocchi[Block][Rotation][ii][i];
               }
             }
         }
}
void RefreshLine(void){
  
   if(InitBlock==1) {NewBlock(); DrawRandNext();}
   else{
      switch(TimerOverflow){
         case 1:
            ClearArray();
            Rotation++;
            if(Rotation==4)Rotation=0;
            CtrlArray();
            if(Collisione==1){
               Rotation--;
               if(Rotation==255) Rotation=3;
            }
            UpdateArray();
            break;
         case 2:
            ClearArray();
            VLine++;
            CtrlArray();
            if(Collisione==1) { VLine--;} //Decrementa la linea 
            UpdateArray();
            break;
         case 3:
            ClearArray();
            VLine--;
            CtrlArray();
            if(Collisione==1) { VLine++;} //Decrementa la linea 
            UpdateArray();
            break;
         case 0:
            ClearArray();
            HLine++;
            CtrlArray();
            if(Collisione==1) HLine--;   
            UpdateArray();
         if(Collisione==1) {ClearLine();}
            break;
      }
   }
   Collisione=0;
   TimerOverflow=0;
}

void ClearLine(void){
_Bool RigaNC=1, GameOver=0;
unsigned char Riga=16, V=0,a=14,i=0;
unsigned char ArrayTemp[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char ScoreTxt[10];
do{
  RigaNC=0;
  
   for(V=2; V<14; V++){
      if(ArrayBox[Riga][V]!=0) { RigaNC=1; continue;}
     else { Riga--; RigaNC=0; break;}
   }     
   if(RigaNC==1){
   a=Riga-1;
   Score=Score+10;
   Livello=Livello-0x0a;   ///Decrementa tempo ogni punto.
      for(i=Riga; i>1; i--){
         for(V=2; V<14; V++){
         ArrayTemp[V]=ArrayBox[a][V];
            ArrayBox[i][V]=ArrayTemp[V];
         }
       a--;
      }
     
   }  
     
   if(RigaNC==0){
   RigaNC=1;
   } 
      //Riga--;
     
       
      if(Riga==3){
        RigaNC=0;
         for(V=2; V<14; V++){
            if(ArrayBox[3][V]!=0) {GameOver=1; /*gotoxy(1,1);*/}
         }
      }
     
   } while(RigaNC==1);
   
   //quadrato(45,115,5,13 WHITE);
   LCD_Rect(45,5,115,13,1,WHITE);
   
   //gotoxy(45,5);
   //font_color(BLACK);
  // printf(fonts,"%ld",Score);
  sprintf(ScoreTxt,"%03ld",Score);
  LCD_Text57(200,30,ScoreTxt,2,BLACK,WHITE);
  
  //printf(fonts," level:%x",(unsigned int8)Livello);
if(GameOver==1) GameOverFun();
else {InitBlock=1;}
   //Azzera le linee complete (se ci sono), aggiorna array.
   //Salta alla funzione di game over.


}

void NewBlock(void){
   unsigned char i,ii;
   
   //RandomNumber  
   unsigned char HBlock[7]={0,0,0,0,0,0,0};//DA sistemare
   unsigned char VBlock[7]={5,5,5,6,5,5,5};//Da sistemare
   Rotation=0;
   Block=PreBlock;
   do{
   PreBlock=rand()>>8;
   }while((PreBlock>=7)||(PreBlock==Block));

   
   
   //Block++;

   //if(Block==7)Block=0;
   //Block=0;
   
   //Recupero linea di partenza
   HLine=HBlock[Block];
   VLine=VBlock[Block];
   
   for(ii=0; ii<5; ii++){
      for(i=0; i<5; i++){
         if(blocchi[Block][Rotation][ii][i]!=0){
            ArrayBox[HLine+ii][VLine+i]=blocchi[Block][Rotation][ii][i];
         }
       }
   }
   //Inserisci nell'array un nuovo blocco (random) inizializzato alla corretta posizione.
   InitBlock=0;
}

void  DrawNewArray(void){
unsigned char i,ii;
//unsigned char DrawXin[15]={0,30,36,42,48,54,60,66,72,78,84,90,96,102,108};
//unsigned char DrawXfin[15]={0,34,40,46,52,58,64,70,76,82,88,94,100,106,112};
//unsigned char DrawYin[18]={20,26,32,38,44,50,56,62,68,74,80,86,92,98,104,110,116,122};
//unsigned char DrawYfin[18]={24,30,36,42,48,54,60,66,72,78,84,90,96,102,108,114,120,126};

unsigned char DrawXin[15]={0,10,22,34,46,58,70,82,94,106,118,130,142,154,166};
unsigned char DrawXfin[15]={0,20,32,44,56,68,80,92,104,116,128,140,152,164,176};
unsigned short int DrawYin[18]={10,22,34,46,58,70,82,94,106,118,130,142,154,166,178,190,202,214};
unsigned short int DrawYfin[18]={20,32,44,56,68,80,92,104,116,128,140,152,164,176,188,200,212,224};

for(ii=0; ii<18; ii++){
    for(i=1; i<15; i++){
      /*if(ArrayBox[ii][i]!=0){
         quadrato(DrawXin[i],DrawXfin[i],DrawYin[ii],DrawYfin[ii], BLUE);
      }
      else{
         quadrato(DrawXin[i],DrawXfin[i],DrawYin[ii],DrawYfin[ii], WHITE);
      }*/
     switch(ArrayBox[ii][i]){
     case 1:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], BLUE);
      break;
     case 2:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], RED);
      break;
     case 3:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], GREEN);
      break;
     case 4:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], PURPLE);
      break;
     case 5:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], ORANGE);
      break;
     case 6:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], YELLOW);
      break;
     case 7:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], CIANO);
      break;
	  case 8:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], GRAY);//Cornice
      break;
     default:
      LCD_FastRect(DrawXin[i], DrawYin[ii], DrawXfin[i], DrawYfin[ii], WHITE);
      break;
     }     
    }
}   
   //Stampa a schermo l'array!
}

void GameOverFun(void){
unsigned char ii,i;
char TetrisTxt[15];
   //gotoxy(45,65);
   //font_color(WHITE);
   //quadrato(43,99,63,74,BLACK);
   //printf(fonts,"Game Over!");
     strcpy(TetrisTxt,"Game Over!");
  LCD_Text57(45,105,TetrisTxt,2,BLACK,NONE);
   
   
   while (ReadTouch()!=OK)
   ;
   LCD_Rect(45,105,165,118,1,WHITE);
   InitBlock=1;
   Livello=0xff;
    /*for(ii=0; ii<17; ii++){
      for(i=2; i<14; i++){      
            ArrayBox[ii][i]=0;        
       }
   }
   quadrato(43,99,63,74,WHITE);*/
	for(ii=0; ii<17; ii++){
      for(i=1; i<15; i++){      
            ArrayBox[ii][i]=8;        
       }
	   DrawNewArray();
	   DelayMs(5);
	   for(i=2; i<14; i++){      
            ArrayBox[ii][i]=0;        
       }
   }  
}

unsigned char ReadTouch(){	
	if(PORTDbits.RD14==0){
		unsigned short int x,y;
		read();
		x=getX();
		y=getY();
                
		x=(unsigned short int)((((float)6.01/(float)233.01)*(float)x)+(float)x);
                y=(unsigned short int)((((float)10.01/(float)313.01)*(float)y)+(float)y);

		if(((60<=x)&&(x<=80))&&((285<=y)&&(y<=305))) return 1; //Left
		if(((110<=x)&&(x<=130))&&((285<=y)&&(y<=305))) return 2; //Right
                if(((85<=x)&&(x<=105))&&((285<=y)&&(y<=305))) return 4; //Down
                if(((160<=x)&&(x<=180))&&((285<=y)&&(y<=305))) return 5;//OK
                if(((85<=x)&&(x<=105))&&((260<=y)&&(y<=280))) return 3;//Up
                if(((190<=x)&&(x<=239))&&((285<=y)&&(y<=305))) return 6;//OK
	}
        return 0;
}

void DrawRandNext(void)
{
    unsigned char PreBlockX[5]={178,190,202,214,226};
    unsigned char PreBlockY[5]={70,82,94,106,118};
    unsigned char i=0,ii=0;

    for(ii=0; ii<5; ii++)
    {
        for(i=0; i<5; i++)
        {
            switch(blocchi[PreBlock][0][ii][i])
            {
                case 1:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, BLUE);
                    break;
                case 2:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, RED);
                    break;
                case 3:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, GREEN);
                    break;
                case 4:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, PURPLE);
                    break;
                case 5:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, ORANGE);
                    break;
                case 6:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, YELLOW);
                    break;
                case 7:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, CIANO);
                    break;
                case 8:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, GRAY);//Cornice
                    break;
                default:
                    LCD_FastRect(PreBlockX[i], PreBlockY[ii], PreBlockX[i]+10, PreBlockY[ii]+10, WHITE);
                    break;
            }
        }
    }
}

void Tetris(void)
{
    char TextBuffer[20];
    LCD_CLS(WHITE);

    LCD_FastRect(60,285,80,305,BLUE);//left
    LCD_FastRect(85,285,105,305,GREEN);//Down
    LCD_FastRect(110,285,130,305,RED);//right
    LCD_FastRect(85,260,105,280,PURPLE);//up
    LCD_FastRect(160,285,180,305,YELLOW);//OK

    sprintf(TextBuffer,"OK");
    LCD_Text57(160,289,TextBuffer,2,BLACK,NONE);

    sprintf(TextBuffer,">");
    LCD_Text57(115,289,TextBuffer,2,BLACK,NONE);

    sprintf(TextBuffer,"<");
    LCD_Text57(65,289,TextBuffer,2,BLACK,NONE);

    sprintf(TextBuffer,"SCORE");
    LCD_Text57(180,10,TextBuffer,2,BLACK,NONE);

    sprintf(TextBuffer,"Esci");
    LCD_Text57(190,289,TextBuffer,2,BLACK,NONE);
    /*LCD_Rect(60,295,70,305,1,BLUE);
    LCD_Rect(75,295,85,305,1,GREEN);
    LCD_Rect(90,295,100,305,1,RED);
    LCD_Rect(105,295,115,305,1,PURPLE);
    LCD_Rect(75,280,85,290,1,YELLOW);
     */

    DrawNewArray();
    while (ReadTouch()!=OK);
    GameOverFun();
    while(TRUE)
    {
        TetrisApp();
        if(Exit==1) {Exit=0; break;}
        //if(PORTDbits.RD3==0) break;
    }
}