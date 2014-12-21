#include"../PIC32/App/crc.c"

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

void Terminal(void);

void Terminal(void)
{
    const char str1[] = {'k',0x00,'e',0x00,'y',0x00,'.',0x00,'b',0x00,'m',0x00,'p',0x00,'\0',0x00};
    const char str2[] = {'\\',0x00,'s',0x00,'y',0x00,'s',0x00,'\0',0x00};
    char KeyBuffer[31]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',',',' ',' ',' ','.'};
    char SpecialKeyBuffer[31]={'1','2','3','4','5','6','7','8','9','0','!','@','#','$','%','&','*','?','/','Z','"',' ','(',')','-','+',';',' ',' ',' ',':'};
     
    const unsigned short int LetterPosX[4]={93,62,32,1};
    const unsigned short int SpecialCharPosY[6]={1,284,1,39,245,284};
     
    const unsigned short int LetterPosY[31]={1,33,65,97,129,161,193,225,257,289,
                                             17,49,81,113,145,177,209,241,273,
                                                49,81,113,145,177,209,241,
                                                   81,113,145,177,209};
    _Bool NumSp=0,UppLow=0,ReadCmd=0,ErrorSyntax=0,HighApp=0,LowApp=0,SyntaxError=0,ExitApp=0,InitRfApp=0,SendApp=0,StatusRfApp=0,ReadApp=0,SetTime=0,SetDate=0;
    char c[2]={'A',0x00};
    char TextBuffer[10],i=0,b=0,Parametri=0,StringBuffer[50],Nchar=0,Param3[10],Param2[10],Param1[10],Param4[10],Param5[10];
    unsigned short int clu=0, dat=0,DelCount=0,a=0x0000;

    TRFData rfData;

    char  Minuti[3]={0x30,0x30,0x00};///minuti
    char  Ore[3]={0x30,0x31,0x00};///Ore

    
    SSD1289_writeResgiter( 0x0049, 0x000A );///fine della finestra a 10 px
    LCD_CLS(AZZURRO);
    sprintf(TextBuffer,"Loading..");
    LCD_Text57(2,1,TextBuffer,1,BLACK,NONE);
    Xcursor=238;
    Ycursor=2;
    wFSchdir ((unsigned short int *)&str2[0]);
    DrawBmp(0,319,(unsigned short int * )&str1[0],0);

    SSD1289_writeResgiter( 0x0049, 0x013F );
    while(TRUE)
    {
        if(PORTDbits.RD14==0)
        {
            read();
            clu=getX();
            dat=getY();
            clu=(unsigned short int)((((float)6.01/(float)233.01)*(float)clu)+(float)clu);
            dat=(unsigned short int)((((float)10.01/(float)313.01)*(float)dat)+(float)dat);
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
                        switch(c[0])
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
                            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,AZZURRO);
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
                            ///da implementare attiva/disattiva numeri+caratteri speciali
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
                            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,AZZURRO);
                            NumSp=0;
                            LCD_Cercle(22,274,3,1,GRAY);
                            UppLow=0;
                            LCD_Cercle(53,29,3,1,BLUE);
                            
                            Ycursor=2;
                            Xcursor-=8;
                            if(Xcursor<=136)
                            {
                                LCD_FastRect(121,0,239,319,AZZURRO);
                                Xcursor=238;
                            }
                            ReadCmd=1;
                            StringBuffer[Nchar]=0x00;
                            Nchar=0;
                            break;
                    }
                    DelayMs(50);
                }
                if(i==1) b=3;
            }
        }


        ///Lampeggio cursore
        DelayMs(1);
        DelCount++;
        if(DelCount==200)
        {
            DelCount=0;
            if(a==0x00000) a=0xffff;
            else a=0x0000;
            LCD_FastRect(Xcursor-6,Ycursor,Xcursor,Ycursor+5,a);
         }

        ///Se premuto invio..
        if(ReadCmd==1)
        {
            ReadCmd=0;
            ErrorSyntax=0;
            Parametri=0;
            b=0;

            ///Ciclo per verificare la stringa passata
            ///carica in Param1, Param2, Param3, ogni parola separata da uno spazio
            for(i=0; i<20; i++)
            {
                if(StringBuffer[i]==0x20) {Parametri=1; Param1[i]=0x00; break;}
                if(StringBuffer[i]==0x00) {Parametri=1; Param1[i]=0x00; break;}
                Param1[i]=StringBuffer[i];
            }

            if(StringBuffer[i]!=0x00)
            {
                b=0;
                for(i<20; i++;)
                {
                    if(StringBuffer[i]==0x20) {Parametri=2; Param2[b]=0x00; break;}
                    if(StringBuffer[i]==0x00) {Parametri=2; Param2[b]=0x00; break;}
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
            ///Fine ciclo

            //Verifica le stringhe
            //da completare salta al programma...
            if(strcmp(Param1,"HIGH")==FALSE) HighApp=1;
            if(strcmp(Param1,"LOW")==FALSE) LowApp=1;
            if(strcmp(Param1,"EXIT")==FALSE) ExitApp=1;
            if(strcmp(Param1,"REBOOT")==FALSE) SoftReset();
            if(strcmp(Param1,"SEND")==FALSE) SendApp=1;
            if(strcmp(Param1,"INITRF")==FALSE) InitRfApp=1;
            if(strcmp(Param1,"STATUSRF")==FALSE) StatusRfApp=1;
            if(strcmp(Param1,"READRF")==FALSE) ReadApp=1;
            if(strcmp(Param1,"SETTIME")==FALSE) SetTime=1;
            if(strcmp(Param1,"SETDATE")==FALSE) SetDate=1;


            if((HighApp==0)&&(LowApp==0)&&(ExitApp==0)&&(SendApp==0)&&(InitRfApp==0)&&(StatusRfApp==0)&&(ReadApp==0)&&(SetTime==0)&&(SetDate==0)) SyntaxError=1;

            if(SetTime)
            {
                SetTime=0;
                Ore[0]=Param2[0];
                Ore[1]=Param2[1];
                Minuti[0]=Param3[0];
                Minuti[1]=Param3[1];
                
                if((Ore[0]>=0x32)&&(Ore[1]>=0x34))
                {
                    sprintf(StringBuffer,"Ore invalide!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
                }
                else if(Minuti[0]>=0x36)
                {
                    sprintf(StringBuffer,"Minuti  invalidi!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
                }
                else{
                    
                    lastTime.hour=atobcd(&Ore[0]);
                    lastTime.min=atobcd(&Minuti[0]);               
                    RtccSetTimeDate(lastTime.l, lastDate.l);
                    sprintf(StringBuffer,"Time updated!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                }
            }

            if(StatusRfApp)
            {
                StatusRfApp=0;
                StatusRead();
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RG_FF_IT);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.POR);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RGUR_FFOV);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.WKUP);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.EXT);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.LBD);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.FFEM);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RSSI_ATS);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.DQD);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.CRL);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor+=16;
                sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.ATGL);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                Ycursor=2;
            }

            if(InitRfApp)
            {
                InitRfApp=0;

                if(strcmp(Param2,"OFF")==FALSE)
                {
                    MRF49XA_Power_Down();
                    sprintf(StringBuffer,"RF Stopped!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
                }

                else{
                    initRFPorts();
                    MRF49XA_Init();
                    InitRFData(&rfData);
                    sprintf(StringBuffer,"RF Initialized! %x",RF_IRQ);
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);

                }
            }

            if(ReadApp)///Test sniff pacchetti
            {
                WORD GENCREG2    = (0x8000|XTAL_LD_CAP_125);
                WORD CFSREG2                             ;
                WORD DRVSREG2                            ;
                WORD RXCREG2                             ;
                WORD PMCREG2 = 0x8201;
                WORD TXCREG2 = 0x9850;
                volatile BOOL RxPacketValid[BANK_SIZE];
                BYTE RxPacket[BANK_SIZE][80];
                volatile BYTE RxPacketLen[BANK_SIZE];
                WORD totalReceived = 0;
                unsigned char FreqBand=0,DataRate=0,Nop=0;
                ReadApp=0;
                sprintf(StringBuffer,"Reading..");
                  LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                //Setta le porte
                mPORTFSetPinsDigitalOut(BIT_5);//SDO
                mPORTFSetPinsDigitalOut(BIT_13);//SCK
                mPORTBSetPinsDigitalOut(BIT_14);//CS
                mPORTBSetPinsDigitalOut(BIT_13);//FSEL
                mPORTESetPinsDigitalIn(BIT_9);//FINT
                mPORTESetPinsDigitalIn(BIT_8);//IRQ
                mPORTFSetPinsDigitalIn(BIT_4);//SDI
                mPORTFSetPinsDigitalIn(BIT_12);//INT

                SPI4CON = 0x0120;
                //SPI1BRG = 0x001F; // 64:1 prescale (slow display update)
                SPI4BRG = 0x0001; // 4:1 prescale (fast display update) 16Mhz spi clock at 72Mhz sys clock
                SPI4CONSET = 0x8000; // enables the spi

                RF_RSCLR;
                DelayUs(10);
                RF_RSSET;
                DelayMs(125);
                RF_CSSET;
                RF_FSELSET;
                //RF_SCKCLR;
                //RF_SDOCLR;
                ///Fine init porte

                i=Param2[0];

                //i=1;
                switch(i)
                {
                    case '1':
                        FreqBand = 1;
                        break;
                    case '2':
                        FreqBand = 2;
                        break;
                    case '3':
                        FreqBand = 3;
                        break;
                }
                GENCREG2 |= ((WORD)FreqBand << 4);

                i=Param3[0];
                //i=1;
                switch(i)
                {
                    case '1':
                        DataRate = 1;
                        DRVSREG2 = 0xC623;
                        break;
                    case '2':
                        DataRate = 2;
                        DRVSREG2 = 0xC611;
                        break;
                    case '3':
                        DataRate = 3;
                        DRVSREG2 = 0xC608;
                        break;
                    case '4':
                        DataRate = 4;
                        DRVSREG2 = 0xC605;
                        break;
                    case '5':
                        DataRate = 5;
                        DRVSREG2 = 0xC602;
                        break;
                }

                i=Param4[0];
                //i=4;
                switch(i)
                {
                    case '1':
                        RXCREG2 = 0x9421;
                        break;

                    case '2':
                        RXCREG2 = 0x9441;
                        break;

                    case '3':
                        RXCREG2 = 0x9461;
                        break;

                    case '4':
                        RXCREG2 = 0x9481;
                        break;

                    case '5':
                        RXCREG2 = 0x94A1;
                        break;

                    case '6':
                        RXCREG2 = 0x94C1;
                        break;
                }

                switch(FreqBand)
                {
                    case 1:
                        CFSREG2 = 0xA640;
                        break;

                    case 2:
                        CFSREG2 = 0xA640;
                        break;

                    case 3:
                        CFSREG2 = 0xA7D0;
                        break;

                    default:
                        break;
                }

                
                
                //Init RF
                SPI_Command(FIFORSTREG);
                SPI_Command( FIFORSTREG | 0x0002);
                SPI_Command(GENCREG2);
                SPI_Command(0xC4F7);
                SPI_Command(CFSREG2);
                SPI_Command(DRVSREG2);
                SPI_Command(PMCREG2);
                SPI_Command(RXCREG2);
                SPI_Command(TXCREG2);
                SPI_Command(PMCREG2 | 0x0020);
                DelayMs(5);
                SPI_Command(PMCREG2 | 0x0080);
                SPI_Command(GENCREG2 | 0x0040);
                SPI_Command(FIFORSTREG);
                SPI_Command( FIFORSTREG | 0x0002);
                SPI_Command(0x0000);

                //InitRFData(&rfData);
                sprintf(StringBuffer,"%x, %x, %x",Param2[0],Param3[0],Param4[0]);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                sprintf(StringBuffer,"%x,%x",RF_IRQ,RF_INT);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                while(TRUE)
                {
                    if((RF_IRQ==0)||(RF_INT==1))
                    {
                        
                        //nCS = 0;
                        RF_CSCLR;
                        Nop++;
                        if( SPI_SDI == 1 )
                        {
                            BYTE RxPacketPtr;
                            BYTE tmpPacketLen;
                            BYTE bIndex;
                            WORD counter;

                            // There is data in RX FIFO
                            //nCS = 1;
                            //nFSEL = 0;                   // FIFO selected
                            RF_CSSET;
                            RF_FSELCLR;

                            tmpPacketLen = SPI_Read();

                            for(bIndex = 0; bIndex < BANK_SIZE; bIndex++)
                            {
                                if( RxPacketValid[bIndex] == FALSE )
                                {
                                    break;
                                }
                            }

                            if( tmpPacketLen >= 80 || tmpPacketLen == 0 || bIndex >= BANK_SIZE )
                            {
                                IGNORE_HERE:
                                //nFSEL = 1;                          // bad packet len received
                                RF_FSELSET;
                                SPI_Command(PMCREG2);                // turn off the transmitter and receiver
                                SPI_Command(FIFORSTREG);            // reset FIFO
                                SPI_Command(GENCREG2);               // disable FIFO, TX_latch
                                SPI_Command(GENCREG2 | 0x0040);      // enable FIFO
                                SPI_Command(PMCREG2 | 0x0080);       // turn on receiver
                                SPI_Command(FIFORSTREG | 0x0002);   // FIFO synchron latch re-enabled
                                goto RETURN_HERE;
                            }

                            RxPacketLen[bIndex] = tmpPacketLen;
                            //RLED = 1;
                            //nFSEL = 1;
                            mPORTDSetBits(BIT_2);
                            RF_FSELSET;

                            RxPacketPtr = 0;
                            counter = 0;

                            while(1)
                            {
                                if( counter++ == 0xFFFF )
                                {
                                    goto IGNORE_HERE;
                                }
                                else if( RF_FINT == 1)
                                    {
                                    //nFSEL = 0;
                                    RF_FSELCLR;
                                    counter = 0;
                                    RxPacket[bIndex][RxPacketPtr++] = SPI_Read();

                                    if( RxPacketPtr >= RxPacketLen[bIndex] )
                                    {
                                        BYTE i;

                                        //nFSEL = 1;
                                        //nCS = 0;
                                        RF_FSELSET;
                                        RF_CSCLR;

                                        //SPI_SDO = 0;
                                        RF_SDOCLR;
                                        Nop++;
                                        for(i = 0; i < 8; i++)
                                        {
                                            //SPI_SCK = 1;
                                            //SPI_SCK = 0;                                       
                                            RF_SCKSET;
                                            Nop++;
                                            RF_SCKCLR;
                                            Nop++;
                                        }


                                        if( SPI_SDI == 0 )
                                        {
                                            goto IGNORE_HERE;
                                        }
                                        //nCS = 1;
                                        RF_CSSET;


                                        SPI_Command(FIFORSTREG);
                                        //RLED = 0;
                                        mPORTDClearBits(BIT_2);
                                        RxPacketValid[bIndex] = TRUE;
                                        SPI_Command(FIFORSTREG | 0x0002);            // FIFO synchron latch re-enable

                                        goto RETURN_HERE;
                                    }
                                    //nFSEL = 1;
                                    RF_FSELSET;
                                    }
                                }
                            }
                            else            // read the rest of the interrupts
                            {
                                SPI_Read();

                                //nCS = 1;
                                RF_CSSET;
                            }

                            RETURN_HERE:
                        Nop++;
                    }
                    
                    for(i = 0; i < BANK_SIZE; i++)
                    {
                        if( RxPacketValid[i] == TRUE )
                        {
                            BYTE j;
                            WORD received_crc;
                            WORD calculated_crc;
                
                            totalReceived++;  
                            //Printf("\r\n");
                            Xcursor-=8;
                            Ycursor=2;

                            sprintf(StringBuffer,"%04x | %04x |",totalReceived,RxPacketLen[i]);
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                            //PrintChar(totalReceived>>8);
                            //PrintChar(totalReceived);

                            //Printf(" | ");
                            //PrintChar(RxPacketLen[i]);
                            //Printf(" | ");

                            for(j = 0; j < RxPacketLen[i]; j++)
                            {
                                sprintf(StringBuffer,"%02x ",RxPacket[i][j]);
                                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                                Ycursor+=12;
                                //PrintChar(RxPacket[i][j]);
                                //Printf(" ");
                            }
                            received_crc = ((WORD)RxPacket[i][RxPacketLen[i]-1]) + (((WORD)RxPacket[i][RxPacketLen[i]-2]) << 8);
                            calculated_crc = CRC16(RxPacket[i], RxPacketLen[i]-2);
                            if( received_crc != calculated_crc )
                            {
                                //Printf(" * CRC");
                                sprintf(StringBuffer," * CRC");
                                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
                            }
                            RxPacketValid[i] = FALSE;
                
                        }
                    }





















                    //i=MRF49XA_Receive_Packet(&rfData);
                    //DelayUs(50);
                    //if(i==3) break;
                    //if(i==2) break;
                    //if(i==1) break;
                    //sprintf(StringBuffer,"%x,%x,%x",RF_IRQ,RF_FINT,SPI_SDI);
                    //LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                    if(PORTDbits.RD14==0) break;
                }
                Xcursor-=8;

                sprintf(StringBuffer,"Ricevuto! %d, 0x%02x, 0x%02x, 0x%02x, 0x%02x",i,rfData.buffer[0],rfData.buffer[1],rfData.buffer[2],rfData.buffer[3]);
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);


}
            if(SendApp)
            {
                SendApp=0;
                //LCD_FastRect(121,0,239,319,AZZURRO);
                AddRFData(&rfData,Param2[0]);
                MRF49XA_Send_Packet(&rfData);
		InitRFData(&rfData);

                sprintf(StringBuffer,"Dato inviato..");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
            }
            if(HighApp)
            {
                HighApp=0;
                if(strcmp(Param2,"D2")==FALSE)
                {
                    sprintf(StringBuffer,"D2 Actived! 1");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,GREEN,NONE);
                    mPORTDSetPinsDigitalOut(BIT_2);
                    mPORTDSetBits(BIT_2);
                 }
                 else
                 {
                    sprintf(StringBuffer,"Port Not Found!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
                 }
            }
            if(LowApp)
            {
                LowApp=0;
                if(strcmp(Param2,"D2")==FALSE)
                {
                    sprintf(StringBuffer,"D2 Deactived! 0");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,GREEN,NONE);
                    mPORTDSetPinsDigitalOut(BIT_2);
                    mPORTDClearBits(BIT_2);
                }
                else
                {
                    sprintf(StringBuffer,"Port Not Found!");
                    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
                }
            }

            if(SyntaxError)
            {
                SyntaxError=0;
                sprintf(StringBuffer,"Syntax Error!");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
            }

            if(ExitApp==1) break;
            
            Xcursor-=8;
            Ycursor=2;
            
            for(i=0; i<10; i++)
            {
                StringBuffer[i]=0x00;
                Param1[i]=0x00;
                Param2[i]=0x00;
                Param3[i]=0x00;
            }
        }
        if(PORTDbits.RD3==0) break;
    }
}