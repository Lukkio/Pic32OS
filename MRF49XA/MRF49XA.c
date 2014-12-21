/*********************************************************************
* FileName:		 MRF49XA.c 
* Dependencies:    See INCLUDES section below
* Processor:       
* Compiler:        
* Company:         Microchip Technology, Inc.
*
* Software License Agreement:
*
* The software supplied herewith by Microchip Technology Incorporated
* (the "Company") for its PICmicro® Microcontroller is intended and
* supplied to you, the Company's customer, for use solely and
* exclusively on Microchip PICmicro Microcontroller products. The
* software is owned by the Company and/or its supplier, and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*********************************************************************
* File Description:
*
* Change History:
* Author               Cristian Toma
********************************************************************/
#include "IOConfig2.h"
#include "MRF49XA.h"



//extern TTranseiverStatus TransceiverStatus;
void initRFPorts(void);
void DebugStatusRead(unsigned short int Xcursor, unsigned short Ycursor);
void ResetRF(void);

//--------------------------------------------------------------------
// SPI_Read ()
//--------------------------------------------------------------------

unsigned char SPI_Read(void)
{
    unsigned char i,Nop=0;
    unsigned short int spidata = 0;
//SPI4CONCLR = 0x8000;
    //SPI_SDO = 0;
    //SPI_SCK = 0;
    RF_SDOCLR;
    //Nop++;
    RF_SCKCLR;
   // Nop++;
    //DelayUs(1);
    for (i=0;i<8;i=i+1)
    {
        spidata=spidata<<1;
        if(SPI_SDI)
        {
            spidata |= 0x01;
        }
        else
        {
            spidata &= 0xFE;
        }
        
        //SPI_SCK = 1;
        RF_SCKSET;
        Nop++;
        //DelayUs(1);
        //SPI_SCK = 0;
        RF_SCKCLR;
        Nop++;
        //DelayUs(1);
    }
    //SPI4CONSET = 0x8000;
    return(spidata);
}
 /*
unsigned char SPI_Read(void)
{
   unsigned char temp;
  //SPI4CONSET = 0x8000;
  
    SPI4BUF=0x00;
    while( !SPI4STATbits.SPIRBF);
    
    temp=(unsigned char)SPI4BUF;
    //SPI4CONCLR = 0x8000;
    return(temp);
}
*/
//--------------------------------------------------------------------
// SPI_Write ()
//--------------------------------------------------------------------

void SPI_Write(unsigned short int spidata)
{
    unsigned char i,Nop=0;

    //SPI_SDO = 0;
    //SPI_SCK = 0;
    RF_SDOCLR;
    //Nop++;
    RF_SCKCLR;
    //Nop++;
    //DelayUs(1);
    for (i=0;i<8;i=i+1)
    {
        if(spidata & 0x80)
        {
            //SPI_SDO = 1;
            RF_SDOSET;
        }
        else
        {
            //SPI_SDO = 0;
            RF_SDOCLR;
        }
        
        spidata=spidata<<1;
        //SPI_SCK = 1;
        RF_SCKSET;
        Nop++;
        //DelayUs(1);
	//SPI_SCK = 0;
        RF_SCKCLR;
        Nop++;
        //DelayUs(1);
    }
    //SPI_SDO = 0;
    RF_SDOCLR;	
}
/*
void SPI_Write(unsigned short int spidata)
{
    unsigned char count=0;
    //unsigned char nop;
    unsigned char temp= (unsigned char) spidata;
    //SPI4CONCLR = 0x8000;
    //SPI4CONSET = 0x8000;

    //count = SPI4BUF;
    
    //temp=spidata;
    SPI4BUF = temp;
    while( !SPI4STATbits.SPIRBF);

    //SPI4CONCLR = 0x8000;
}
*/
//--------------------------------------------------------------------
// SPI_Command ()
//--------------------------------------------------------------------
void SPI_Command(unsigned short int spicmd)
{
    //SPI_CS = 0;
    RF_CSCLR;
    SPI_Write ((spicmd & 0xFF00) >> 8);
    SPI_Write ((spicmd & 0x00FF));
    //SPI_CS = 1;
    RF_CSSET;
}

//--------------------------------------------------------------------
// SPI_Write16 ()
//--------------------------------------------------------------------
void SPI_Write16(unsigned short int spicmd)
{
    SPI_Write ((spicmd & 0xFF00) >> 8);
    SPI_Write ((spicmd & 0x00FF));
}

//--------------------------------------------------------------------
// FIFO syncron latch re-enable
//--------------------------------------------------------------------
void MRF49XA_Reset_Radio() {
	SPI_Command(PMCREG);			// turn off tx and rx
	SPI_Command(FIFORSTREG);		// reset FIFO
	SPI_Command(GENCREG);			// disable FIFO , Tx_latch
	SPI_Command(PMCREG | 0x0080);	// turn on receiver
	SPI_Command(GENCREG | 0x0040);	// enable the FIFO	
	SPI_Command(FIFORSTREG | 0x0002);   // FIFO syncron latch re-enable	
}

//--------------------------------------------------------------------
// Power down the radio chip
//--------------------------------------------------------------------
void MRF49XA_Power_Down(void) {
	SPI_Command(0x8201);
}

//--------------------------------------------------------------------
// MRF49XA_Init 
// Initializes the radio chip
//--------------------------------------------------------------------
void MRF49XA_Init(){

//	int delay;
//	RF_RES = 0;
//			asm("Nop");
//	RF_RES = 1; // Release the Reset Pin
//----  configuring the RF link --------------------------------
mINT2IntEnable(0);
 ///Timer 1 stop
        IFS0bits.T1IF = 0; /* clear interrupt flag */
        IEC0bits.T1IE = 0; /* disable interrupts */
        T1CONbits.TON = 0; /* stop the timer */

    RF_RSCLR;
    DelayUs(10);
    RF_RSSET;
    DelayMs(5);
//---- Send init cmd
	SPI_Command( FIFORSTREG );
	SPI_Command( FIFORSTREG | 0x0002);
	SPI_Command( GENCREG);
	SPI_Command( AFCCREG);
	SPI_Command( CFSREG);
	SPI_Command( DRSREG);	
	SPI_Command( PMCREG);
	SPI_Command( RXCREG);
	SPI_Command( TXCREG);	
	SPI_Command(BBFCREG);

//---- antenna tunning
	SPI_Command( PMCREG | 0x0020);		// turn on tx
  DelayMs(5);
//---- end of antenna tunning
	SPI_Command( PMCREG | 0x0080);		// turn off Tx, turn on receiver
	SPI_Command( GENCREG | 0x0040);		// enable the FIFO
	SPI_Command( FIFORSTREG);
	SPI_Command( FIFORSTREG | 0x0002);	// enable syncron latch	
	//RF_FSEL=1; // FSEL bit in 1 to enable FIFO in software
        mINT2IntEnable(1);
        RF_FSELSET;
         ///Timer 1 stop
        IFS0bits.T1IF = 0; /* clear interrupt flag */
        IEC0bits.T1IE = 1; /* disable interrupts */
        T1CONbits.TON = 1; /* stop the timer */
}

//--------------------------------------------------------------------
// MRF49XA_Send_Packet
// Sends a data packet
//--------------------------------------------------------------------
void MRF49XA_Send_Packet(TRFData *RFData){

	unsigned char len;
        char BufferTxt[20];
	BYTE a;
	
	//---- turn off receiver , enable Tx register
	SPI_Command(PMCREG);				// turn off the transmitter and receiver
	SPI_Command(GENCREG | 0x0080);		// Enable the Tx register
	//---- Packet transmission
	// Reset value of the Tx regs are [AA AA], we can start transmission
	//---- Enable Tx
	SPI_Command(PMCREG |0x0020);		// turn on tx

		//SPI_CS=0;						// chip select low
        RF_CSCLR;
                //PORTDbits.RD2=1;
		while(!SPI_SDI)
                {
                   /* if(RF_IRQ==1)
                    {
                        //sprintf(BufferTxt,"%x",RF_IRQ);
                        //LCD_Text57Land(200,260,BufferTxt,1,RED,NONE);
                        //LCD_FastRect(50,50,80,80,RED);
                        DebugStatusRead(230,2);
                        break;
                    }*/
                }
			SPI_Write16(TXBREG | 0xAA);	// preamble
                        
		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(220,2);}*/}
			SPI_Write(0xAA);	// preamble 
		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(210,2);}*/}
			SPI_Write(0x2D);	// sync pattern 1st byte
		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(200,2);}*/}
			SPI_Write(0xD4);	// sync pattern 2nd byte
		len = RFData->index; 
		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(190,2);}*/}
			SPI_Write(len + 1);	// Include in the payload the Checksum byte at the end
//			SPI_Write(0x03);	// Include in the payload the Checksum byte at the end


		for (a=0;a<len;a++){				// send payload
			while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(180,2);}*/}				// wait for SDO, when buffer data <=8 bits
			SPI_Write(RFData->buffer[a]); // write a byte to tx register
		}
//		while(!SPI_SDI) {}		
//			SPI_Write(0x00);	// Include in the payload the Checksum byte at the end
//		while(!SPI_SDI){}		
//			SPI_Write(0x01);	// Include in the payload the Checksum byte at the end


		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(170,2);}*/}
			SPI_Write(CalChkSum(RFData->buffer,len));	// write a dummy byte since the previous byte is still in buffer 		
//			SPI_Write(0x01);	// Include in the payload the Checksum byte at the end

		while(!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(160,2);}*/}
			SPI_Write(0x00);	// write a dummy byte since the previous byte is still in buffer 		
		while (!SPI_SDI){/*if(RF_IRQ==1){DebugStatusRead(150,2);}*/}				// wait for the last byte transmission end
		//SPI_CS=1;						// chip select high, end transmission
                        RF_CSSET;
		
	//---- Turn off Tx disable the Tx register
		SPI_Command(FIFORSTREG);   // FIFO Reset
		SPI_Command(PMCREG | 0x0080);	// turn on receiver
		SPI_Command(GENCREG | 0x0040);	// enable the FIFO	
		SPI_Command(FIFORSTREG | 0x0002);   // FIFO syncron latch re-enable
	
}

//--------------------------------------------------------------------
// MRF49XA_Receive_Packet
// Receives a data packet
// This function should be called periodically until it returns
// a valid data packet
// The return values are (see MRF49XA.h) :
// NODATA 			0			no data received
// DATA_RECEIVED 		1			data received, data capture in progress
// PACKET_RECEIVED	2			data received, data packet received ok
//
// This function should be called periodically , at least once every 800us for 9600bps.
// For higher speed, the function should be called more rapidly.
// When a complete packet has been received, the function returns a PACKET_RECEIVED.
// In order to "re-arm" the receiver to receive a new packet call the 
// MRF49XA_Reset_Radio function.
//
// Use a call similar to :
// if ( MRF49XA_Receive_Packet(dataPacket,&length) == PACKET_RECEIVED)
// { 
//   .... do something with the received packet....
// }
// // re-arm for next packet
// MRF49XA_Reset_Radio();
//
//--------------------------------------------------------------------
unsigned char MRF49XA_Receive_Packet( TRFData *RFData){

//	static unsigned char PacketLen =0;
	unsigned char bl,Nop=0;
	

	//SPI_SDO = 0;
	//SPI_CS	=0;							// chip select low
        RF_SDOCLR;
       // Nop++;
        RF_CSCLR;
       Nop++;

	if(SPI_SDI) {								// in case of FINT then read out
		//SPI_CS=1;
            RF_CSSET;
		//RF_FSEL = 0;			// FIFO Select
            RF_FSELCLR;
		if(RFData->len) {	// is this the first byte? go on if not
		Nop++;

			AddRFData(RFData,SPI_Read());// read the data byte and stores it in the buffer
			Nop++;

			if (RFData->index >= RFData->len) {   // end of packet
				//RF_FSEL=1;
                            RF_FSELSET;
				// whole packet received
				
				RFData->len = RFData->index;				// assing the received length of the packet
				return PACKET_RECEIVED;	
			}
		}
		else {	// the first byte received
			bl=SPI_Read(); // number of bytes in payload is the first byte
			if((bl>0) && (bl<PAYLOAD_MAX)) {   // check if correct number of bytes in payload
				RFData->len=bl;
				RFData->index=0; 
			 // DelayMs(1);
			}
			else {		
				//RF_FSEL=1;						// bad packet length
                            RF_FSELSET;
				MRF49XA_Reset_Radio();
				return NODATA2;
			}
		}
		
		//RF_FSEL=1;
            RF_FSELSET;
		return DATA_RECEIVED;
	}
	else {
		//SPI_CS = 1;
            RF_CSSET;
		return NODATA;  
	} 
}



/******************************************************************************
 * Function:        void AddRFData(TRFData *RFData, unsigned char data)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Adds a byte into the buffer and calculates the CheckSum 
 *
 * Note:            None
 *****************************************************************************/
void AddRFData(TRFData *RFData, unsigned char data){
	RFData->buffer[RFData->index] = data;
	RFData->index++;
}


/*********************************************************************
 * void StatusRead(void)
 *
 * Overview:        
 *              This function read the status register and output the
 *              status in the global variable TransceiverStatus.
 *
 * PreCondition:    
 *              MRF49XA transceiver has been properly initialized
 *
 * Input:       None   
 *
 * Output:      None    
 *
 * Side Effects:    Global variable TransceiverStatus has been modified
 *
 ********************************************************************/
unsigned short int StatusRead(void)
{
    unsigned char preRF_FSEL = RF_FSEL_READ;
    unsigned char preSPI_CS = RF_CS_READ;
    unsigned char i=0;
    unsigned short int STATUSRF=0x0000;
    ///Timer 1 stop
    IFS0bits.T1IF = 0; /* clear interrupt flag */
    IEC0bits.T1IE = 0; /* disable interrupts */
    T1CONbits.TON = 0; /* stop the timer */

    //Interrupt stop
    mINT2IntEnable(0);
    //SPI_Command(0x0000);

   // RF_FSELSET;
    RF_CSCLR;
    RF_SDOCLR;
    RF_SCKCLR;

    for(i=0;i<16; i++)
    {
        if(SPI_SDI) STATUSRF++;

        RF_SCKSET;
        RF_SCKCLR;
        STATUSRF=STATUSRF<<1;       
    }
//RF_FSELSET;
RF_CSSET;
    
     /* if(preRF_FSEL==1) {RF_FSELSET;}
        else {RF_FSELCLR;}
        //Nop++;
        if(preSPI_CS==1) {RF_CSSET;}
        else {RF_CSCLR;}

*/
        ///Timer 1 start
        IFS0bits.T1IF = 0; /* clear interrupt flag */
        IEC0bits.T1IE = 1; /* disable interrupts */
        T1CONbits.TON = 1; /* stop the timer */

        //Interrupt start
        mINT2IntEnable(1);

    return STATUSRF;
}


/*

void StatusRead(void) {
	//unsigned char	preRF_FSEL = RF_FSEL;
	//unsigned char	preSPI_CS = SPI_CS;
        unsigned char	preRF_FSEL = RF_FSEL_READ;
	unsigned char	preSPI_CS = RF_CS_READ;
        //unsigned char Nop=0;
	//RF_FSEL = 1;
	//SPI_CS = 0;
	
	//SPI_SDO = 0;

        ///Timer 1 stop
        IFS0bits.T1IF = 0; 
        IEC0bits.T1IE = 0; 
        T1CONbits.TON = 0; 
        
        //Interrupt stop
        mINT2IntEnable(0);
        SPI_Command(0x0000);

        RF_FSELSET;
       // Nop++;
        RF_CSCLR;
        //Nop++;
        RF_SDOCLR;
        //Nop++;

	TransceiverStatus.bits.RG_FF_IT = SPI_SDI;    
	//SPI_SCK = 1;
	//SPI_SCK = 0;
        //Nop++;
        RF_SCKSET;
        //Nop++;
        RF_SCKCLR;
        //Nop++;

	TransceiverStatus.bits.POR = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
        //Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.RGUR_FFOV = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.WKUP = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.EXT = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
        //Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
       // Nop++;
	
	TransceiverStatus.bits.LBD = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
        //Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.FFEM = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
        //Nop++;
        RF_SCKSET;
        //Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.RSSI_ATS = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
       // Nop++;
	   
	TransceiverStatus.bits.DQD = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
        //Nop++;
        RF_SCKCLR;
        //Nop++;
	
	TransceiverStatus.bits.CRL = SPI_SDI;
	//SPI_SCK = 1;
	///SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
       // Nop++;
        RF_SCKCLR;
       // Nop++;
	
	TransceiverStatus.bits.ATGL = SPI_SDI;
	//SPI_SCK = 1;
	//SPI_SCK = 0;
       // Nop++;
        RF_SCKSET;
        //Nop++;
        //RF_SCKCLR;
        //Nop++;

if(preRF_FSEL==1) {RF_FSELSET;}
        else {RF_FSELCLR;}
        //Nop++;
        if(preSPI_CS==1) {RF_CSSET;}
        else {RF_CSCLR;}


        ///Timer 1 start
        IFS0bits.T1IF = 0;
        IEC0bits.T1IE = 1; 
        T1CONbits.TON = 1; 

        //Interrupt start
        mINT2IntEnable(1);

	//RF_FSEL = preRF_FSEL;
	//SPI_CS = preSPI_CS;	
}
*/

/******************************************************************************
 * Function:        void AddRFData(TRFData *RFData, unsigned char data)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Adds a byte into the buffer and calculates the CheckSum 
 *
 * Note:            None
 *****************************************************************************/
void InitRFData(TRFData *RFData){
	RFData->index=0;
	RFData->len = 0;
	RFData->ChkSum=0;
}


/******************************************************************************
 * Function:        unsigned char CalChkSum(unsigned char *buffer, len)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Side Effects:    None
 * Overview:        Calculates the CheckSum 
 *
 * Note:            None
 *****************************************************************************/
unsigned char CalChkSum(unsigned char *buffer, unsigned char len){
  unsigned char i;
  unsigned char Received = 0;
  
  for (i=0;i<len;i++) {
  	Received = Received ^ buffer[i];
  }
  return Received;

}

void initRFPorts(void)
{
    /*TRIS_SPI_SDO 	= OUTPUT_PIN;
    TRIS_SPI_SCK 	= OUTPUT_PIN;
    TRIS_SPI_CS  	= OUTPUT_PIN;
    TRIS_RF_FSEL	= OUTPUT_PIN;
    TRIS_SPI_SDI 	= INPUT_PIN;
    TRIS_RF_FINT	= INPUT_PIN;
    TRIS_RF_IRQ         = INPUT_PIN;
     */

    //Define direction port
    mPORTFSetPinsDigitalOut(BIT_5);//SDO
    mPORTFSetPinsDigitalOut(BIT_13);//SCK
    mPORTBSetPinsDigitalOut(BIT_9);//CS
    mPORTBSetPinsDigitalOut(BIT_13);//FSEL
    mPORTBSetPinsDigitalOut(BIT_12);//RESET

    mPORTESetPinsDigitalIn(BIT_9);//FINT
    mPORTESetPinsDigitalIn(BIT_8);//IRQ
    mPORTFSetPinsDigitalIn(BIT_4);//SDI
    mPORTFSetPinsDigitalIn(BIT_12);//INT


    DelayMs(125);
    
    RF_CSSET;
    RF_SCKSET;
    RF_SDOCLR;

#ifdef SPI_RFHW
    SPI4CON = 0x0120;
    //SPI4BRG = 0x001F; // 64:1 prescale (slow display update)
    SPI4BRG = 0x0001; // 4:1 prescale (fast display update) 16Mhz spi clock at 72Mhz sys clock
    SPI4CONSET = 0x8000; // enables the spi
#endif

    //SPI_CS = 1;
    //SPI_SCK = 1;
    //SPI_SDO=0;
}

void DebugStatusRead(unsigned short int Xcursor, unsigned short Ycursor)
{
    char StringBuffer[50];
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
}

void ResetRF(void)
{
    RF_RSCLR;
    DelayUs(10);
    RF_RSSET;
    DelayMs(125);
    RF_CSSET;
    RF_SCKSET;
    RF_SDOCLR;
}

