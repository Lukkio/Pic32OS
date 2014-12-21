
/*
*************************************************************************************************
*		Variabili globali
*************************************************************************************************
*/
static rtccTime		lastTime;
static rtccDate		lastDate;
_Bool Touch=0;
static char		dateStr[12]= "//////20//\0";	// 08/06/15
static char		timeStr[10]= "::::::::\0";	// 23:14:15
unsigned char StringBuffer[50],Param3[15],Param2[15],Param1[15],Param4[15],Param5[15],Parametri=0;


void InitTerminal(void);
void LoadArgvArgc(void);
void Terminal(void);
void ConsoleReady(void);

#include"../App/crc.c"
#include"../App/TerminalApp.c"






void InitTerminal(void)
{
    const char str1[] = {'k',0x00,'e',0x00,'y',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const char str2[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};

    SSD1289_writeResgiter( 0x0049, 0x000A );///fine della finestra a 10 px
    LCD_CLS(WHITE);
    sprintf(StringBuffer,"Loading..");
    LCD_Text57(2,1,StringBuffer,1,BLACK,NONE);
    wFSchdir ((unsigned short int *)&str2[0]);
    DrawBmp(0,319,(unsigned short int * )&str1[0],0);
    LCD_Cercle(53,29,3,1,GRAY);//Uppercase up
    LCD_Cercle(22,274,3,1,GRAY);//Special key off
    Xcursor=246;
    Ycursor=2;
    SSD1289_writeResgiter( 0x0049, 0x013F );
    setPrecision(PREC_EXTREME);
}

void LoadArgvArgc(void)
{
    unsigned char i=0,b=0;
    ///Ciclo per verificare la stringa passata
    ///carica in Param1, Param2, Param3, ogni parola separata da uno spazio
    for(i=0; i<20; i++)
    {
        if(StringBuffer[i]==0x20)
        {
            Parametri=1;
            Param1[i]=0x00;
            break;
        }
        if(StringBuffer[i]==0x00)
        {
            Parametri=1;
            Param1[i]=0x00;
            break;
        }
        Param1[i]=StringBuffer[i];
    }

    if(StringBuffer[i]!=0x00)
    {
        b=0;
        for(i<20; i++;)
        {
            if(StringBuffer[i]==0x20)
            {
                Parametri=2;
                Param2[b]=0x00;
                break;
            }

            if(StringBuffer[i]==0x00)
            {
                Parametri=2;
                Param2[b]=0x00;
                break;
            }

            Param2[b]=StringBuffer[i];
            b++;
        }
    }

    if(StringBuffer[i]!=0x00)
    {
        b=0;
        for(i<20; i++;)
        {
            if(StringBuffer[i]==0x20) {Parametri=3; Param3[b]=0x00;   break;}
            if(StringBuffer[i]==0x00) {Parametri=3; Param3[b]=0x00; break;}
            Param3[b]=StringBuffer[i];
            b++;
        }
    }

    if(StringBuffer[i]!=0x00)
    {
        b=0;
        for(i<20; i++;)
        {
            if(StringBuffer[i]==0x20) {Parametri=4; Param4[b]=0x00;   break;}
            if(StringBuffer[i]==0x00) {Parametri=4; Param4[b]=0x00; break;}
            Param4[b]=StringBuffer[i];
            b++;
        }
    }

    if(StringBuffer[i]!=0x00)
    {
        b=0;
        for(i<20; i++;)
        {
            if(StringBuffer[i]==0x20) {Parametri=5; Param5[b]=0x00;   break;}
            if(StringBuffer[i]==0x00) {Parametri=5; Param5[b]=0x00; break;}
            Param5[b]=StringBuffer[i];
            b++;
        }
    }
}

void Terminal(void)
{
    _Bool exit=0;
    unsigned char App=0;
    InitTerminal();

    while(TRUE)
    {
        ConsoleReady();///quando riceve invio prosegue il ciclo

        if(strcmp(Param1,"high")==FALSE) App=1;
        if(strcmp(Param1,"low")==FALSE) App=2;
        if(strcmp(Param1,"exit")==FALSE) App=3;
        if(strcmp(Param1,"reboot")==FALSE) SoftReset();
        if(strcmp(Param1,"send")==FALSE) App=4;
        if(strcmp(Param1,"initrf")==FALSE) App=5;
        if(strcmp(Param1,"statusrf")==FALSE) App=6;
        if(strcmp(Param1,"readrf")==FALSE) App=7;
        if(strcmp(Param1,"setime")==FALSE) App=8;
        if(strcmp(Param1,"setdate")==FALSE) App=9;
        if(strcmp(Param1,"readpk")==FALSE) App=10;
        if(strcmp(Param1,"sendpk")==FALSE) App=11;
        if(strcmp(Param1,"potrf")==FALSE) App=12;
        if(strcmp(Param1,"sendpot")==FALSE) App=13;
        if(strcmp(Param1,"list")==FALSE) App=14;
        if(strcmp(Param1,"color")==FALSE) App=15;
        if(strcmp(Param1,"touch")==FALSE) App=16;
        //if(strcmp(Param1,"scroll")==FALSE) App=15;

        switch(App)
	{
            case 1:
                LedHigh();
                break;
            case 2:
		LedLow();
		break;
            case 3:
		exit=1;
		break;
            case 4:
		Sendrf();
		break;
            case 5:
		Initrf();
		break;
            case 6:
		Satusrf();
		break;
            case 7:
		ReadRF();
		break;
            case 8:
		SetTime();
		break;
            case 9:
		SetData();
		break;
            case 10:
		ReadPk();
		break;
            case 11:
		SendPk();
		break;
            case 12:
		ReadPot();
		break;
            case 13:
		SendPot();
		break;
            case 14:
		ListCmd();
		break;
            case 15:
		ColorConv();
		break;
            case 16:
                TouchCalib();
		break;
            //case 15:
		//TestScroll();
		//break;
            default:
		SyntaxError();
		break;
        }
        App=0;
        if(exit==1) break;
    }
    setPrecision(PREC_EXTREME);
}

void ConsoleReady(void)
{
    char KeyBuffer[31]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',',',' ',' ',' ','.'};
    char SpecialKeyBuffer[31]={'1','2','3','4','5','6','7','8','9','0','!','@','#','$','%','&','*','?','/','Z','"',' ','(',')','-','+',';',' ',' ',' ',':'};    
    const unsigned short int LetterPosX[4]={93,62,32,1};
    const unsigned short int SpecialCharPosY[6]={1,284,1,39,245,284};   
    const unsigned short int LetterPosY[31]={1,33,65,97,129,161,193,225,257,289,
                                             17,49,81,113,145,177,209,241,273,
                                                49,81,113,145,177,209,241,
                                                   81,113,145,177,209};
    _Bool ConsoleOK=0,NumSp=0,UppLow=1;
    char c[2]={'A',0x00};
    char TextBuffer[10],i=0,b=0,Nchar=0;
    unsigned short int clu=0, dat=0,DelCount=0,a=0x0000;
    uint32_t adx, ady;

   // if((Xcursor!=238)&&(Ycursor!=2))
   // {
        Xcursor-=8;
        Ycursor=2;
   // }

    for(i=0; i<10; i++){
        Param1[i]=0x00;
        Param2[i]=0x00;
        Param3[i]=0x00;
        Param4[i]=0x00;
        Param5[i]=0x00;
    }

    sprintf(StringBuffer,"User$ ");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLUE,NONE);

    for(i=0; i<50; i++) StringBuffer[i]=0x00;
    
    while(TRUE)
    {
        //if(PORTDbits.RD14==0)
        if(T_IRQ==0)
        {
            //Old Touch driver
            //read();
            //clu=getX();
            //dat=getY();
            //clu=(unsigned short int)((((float)6.01/(float)233.01)*(float)clu)+(float)clu);
            //dat=(unsigned short int)((((float)10.01/(float)313.01)*(float)dat)+(float)dat);

            TP_GetMedianAdXY(&adx, &ady);
            dat = getDisplayCoordinateX(adx, ady);
            clu = getDisplayCoordinateY(adx, ady);

            LCD_CercleRead((signed char)clu,(signed short int)dat, 5,(unsigned short int * )&CercleTemp[0][0]);
            LCD_Cercle((signed char)clu,(signed short int)dat, 5,0,BLUE);
            
            b=0;
            for(i=0; i<31; i++)
            {
                ///lettere
                if((LetterPosX[b]<=clu)&&(clu<=(LetterPosX[b]+29))&&((LetterPosY[i]<=dat)&&(dat<=(LetterPosY[i]+29))))//la Q
                {
                    ///se attivo caratteri speciali
                    if(NumSp) c[0]=SpecialKeyBuffer[i];
                    else c[0]=KeyBuffer[i];
                    if((UppLow==1)&&(NumSp==0))
                    {
                        switch(c[0])//converte in maiuscolo le lettere
                        {
                            case ',':
                                break;
                            case' ':
                                break;
                            case'.':
                                break;
                            default:
                                c[0]+=0x20;
                                break;
                        }
                    }
                     
                    LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,WHITE);
                    strcpy(TextBuffer,c);
                    StringBuffer[Nchar]=c[0];
                    LCD_Text57Land(Xcursor,Ycursor,TextBuffer,1,BLACK,NONE);
                    Nchar++;
                    //Ycursor+=6;
                    if(Ycursor>=319)
                    {
                        Ycursor=2;
                        Xcursor-=8;
                        Nchar=0;
                    }
                    DelayMs(50);
                }
                if(i==9) b++;
                if(i==18) b++;
                if(i==25) b++;
            }

            ///comandi speciali
            b=2;
            for(i=0; i<6; i++)
            {
                if((LetterPosX[b]<=clu)&&(clu<=(LetterPosX[b]+29))&&((SpecialCharPosY[i]<=dat)&&(dat<=(SpecialCharPosY[i]+34))))//la Q
                {
                    switch(i)
                    {
                        case 0:
                            ///da implementare Upper/lower letter
                            if(UppLow==0)
                            {
                                UppLow=1;
                                LCD_Cercle(53,29,3,1,GRAY);
                            }
                            else
                            {
                                UppLow=0;
                                LCD_Cercle(53,29,3,1,BLUE);
                            }
                            break;
                        case 1:
                            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,WHITE);
                            Ycursor-=6;
                            Nchar--;
                            if(Ycursor>350) 
                            {
                                Ycursor=314;
                                Xcursor+=8;
                                Nchar=0;
                               if(Xcursor>241) Xcursor=238;
                            }
                            break;
                         case 2:
                            ///da implementare
                            break;
                         case 3:
                            ///da implementare
                            break;
                         case 4:
                             if(NumSp==0)
                             {
                                 NumSp=1;
                                 LCD_Cercle(22,274,3,1,BLUE);
                             }
                             else
                             {
                                 NumSp=0;
                                 LCD_Cercle(22,274,3,1,GRAY);
                             }
                             break;
                        case 5:
                            ///torna a capo riga (invio)
                            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,WHITE);
                            NumSp=0;
                            LCD_Cercle(22,274,3,1,GRAY);
                            UppLow=1;
                            LCD_Cercle(53,29,3,1,GRAY);
                            Ycursor=10;
                            Xcursor-=8;
                            if(Xcursor<=136)
                            {
                                LCD_FastRect(121,0,239,319,WHITE);
                                Xcursor=238;///prima riga
                            }

                            StringBuffer[Nchar]=0x00;//forza la chiusura dell'array
                            Nchar=0;
                            LoadArgvArgc();//carica la stringa su param1,2,3,4,5.
                            ConsoleOK=1;
                            break;
                    }
                    DelayMs(100);
                }
                if(i==1) b=3;
            }
            DelayMs(100);
            LCD_CercleBackGround((signed char)clu,(signed short int)dat, 5,(unsigned short int * )&CercleTemp[0][0]);
        }

        ///Lampeggio cursore
        DelayMs(1);
        DelCount++;
        if(DelCount==200)
        {
            DelCount=0;
            if(a==0x0000) a=0xffff;
            else a=0x0000;
            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,a);
        }
        if(ConsoleOK==1) break;
    }
}