void DrawBmp( unsigned char x, unsigned short int y, unsigned short int * BmpName, _Bool ScrollMode);
void DrawIconFile(unsigned char x, unsigned short int y, unsigned char nlist, FileList * ListToLoad);
void ListDraw(unsigned char Listpos, unsigned char Updown, unsigned char page, FileList * ListToLoad, unsigned short int * tempdir);
void UpdateDir(FileList * ListLoaded, unsigned char ListPos, unsigned short int * actdir);
void DrawTxt(unsigned char ListPos, FileList * ListLoaded, unsigned short int * tempfile, unsigned short int * actdir);
unsigned char CheckExt(FileList * ListToLoad, unsigned char listpos);
unsigned char MmcApp(void);
short int colorconv16(char r, char g, char b);
void PhotoApp(void);
void MmcStringConvert(unsigned short int * TextToConvert, unsigned short int * TextConverted);
void MmcStringDirConvert(unsigned short int * TextToConvert, unsigned short int * TextConverted, _Bool RmDir);
void SdExplorer(void);
void PixelOutput(IMG_PIXEL_XY_RGB_888 *pPix);

#define DISP_VER_RESOLUTION 320
#define DISP_HOR_RESOLUTION 240

#define	GetMaxX() 			(DISP_HOR_RESOLUTION-1)
#define	GetMaxY() 			(DISP_VER_RESOLUTION-1)

union
{
    unsigned char a[2];
    short int b;
}number;



void DrawBmp( unsigned char x, unsigned short int y, unsigned short int * BmpName, _Bool ScrollMode){
    FSFILE * Punta;
    unsigned short int y16=0,ystart,yinc,ylenght;
    unsigned long int Area=0,ii=0;
    unsigned char BmpBuffer[64],xstart,xinc,xlenght;
    Punta = wFSfopen ((unsigned short int *)BmpName, "r");
    if(Punta==NULL){
		sprintf(BmpBuffer,"File non trovato!");
		LCD_Rect(20,20,110,40,1,WHITE);
		LCD_Text57(20,30,BmpBuffer,1,BLACK,NONE);
    }
    else{
        FSfread (BmpBuffer, 54, 1, Punta);
        number.a[0]=BmpBuffer[22];
        number.a[1]=BmpBuffer[23];         
        y16=number.b;
        Area=(unsigned short int)BmpBuffer[18]*y16;
        //left-down corner
        xstart=x;  //xstart=0;
	ystart=y;  //ystart=319;       
        xlenght=BmpBuffer[18];
	ylenght=y16;
        if((xstart==0)&&(ystart==0))
        {
            xstart=120-(xlenght/2);
            ystart=159+(y16/2);
        }
	xinc=xstart;
	yinc=ystart;
        if(ScrollMode) LCD_ScrollOn();
        for(ii=0; ii<Area; ii++){
            FSfread (BmpBuffer, 3, 1, Punta);

			LCD_Pixel(xinc, yinc,RGB16(BmpBuffer[2],BmpBuffer[1],BmpBuffer[0]));
			xinc++;
			if(xinc>(xstart+xlenght-1))
                        {
                            xinc=xstart;
                            yinc--;
                            if(ScrollMode) LCD_ScrollArea(yinc+1,0);
                        }
        }
        if(ScrollMode) LCD_ScrollOff();
        FSfclose (Punta);
    }
}

void DrawIconFile(unsigned char x, unsigned short int y, unsigned char nlist, FileList * ListToLoad){
    const	char str1[] = {'F',0x00,'o',0x00,'l',0x00,'d',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str2[] = {'F',0x00,'b',0x00,'m',0x00,'p',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str3[] = {'F',0x00,'t',0x00,'x',0x00,'t',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str4[] = {'F',0x00,'b',0x00,'l',0x00,'k',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const       char str6[] = {'\\',0x00,'\0',0x00};
    const	char str5[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    unsigned char i=0,b=0;
    wFSchdir ((unsigned short int *)&str5[0]);
    if(ListToLoad->IsDir[nlist]==1){
        DrawBmp(x,y,(unsigned short int * )&str1[0],0);
    }
    else{
        b=CheckExt(ListToLoad, nlist);
        if(b==1) DrawBmp(x,y,(unsigned short int * )&str3[0],0);
        if(b==2) DrawBmp(x,y,(unsigned short int * )&str2[0],0);
        if(b==3) DrawBmp(x,y,(unsigned short int * )&str4[0],0);
    }
     wFSchdir ((unsigned short int *)&str6[0]);
}


void ListDraw(unsigned char Listpos, unsigned char Updown, unsigned char page, FileList * ListToLoad, unsigned short int * actdir){
    unsigned char i=0,b=0,c=6,d=99;
	unsigned short int y=23;
    const	char str9[] = {'b',0x00,'a',0x00,'c',0x00,'k',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str5[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    char * temppath = (char *) actdir;//NOn so cosa fa precisamente ma serve per leggere/modificare l'array passato...
    char temp[5];
    if(Updown==1){
            //font_color(BLACK);
            if(page==2) {b=6; c=12; }
            if(page==3) {b=12; c=18; }
            for(i=b; i<c;){
                //gotoxy(20,y);
                if(i==Listpos) /*font_color(RED);*/ LCD_Text57(20,y,ListToLoad->Listaa[i],1,RED,NONE);
				else LCD_Text57(20,y,ListToLoad->Listaa[i],1,BLACK,NONE);
                //fonts(ListToLoad->Listaa[i]);
                //if(i==Listpos) font_color(BLACK);
                y=y+16;
                i++;
                if(ListToLoad->Listaa[i][0]=='\0') break;
            }
    }
    else{
        wFSchdir ((unsigned short int *)&str5[0]);
        DrawBmp(1,1,(unsigned short int * )&str9[0],0);
        //font_color(BLACK);
        if(page==2) {b=6; c=12; }
        if(page==3) {b=12; c=18; }
        for(i=b; i<c;){
            //gotoxy(20,y);         
            if(i==Listpos) /*font_color(RED);*/LCD_Text57(20,y,ListToLoad->Listaa[i],1,RED,NONE);
			else LCD_Text57(20,y,ListToLoad->Listaa[i],1,BLACK,NONE);
            //fonts(ListToLoad->Listaa[i]);
            //if(i==Listpos) font_color(BLACK);
            DrawIconFile(2, d, i, ListToLoad);/// La &??
            d=d-16;
            y=y+16;
            i++;
            if(ListToLoad->Listaa[i][0]=='\0') break;
        }
        //font_color(WHITE);
        //gotoxy(105,122);
        //sprintf(temp,"%d/3",page);
        //fonts(temp);

        //gotoxy(5,4);
        sprintf(temp,"SD0:");
		strcat(temp,temppath);
		LCD_Text57(5,4,temppath,1,BLACK,NONE);
        //fonts(temp);
        //fonts(temppath);
    }
        
}

unsigned char CheckExt(FileList * ListToLoad, unsigned char listpos){
    unsigned char i=0;

    for(i=0; i<20; i++)
    {
        if(ListToLoad->Listaa[listpos][i]==0x00) break;
    }

    if(i>=5)
        if(ListToLoad->Listaa[listpos][i-1]==0x50)
            if(ListToLoad->Listaa[listpos][i-2]==0x4d)
                if(ListToLoad->Listaa[listpos][i-3]==0x42)
                    if(ListToLoad->Listaa[listpos][i-4]==0x2e) return 2;
    if(i>=5)
        if(ListToLoad->Listaa[listpos][i-1]==0x46)
            if(ListToLoad->Listaa[listpos][i-2]==0x49)
                if(ListToLoad->Listaa[listpos][i-3]==0x47)
                    if(ListToLoad->Listaa[listpos][i-4]==0x2e) return 4;
            
    
    /*for(i=0; i<10; i++){
            if(ListToLoad->Listaa[listpos][i]==0x2e){//.
               if(ListToLoad->Listaa[listpos][i+1]==0x54){//T
                  if(ListToLoad->Listaa[listpos][i+2]==0x58){//X
                     if(ListToLoad->Listaa[listpos][i+3]==0x54){//T
                        return 1;
                     }
                  }
               }
            }
    }
    for(i=0; i<10; i++){
            if(ListToLoad->Listaa[listpos][i]==0x2e){//.
               if(ListToLoad->Listaa[listpos][i+1]==0x42){//B
                  if(ListToLoad->Listaa[listpos][i+2]==0x4d){//M
                     if(ListToLoad->Listaa[listpos][i+3]==0x50){//P
                        return 2;
                     }
                  }
               }
            }
    }*/
    return 3;
}

void UpdateDir(FileList * ListLoaded, unsigned char listpos, unsigned short int * actdir){
    unsigned char nstringdir=0, nstring=0,i=0,ii=0;
    char * temppath = (char *) actdir;//NOn so cosa fa precisamente ma serve per leggere/modificare l'array passato...
    /*quadrato(1,130,1,130,WHITE);
                    gotoxy(5,10);
                    font_color(BLACK);
                    for(i=0; i<20;){
                        sprintf(path1,"%x ",temppath[i]);
                        fonts(path1);
                        i++;
                    }
                    while(PORTDbits.RD4==1);*/
    for(i=0; i<30;){
        if((temppath[i]=='\0')&&(temppath[i+1]=='\0')){ nstringdir=i+1; break;}///Trovo numero di lettere da bypassare della cartella di lavoro
        i++;
    }
    for(i=0; i<30;){
        if(ListLoaded->Listaa[listpos][i]=='\0'){ nstring=i; break;}///Trovo numero di lettere della directory nella lista
        i++;
    }
    i=nstringdir;
    if(temppath[nstringdir-2]!='\\'){
        temppath[nstringdir]='\\';
        i=nstringdir+2;
    }
    for(ii=0; ii<nstring;){
        temppath[i]=ListLoaded->Listaa[listpos][ii];
        i=i+2;
        ii++;
    }
    temppath[i-2]='\0';

 /*   quadrato(1,130,1,130,WHITE);
                    gotoxy(5,10);
                    font_color(BLACK);
                    for(i=0; i<22;){
                        sprintf(path1,"%x ",temppath[i]);
                        fonts(path1);
                        i++;
                    }
                    while(PORTDbits.RD4==1);*/
}
/*
void DrawTxt(unsigned char ListPos, FileList * ListLoaded, unsigned short int * tempfile, unsigned short int * actdir){
    const	char str9[] = {'b',0x00,'a',0x00,'c',0x00,'k',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str5[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    const       char str6[] = {'\\',0x00,'\0',0x00};
    FSFILE * Punta;
    char TxTBuffer[50];
    unsigned char a=0;

    wFSchdir ((unsigned short int *)&str5[0]);
    DrawBmp(1,1,(unsigned short int * )&str9[0]);
    //wFSchdir ((unsigned short int *)&str6[0]);
    wFSchdir ((unsigned short int *)actdir);

    font_color(WHITE);
    gotoxy(5,4);
    fonts(ListLoaded->Listaa[ListPos]);


    Punta = wFSfopen ((unsigned short int *)tempfile, "r");
    if(Punta==NULL){
        quadrato(20,110,20,40,WHITE);
        font_color(BLACK);
        gotoxy(20,30);
        sprintf(TxTBuffer,"File non trovato!");
        fonts(TxTBuffer);
    }
    else{
        font_color(BLACK);
        gotoxy(5,20);
        FSfread (TxTBuffer, 50, 1, Punta);
        fonts(TxTBuffer);
        FSfclose (Punta);
    }  
}*/
/*
unsigned char MmcApp(void){

    char a=0x00,b=0x00;
    char path1[80];
    char str12[] = {'\\',0x00,'\0',0x00};
    char ActDir[]={'\\',0x00,'\0',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,'\0',0x00};///il punto serve per la sub-directory 2
    char str8[] = {'d',0x00,'o',0x00,'c',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    char tempnamedir[20];
    unsigned char  i=0,ListPos=0,Page=0,UpDown=0,ii=0;
    FileList ListLoaded;
    SearchRec rec;

LoadList(((unsigned short int *)&str12[0]), &rec, &ListLoaded);/// root
    strcpy(tempnamedir,"\\");
    ListDraw(0, 0, 1, &ListLoaded, (unsigned short int *)&tempnamedir[0]);
    //gotoxy(100,23);
    //font_color(BLACK);
    //sprintf(path1,"%d",ListLoaded.NFile);
    //fonts(path1);
    while(TRUE){


        ///UpDown=1; lista giu/su
        ///Page=2; carica seconda lista
        ///Page=1; carica prima lista
        if((Pulsante[1]==1)||(Pulsante[5]==0x41)){//DOWN
            ListPos++;
            UpDown=1;
            //Page=0;
            if(ListPos==6) {Page=2; UpDown=0;} ///Carica seconda pagina
            if(ListPos==12) {Page=3; UpDown=0;} ///Carica terza pagina
            if(ListPos<=ListLoaded.NFile) ListDraw(ListPos, UpDown, Page, &ListLoaded, (unsigned short int *)&tempnamedir[0]);//OK
            if(ListPos>ListLoaded.NFile) ListPos=ListLoaded.NFile;///Posizione giusta?
        }

        if((Pulsante[0]==1)||(Pulsante[5]==0x40)){
            ListPos--;
            UpDown=1;
           // Page=0;
            if(ListPos==5) {Page=1; UpDown=0;}///carica prima pagina
            if(ListPos==11) {Page=2; UpDown=0;} ///Carica seconda pagina
            if(ListPos!=255) ListDraw(ListPos, UpDown, Page, &ListLoaded, (unsigned short int *)&tempnamedir[0]);
            if(ListPos==255) ListPos=0;
        }
        if((Pulsante[4]==1)||(Pulsante[5]==0x44)){
            //if((ListPos==0)||(ListPos==6)||(ListPos==12)){
            if(ListPos==0){
                strcpy(tempnamedir,"\\");

                LoadList(((unsigned short int *)&str12[0]), &rec, &ListLoaded);///carica lista root

                Page=1;
                ListPos=0;
                ListDraw(0, 0, 1, &ListLoaded, (unsigned short int *)&tempnamedir[0]);///Stampa lista passata
                 ActDir[2]='\0';
            }
            else{
                if(ListLoaded.IsDir[ListPos]==1){
                    strcat(tempnamedir,ListLoaded.Listaa[ListPos]);
                    //char ActDir[]={'\\',0x00,'\0',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,' ',0x00,'\0',0x00};
                    UpdateDir(&ListLoaded, ListPos,((unsigned short int *)&ActDir[0]));///Aggiorna l'array della directory
                    Page=1;
                    ListPos=0;
                    LoadList(((unsigned short int *)&ActDir[0]), &rec, &ListLoaded);///carica lista passata
                    ListDraw(0, 0, 1, &ListLoaded, (unsigned short int *)&tempnamedir[0]);///Stampa lista passata
                }
                else{//Se non è una directory
                    wFSchdir ((unsigned short int *)&ActDir[0]);//Aggiorna la cartella di lavoro

                    ///Converte nel formato giusto il nome del file per essere passato a wfopen();
                    i=0;
                    ii=0;
                    for(;;){
                        str8[i]=ListLoaded.Listaa[ListPos][ii];
                        if(ListLoaded.Listaa[ListPos][ii]=='\0') break;
                        i=i+2;
                        ii++;
                    }
                    ///fine converrsione

                    b=CheckExt(&ListLoaded, ListPos);//ritorna opzione da caricare
                    if(b==2){ LCD_Rect(1,1,130,130,1,WHITE); DrawBmp(0,0,(unsigned short int * )&str8[0],0);}
                    //if(b==1){ quadrato(1,1,130,130,,1,WHITE); DrawTxt(ListPos, &ListLoaded,(unsigned short int * )&str8[0],(unsigned short int *)&ActDir[0]);}
                    //while(PORTDbits.RD4==1);
                    PushButton();
                    DelayMs(100);
                    LoadList(((unsigned short int *)&ActDir[0]), &rec, &ListLoaded);///carica lista root
                    ListDraw(ListPos, 0, Page, &ListLoaded, (unsigned short int *)&tempnamedir[0]);///Stampa lista passata

                }
            }
        }
        PushButton();
        //if(((Pulsante[2]&&Pulsante[3])==1)||(Pulsante[5]==0x5b)) break; //Esce dall'applicazione mmc OK+UP
    }
}*/

short int colorconv16(char r, char g, char b){
  unsigned  short int color16; 
  //#define RGB16(R,G,B) (((R << 8) & 0xF800) | ((G << 3) & 0x7E0) | (B >> 3))
color16 = (((unsigned short int)r<<11)+(unsigned short int)g<<5)+(unsigned char)b;

return color16;
}

void PhotoApp(void)
{
    unsigned char i=0,a=0x31,dec=0x30,cent;
    char str1[] = {'c',0x00,'o',0x00,'n',0x00,'v',0x00,'(',0x00,'0',0x00,'1',0x00,')',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    char str2[] = {'c',0x00,'o',0x00,'n',0x00,'v',0x00,'(',0x00,'1',0x00,'0',0x00,'0',0x00,')',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const	char str5[] = {'\\',0x00,'s',0x00,'e',0x00,'d',0x00,'\0',0x00};
    _Bool esci=0;
    wFSchdir ((unsigned short int *)&str5[0]);
    for(i=0; i<99; i++)
    {
        DrawBmp(0,319,(unsigned short int * )&str1[0],1);
        DelayMs(2000);
        a=a+0x01;
        if(a==0x3a)
        {
            a=0x30;
            dec=dec+0x01;
            if(dec==0x3a) dec=0x30;
        }
        str1[12]=a;
        str1[10]=dec;
        //if(PORTDbits.RD3==0) break;
        if(PORTDbits.RD14==0){esci=1; break; }
    }

    cent=0x31;
    a=0x30;
    dec=0x30;
    i=0;
    for(i=0; i<199; i++)
    {
        if(esci==1) break;
        DrawBmp(0,319,(unsigned short int * )&str2[0],1);
        DelayMs(2000);
        a=a+0x01;
        if(a==0x3a){
            a=0x30;
            dec=dec+0x01;
            if(dec==0x3a)
            {
                dec=0x30;
                cent=cent+0x01;
            }
        }
        str2[14]=a;
        str2[12]=dec;
        str2[10]=cent;
        //if(PORTDbits.RD3==0) break;
        if(PORTDbits.RD14==0){esci=1; break; }
    }
}

void MmcStringConvert(unsigned short int * TextToConvert, unsigned short int * TextConverted)
{
    BYTE i=0,ii=0;
    unsigned char * temptesto = (unsigned char *) TextConverted;
    unsigned char * Text = (unsigned char *) TextToConvert;

    for(;;)
    {
        temptesto[i]=Text[ii];
        if(Text[ii]=='\0') break;
        i=i+2;
        ii++;
    }
}

void MmcStringDirConvert(unsigned short int * TextToConvert, unsigned short int * TextConverted, _Bool RmDir)
{
    BYTE i=0,ii=0;
    unsigned char * temptesto = (unsigned char *) TextConverted;///convertito
    unsigned char * Text = (unsigned char *) TextToConvert;///da convertire

    if(RmDir)
    {
        for(;;)
        {
            if(temptesto[i]=='\0') break;
            i=i+2;
        }
        
        for(;;)
        {
            if(i==0) break;
            if(temptesto[i]=='\\') { temptesto[i]='\0';  break; }
            temptesto[i]='\0';
            i=i-2;
        }
    }
    
    else
    {
        for(;;)
        {
            if(temptesto[i]=='\0') break;
            i=i+2;
        }

        if(temptesto[i-2]=='\\');
        else {temptesto[i]='\\'; i=i+2;}
        
        

        for(;;)
        {
            if(Text[ii]=='\\') { temptesto[i]='\0';  break; }
            temptesto[i]=Text[ii];
            i=i+2;
            ii++;
        }
    }
}

void SdExplorer(void)
{
    _Bool PlusPos=0;
    unsigned short int xpos=0,ypos=0,oldypos=36,oldxpos=2,e=0;
    BYTE nfile,a=0,b=0,oldb=0,FinalXPos=0,nlista=0,SelectDraw=222,ExtReturn=3,DirN=0,i=0;
    BYTE c[2];
    BYTE StringBuffer[20];
    FileList ListLoaded;
    SearchRec rec;
    FSFILE * pointer;
    _Bool ActiveScoll=0,ExitApp=0;
    char str12[] = {'\\',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00,'\0',0x00};
    const char str2[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    char Fileconverted[] = {'c',0x00,'o',0x00,'n',0x00,'v',0x00,'(',0x00,'0',0x00,'1',0x00,')',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    char TextBuffer[20];
    unsigned char NonLoso=0;

    ///Init files
    LoadList(((unsigned short int *)&str12[0]), &rec, &ListLoaded);/// root
    nfile=ListLoaded.NFile+1;


    SetFontOrientation(ORIENT_HOR);
    SetFont((void *) &DroidSans_20);
    SetColor(BLACK);
    GFX_Font_SetAntiAliasType(ANTIALIAS_TRANSLUCENT);

    RIPARTE:
    SelectDraw=222;
    ExtReturn=3;

    ///Init grafica
    LCD_CLS(WHITE);

    LCD_FastRect(0,0,239,29,ORANGE);
    LCD_FastRect(0,301,239,319,ORANGE);
    LCD_Rect(0,30,239,300,0,BLACK);
    draw_line(215,95,215,275,BLACK);

    //Frecce
    LCD_Cercle(215,44,10,1,ORANGE);
    LCD_Cercle(215,286,10,1,ORANGE);
    LCD_Cercle(215,44,10,0,BLACK);
    LCD_Cercle(215,286,10,0,BLACK);
    draw_line(208,284,222,284,BLACK);
    for(i=0; i<8; i++) draw_line(208+i,285+i,222-i,285+i,BLACK);
    draw_line(208,46,222,46,BLACK);
    for(i=0; i<8; i++) draw_line(208+i,45-i,222-i,45-i,BLACK);

    //Cursore
     draw_line(215,55,215,275,BLACK);

    LCD_Cercle(215,65+b,10,1,ORANGE);
    LCD_Cercle(215,85+b,10,1,ORANGE);
    LCD_Cercle(215,65+b,10,0,BLACK);
    LCD_Cercle(215,85+b,10,0,BLACK);

    LCD_FastRect(206,65+b,224,85+b,ORANGE);
    draw_line(205,65+b,205,85+b,BLACK);
    draw_line(225,65+b,225,85+b,BLACK);

    LCD_FastRect(210,73+b,220,73+b,BLACK);
    LCD_FastRect(210,75+b,220,75+b,BLACK);
    LCD_FastRect(210,77+b,220,77+b,BLACK);

    sprintf(StringBuffer,"Sd Explorer");

    //OutTextXY(2, 7, (char *)StringBuffer);

    LCD_Text57(2,7,StringBuffer,2,BLACK,NONE);
    sprintf(StringBuffer,"Esci");
    LCD_Text57(2,304,StringBuffer,2,BLACK,NONE);

    //sprintf(StringBuffer,"n: %d",nfile);
    //LCD_Text57(180,10,StringBuffer,1,GREEN,RED);
    //setPrecision(PREC_LOW);

    ///Stampa files

    Ycursor=oldypos;
    SetColor(BLACK);
    for(i=0; i<12; i++)
    {
        Xcursor=2;
        if(i>=nfile) break;
        //OutTextXY(Xcursor,Ycursor, (char *)ListLoaded.Listaa[nlista+i]);
        LCD_Text57(Xcursor,Ycursor,ListLoaded.Listaa[nlista+i],2,BLACK,NONE);
        Ycursor+=20;
    }

    //Ycursor=36;
    Ycursor=oldypos;
    //oldypos=Ycursor;
    //Xcursor=2;

    while(TRUE)
    {
        if(PORTDbits.RD14==0)
        {

            read();
            xpos=getX();
            ypos=getY();
            xpos=(unsigned short int)((((float)6.01/(float)233.01)*(float)xpos)+(float)xpos);
            ypos=(unsigned short int)((((float)10.01/(float)313.01)*(float)ypos)+(float)ypos);

            PlusPos=0;
            oldb=b;

            if(((2<=xpos)&&(xpos<=40))&&((300<=ypos)&&(ypos<=319)))
            {
                //InitTerminal();
                setPrecision(PREC_EXTREME);
                break;
            }

            e=Ycursor;

            for(i=0; i<12; i++)
            {
                if(i>=nfile) break;
                if(((2<=xpos)&&(xpos<=130))&&((e<=ypos)&&(ypos<=(e+19))))
                {
                    Ycursor=oldypos+(20*i);
                    SetColor(RED);
                    //OutTextXY(2,Ycursor,(char *)ListLoaded.Listaa[nlista+i]);
                    LCD_Text57(2,Ycursor,ListLoaded.Listaa[nlista+i],2,RED,NONE);
                    SelectDraw=nlista+i;
                    DelayMs(100);
                }
                e+=20;
            }
            Ycursor=oldypos;///Ripristina posizione di y!!!

            if(((205<=xpos)&&(xpos<=225))&&((34<=ypos)&&(ypos<=54)))
            {
                if(nlista!=0)
                {
                    PlusPos=1;
                    Ycursor+=4;
                    if(Ycursor==56)
                    {
                        Ycursor=36;
                        nlista--;
                        LCD_FastRect(2,272,140,293,WHITE);
                    }

                    a--;
                    if(a==255){a=3; b=b-(182/(nfile-9)); }
                    ActiveScoll=1;
                }
            }

            if(((205<=xpos)&&(xpos<=225))&&((275<=ypos)&&(ypos<=295)))
            {
                if(((nlista+12)!=nfile)&&(nfile>11))
                {
                    PlusPos=0;
                    Ycursor-=4;
                    if(Ycursor==32)
                    {
                        Ycursor=52;
                        LCD_FastRect(2,31,140,51,WHITE);
                        nlista++;
                    }

                    a++;
                    if(a==4){a=0; b=b+(182/(nfile-9)); }
                    ActiveScoll=1;
                }
            }

            if(ActiveScoll)
            {
                oldypos=Ycursor;

                for(i=0; i<12; i++)
                {
                    //if(ListLoaded.Listaa[i][0]=='\0') break;
                    Xcursor=2;
                    //if((35<=Ycursor)&&(Ycursor<=280))
                    //{
                    if(i>nfile) break;
                        FinalXPos=CenterX(2,2,4,(unsigned short int * )&ListLoaded.Listaa[nlista+i][0]);

                        if(PlusPos)
                        {
                            LCD_FastRect(2,Ycursor-4,FinalXPos,Ycursor+11,WHITE);
                        }
                        else
                        {
                            LCD_FastRect(2,Ycursor+4,FinalXPos,Ycursor+17,WHITE);
                        }

                        SetColor(BLACK);
                        //OutTextXY(Xcursor,Ycursor,(char *)ListLoaded.Listaa[nlista+i]);
                        LCD_Text57(Xcursor,Ycursor,ListLoaded.Listaa[nlista+i],2,BLACK,NONE);
                    //}
                    Ycursor+=20;

                }

                LCD_FastRect(205,55+oldb,225,95+oldb,WHITE);
                //Cursore
                draw_line(215,55,215,275,BLACK);

                LCD_Cercle(215,65+b,10,1,ORANGE);
                LCD_Cercle(215,85+b,10,1,ORANGE);
                LCD_Cercle(215,65+b,10,0,BLACK);
                LCD_Cercle(215,85+b,10,0,BLACK);

                LCD_FastRect(206,65+b,224,85+b,ORANGE);
                draw_line(205,65+b,205,85+b,BLACK);
                draw_line(225,65+b,225,85+b,BLACK);

                LCD_FastRect(210,73+b,220,73+b,BLACK);
                LCD_FastRect(210,75+b,220,75+b,BLACK);
                LCD_FastRect(210,77+b,220,77+b,BLACK);

                Ycursor=oldypos;
                ActiveScoll=0;
            }
        }
        else
            if(SelectDraw!=222)
            {
                if((strcmp(ListLoaded.Listaa[SelectDraw],"\\")==FALSE)&&(DirN==0))///Solo sulla root esce dall'app.
                {
                    //InitTerminal();
                    setPrecision(PREC_EXTREME);
                    break;
                }
                ExtReturn=CheckExt(&ListLoaded,SelectDraw);//controlla l'estensione

                ///Lancia L'applicazione
                if(ExtReturn==2)
                {/*
                    MmcStringConvert((unsigned short int * )&ListLoaded.Listaa[SelectDraw][0],(unsigned short int * )&Fileconverted[0]);
                    LCD_CLS(WHITE);
                    DrawBmp(0,0,(unsigned short int * )&Fileconverted[0],0);*/
                    ImageDecoderInit();
                    LCD_CLS(WHITE);
                    pointer = FSfopen(ListLoaded.Listaa[SelectDraw], "r");
                    ImageFullScreenDecode(pointer, IMG_BMP, NULL, PixelOutput);
                    FSfclose(pointer);

                    while(PORTDbits.RD14==1);
                    DelayMs(150);

                    ExtReturn=0;
                    goto RIPARTE;
                }

                if(ExtReturn==4)
                {
                    ImageDecoderInit();
                    LCD_CLS(WHITE);
                    pointer = FSfopen(ListLoaded.Listaa[SelectDraw], "r");
                    ImageFullScreenDecode(pointer, IMG_GIF, NULL, PixelOutput);
                    
                    while(PORTDbits.RD14==1) 
                    {
                        NonLoso=GIF_bDecodeNextImage(&GifDec);
                        if(NonLoso==0x64)
                        {
                            FSfclose(pointer);
                            ImageDecoderInit();
                            pointer = FSfopen(ListLoaded.Listaa[SelectDraw], "r");
                            ImageFullScreenDecode(pointer, IMG_GIF, NULL, PixelOutput);
                        }
                        //sprintf(TextBuffer,"Ritorna: %02x",NonLoso);
                        //LCD_Text57Land(230,200,TextBuffer,1,BLACK,AZZURRO);
                        
                    }

                    //while(PORTDbits.RD14==1) GIF_bDecodeNextImage(&GifDec);
                    //GIF_bDecodeNextImage(&GifDec);
                    //GIF_bDecodeNextImage(&GifDec);
                    //sprintf(TextBuffer,"Ritorna: %02x",NonLoso);
                    //LCD_Text57Land(230,200,TextBuffer,1,BLACK,AZZURRO);
                    FSfclose(pointer);
                    
                    //while(PORTDbits.RD14==1);
                    DelayMs(150);
                    ExtReturn=0;
                    goto RIPARTE;
                }

                if(ListLoaded.IsDir[SelectDraw])///se una cartella
                {
                    if(strcmp(ListLoaded.Listaa[SelectDraw],"\\")==FALSE)
                    {
                        DirN--;
                        MmcStringDirConvert((unsigned short int * )&ListLoaded.Listaa[SelectDraw][0],(unsigned short int * )&str12[0],1);
                       Xcursor=2;
                    /*for(i=0; i<12; i++)
                    {
                        c[0]=str12[i];
                        c[1]=0x00;
                        LCD_Text57(Xcursor,10,c,1,GREEN,RED);
                    } */
                    }
                    else{
                        MmcStringDirConvert((unsigned short int * )&ListLoaded.Listaa[SelectDraw][0],(unsigned short int * )&str12[0],0);
                        DirN++;
                    }

                    LoadList(((unsigned short int *)&str12[0]), &rec, &ListLoaded);/// root

                    nfile=ListLoaded.NFile+1;
                    Ycursor=36;
                    oldypos=Ycursor;
                    Xcursor=2;

                    LCD_FastRect(2,31,160,299,WHITE);
                    for(i=0; i<nfile; i++)
                    {
                        if(i>11) break;
                        Xcursor=2;

                        SetColor(BLACK);
                        //OutTextXY(Xcursor,Ycursor,(char *)ListLoaded.Listaa[i]);
                        LCD_Text57(Xcursor,Ycursor,ListLoaded.Listaa[i],2,BLACK,NONE);
                        Ycursor+=20;
                    }

                    Ycursor=36;
                    oldypos=Ycursor;
                    Xcursor=2;
                    nlista=0;
                    a=0,b=0,oldb=0,FinalXPos=0;
                }
                SelectDraw=222;
            }
    }
}

void PixelOutput(IMG_PIXEL_XY_RGB_888 *pPix)
{
    //SetColor(RGB565CONVERT(pPix->R, pPix->G, pPix->B));
    coloregif=RGB16(pPix->R, pPix->G, pPix->B);
    
    if(pPix->X <= GetMaxX() && pPix->Y <= GetMaxY())
    {
        //LCD_Pixel(pPix->X, pPix->Y,coloregif);
        //PutPixel(pPix->X, pPix->Y);
    }
    if(pPix->X > GetMaxX() && pPix->Y > GetMaxY())
    {
        ImageAbort();
    }
}