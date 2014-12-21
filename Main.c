/*
*************************************************************************************************
*		Inserimento file include
*************************************************************************************************
*/

#include "Header/FSIO.h"
#include <math.h>
#include "DelayMs.c"

#include"Drivers/SSD1289_PMP.c"
#include"Drivers/TimeUpdate.c"
#include"Drivers/ads7843_2.c"
#include"Drivers/Touch/touchscreen.c"
#include"Drivers/Touch/ads7843drv.c"
#include"Drivers/font_anti.c"
//#include"../PIC32/Drivers/InternalResourceXC32.h"
//#include"../PIC32/Drivers/InternalResourceXC32.c"
#include"Drivers/DroidSans_12.h"
#include"Drivers/DroidSans_12.c"
//#include"../PIC32/Drivers/droidsans_32/doidsans_32.h"
//#include"../PIC32/Drivers/droidsans_32/doidsans_32.c"
#include"Drivers/droidsans_20/doidsans_20.h"
#include"Drivers/droidsans_20/doidsans_20.c"
#include"gif/GifDecoder.c"
#include"bmp/BmpDecoder.c"
#include"SD/mmc_ssd1289.c"
#include"MRF49XA/MRF49XA.c"
#include"App/ball.c"
#include"App/demook.c"
#include"App/TETRIS.c"
#include"App/SuperMario.c"
#include"App/Paint.c"
#include"App/Terminal.c"
#include"App/3d_rota.c"

/*
*************************************************************************************************
*		Definizione prototipi
*************************************************************************************************
*/

void MainMenu(void);
void TestLcdPort(void);
static void bcdtoa(int bcd, char* dest); ///Converte l'ora del rtcc in decimale

/*
*************************************************************************************************
*		DEFINE
*************************************************************************************************
*/

#define LCDGUI
#define MAINBACKGROUND

int main (void)
{
	///Variabili del main
    char TextBuffer[20]; 
    const char logo[] = {'l',0x00,'o',0x00,'g',0x00,'o',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const char sfondo[] = {'S',0x00,'F',0x00,'O',0x00,'N',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const char sys[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    unsigned char RtccOk=0;
	extern const FONT_FLASH     DroidSans_12;
	//extern const FONT_FLASH     DroidSans_32;
	extern const FONT_FLASH     DroidSans_20;
	//extern  const XCHAR          AntialisedText[];
	XCHAR Textprova[30]={"DroidSans font!\0"};
	static rtccTime		lastTime;
    static rtccDate		lastDate;
    static rtccTime		currTime;
    static rtccDate		currDate;
    rtccRes res;
	
	//Resetta alcuni registri
	DDPCONbits.JTAGEN = 0;
    OSCCONbits.SOSCEN=1;
    U2MODEbits.ON = 0;
    U1MODEbits.ON = 0;
    U5MODEbits.ON = 0;
	
    
    //Turn the Ethernet controller off
	IEC1CLR = _IEC1_ETHIE_MASK;
    ETHCON1CLR = _ETHCON1_ON_MASK | _ETHCON1_TXRTS_POSITION | _ETHCON1_RXEN_MASK;
    while(ETHSTAT & _ETHSTAT_ETHBUSY_MASK);

    ///Init cpu
    SYSTEMConfigPerformance(80000000);

	//Init interrupt
    INTEnableSystemMultiVectoredInt();

    IEC1CLR = 0x0004;   // Disable PMP interrupt
    PMCON = 0x0000;   // Stop PMP module and clear control register
    DisableIntT1;

    DelayMs(10);

	//Initialize the RTCC
    RtccInit();
    while(RtccGetClkStat()!=RTCC_CLK_ON);

	//Init Time & date
    lastTime.hour=0x00;
    lastTime.min=0x00;
    lastTime.sec=0x00;
    lastDate.mday=0x01;
    lastDate.mon=0x01;
    lastDate.year=0x14;
    lastDate.wday=0x03;

    RtccSetTimeDate(lastTime.l, lastDate.l);
    lastTime.l=lastDate.l=-1;
    mRtccSelectSecPulseOutput();
    mRtccOutputEnable();

    DelayMs(30);

    ///Setta le porte come uscite
    mPORTEDirection(0x0300);
    mPORTGDirection(0);
    mPORTFDirection(0);
    mPORTBDirection(0);
	mPORTDDirection(0x4000);
    mPORTADirection(0);

	///Mette tutte le uscite a zero
    mPORTEWrite(0x0000);
    mPORTDWrite(0x0000);
    mPORTFWrite(0x0000);
    mPORTGWrite(0x0000);
    mPORTAWrite(0x0000);
    TRISGbits.TRISG15=1;//setta input

	//Init PMP module
    PMP_InitHW();

    ///Inizializza LCD
    SSD1289_on();

    ///Clear display
    LCD_CLS(BLACK);

	///fine della finestra a 213
    //SSD1289_writeResgiter( 0x0049, 0x008C );
	
	///Stampa windows boot
    LCD_CLS(WHITE);
    SSD1289_writeResgiter( 0x0049, 0x008C );///fine della finestra a 213

    Xcursor=2;
    Ycursor=20;

    sprintf(TextBuffer,"All I/O port.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    sprintf(TextBuffer,"OK!\r\n");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
    sprintf(TextBuffer,"PMP16.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    sprintf(TextBuffer,"OK!\r\n");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
    sprintf(TextBuffer,"Lcd.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    sprintf(TextBuffer,"OK!\r\n");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
    sprintf(TextBuffer,"Init Sd.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
        
    ///Inizializza SD
    if(FSInit()==TRUE)
    {
        sprintf(TextBuffer,"OK!\r\n");
        LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
    }
    else
    {
        sprintf(TextBuffer,"Error!\r\n");
        LCD_Text57(Xcursor,Ycursor,TextBuffer,2,RED,BLACK);
        sprintf(TextBuffer,"Insert SD end reboot!\r\n");
        LCD_Text57(Xcursor,Ycursor,TextBuffer,2,RED,BLACK);
        while(TRUE);
    }
       
    sprintf(TextBuffer,"Init Touch.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    
	//Inizializza TouchScreen
    InitTouch(0);
    setPrecision(PREC_EXTREME);
    Touch=0;    
    sprintf(TextBuffer,"OK!\r\n");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);

	//Inizializza RTCC
    sprintf(TextBuffer,"Rtcc.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    if(RtccOk>250)
    {
        sprintf(TextBuffer,"Error!\r\n");
        LCD_Text57(Xcursor,Ycursor,TextBuffer,2,RED,NONE);
    }
    else
    {
        sprintf(TextBuffer,"OK!\r\n");
        LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
    }
    
	//Inizializza RFID    
    sprintf(TextBuffer,"MRF49XA.. ");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,BLACK,NONE);
    initRFPorts();
    PacketReady=0;
    ResetRadio = 0;
    sprintf(TextBuffer,"OK!\r\n");
    LCD_Text57(Xcursor,Ycursor,TextBuffer,2,GREEN,NONE);
       
	//Disattiva Interrupt
    DisableIntT1;
       
	//Write Logo
    wFSchdir ((unsigned short int *)&sys[0]);
    DrawBmp(74,280,(unsigned short int * )&logo[0],0);
    SSD1289_writeResgiter( 0x0049, 0x013F );///fine della finestra impostato a 320
 
	//Delay boot
	// while(PORTDbits.RD14==1);
    RtccOk=0;
    while(TRUE)
    {
        DelayMs(5);
        RtccOk++;
        if(RtccOk==100) break;
    }

    while(TRUE) MainMenu();
}

void MainMenu(void)
{
    const char str5[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    const char backgr[] = {'b',0x00,'a',0x00,'c',0x00,'k',0x00,'g',0x00,'r',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    char BackgrLand[] = {'b',0x00,'a',0x00,'c',0x00,'k',0x00,'g',0x00,'r',0x00,'2',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    char TextBuffer[20];
    unsigned short int AlignmentX=0,clu=0, dat=0,Colore=0x0000,AlignmentY=0;
    char day[7][4]={{"Lun"},{"Mar"},{"Mer"},{"Gio"},{"Ven"},{"Sab"},{"Dom"}};
    char MainMenuApp[3][8][13]=
        {
            {{"Paint"},{"Galleria"},{"Screen Saver"},{"Terminal"},{"Sd Explorer"},{"Tetris"},{"Super Mario"},{"Next"}},
            {{"3D"},{"Touch cal."},{"App10"},{"App11"},{"App12"},{"App13"},{"App14"},{"Next"}},
            {{"App15"},{"App16"},{"App17"},{"App18"},{"App19"},{"App20"},{"App21"},{"Next"}},
        };
    char MainMenu=0;
    unsigned short int PosMenu[4]={40,120,200,280};
    unsigned char PosMenuLine=140,ii=0;
    _Bool esci=0,NextMenu=0;
    rtccTime currTime;
    rtccDate currDate;

    while(TRUE)
    {
		///Inizializza il menu, nuova versione in landscape
        esci=0;
		
        if(NextMenu==1);
        else
		{
            SSD1289_writeResgiter( 0x0049, 0x000E );///fine della finestra a 14 in y
            LCD_CLS(WHITE);
            LCD_FastRect(0,0,239,14,BLACK);
            sprintf(TextBuffer,"Loading Gui...");
            AlignmentX=CenterX(120,1,ALIGNMENT_CENTER,(unsigned short int * )&TextBuffer[0]);
            LCD_Text57(AlignmentX,4,TextBuffer,1,WHITE,NONE);
        }
        
        lastDate.l=RtccGetDate();
        currDate.l=lastDate.l;
        
        bcdtoa(lastDate.mday, dateStr);
        bcdtoa(lastDate.mon, dateStr+3);
        bcdtoa(lastDate.year, dateStr+8);

        wFSchdir ((unsigned short int *)&str5[0]);
        switch(MainMenu)
        {
            case 0:
                BackgrLand[12]=0x30;
                DrawBmp(0,319,(unsigned short int * )&BackgrLand[0],NextMenu);
                break;
            case 1:
                BackgrLand[12]=0x31;
                DrawBmp(0,319,(unsigned short int * )&BackgrLand[0],NextMenu);
                break;
            case 2:
                BackgrLand[12]=0x32;
                DrawBmp(0,319,(unsigned short int * )&BackgrLand[0],NextMenu);
                break;
        }

        NextMenu=0;
        Colore=0xFFFF;
        PosMenuLine=100;
        ii=0;

        ////Prototipo font antialiased DroidSans12
        SetFontOrientation(ORIENT_VER2);
        SetFont((void *) &DroidSans_12);
        SetColor(WHITE);
        GFX_Font_SetAntiAliasType(ANTIALIAS_TRANSLUCENT);

        for(i=0; i<8; i++)
        {
            AlignmentX = (PosMenu[ii] -(GetTextWidth((XCHAR *)MainMenuApp[MainMenu][i], (void *) &DroidSans_12)/2));
            OutTextXY(AlignmentX, PosMenuLine, (XCHAR *)MainMenuApp[MainMenu][i]);
            /*
            AlignmentY=CenterX(PosMenu[ii],1,ALIGNMENT_CENTER,(unsigned short int * )&MainMenuApp[MainMenu][i][0]);
            LCD_Text57Land(PosMenuLine,AlignmentY,MainMenuApp[MainMenu][i],1,Colore,NONE);
             */
            ii++;
            if(ii==4)
			{ 
				ii=0; 
				PosMenuLine+=100;
			}           
        }

		
        //LCD_FastRect(0,0,239,14,BLACK);
        sprintf(TextBuffer,"OpenPic OS");
        LCD_Text57Land(234,4,TextBuffer,1,WHITE,NONE);
        
        SSD1289_writeResgiter( 0x0049, 0x013F );///Attiva tutta la finestra

        //Bottom
        //LCD_FastRect(0,305,239,319,BLACK);

        strcpy(TextBuffer,dateStr);
        strcat(TextBuffer," 00:00:00");

        AlignmentY=CenterX(319,1,ALIGNMENT_RIGHT,(unsigned short int * )&TextBuffer[0]);
        LCD_Text57Land(10,AlignmentY,TextBuffer,1,WHITE,NONE);

        sprintf(TextBuffer,"By Lucio");
        LCD_Text57Land(10,4,TextBuffer,1,WHITE,NONE);
        ///Fine init menu
        
        while(TRUE)
        {
            if(PORTDbits.RD14==0)
            {
                read();
                clu=getX();
                dat=getY();

                clu=(unsigned short int)((((float)6.01/(float)233.01)*(float)clu)+(float)clu);
                dat=(unsigned short int)((((float)10.01/(float)313.01)*(float)dat)+(float)dat);
                
                //x---
                //----
                if(((150<=clu)&&(clu<=210))&&((10<=dat)&&(dat<=70)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            //TS_Calibration();
                            Paint();
                            break;                           
                        case 1:
                            demo();
                            break;
                        case 2:
                            break;
                    }
                    esci=1;
                }
                
                //-x--
                //----
                if(((150<=clu)&&(clu<=210))&&((90<=dat)&&(dat<=150)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            PhotoApp();
                            break;
                        case 1:
                            TS_Calibration();
                            break;
                        case 2:
                            break;
                    }
                    esci=1;
                }

                //--x-
                //----
                if(((150<=clu)&&(clu<=210))&&((170<=dat)&&(dat<=230)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            BallMatrix();
                            DelayMs(100);
                            BallRand();
                            DelayMs(100);
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                    }    
                    esci=1;
                }
                
                //---x
                //----
                if(((150<=clu)&&(clu<=210))&&((250<=dat)&&(dat<=310)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            Terminal();
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                    }                  
                    DelayMs(100);
                    esci=1;
                }

                //----
                //x---
                if(((50<=clu)&&(clu<=110))&&((10<=dat)&&(dat<=70)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            SdExplorer();
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                    }
                    DelayMs(100);                   
                    esci=1;
                }

                //----
                //-x--
                if(((50<=clu)&&(clu<=110))&&((90<=dat)&&(dat<=150)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            Tetris();
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                    }  
                    DelayMs(100);
                    esci=1;
                }
              
                //----
                //--x-
                if(((50<=clu)&&(clu<=110))&&((170<=dat)&&(dat<=230)))
                {
                    DelayMs(100);
                    switch(MainMenu){
                        case 0:
                            CollisionTestTwo();
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                    } 
                    DelayMs(100);
                    esci=1;
                }

                //----
                //---x
                if(((50<=clu)&&(clu<=110))&&((250<=dat)&&(dat<=310)))
                {
                    DelayMs(100);
                    MainMenu++;
                    if(MainMenu==3) MainMenu=0;
                    NextMenu=1;
                    esci=1;
                }

            }
            
            Screen_Saver++;
            if(Screen_Saver==200)
            {
                BallRand();
                Screen_Saver=0;
                esci=1;
            }

            if(esci==1) {DelayMs(100); esci=0; break;}

            currTime.l=RtccGetTime();//Scarica l'ora agiornata dal pic
            if(lastTime.sec!=currTime.sec)
            {
                lastTime.l=currTime.l;
                bcdtoa(currTime.hour, timeStr);
                bcdtoa(currTime.min, timeStr+3);
                bcdtoa(currTime.sec, timeStr+6);

                //sprintf(TextBuffer,"Ven 00:00");
                AlignmentY=CenterX(319,1,ALIGNMENT_RIGHT,(unsigned short int * )&timeStr[0]);
                LCD_Text57Land(10,AlignmentY,timeStr,1,WHITE,BLACK);
                currDate.l=RtccGetDate();
                if(currDate.mday!=lastDate.mday)
                {
                    lastDate.l=currDate.l;
                    bcdtoa(currDate.mday, dateStr);
                    bcdtoa(currDate.mon, dateStr+3);
                    bcdtoa(currDate.year, dateStr+8);
                    
                    strcpy(TextBuffer,dateStr);
                    strcat(TextBuffer," 00:00:00");
                    AlignmentY=CenterX(319,1,ALIGNMENT_RIGHT,(unsigned short int * )&TextBuffer[0]);
                    LCD_Text57Land(10,AlignmentY,TextBuffer,1,WHITE,BLACK);
                }
            }
            DelayMs(25);         
        }
    }
}




void TestLcdPort(void)
{
        //TRISDbits.TRISD2=0;//setta output
        mPORTEDirection(0);
        mPORTGDirection(0);
        mPORTFDirection(0);
        mPORTDDirection(0);

        while(TRUE)
        {
            PORTDbits.RD2=1;//hig
            mPORTDSetBits(BIT_10);
            mPORTDSetBits(BIT_11);
            mPORTDSetBits(BIT_4);
            mPORTDSetBits(BIT_5);

            mPORTESetBits(BIT_0);
            mPORTESetBits(BIT_1);
            mPORTESetBits(BIT_2);
            mPORTESetBits(BIT_3);
            mPORTESetBits(BIT_4);
            mPORTESetBits(BIT_5);
            mPORTESetBits(BIT_6);
            mPORTESetBits(BIT_7);

            mPORTGSetBits(BIT_0);
            mPORTGSetBits(BIT_1);

            mPORTFSetBits(BIT_1);
            mPORTFSetBits(BIT_0);

            mPORTDSetBits(BIT_12);
            mPORTDSetBits(BIT_13);

            mPORTDSetBits(BIT_6);
            mPORTDSetBits(BIT_7);

            DelayMs(100);
            PORTDbits.RD2=0;//low

            mPORTDClearBits(BIT_10);
            mPORTDClearBits(BIT_11);
            mPORTDClearBits(BIT_4);
            mPORTDClearBits(BIT_5);

            mPORTEClearBits(BIT_0);
            mPORTEClearBits(BIT_1);
            mPORTEClearBits(BIT_2);
            mPORTEClearBits(BIT_3);
            mPORTEClearBits(BIT_4);
            mPORTEClearBits(BIT_5);
            mPORTEClearBits(BIT_6);
            mPORTEClearBits(BIT_7);

            mPORTGClearBits(BIT_0);
            mPORTGClearBits(BIT_1);

            mPORTFClearBits(BIT_1);
            mPORTFClearBits(BIT_0);

            mPORTDClearBits(BIT_12);
            mPORTDClearBits(BIT_13);

            mPORTDClearBits(BIT_6);
            mPORTDClearBits(BIT_7);
            DelayMs(100);

        }
}


/*
void ScrollTest(void)
{
    unsigned short int clu,dat,posyfixed=160,page=0;
    signed short int scroll=0;
    LCD_FastRect(200,145,210,175,RED);
    draw_line(205,0,205,143,GREEN);
    draw_line(205,177,205,319,GREEN);
    LCD_ScrollOn();
    while(TRUE){
        if(PORTFbits.RF4==0)
        {
            read();
            clu=getX();
            dat=getY();
            clu=(unsigned short int)((((float)6.01/(float)233.01)*(float)clu)+(float)clu);
            dat=(unsigned short int)((((float)10.01/(float)313.01)*(float)dat)+(float)dat);

            if(((200<=clu)&&(clu<=210))&&(((posyfixed+scroll)<=dat)&&(dat<=(posyfixed+scroll+15))))
                {
                scroll++;
                page--;
                if(page>340) page=319;
                LCD_ScrollArea(page,0);
                }
            if(((200<=clu)&&(clu<=210))&&(((posyfixed+scroll-15)<=dat)&&(dat<=(posyfixed+scroll))))
                {
                scroll--;
                page++;
                if(page>319) page=0;
                LCD_ScrollArea(page,0);
                }
            DelayMs(1);
        }
        if(PORTDbits.RD3==0) {LCD_ScrollOff(); break;}
    }
}
*/

/*void __ISR(_CHANGE_NOTICE_VECTOR, ipl2) ChangeNotice_Handler(void)
{
    unsigned short int porta;
    porta=mPORTDRead();

   // if(BitTest(porta,5)) minus=1;
   // else add=1;

    if(Touch==1)
    {
        Touch=0;
    }
    else
    {
        Touch=1;       
    }
    
    // clear the interrupt flag
    mCNClearIntFlag();
}*/

/*void __ISR(_EXTERNAL_1_VECTOR, ipl3) INT1Interrupt()
{    
   mINT1ClearIntFlag();
   //PacketReady = 1;
}*/

void __ISR(_EXTERNAL_2_VECTOR, ipl4) INT2Interrupt()
{
   mINT2ClearIntFlag();
   PacketReady = 1;

   PacketReady = 0; // Clears Flag
            PackState = MRF49XA_Receive_Packet(&rfData);
            switch (PackState)
            {
                case DATA_RECEIVED:
                    IFS0bits.T1IF = 0; /* clear interrupt flag */
                    IEC0bits.T1IE = 1; /* enable interrupts */
                    TMR1 = 0; /* clear timer1 register */
                    T1CONbits.TON = 1; /* start the timer */
                    //RXLed=1;
                    break;
                case PACKET_RECEIVED:
                    IFS0bits.T1IF = 0; /* clear interrupt flag */
                    IEC0bits.T1IE = 0; /* disable interrupts */
                    T1CONbits.TON = 0; /* stop the timer */
                    if (rfData.buffer[rfData.len-1] == CalChkSum(rfData.buffer,rfData.len-1)) ChkSumLed = 1; // CheckSum is the same
                    else ChkSumLed = 0; // Checksum is different
                    //PKTLed=1;
                    //ChkSumLed = 1;
                    InitRFData(&rfData); // clears indexes
                    break;
            }
}

void __ISR(_TIMER_1_VECTOR, ipl2) Timer1Handler(void)
{
    mT1ClearIntFlag();
    ResetRadio = 1;

    ResetRadio=0;
            //mINT1ClearIntFlag();/* clear interrupt flag */
            DisableIntT1;/* disable interrupts */
            InitRFData(&rfData);
            MRF49XA_Reset_Radio();

}

static void bcdtoa(int bcd, char* dest)
{
    *dest++=(char)((bcd>>4)+'0');
    *dest=(char)((bcd&0x0f)+'0');
}