rtccTime TimeCorrente;
rtccDate DateCorrente;
rtccTime TimeOld;
rtccDate DateOld;

static void bcdtoab(int bcd, char* dest); ///Converte l'ora del rtcc in decimale

void InitDataOra(void)
{
    RtccInit();
    while(RtccGetClkStat()!=RTCC_CLK_ON);

    //Init Time & date
    TimeOld.hour=0x17;
    TimeOld.min=0x00;
    TimeOld.sec=0x00;
    DateOld.mday=0x01;
    DateOld.mon=0x01;
    DateOld.year=0x14;
    DateOld.wday=0x03;

    RtccSetTimeDate(TimeOld.l, DateOld.l);
    TimeOld.l=DateOld.l=-1;
    mRtccSelectSecPulseOutput();
    mRtccOutputEnable();

}

_Bool UpdateTime(void)
{
    TimeCorrente.l=RtccGetTime();//Scarica l'ora agiornata dal pic
    if(TimeOld.sec!=TimeCorrente.sec)
    {
        TimeOld.l=TimeCorrente.l;
        return 1;
    }
    return 0;
}

_Bool UpdateDate(void)
{
    DateCorrente.l=RtccGetDate();//Scarica l'ora agiornata dal pic
    if(DateOld.mday!=DateCorrente.mday)
    {
        DateOld.l=DateCorrente.l;
        return 1;
    }
    return 0;
}


void StampaOra(unsigned char XTime, unsigned char YTime, unsigned char SizeFontTime, _Bool Orientation, _Bool Backgr)
{
    static char		timeStr[10]= "::::::::\0";	// 23:14:15
    
    bcdtoab(TimeCorrente.hour, timeStr);
    bcdtoab(TimeCorrente.min, timeStr+3);
    bcdtoab(TimeCorrente.sec, timeStr+6);

    if(Orientation==0) LCD_Text57Land(XTime,YTime,timeStr,SizeFontTime,WHITE,BLACK);
    else  LCD_Text57(XTime,YTime,timeStr,SizeFontTime,WHITE,BLACK);
}

void StampaDate(unsigned char XData, unsigned char YData, unsigned char SizeFontDate, _Bool Orientation, _Bool Backgr)
{
    static char		dateStr[12]= "//////20//\0";	// 08/06/15

    bcdtoab(DateCorrente.mday, dateStr);
    bcdtoab(DateCorrente.mon, dateStr+3);
    bcdtoab(DateCorrente.year, dateStr+8);

    if(Orientation==0) LCD_Text57Land(XData,YData,dateStr,SizeFontDate,WHITE,NONE);
    else  LCD_Text57(XData,YData,dateStr,SizeFontDate,WHITE,NONE);
}

static void bcdtoab(int bcd, char* dest)
{
    *dest++=(char)((bcd>>4)+'0');
    *dest=(char)((bcd&0x0f)+'0');
}

