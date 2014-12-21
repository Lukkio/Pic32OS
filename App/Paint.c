void Paint(void);

void Paint(void)
{
    char drawcol=0,noise=0,radiuscol=3;
    unsigned short int clu,dat,AlignmentY;
    char TextBuffer[20];
    _Bool esci=0;
    uint32_t adx, ady;
    
    #define PAINTLAND

    #ifndef PAINTLAND
        ////Init gui
        LCD_FastRect(0,0,239,319,BLACK);
        LCD_Rect(60,295,70,305,1,BLUE);
        LCD_Rect(75,295,85,305,1,GREEN);
        LCD_Rect(90,295,100,305,1,RED);
        LCD_Rect(105,295,115,305,1,PURPLE);
        LCD_Rect(210,295,220,305,1,YELLOW);
        LCD_Rect(225,295,235,305,0,YELLOW);
        draw_line(200,286,200,305,ORANGE);
        draw_line(0,286,239,286,ORANGE);
        draw_line(50,286,50,305,ORANGE);
        draw_line(0,20,239,20,ORANGE);
        LCD_Cercle(125,300, 1,1,CLAIRBLUE);
        LCD_Cercle(140,300, 2,1,CLAIRBLUE);
        LCD_Cercle(155,300, 3,1,CLAIRBLUE);
        LCD_Rect(5,295,15,305,1,BLUE);
        LCD_Cercle(25,300, 1,1,CLAIRBLUE);
        sprintf(TextBuffer,"Esci");
        LCD_Text57(190,2,TextBuffer,2,WHITE,NONE);
        ///Finish init gui
    #else
        LCD_FastRect(0,0,239,319,BLACK);///clear screen
        //LCD_Rect(0,0,239,319,0,WHITE);///cornice bianca
        draw_line(18,0,18,319,WHITE);///linea sotto
        draw_line(221,0,221,319,WHITE);///linea sopra

        sprintf(TextBuffer,"Esci");
        AlignmentY=CenterX(319,2,ALIGNMENT_RIGHT,(unsigned short int * )&TextBuffer[0]);
        LCD_Text57Land(13,AlignmentY,TextBuffer,2,WHITE,NONE);

        sprintf(TextBuffer,"X:000 Y:000");
	LCD_Text57Land(13,1,TextBuffer,2,WHITE,BLACK);

        ///Colori

        LCD_Rect(225,1,237,13,0,WHITE);
        LCD_Rect(226,2,236,12,1,RED);///colore selezionato
        LCD_Cercle(231,20, 3,1,WHITE);///penna
        
        draw_line(221,27,239,27,WHITE);///separatore

        LCD_Rect(226,32,236,42,1,RED);
        LCD_Rect(226,47,236,57,1,GREEN);
        LCD_Rect(226,62,236,72,1,BLUE);
        LCD_Rect(226,77,236,87,1,ORANGE);
        LCD_Rect(226,92,236,102,1,PURPLE);
        LCD_Rect(226,107,236,117,1,YELLOW);
        LCD_Rect(226,122,236,132,1,WHITE);
        LCD_Rect(226,137,236,147,1,CLAIRBLUE);

        draw_line(221,152,239,152,WHITE);///separatore

        LCD_Cercle(231,162, 1,1,WHITE);
        LCD_Cercle(231,177, 2,1,WHITE);
        LCD_Cercle(231,192, 3,1,WHITE);

        draw_line(221,286,239,286,WHITE);///separatore

        LCD_Rect(225,289,237,301,0,WHITE);
        LCD_Rect(228,289,234,301,1,YELLOW);///gomma

        LCD_Rect(225,306,237,318,0,WHITE);//clear screen
        
    #endif
    
    
    DelayMs(100);
    while(TRUE)
    {
        if(PORTDbits.RD14==0){

            TP_GetMedianAdXY(&adx, &ady);

            dat = getDisplayCoordinateX(adx, ady);
            clu = getDisplayCoordinateY(adx, ady);

            sprintf(TextBuffer,"X:%03d Y:%03d",dat,clu);
            LCD_Text57Land(13,1,TextBuffer,2,WHITE,BLACK);

            if(((21<clu)&&(clu<218))&&((4<=dat)&&(dat<=316)))
            {
                    if(drawcol==0) LCD_Cercle(clu,dat, radiuscol,1,RED);
                    if(drawcol==1) LCD_Cercle(clu,dat, radiuscol,1,GREEN);
                    if(drawcol==2) LCD_Cercle(clu,dat, radiuscol,1,BLUE);
                    if(drawcol==3) LCD_Cercle(clu,dat, radiuscol,1,ORANGE);
                    if(drawcol==4) LCD_Cercle(clu,dat, radiuscol,1,PURPLE);
                    if(drawcol==5) LCD_Cercle(clu,dat, radiuscol,1,YELLOW);
                    if(drawcol==6) LCD_Cercle(clu,dat, radiuscol,1,WHITE);
                    if(drawcol==7) LCD_Cercle(clu,dat, radiuscol,1,CLAIRBLUE);
                    if(drawcol==8) LCD_Cercle(clu,dat, radiuscol,1,BLACK);
             }

                //colori
                if(((226<=clu)&&(clu<=236))&&((32<=dat)&&(dat<=42)))
                {
                    drawcol=0;
                    LCD_Rect(226,2,236,12,1,RED);
                }
                if(((226<=clu)&&(clu<=236))&&((47<=dat)&&(dat<=57)))
                {
                    drawcol=1;
                    LCD_Rect(226,2,236,12,1,GREEN);
                }
                if(((226<=clu)&&(clu<=236))&&((62<=dat)&&(dat<=72)))
                {
                    drawcol=2;
                    LCD_Rect(226,2,236,12,1,BLUE);
                }
                if(((226<=clu)&&(clu<=236))&&((77<=dat)&&(dat<=87)))
                {
                    drawcol=3;
                    LCD_Rect(226,2,236,12,1,ORANGE);
                }
                if(((226<=clu)&&(clu<=236))&&((92<=dat)&&(dat<=102)))
                {
                    drawcol=4;
                    LCD_Rect(226,2,236,12,1,PURPLE);
                }
                if(((226<=clu)&&(clu<=236))&&((107<=dat)&&(dat<=117)))
                {
                    drawcol=5;
                    LCD_Rect(226,2,236,12,1,YELLOW);
                }
                if(((226<=clu)&&(clu<=236))&&((122<=dat)&&(dat<=132)))
                {
                    drawcol=6;
                    LCD_Rect(226,2,236,12,1,WHITE);
                }
                if(((226<=clu)&&(clu<=236))&&((137<=dat)&&(dat<=147)))
                {
                    drawcol=7;
                    LCD_Rect(226,2,236,12,1,CLAIRBLUE);
                }
                if(((225<=clu)&&(clu<=237))&&((289<=dat)&&(dat<=301)))///Gomma
                {
                    drawcol=8;
                    LCD_Rect(226,2,236,12,1,BLACK);
                }




                if(((225<=clu)&&(clu<=237))&&((306<=dat)&&(dat<=318))) LCD_FastRect(19,0,220,319,BLACK);///Clearscreen

                ///aggiorna penna selezionata

                if(((226<=clu)&&(clu<=236))&&((157<=dat)&&(dat<=167)))
                {
                    radiuscol=1;
                    LCD_Rect(226,15,236,25,1,BLACK);
                    LCD_Cercle(231,20, 1,1,WHITE);
                }
                if(((226<=clu)&&(clu<=1236))&&((172<=dat)&&(dat<=182)))
                {
                    radiuscol=2;
                    LCD_Rect(226,15,236,25,1,BLACK);
                    LCD_Cercle(231,20, 2,1,WHITE);
                }
                if(((226<=clu)&&(clu<=236))&&((187<=dat)&&(dat<=197)))
                {
                    radiuscol=3;
                    LCD_Rect(226,15,236,25,1,BLACK);
                    LCD_Cercle(231,20, 3,1,WHITE);
                }


                if(((0<=clu)&&(clu<=17))&&((290<=dat)&&(dat<=319)))
                {
                    esci=1;
                }
            //}
        }
        //else noise=0;
        //if(PORTDbits.RD3==0) break;
        if(esci==1) break;
    }
}