/*********************************************************************
 * FileName:        IOConfig.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 3.05 +
 * Company:         Microchip Technology, Inc.
 *
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Ernesto Pareja       06/10/2010    Original.
 ********************************************************************/


/** T R I S *********************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0


/** D C C   S I G N A L **********************************************/

#define RF_FSELSET mPORTBSetBits(BIT_13);//FSEL
#define RF_FSELCLR mPORTBClearBits(BIT_13);//FSEL

#define RF_SDOSET mPORTFSetBits(BIT_5);//SDO
#define RF_SDOCLR mPORTFClearBits(BIT_5);//SDO

#define RF_SCKSET mPORTFSetBits(BIT_13);//SCK
#define RF_SCKCLR mPORTFClearBits(BIT_13);//SCK

#define RF_CSSET mPORTBSetBits(BIT_9);//CS
#define RF_CSCLR mPORTBClearBits(BIT_9);//CS

#define RF_RSSET mPORTBSetBits(BIT_12);//RESET
#define RF_RSCLR mPORTBClearBits(BIT_12);//RESET

#define RF_FSEL_READ mPORTBReadLatchBits(BIT_13);///FSEL READ
#define RF_CS_READ mPORTBReadLatchBits(BIT_9); //CS READ

#define RF_FINT_READ mPORTEReadLatchBits(BIT_9);///FINT READ
#define RF_CS_IRQ mPORTEReadLatchBits(BIT_8); //IRQ READ






#define SPI_SDO				PORTFbits.RF5		// PIN_F3  SDO
#define SPI_SDI				PORTFbits.RF4		// PIN_F2  SDI
#define SPI_SCK				PORTFbits.RF13		// PIN_E8  SPI clock
#define SPI_CS				PORTBbits.RB14		// PIN_E2  chip select
#define RF_IRQ			PORTEbits.RE8		// PIN_E3  MRF49XA interrupt
#define RF_INT			PORTFbits.RF12
#define RF_FSEL				PORTBbits.RB13		// fifo select, active low output
//#define RF_DIO			PORTEbits.RE0		// PIN_E0 
//#define RF_RES			LATEbits.LATE4		// PIN_B4  MRF49XA reset
//#define RF_RSSIO			PORTEbits.RE1		
#define RF_FINT				PORTEbits.RE9		// FIFO Interrupt pin
#define TRIS_SPI_SDO	TRISFbits.TRISF5		// PIN_F2  SDO (Out to SPI)
#define TRIS_SPI_SDI	TRISFbits.TRISF4		// PIN_F3  SDI (IN from SPI)
#define TRIS_SPI_SCK	TRISFbits.TRISF13		// PIN_E8  SPI clock
#define TRIS_SPI_CS	TRISBbits.TRISB14		// PIN_E2  chip select
#define TRIS_RF_IRQ			TRISEbits.TRISE8		// PIN_D0  MRF49XA interrupt
#define TRIS_RF_INT			TRISFbits.TRISF12
#define TRIS_RF_FSEL	TRISBbits.TRISB13		// PIN_E5  fifo select, active low output
//#define TRIS_RF_DIO		TRISEbits.TRISE0		// PIN_E0 
//#define TRIS_RF_RES			TRISEbits.TRISE4		// PIN_B4  MRF49XA reset
//#define TRIS_RF_RSSIO		TRISEbits.TRISE1		
#define TRIS_RF_FINT	TRISEbits.TRISE9

/*
#define Button1			RA1		// 1= On 0=Off
#define Button2			RA2		// 1= On 0=Off
#define Button3			RA3		// 1= On 0=Off


#define TRISButton1		TRISA1		// 1= TX 0=RX
#define TRISButton2		TRISA2		// 1= TX 0=RX
#define TRISButton3		TRISA3		// 1= TX 0=RX


#define LED1				RB7
#define LED2				RA6
#define LED3				RA7

#define TRISLED1		TRISB7
#define TRISLED2		TRISA6
#define TRISLED3		TRISA7

*/

