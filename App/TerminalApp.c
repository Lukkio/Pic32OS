void LedHigh(void);
void LedLow(void);
void Sendrf(void);
void Initrf(void);
void Satusrf(void);
void ReadRF(void);
void SetTime(void);
void SetData(void);
void SyntaxError(void);
void ReadPk(void);
void SendPk(void);
void SendPot(void);
void ListCmd(void);
void TouchCalib(void);

void ReadPot(void);

void ReadPot(void)
{
    unsigned char PackState=0,ChkSumLed=0,a,c=0;
    unsigned short int pos16=0x0000,count=0;
    MRF49XA_Init();
    InitRFData(&rfData);
    LCD_CLS(AZZURRO);
    sprintf(StringBuffer,"100%\r");
    LCD_Text57Land(238,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"50%\r");
    LCD_Text57Land(120,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"0%\r");
    LCD_Text57Land(10,Ycursor,StringBuffer,1,BLACK,NONE);

    PacketReady=0;
    ResetRadio=0;

    while(TRUE)
    {
        c=RF_CS_IRQ;
        
        if(c==1)
        {
            a++;
            IFS0bits.INT2IF=1;
            sprintf(StringBuffer,"\r%u\r",a);
            LCD_Text57Land(100,100,StringBuffer,1,BLACK,AZZURRO);
        }
        
        if (PacketReady==1)
        {
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
            //break;
        }
        if(ChkSumLed == 1)
        {
            ChkSumLed=0;
            count++;
            
            LCD_FastRect(0,count,239,count+2,AZZURRO);
            if(count==317) count=0;
            
            //pos16=rfData.buffer[0];
           // pos16=rfData.buffer[1];

            //pos16=((rfData.buffer[0] & pos16)<<8);
           // pos16=(rfData.buffer[1] & pos16);

            pos16 = (rfData.buffer[1] << 8 ) | rfData.buffer[0];

            sprintf(StringBuffer,"\r%u\r",pos16);
            LCD_Text57Land(10,Ycursor,StringBuffer,1,BLACK,AZZURRO);

            pos16=(unsigned short int)((pos16*240)/1024);

            LCD_FastRect(pos16,count,pos16+1,count+1,BLACK);
            //LCD_Pixel(pos16,count,BLACK);
            //sprintf(StringBuffer,"%u\r",pos16);
            //LCD_Text57Land(238,Ycursor,StringBuffer,1,BLACK,AZZURRO);
            //if(Xcursor<=136) {Xcursor=238; LCD_FastRect(121,0,239,319,AZZURRO);}
        }
        if (ResetRadio==1) {
            ResetRadio=0;
            mINT1ClearIntFlag();/* clear interrupt flag */
            DisableIntT1;/* disable interrupts */
            //CloseTimer1();/* stop the timer */
            //ChkSumLed = 1;
            InitRFData(&rfData);
            MRF49XA_Reset_Radio();
        }
        if(PORTDbits.RD14==0) {InitTerminal(); break;}
    }

}

void SendPk(void)
{
    MRF49XA_Init();
    InitRFData(&rfData);
    AddRFData(&rfData,4);
    //AddRFData(&rfData,2);
    //AddRFData(&rfData,3);
    //AddRFData(&rfData,4);

    while(TRUE)
    {
        MRF49XA_Send_Packet(&rfData);
        if(PORTDbits.RD14==0) break;
        DelayUs(800);
    }
    InitRFData(&rfData);
    sprintf(StringBuffer,"Dato inviato!");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,GREEN,NONE);
}
void ReadPk(void)
{
    unsigned char PackState=0,ChkSumLed=0,count=0;
    Ycursor=10;
    //MRF49XA_Init();
    InitRFData(&rfData);
    sprintf(StringBuffer,"Reading..\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    PacketReady=0;
    ResetRadio=0;
    Ycursor=10;

    while(TRUE)
    {
        if (PacketReady==1)
        {
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
            //break;
        }
        if(ChkSumLed == 1)
        {
            ChkSumLed=0;
            count++;
            sprintf(StringBuffer,"%x,%x,%x,%x,%u \r\n",rfData.buffer[0],rfData.buffer[1],rfData.buffer[2],rfData.buffer[3],count);
            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
            if(Xcursor<=136) {Xcursor=238; LCD_FastRect(121,0,239,319,AZZURRO);}
        }
        if (ResetRadio==1) {
            ResetRadio=0;
            mINT1ClearIntFlag();/* clear interrupt flag */
            DisableIntT1;/* disable interrupts */
            //CloseTimer1();/* stop the timer */
            //ChkSumLed = 1;
            InitRFData(&rfData);
            MRF49XA_Reset_Radio();
        }
        if(PORTDbits.RD14==0) break;
    }


    /*
    while(TRUE)
    {
        DelayUs(850);
        PackState = MRF49XA_Receive_Packet(&rfData);
        if(PackState==2) break;
        if(PORTDbits.RD14==0) break;
        //sprintf(StringBuffer,"%x,%x,%x,%x",RF_IRQ,RF_FINT,SPI_SDI,RF_INT);
        //LCD_Text57Land(200,100,StringBuffer,1,GREEN,AZZURRO);
    }
    sprintf(StringBuffer,"%x,%x,%x,%x,%x",rfData.buffer[0],rfData.buffer[1],rfData.buffer[2],rfData.buffer[3],PackState);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    MRF49XA_Reset_Radio();*/
}

void ColorConv(void)
{
    char c=0;
    unsigned short int R=0, G=0, B=0;
    unsigned int Color16=0;
    Ycursor=10;
    if(strcmp(Param2,"-rgb24")==FALSE)
    {
        //Converte stringa in intero
        for(c=0; Param3[c] != '\0'; c++) R = R * 10 + Param3[c] - '0';
        for(c=0; Param4[c] != '\0'; c++) G = G * 10 + Param4[c] - '0';
        for(c=0; Param5[c] != '\0'; c++) B = B * 10 + Param5[c] - '0';

        Color16=RGB16(R,G,B);
        sprintf(StringBuffer,"RGB16: 0x%04x",Color16);
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,Color16,NONE);
    }
    else
    {
        sprintf(StringBuffer,"Usage: color -rgb24 123 123 123");
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    }
}


void LedHigh(void)
{
    Ycursor=10;
    if(strcmp(Param2,"d2")==FALSE)
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

void LedLow(void)
{
    Ycursor=10;
    if(strcmp(Param2,"d2")==FALSE)
    {
        sprintf(StringBuffer,"D2 Deactived! 1");
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

void Sendrf(void)
{
    BYTE centinaia=0, decine=0,unita=0,risultato=0;

    Ycursor=10;
    sprintf(StringBuffer,"Scrivi un valore tra 000 - 255");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);

    while(TRUE)
    {
        INIZIA:
        InitRFData(&rfData);
        ConsoleReady();
        if(strcmp(Param1,"exit")==FALSE) break;

        
        centinaia=(Param1[0] & 0x0F)*100;
        decine=(Param1[1] & 0x0F)*10;
        unita=Param1[2] & 0x0F;
        
        risultato=centinaia+decine+unita;

        if(Param1[3]!=0x00)
        {
            sprintf(StringBuffer,"Valore non valido! (000 - 255)");
            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
            goto INIZIA;
        }
        else
        {
            AddRFData(&rfData,risultato);
            MRF49XA_Send_Packet(&rfData);
            sprintf(StringBuffer,"Inviato: %u",risultato);
            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
        }
    }
}

void Initrf(void)
{
    if(strcmp(Param2,"off")==FALSE)
    {
        MRF49XA_Power_Down();
        sprintf(StringBuffer,"RF Stopped!");
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
    }
    else
        
    {
        if((strcmp(Param2,"rs")==FALSE)) ResetRF();
        //initRFPorts();
        MRF49XA_Init();
        //InitRFData(&rfData);
        sprintf(StringBuffer,"RF Initialized! %x",RF_IRQ);
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    }
}

void Satusrf(void)
{
    unsigned short int Statusbits;
    unsigned char i=0;

    Statusbits=StatusRead();

    for(i=0; i<16; i++)
    {
        if(BitTest(Statusbits, i)) sprintf(StringBuffer,"1 ");
        else  sprintf(StringBuffer,"0 ");
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    }

    /*sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RG_FF_IT);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.POR);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RGUR_FFOV);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.WKUP);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.EXT);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.LBD);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.FFEM);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.RSSI_ATS);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.DQD);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x ",TransceiverStatus.bits.CRL);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
    sprintf(StringBuffer,"%02x",TransceiverStatus.bits.ATGL);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);*/
}

void ReadRF(void)
{
    WORD GENCREG2=(0x8000|XTAL_LD_CAP_125);
    WORD CFSREG2;
    WORD DRVSREG2;
    WORD RXCREG2;
    WORD PMCREG2 = 0x8201;
    WORD TXCREG2 = 0x9850;
    volatile BOOL RxPacketValid[BANK_SIZE];
    BYTE RxPacket[BANK_SIZE][80];
    volatile BYTE RxPacketLen[BANK_SIZE];
    WORD totalReceived=0;
    unsigned char FreqBand=0,DataRate=0,Nop=0,i=0,j=0;
    BYTE Channel;

    sprintf(StringBuffer,"MRF49XA snif packet\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
FreqBandAgain:
    sprintf(StringBuffer,"Frequency Band: \r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(1) 434MHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(2) 868MHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(3) 915MHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    ConsoleReady();

    switch(Param1[0])
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
        default:
            goto FreqBandAgain;
    }
    GENCREG2 |= ((WORD)FreqBand << 4);
DataRateAgain:
    sprintf(StringBuffer,"Data Rate: \r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(1) 9.6Kbps\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(2) 19.2Kbps\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(3) 38.4Kbps\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(4) 57.6Kbps\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(5) 115.2Kbps\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    ConsoleReady();

    switch(Param1[0])
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
        default:
            goto DataRateAgain;
    }
BandwidthAgain:
    sprintf(StringBuffer,"Receiver Bandwidth:\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(1) 400KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(2) 340KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(3) 270KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(4) 200KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(5) 134KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    sprintf(StringBuffer,"(6) 67KHz\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
    ConsoleReady();

    switch(Param1[0])
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

        default:
            goto BandwidthAgain;
    }
ChannelAgain:

    sprintf(StringBuffer,"Channel: (Two Decimal, 01 for Channel 1)\r\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);

    ConsoleReady();
    i=Param1[0];
    j=Param1[1];

    if( i < '0' && i > '3' )
        {
            goto ChannelAgain;
        }
    if( j < '0' && j > '9' )
        {
            goto ChannelAgain;
        }
    Channel = (i - '0') * 10 + (j - '0');
        switch(FreqBand)
        {
            case 1:
                switch(DataRate)
                {
                    case 1:
                        if(Channel > 4)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-04\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-04");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)1332 + (WORD)132 * Channel;
                        break;

                    case 2:
                        if( Channel > 3)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-03\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-03");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)1412 + (WORD)154 * Channel;
                        break;

                    case 3:
                        if( Channel > 3)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-03\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-03");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)1388 + (WORD)180 * Channel;
                        break;

                    case 4:
                        if( Channel > 2)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-02\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-02");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)1444 + (WORD)256 * Channel;
                        break;

                    case 5:
                        if( Channel > 1)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-01\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-01");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)1564 + (WORD)345 * Channel;
                        break;
                    default:
                        break;
                }
                break;

            case 2:

                switch(DataRate)
                {
                    case 1:
                        if( Channel > 14)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-14\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-14");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)710 + (WORD)90 * Channel;
                        break;

                    case 2:
                        if( Channel > 11)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-11\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-11");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)740 + (WORD)110 * Channel;
                        break;

                    case 3:
                        if( Channel > 10)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-10\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-10");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)724 + (WORD)128 * Channel;
                        break;

                    case 4:
                        if( Channel > 8)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-08\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-08");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)750 + (WORD)157 * Channel;
                        break;

                    case 5:
                        if( Channel > 6)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-06\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-06");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)800 + (WORD)200 * Channel;
                        break;

                    default:
                        break;

                }
                break;

            case 3:

                switch(DataRate)
                {
                    case 1:
                        if( Channel > 31)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-31\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-31");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)320 + (WORD)105 * Channel;
                        break;

                    case 2:
                        if( Channel > 31)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-31\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-31");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)320 + (WORD)105 * Channel;
                        break;

                    case 3:
                        if( Channel > 31)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-31\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-31");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)320 + (WORD)105 * Channel;
                        break;

                    case 4:
                        if( Channel > 31)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-31\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-31");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)320 + (WORD)105 * Channel;
                        break;

                    case 5:
                        if( Channel > 25)
                        {
                            sprintf(StringBuffer,"Valid Channel 00-25\r\n");
                            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                            //Printf("\r\nValid Channel 00-25");
                            goto InvalidChannel;
                        }
                        CFSREG2 = 0xA000 + (WORD)333 + (WORD)134 * Channel;
                        break;

                    default:
                        break;

                }
                break;

            default:
InvalidChannel:
                sprintf(StringBuffer,"Invalid Channel! Enter it again.\r\n");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);
                //Printf("\r\nInvalid Channel! Enter it again.");
                break;
        }



    SPI_Command(FIFORSTREG);
    SPI_Command( FIFORSTREG | 0x0002);
    SPI_Command(GENCREG);
    SPI_Command(0xC4D7);
    SPI_Command(CFSREG);
    SPI_Command(DRSREG);
    SPI_Command(PMCREG);
    SPI_Command(RXCREG);
    SPI_Command(TXCREG);
    SPI_Command(PMCREG | 0x0020);
    DelayMs(5);
    SPI_Command(PMCREG | 0x0080);
    SPI_Command(GENCREG | 0x0040);
    SPI_Command(FIFORSTREG);
    SPI_Command( FIFORSTREG | 0x0002);
    SPI_Command(0x0000);
    RF_FSELSET;
    
    sprintf(StringBuffer,"Freq: %x, DataR: %x, RXC: %x, CREG: %x\r\n",FreqBand,DataRate,RXCREG2,CFSREG2);
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,AZZURRO);

    sprintf(StringBuffer,"Setup Finished\r\n");
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
                    if(PORTDbits.RD14==0) break;
                }

}



void SetTime(void)
{
    unsigned char Ore[3];
    unsigned char Minuti[3];
    Ycursor=10;

    if((strcmp(Param2,"-h")==FALSE)||(Parametri<3))//Help
    {
        sprintf(StringBuffer,"Usage: setime HH MM");
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
    }
    else
    {
        Ore[0]=Param2[0];
        Ore[1]=Param2[1];
        Minuti[0]=Param3[0];
        Minuti[1]=Param3[1];
        
        if((Ore[0]>=0x32)&&(Ore[1]>=0x34))
        {
            sprintf(StringBuffer,"Ore invalide!");
            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
        }
        else
        {
            if(Minuti[0]>=0x36)
            {
                sprintf(StringBuffer,"Minuti  invalidi!");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
            }
            else
            {
                lastTime.hour=atobcd(&Ore[0]);
                lastTime.min=atobcd(&Minuti[0]);
                RtccSetTimeDate(lastTime.l, lastDate.l);
                sprintf(StringBuffer,"Time updated!");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
            }
        }
    }
}

void SetData(void)
{
    unsigned char Giorno[3];
    unsigned char Mese[3];
    unsigned char Anno[3];
    Ycursor=10;
    
    if((strcmp(Param2,"-h")==FALSE)||(Parametri<4))//Help
    {
        sprintf(StringBuffer,"Usage: setdate GG MM AA");
        LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
    }
    else
    {
        Giorno[0]=Param2[0];
        Giorno[1]=Param2[1];
        Mese[0]=Param3[0];
        Mese[1]=Param3[1];
        Anno[0]=Param4[0];
        Anno[1]=Param4[1];

        if((Mese[0]>=0x32)&&(Mese[1]>=0x33))
        {
            sprintf(StringBuffer,"Mese invalido!");
            LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
        }
        else
        {
            if((Giorno[0]>=0x33)&&(Giorno[1]>=0x32))
            {
                sprintf(StringBuffer,"Giorno invalido!");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
            }
            else
            {
                lastDate.mday=atobcd(&Giorno[0]);
                lastDate.mon=atobcd(&Mese[0]);
                lastDate.year=atobcd(&Anno[0]);

                lastTime.l=RtccGetTime();
                RtccSetTimeDate(lastTime.l, lastDate.l);
                sprintf(StringBuffer,"Date updated!");
                LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
            }
        }
    }
}

void SyntaxError(void)
{
    Ycursor=10;
    sprintf(StringBuffer,"Comando non valido!");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,RED,NONE);
}

void SendPot(void)
{
    _Bool Pos=0;
    BYTE RealPot=255,TextBuffer[10];
    unsigned short int Position=0,PotVal=310,dat=0, clu=0;
    InitRFData(&rfData);
    LCD_CLS(WHITE);
    sprintf(StringBuffer,"Potenziometro");
    LCD_Text57(2,3,StringBuffer,2,BLACK,NONE);

    //sprintf(StringBuffer,"0");
    //Position=CenterX(120,2,ALIGNMENT_CENTER,(unsigned short int * )&StringBuffer[0]);
    //LCD_Text57(Position,35,StringBuffer,2,BLACK,NONE);

    sprintf(StringBuffer,"100%");
    LCD_Text57(10,52,StringBuffer,2,BLACK,NONE);
    sprintf(StringBuffer,"50%");
    LCD_Text57(10,182,StringBuffer,2,BLACK,NONE);
    sprintf(StringBuffer,"0%");
    LCD_Text57(10,297,StringBuffer,2,BLACK,NONE);

    sprintf(StringBuffer,"Esci");
    LCD_Text57(190,300,StringBuffer,2,BLACK,NONE);


    LCD_FastRect(70,310,170,310,GREEN);
    LCD_Rect(67,52,173,313,0,BLACK);


    setPrecision(PREC_LOW);
    while(TRUE)
    {
        if(PORTDbits.RD14==0)
        {
            read();
            clu=getX();
            dat=getY();
            clu=(unsigned short int)((((float)6.01/(float)233.01)*(float)clu)+(float)clu);
            dat=(unsigned short int)((((float)10.01/(float)313.01)*(float)dat)+(float)dat);

            if(((70<=clu)&&(clu<=170))&&(PotVal<dat))
            {
                PotVal++;
                RealPot++;
                if(PotVal==311)
                {
                    PotVal=310;
                    RealPot=255;   
                }
                Pos=1;
            }

            if(((70<=clu)&&(clu<=170))&&(PotVal>dat))
            {
                PotVal--;
                RealPot--;
                if(PotVal==54)
                {
                    PotVal++;
                    RealPot++;               
                }
                Pos=1;
            }

            if(Pos==1)
            {
                Pos=0;
                //sprintf(StringBuffer,"%u",RealPot);
                //Position=CenterX(120,2,ALIGNMENT_CENTER,(unsigned short int * )&StringBuffer[0]);
                //LCD_FastRect(100,35,140,52,WHITE);
                //LCD_Text57(Position,35,StringBuffer,2,BLACK,NONE);
                          
                LCD_FastRect(70,PotVal,170,PotVal,GREEN);
                LCD_FastRect(70,PotVal-1,170,PotVal-1,WHITE);
                AddRFData(&rfData,RealPot);
                MRF49XA_Send_Packet(&rfData);
                InitRFData(&rfData);
            }

            if(((210<=clu)&&(clu<=239))&&((300<=dat)&&(dat<=319)))
                {
                    InitTerminal();
                    setPrecision(PREC_EXTREME);
                    break;
                }
        }
        DelayUs(1);
    }
}

void ListCmd(void)
{
    Ycursor=10;
    sprintf(StringBuffer,"high | low | exit | reboot | send | initrf\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);

    Ycursor=10;
    sprintf(StringBuffer,"statusrf | readrf | setime | setdate | readpk\n");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);

    Ycursor=10;
    sprintf(StringBuffer,"sendpk | potrf | sendpot | list | color");
    LCD_Text57Land(Xcursor,Ycursor,StringBuffer,1,BLACK,NONE);
}

void TouchCalib(void)
{
    unsigned short int PanelPointX[3];
    unsigned short int PanelPointY[3];

    unsigned short int TouchPointX[3];
    unsigned short int TouchPointY[3];

    unsigned char CountPoint=0;
    signed short TP_X_REAL_LOCAL[3], TP_Y_REAL_LOCAL[3];
    //float _ax, _bx, _dx, _ay, _by, _dy;

    signed int delta,deltaX1,deltaX2,deltaX3,deltaY1,deltaY2,deltaY3;

    signed short int datacount=0,  temp_x, temp_y;
    
    signed int ty, tx;
    
    LCD_CLS(WHITE);
    sprintf(StringBuffer,"Touch Screen Calibrator");
    LCD_Text57Land(220,10,StringBuffer,2,BLACK,NONE);

    DelayMs(100);

    PanelPointX[0]=(240*5)/100;// X=25% 60
    PanelPointX[1]=(240*75)/100;// X=75% 180
    PanelPointX[2]=(240*75)/100;// X=75% 180

    PanelPointY[0]=(320*50)/100;// Y=50% 160
    PanelPointY[1]=(320*5)/100;// Y=25% 80
    PanelPointY[2]=(320*95)/100;// Y=75% 240

    LCD_FastRect(PanelPointX[0],PanelPointY[0],PanelPointX[0]+1,PanelPointY[0]+1, BLUE);
    LCD_FastRect(PanelPointX[1],PanelPointY[1],PanelPointX[1]+1,PanelPointY[1]+1, BLUE);
    LCD_FastRect(PanelPointX[2],PanelPointY[2],PanelPointX[2]+1,PanelPointY[2]+1, BLUE);


    for(CountPoint=0; CountPoint<=2; CountPoint++)
    {
        sprintf(StringBuffer,"Tap and hold the red point");
        LCD_Text57Land(200,10,StringBuffer,1,BLACK,WHITE);
        LCD_FastRect(PanelPointX[CountPoint],PanelPointY[CountPoint],PanelPointX[CountPoint]+1,PanelPointY[CountPoint]+1, RED);

        while(TRUE)
        {
            if(PORTDbits.RD14==0)
            {
                //read();

                datacount=0;
                ty=0;
                tx=0;
                temp_x=0;
                temp_y=0;
                
                T_CS=0;

	for (i=0; i<prec; i++)
	{
		touch_WriteData(0x90);
		T_CLK=1;
		T_CLK=0;
		temp_x=touch_ReadData();

		touch_WriteData(0xD0);
		T_CLK=1;
		T_CLK=0;
		temp_y=touch_ReadData();
		ty+=temp_x;
		tx+=temp_y;
		datacount++;
	}

	T_CS=1;

                TP_X_REAL=tx/datacount;
                TP_Y_REAL=ty/datacount;


                TP_X_REAL_LOCAL[CountPoint]=TP_X_REAL;
                TP_Y_REAL_LOCAL[CountPoint]=TP_Y_REAL;
                //TouchPointX[CountPoint]=getX();
                //TouchPointY[CountPoint]=getY();
                TouchPointX[CountPoint]=TP_X_REAL_LOCAL[CountPoint];
                TouchPointY[CountPoint]=TP_Y_REAL_LOCAL[CountPoint];
                break;
            }
        }

        LCD_FastRect(PanelPointX[CountPoint],PanelPointY[CountPoint],PanelPointX[CountPoint]+1,PanelPointY[CountPoint]+1, WHITE);
        sprintf(StringBuffer,"Stop pressing the screen  ");
        LCD_Text57Land(200,10,StringBuffer,1,BLACK,WHITE);
        DelayMs(600);
        LCD_FastRect(PanelPointX[CountPoint],PanelPointY[CountPoint],PanelPointX[CountPoint]+1,PanelPointY[CountPoint]+1, BLUE);
    }

    delta=((signed int)(TouchPointX[0]-TouchPointX[2])*(signed int)(TouchPointY[1]-TouchPointY[2]))-((signed int)(TouchPointX[1]-TouchPointX[2])*(signed int)(TouchPointY[0]-TouchPointY[2]));

    deltaX1=((signed int)(PanelPointX[0]-PanelPointX[2])*(signed int)(TouchPointY[1]-TouchPointY[2]))-((signed int)(PanelPointX[1]-PanelPointX[2])*(signed int)(TouchPointY[0]-TouchPointY[2]));
    deltaX2=((signed int)(TouchPointX[0]-TouchPointX[2])*(signed int)(PanelPointX[1]-PanelPointX[2]))-((signed int)(TouchPointX[1]-TouchPointX[2])*(signed int)(PanelPointX[0]-PanelPointX[2]));
    deltaX3=PanelPointX[0]*((signed int)TouchPointX[1]*(signed int)TouchPointY[2] - (signed int)TouchPointX[2]*(signed int)TouchPointY[1]) - PanelPointX[1]*(TouchPointX[0]*(signed int)TouchPointY[2] - (signed int)TouchPointX[2]*(signed int)TouchPointY[0]) + PanelPointX[2]*((signed int)TouchPointX[0]*(signed int)TouchPointY[1] - (signed int)TouchPointX[1]*(signed int)TouchPointY[0]);

    deltaY1=((signed int)(PanelPointY[0]-PanelPointY[2])*(signed int)(TouchPointY[1]-TouchPointY[2]))-((signed int)(PanelPointY[1]-PanelPointY[2])*(signed int)(TouchPointY[0]-TouchPointY[2]));
    deltaY2=((signed int)(TouchPointX[0]-TouchPointX[2])*(signed int)(PanelPointY[1]-PanelPointY[2]))-((signed int)(TouchPointX[1]-TouchPointX[2])*(signed int)(PanelPointY[0]-PanelPointY[2]));
    deltaY3=PanelPointY[0]*((signed int)TouchPointX[1]*(signed int)TouchPointY[2] - (signed int)TouchPointX[2]*(signed int)TouchPointY[1]) - PanelPointY[1]*((signed int)TouchPointX[0]*(signed int)TouchPointY[2] - (signed int)TouchPointX[2]*(signed int)TouchPointY[0]) + PanelPointY[2]*((signed int)TouchPointX[0]*(signed int)TouchPointY[1] - (signed int)TouchPointX[1]*TouchPointY[0]);

    _ax=(float)deltaX1/(float)delta;
    _bx=(float)deltaX2/(float)delta;
    _dx=(float)deltaX3/(float)delta;

    _ay=(float)deltaY1/(float)delta;
    _by=(float)deltaY2/(float)delta;
    _dy=(float)deltaY3/(float)delta;


    ///Calcola la corretta posizione del touch rispetto al display


    for(CountPoint=0; CountPoint<=2; CountPoint++)
    {
        TouchPointX[CountPoint]=_ax*TouchPointX[CountPoint] + _bx*TouchPointY[CountPoint] + _dx;
        TouchPointY[CountPoint]=_ay*TouchPointX[CountPoint] + _by*TouchPointY[CountPoint] + _dy;
    }

    //sprintf(StringBuffer,"Value calculated: %lf, %lf, %lf, %lf, %lf, %lf, ",_ax, _bx, _dx, _ay, _by, _dy);
    sprintf(StringBuffer,"Value calculated: %ld, %ld, %ld, %ld, %ld, %ld, %ld",delta,deltaX1,deltaX2,deltaX3,deltaY1,deltaY2,deltaY3);
    LCD_Text57Land(180,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X1=%03d Y1=%03d",TouchPointX[0],TouchPointY[0]);
    LCD_Text57Land(160,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X2=%03d Y2=%03d",TouchPointX[1],TouchPointY[1]);
    LCD_Text57Land(150,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X3=%03d Y3=%03d",TouchPointX[2],TouchPointY[2]);
    LCD_Text57Land(140,10,StringBuffer,1,BLACK,WHITE);

    
    
    
    sprintf(StringBuffer,"Value printed:");
    LCD_Text57Land(120,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X1=060 Y1=160");
    LCD_Text57Land(110,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X2=180 Y2=080");
    LCD_Text57Land(100,10,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X3=180 Y3=240");
    LCD_Text57Land(90,10,StringBuffer,1,BLACK,WHITE);


    sprintf(StringBuffer,"X1=%03d Y1=%03d",TP_X_REAL_LOCAL[0],TP_Y_REAL_LOCAL[0]);
    LCD_Text57Land(110,160,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X2=%03d Y2=%03d",TP_X_REAL_LOCAL[1],TP_Y_REAL_LOCAL[1]);
    LCD_Text57Land(100,160,StringBuffer,1,BLACK,WHITE);

    sprintf(StringBuffer,"X3=%03d Y3=%03d",TP_X_REAL_LOCAL[2],TP_Y_REAL_LOCAL[2]);
    LCD_Text57Land(90,160,StringBuffer,1,BLACK,WHITE);


    sprintf(StringBuffer,"Calibration completed. Tap to exit!");
    LCD_Text57Land(70,10,StringBuffer,1,BLACK,WHITE);

    while(PORTDbits.RD14==1);

    InitTerminal();
}
