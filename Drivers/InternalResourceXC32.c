/*****************************************************************************
 * FileName:        InternalResourceXC32.c
 * Processor:       PIC32MX
 * Compiler:        MPLAB C32/XC32 (see release notes for tested revision)
 * Linker:          MPLAB LINK32/XC32
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright(c) 2012 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * AUTO-GENERATED CODE:  Graphics Resource Converter version: 3.28.15
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Includes
 *****************************************************************************/
//#include <Graphics/Graphics.h>
//#include "HardwareProfile.h"

/*****************************************************************************
 * SECTION:  Graphics Library Firmware Check
 *****************************************************************************/
//#if(GRAPHICS_LIBRARY_VERSION != 0x0306)
//#warning "It is suggested to use Graphics Library version 3.06 with this version of GRC."
//#endif

/*****************************************************************************
 * SECTION:  Graphics Bitmap Padding Check
 *****************************************************************************/
#ifdef USE_BITMAP_NO_PADDING_LINE
#error These bitmap resources have been converted with padding of the horizontal lines, but USE_BITMAP_NO_PADDING_LINE is defined in GraphicsConfig.h.
#endif

/*****************************************************************************
 * Converted Resources
 * -------------------
 *
 * Bitmaps
 * -------
 * flower1bit - 85x113 pixels, 1-bits per pixel
 * flower4bit - 85x113 pixels, 4-bits per pixel
 * flower8bit - 85x113 pixels, 8-bits per pixel
 * flower16bit - 85x113 pixels, 16-bits per pixel
 * Sun8bit - 72x72 pixels, 8-bits per pixel
 * Sun8bit_RLE - 72x72 pixels, 8-bits per pixel
 * Gaming4bit - 72x72 pixels, 4-bits per pixel
 * Gaming4bit_RLE - 72x72 pixels, 4-bits per pixel
 *
 * Fonts
 * -----
 * Font25 - Height: 25 pixels, 1 bit per pixel, Range: ' ' to '~'
 * Font35 - Height: 35 pixels, 1 bit per pixel, Range: ' ' to '~'
 * Font35_Antialiased - Height: 35 pixels, 2 bits per pixel, Range: 'A' to 'T'
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Font35_Antialiased
 *****************************************************************************/

 const XCHAR AntialisedText[] = {   0x0020, 0x0025, 0x0027, 0x0023, 0x0020, 0x0024, 0x0023, 0x0020, 0x0026, 0x0022, 0x0021, 0x0000    };    //Antialised text
//const XCHAR AntialisedText[] = {"Testo antialiasing!"};

/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * TTF Font File Structure
 * Label: Font25
 * Description:  Height: 25 pixels, 1 bit per pixel, Range: ' ' to '~'
 ***********************************/

extern const char __Font25[] __attribute__((aligned(2)));

const FONT_FLASH Font25 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__Font25
};

const char __Font25[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x00,           // Font information:  1 bit per pixel, Characters zero degress rotation
    0x20, 0x00,     // First Character
    0x7E, 0x00,     // Last Character
    0x19, 0x00,     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
    0x05,              // width of the glyph
    0x84, 0x01, 0x00,       // Character - 32, offset (0x00000184)
    0x06,              // width of the glyph
    0x9D, 0x01, 0x00,       // Character - 33, offset (0x0000019D)
    0x09,              // width of the glyph
    0xB6, 0x01, 0x00,       // Character - 34, offset (0x000001B6)
    0x0A,              // width of the glyph
    0xE8, 0x01, 0x00,       // Character - 35, offset (0x000001E8)
    0x0A,              // width of the glyph
    0x1A, 0x02, 0x00,       // Character - 36, offset (0x0000021A)
    0x0F,              // width of the glyph
    0x4C, 0x02, 0x00,       // Character - 37, offset (0x0000024C)
    0x0F,              // width of the glyph
    0x7E, 0x02, 0x00,       // Character - 38, offset (0x0000027E)
    0x05,              // width of the glyph
    0xB0, 0x02, 0x00,       // Character - 39, offset (0x000002B0)
    0x07,              // width of the glyph
    0xC9, 0x02, 0x00,       // Character - 40, offset (0x000002C9)
    0x07,              // width of the glyph
    0xE2, 0x02, 0x00,       // Character - 41, offset (0x000002E2)
    0x09,              // width of the glyph
    0xFB, 0x02, 0x00,       // Character - 42, offset (0x000002FB)
    0x09,              // width of the glyph
    0x2D, 0x03, 0x00,       // Character - 43, offset (0x0000032D)
    0x05,              // width of the glyph
    0x5F, 0x03, 0x00,       // Character - 44, offset (0x0000035F)
    0x07,              // width of the glyph
    0x78, 0x03, 0x00,       // Character - 45, offset (0x00000378)
    0x05,              // width of the glyph
    0x91, 0x03, 0x00,       // Character - 46, offset (0x00000391)
    0x0A,              // width of the glyph
    0xAA, 0x03, 0x00,       // Character - 47, offset (0x000003AA)
    0x0A,              // width of the glyph
    0xDC, 0x03, 0x00,       // Character - 48, offset (0x000003DC)
    0x0A,              // width of the glyph
    0x0E, 0x04, 0x00,       // Character - 49, offset (0x0000040E)
    0x0A,              // width of the glyph
    0x40, 0x04, 0x00,       // Character - 50, offset (0x00000440)
    0x0A,              // width of the glyph
    0x72, 0x04, 0x00,       // Character - 51, offset (0x00000472)
    0x0A,              // width of the glyph
    0xA4, 0x04, 0x00,       // Character - 52, offset (0x000004A4)
    0x0A,              // width of the glyph
    0xD6, 0x04, 0x00,       // Character - 53, offset (0x000004D6)
    0x0A,              // width of the glyph
    0x08, 0x05, 0x00,       // Character - 54, offset (0x00000508)
    0x0A,              // width of the glyph
    0x3A, 0x05, 0x00,       // Character - 55, offset (0x0000053A)
    0x0B,              // width of the glyph
    0x6C, 0x05, 0x00,       // Character - 56, offset (0x0000056C)
    0x0A,              // width of the glyph
    0x9E, 0x05, 0x00,       // Character - 57, offset (0x0000059E)
    0x05,              // width of the glyph
    0xD0, 0x05, 0x00,       // Character - 58, offset (0x000005D0)
    0x05,              // width of the glyph
    0xE9, 0x05, 0x00,       // Character - 59, offset (0x000005E9)
    0x09,              // width of the glyph
    0x02, 0x06, 0x00,       // Character - 60, offset (0x00000602)
    0x09,              // width of the glyph
    0x34, 0x06, 0x00,       // Character - 61, offset (0x00000634)
    0x09,              // width of the glyph
    0x66, 0x06, 0x00,       // Character - 62, offset (0x00000666)
    0x09,              // width of the glyph
    0x98, 0x06, 0x00,       // Character - 63, offset (0x00000698)
    0x12,              // width of the glyph
    0xCA, 0x06, 0x00,       // Character - 64, offset (0x000006CA)
    0x0D,              // width of the glyph
    0x15, 0x07, 0x00,       // Character - 65, offset (0x00000715)
    0x0B,              // width of the glyph
    0x47, 0x07, 0x00,       // Character - 66, offset (0x00000747)
    0x0B,              // width of the glyph
    0x79, 0x07, 0x00,       // Character - 67, offset (0x00000779)
    0x0C,              // width of the glyph
    0xAB, 0x07, 0x00,       // Character - 68, offset (0x000007AB)
    0x0A,              // width of the glyph
    0xDD, 0x07, 0x00,       // Character - 69, offset (0x000007DD)
    0x0A,              // width of the glyph
    0x0F, 0x08, 0x00,       // Character - 70, offset (0x0000080F)
    0x0C,              // width of the glyph
    0x41, 0x08, 0x00,       // Character - 71, offset (0x00000841)
    0x0E,              // width of the glyph
    0x73, 0x08, 0x00,       // Character - 72, offset (0x00000873)
    0x06,              // width of the glyph
    0xA5, 0x08, 0x00,       // Character - 73, offset (0x000008A5)
    0x08,              // width of the glyph
    0xBE, 0x08, 0x00,       // Character - 74, offset (0x000008BE)
    0x0C,              // width of the glyph
    0xD7, 0x08, 0x00,       // Character - 75, offset (0x000008D7)
    0x0A,              // width of the glyph
    0x09, 0x09, 0x00,       // Character - 76, offset (0x00000909)
    0x11,              // width of the glyph
    0x3B, 0x09, 0x00,       // Character - 77, offset (0x0000093B)
    0x0E,              // width of the glyph
    0x86, 0x09, 0x00,       // Character - 78, offset (0x00000986)
    0x0D,              // width of the glyph
    0xB8, 0x09, 0x00,       // Character - 79, offset (0x000009B8)
    0x0B,              // width of the glyph
    0xEA, 0x09, 0x00,       // Character - 80, offset (0x000009EA)
    0x0D,              // width of the glyph
    0x1C, 0x0A, 0x00,       // Character - 81, offset (0x00000A1C)
    0x0C,              // width of the glyph
    0x4E, 0x0A, 0x00,       // Character - 82, offset (0x00000A4E)
    0x0A,              // width of the glyph
    0x80, 0x0A, 0x00,       // Character - 83, offset (0x00000A80)
    0x0C,              // width of the glyph
    0xB2, 0x0A, 0x00,       // Character - 84, offset (0x00000AB2)
    0x0E,              // width of the glyph
    0xE4, 0x0A, 0x00,       // Character - 85, offset (0x00000AE4)
    0x0E,              // width of the glyph
    0x16, 0x0B, 0x00,       // Character - 86, offset (0x00000B16)
    0x12,              // width of the glyph
    0x48, 0x0B, 0x00,       // Character - 87, offset (0x00000B48)
    0x0D,              // width of the glyph
    0x93, 0x0B, 0x00,       // Character - 88, offset (0x00000B93)
    0x0C,              // width of the glyph
    0xC5, 0x0B, 0x00,       // Character - 89, offset (0x00000BC5)
    0x0B,              // width of the glyph
    0xF7, 0x0B, 0x00,       // Character - 90, offset (0x00000BF7)
    0x06,              // width of the glyph
    0x29, 0x0C, 0x00,       // Character - 91, offset (0x00000C29)
    0x0A,              // width of the glyph
    0x42, 0x0C, 0x00,       // Character - 92, offset (0x00000C42)
    0x06,              // width of the glyph
    0x74, 0x0C, 0x00,       // Character - 93, offset (0x00000C74)
    0x0A,              // width of the glyph
    0x8D, 0x0C, 0x00,       // Character - 94, offset (0x00000C8D)
    0x0A,              // width of the glyph
    0xBF, 0x0C, 0x00,       // Character - 95, offset (0x00000CBF)
    0x07,              // width of the glyph
    0xF1, 0x0C, 0x00,       // Character - 96, offset (0x00000CF1)
    0x0A,              // width of the glyph
    0x0A, 0x0D, 0x00,       // Character - 97, offset (0x00000D0A)
    0x0B,              // width of the glyph
    0x3C, 0x0D, 0x00,       // Character - 98, offset (0x00000D3C)
    0x09,              // width of the glyph
    0x6E, 0x0D, 0x00,       // Character - 99, offset (0x00000D6E)
    0x0B,              // width of the glyph
    0xA0, 0x0D, 0x00,       // Character - 100, offset (0x00000DA0)
    0x0A,              // width of the glyph
    0xD2, 0x0D, 0x00,       // Character - 101, offset (0x00000DD2)
    0x09,              // width of the glyph
    0x04, 0x0E, 0x00,       // Character - 102, offset (0x00000E04)
    0x0B,              // width of the glyph
    0x36, 0x0E, 0x00,       // Character - 103, offset (0x00000E36)
    0x0C,              // width of the glyph
    0x68, 0x0E, 0x00,       // Character - 104, offset (0x00000E68)
    0x06,              // width of the glyph
    0x9A, 0x0E, 0x00,       // Character - 105, offset (0x00000E9A)
    0x06,              // width of the glyph
    0xB3, 0x0E, 0x00,       // Character - 106, offset (0x00000EB3)
    0x0B,              // width of the glyph
    0xCC, 0x0E, 0x00,       // Character - 107, offset (0x00000ECC)
    0x06,              // width of the glyph
    0xFE, 0x0E, 0x00,       // Character - 108, offset (0x00000EFE)
    0x12,              // width of the glyph
    0x17, 0x0F, 0x00,       // Character - 109, offset (0x00000F17)
    0x0C,              // width of the glyph
    0x62, 0x0F, 0x00,       // Character - 110, offset (0x00000F62)
    0x0B,              // width of the glyph
    0x94, 0x0F, 0x00,       // Character - 111, offset (0x00000F94)
    0x0B,              // width of the glyph
    0xC6, 0x0F, 0x00,       // Character - 112, offset (0x00000FC6)
    0x0B,              // width of the glyph
    0xF8, 0x0F, 0x00,       // Character - 113, offset (0x00000FF8)
    0x08,              // width of the glyph
    0x2A, 0x10, 0x00,       // Character - 114, offset (0x0000102A)
    0x08,              // width of the glyph
    0x43, 0x10, 0x00,       // Character - 115, offset (0x00001043)
    0x08,              // width of the glyph
    0x5C, 0x10, 0x00,       // Character - 116, offset (0x0000105C)
    0x0B,              // width of the glyph
    0x75, 0x10, 0x00,       // Character - 117, offset (0x00001075)
    0x0A,              // width of the glyph
    0xA7, 0x10, 0x00,       // Character - 118, offset (0x000010A7)
    0x0F,              // width of the glyph
    0xD9, 0x10, 0x00,       // Character - 119, offset (0x000010D9)
    0x0B,              // width of the glyph
    0x0B, 0x11, 0x00,       // Character - 120, offset (0x0000110B)
    0x0A,              // width of the glyph
    0x3D, 0x11, 0x00,       // Character - 121, offset (0x0000113D)
    0x09,              // width of the glyph
    0x6F, 0x11, 0x00,       // Character - 122, offset (0x0000116F)
    0x08,              // width of the glyph
    0xA1, 0x11, 0x00,       // Character - 123, offset (0x000011A1)
    0x05,              // width of the glyph
    0xBA, 0x11, 0x00,       // Character - 124, offset (0x000011BA)
    0x08,              // width of the glyph
    0xD3, 0x11, 0x00,       // Character - 125, offset (0x000011D3)
    0x0A,              // width of the glyph
    0xEC, 0x11, 0x00,       // Character - 126, offset (0x000011EC)
/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 32
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 33
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 34
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x6C, 0x00,         //   ** **         
    0x6C, 0x00,         //   ** **         
    0x64, 0x00,         //   *  **         
    0x44, 0x00,         //   *   *         
    0x44, 0x00,         //   *   *         
    0x44, 0x00,         //   *   *         
    0x44, 0x00,         //   *   *         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 35
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x20, 0x01,         //      *  *       
    0x20, 0x01,         //      *  *       
    0x90, 0x00,         //     *  *        
    0xFC, 0x03,         //   ********      
    0x90, 0x00,         //     *  *        
    0xC8, 0x00,         //    *  **        
    0x48, 0x00,         //    *  *         
    0xFE, 0x01,         //  ********       
    0x4C, 0x00,         //   **  *         
    0x24, 0x00,         //   *  *          
    0x24, 0x00,         //   *  *          
    0x24, 0x00,         //   *  *          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 36
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x10, 0x00,         //     *           
    0x10, 0x00,         //     *           
    0xFC, 0x00,         //   ******        
    0xD6, 0x00,         //  ** * **        
    0x16, 0x00,         //  ** *           
    0x16, 0x00,         //  ** *           
    0x1E, 0x00,         //  ****           
    0x78, 0x00,         //    ****         
    0xF0, 0x00,         //     ****        
    0x90, 0x01,         //     *  **       
    0x90, 0x01,         //     *  **       
    0x92, 0x01,         //  *  *  **       
    0xD6, 0x00,         //  ** * **        
    0x7C, 0x00,         //   *****         
    0x10, 0x00,         //     *           
    0x10, 0x00,         //     *           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 37
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x38, 0x08,         //    ***     *    
    0x64, 0x0C,         //   *  **   **    
    0x66, 0x06,         //  **  **  **     
    0x66, 0x02,         //  **  **  *      
    0x66, 0x01,         //  **  ** *       
    0xA4, 0x01,         //   *  * **       
    0xDC, 0x1C,         //   *** **  ***   
    0x40, 0x32,         //       *  *  **  
    0x60, 0x33,         //      ** **  **  
    0x30, 0x33,         //     **  **  **  
    0x10, 0x33,         //     *   **  **  
    0x08, 0x12,         //    *     *  *   
    0x0C, 0x0E,         //   **     ***    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 38
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x00,         //      ***        
    0x90, 0x01,         //     *  **       
    0x98, 0x01,         //    **  **       
    0x98, 0x01,         //    **  **       
    0x98, 0x00,         //    **  *        
    0xD8, 0x00,         //    ** **        
    0x30, 0x00,         //     **          
    0x38, 0x3F,         //    ***  ******  
    0x6C, 0x0E,         //   ** **  ***    
    0x46, 0x0C,         //  **   *   **    
    0x86, 0x0C,         //  **    *  **    
    0x86, 0x05,         //  **    ** *     
    0x06, 0x07,         //  **     ***     
    0x0C, 0x0D,         //   **    * **    
    0xF8, 0x38,         //    *****   ***  
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 39
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 40
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x20,         //      *  
    0x10,         //     *   
    0x18,         //    **   
    0x08,         //    *    
    0x0C,         //   **    
    0x04,         //   *     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x04,         //   *     
    0x0C,         //   **    
    0x0C,         //   **    
    0x18,         //    **   
    0x10,         //     *   
    0x20,         //      *  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 41
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x04,         //   *     
    0x0C,         //   **    
    0x18,         //    **   
    0x18,         //    **   
    0x10,         //     *   
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x10,         //     *   
    0x18,         //    **   
    0x08,         //    *    
    0x0C,         //   **    
    0x04,         //   *     
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 42
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x10, 0x00,         //     *           
    0x10, 0x00,         //     *           
    0x92, 0x01,         //  *  *  **       
    0xDC, 0x00,         //   *** **        
    0x30, 0x00,         //     **          
    0xFC, 0x00,         //   ******        
    0x96, 0x00,         //  ** *  *        
    0x10, 0x00,         //     *           
    0x10, 0x00,         //     *           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 43
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xFF, 0x00,         // ********        
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 44
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x0C,         //   **    
    0x0C,         //   **    
    0x04,         //   *     
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 45
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 46
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 47
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x01,         //         *       
    0x80, 0x01,         //        **       
    0x80, 0x00,         //        *        
    0x80, 0x00,         //        *        
    0xC0, 0x00,         //       **        
    0x40, 0x00,         //       *         
    0x60, 0x00,         //      **         
    0x20, 0x00,         //      *          
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x10, 0x00,         //     *           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x04, 0x00,         //   *             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x03, 0x00,         // **              
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 48
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x70, 0x00,         //     ***         
    0xCC, 0x00,         //   **  **        
    0xC4, 0x00,         //   *   **        
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x8C, 0x00,         //   **   *        
    0xCC, 0x00,         //   **  **        
    0x78, 0x00,         //    ****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 49
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x30, 0x00,         //     **          
    0x3C, 0x00,         //   ****          
    0x32, 0x00,         //  *  **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 50
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x00,         //     ****        
    0xCC, 0x01,         //   **  ***       
    0x84, 0x01,         //   *    **       
    0x82, 0x01,         //  *     **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x01,         //    **   *       
    0x0C, 0x01,         //   **    *       
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 51
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x00,         //    ****         
    0xE6, 0x00,         //  **  ***        
    0xC6, 0x00,         //  **   **        
    0xC0, 0x00,         //       **        
    0x40, 0x00,         //       *         
    0x30, 0x00,         //     **          
    0xE8, 0x00,         //    * ***        
    0xC0, 0x01,         //       ***       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC2, 0x00,         //  *    **        
    0x3C, 0x00,         //   ****          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 52
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x00,         //       **        
    0xE0, 0x00,         //      ***        
    0xF0, 0x00,         //     ****        
    0xD0, 0x00,         //     * **        
    0xC8, 0x00,         //    *  **        
    0xC8, 0x00,         //    *  **        
    0xC4, 0x00,         //   *   **        
    0xC2, 0x00,         //  *    **        
    0xFE, 0x03,         //  *********      
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xF0, 0x01,         //     *****       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 53
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x01,         //         *       
    0xFC, 0x00,         //   ******        
    0x04, 0x00,         //   *             
    0x04, 0x00,         //   *             
    0x04, 0x00,         //   *             
    0x7C, 0x00,         //   *****         
    0xC2, 0x00,         //  *    **        
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC2, 0x00,         //  *    **        
    0x7C, 0x00,         //   *****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 54
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x00,         //       **        
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xF6, 0x00,         //  ** ****        
    0xCE, 0x01,         //  ***  ***       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x84, 0x01,         //   *    **       
    0xCC, 0x00,         //   **  **        
    0x78, 0x00,         //    ****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 55
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x82, 0x01,         //  *     **       
    0x80, 0x00,         //        *        
    0xC0, 0x00,         //       **        
    0x40, 0x00,         //       *         
    0x40, 0x00,         //       *         
    0x20, 0x00,         //      *          
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x10, 0x00,         //     *           
    0x18, 0x00,         //    **           
    0x0C, 0x00,         //   **            
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 56
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF8, 0x00,         //    *****        
    0xCC, 0x01,         //   **  ***       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0xCE, 0x00,         //  ***  **        
    0x78, 0x00,         //    ****         
    0xF8, 0x01,         //    ******       
    0x8C, 0x03,         //   **   ***      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x8C, 0x01,         //   **   **       
    0x78, 0x00,         //    ****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 57
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x00,         //    ****         
    0xCC, 0x00,         //   **  **        
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0xCC, 0x01,         //   **  ***       
    0xB8, 0x01,         //    *** **       
    0x80, 0x00,         //        *        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x0C, 0x00,         //   **            
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 58
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 59
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x0C,         //   **    
    0x0C,         //   **    
    0x04,         //   *     
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 60
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x01,         //        **       
    0x70, 0x00,         //     ***         
    0x0E, 0x00,         //  ***            
    0x0E, 0x00,         //  ***            
    0x78, 0x00,         //    ****         
    0xC0, 0x01,         //       ***       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 61
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 62
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x00,         //  **             
    0x3C, 0x00,         //   ****          
    0xE0, 0x01,         //      ****       
    0xE0, 0x00,         //      ***        
    0x1C, 0x00,         //   ***           
    0x02, 0x00,         //  *              
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 63
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x00,         //    ****         
    0xE4, 0x00,         //   *  ***        
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 64
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x80, 0x1F, 0x00,         //        ******           
    0x70, 0x38, 0x00,         //     ***    ***          
    0x18, 0x60, 0x00,         //    **        **         
    0x0C, 0xC0, 0x00,         //   **          **        
    0x86, 0xCB, 0x00,         //  **    *** *  **        
    0x46, 0x8C, 0x01,         //  **   *   **   **       
    0x23, 0x8C, 0x01,         // **   *    **   **       
    0x33, 0x8C, 0x01,         // **  **    **   **       
    0x33, 0x8C, 0x01,         // **  **    **   **       
    0x33, 0x8C, 0x01,         // **  **    **   **       
    0x33, 0x8C, 0x00,         // **  **    **   *        
    0x33, 0xCC, 0x00,         // **  **    **  **        
    0x66, 0x4E, 0x00,         //  **  **  ***  *         
    0xC6, 0x39, 0x00,         //  **   ***  ***          
    0x0C, 0x00, 0x00,         //   **                    
    0x1C, 0x40, 0x00,         //   ***         *         
    0x70, 0x60, 0x00,         //     ***      **         
    0xC0, 0x1F, 0x00,         //       *******           
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 65
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x40, 0x00,         //       *         
    0x60, 0x00,         //      **         
    0xE0, 0x00,         //      ***        
    0x90, 0x00,         //     *  *        
    0x90, 0x00,         //     *  *        
    0x90, 0x01,         //     *  **       
    0x08, 0x01,         //    *    *       
    0xF8, 0x01,         //    ******       
    0x08, 0x03,         //    *    **      
    0x04, 0x02,         //   *      *      
    0x04, 0x02,         //   *      *      
    0x04, 0x06,         //   *      **     
    0x0F, 0x0F,         // ****    ****    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 66
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x00,         //  *******        
    0xCD, 0x01,         // * **  ***       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0xCC, 0x00,         //   **  **        
    0xFC, 0x00,         //   ******        
    0x8C, 0x01,         //   **   **       
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x8C, 0x01,         //   **   **       
    0xFE, 0x00,         //  *******        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 67
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x03,         //      *****      
    0x10, 0x06,         //     *    **     
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0C, 0x00,         //   **            
    0x0C, 0x04,         //   **      *     
    0x18, 0x06,         //    **    **     
    0xE0, 0x01,         //      ****       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 68
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x00,         //  *******        
    0x8D, 0x01,         // * **   **       
    0x0C, 0x03,         //   **    **      
    0x0C, 0x07,         //   **    ***     
    0x0C, 0x06,         //   **     **     
    0x0C, 0x06,         //   **     **     
    0x0C, 0x06,         //   **     **     
    0x0C, 0x06,         //   **     **     
    0x0C, 0x06,         //   **     **     
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x8C, 0x01,         //   **   **       
    0xFE, 0x00,         //  *******        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 69
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x0C, 0x01,         //   **    *       
    0x0C, 0x01,         //   **    *       
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xFC, 0x00,         //   ******        
    0x8C, 0x00,         //   **   *        
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x02,         //   **     *      
    0x0C, 0x02,         //   **     *      
    0xFE, 0x03,         //  *********      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 70
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x03,         //  *********      
    0x0C, 0x01,         //   **    *       
    0x0C, 0x01,         //   **    *       
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xFC, 0x00,         //   ******        
    0x4C, 0x00,         //   **  *         
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x3E, 0x00,         //  *****          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 71
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x01,         //      ****       
    0x18, 0x03,         //    **   **      
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0xC6, 0x07,         //  **   *****     
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x0C, 0x03,         //   **    **      
    0x18, 0x03,         //    **   **      
    0xF0, 0x00,         //     ****        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 72
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1E, 0x1E,         //  ****    ****   
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0xFC, 0x0F,         //   **********    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x1E, 0x1E,         //  ****    ****   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 73
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 74
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0xF8,         //    *****
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x60,         //      ** 
    0x20,         //      *  
    0x12,         //  *  *   
    0x0F,         // ****    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 75
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x9E, 0x07,         //  ****  ****     
    0x0C, 0x01,         //   **    *       
    0x8C, 0x00,         //   **   *        
    0x4C, 0x00,         //   **  *         
    0x6C, 0x00,         //   ** **         
    0x3C, 0x00,         //   ****          
    0x3C, 0x00,         //   ****          
    0x6C, 0x00,         //   ** **         
    0x6C, 0x00,         //   ** **         
    0xCC, 0x00,         //   **  **        
    0x8C, 0x01,         //   **   **       
    0x0C, 0x03,         //   **    **      
    0x1E, 0x0E,         //  ****    ***    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 76
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1E, 0x00,         //  ****           
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x02,         //   **     *      
    0x0C, 0x02,         //   **     *      
    0xFE, 0x03,         //  *********      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 77
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x0E, 0xF0, 0x00,         //  ***        ****        
    0x1C, 0x70, 0x00,         //   ***       ***         
    0x1C, 0x70, 0x00,         //   ***       ***         
    0x14, 0x68, 0x00,         //   * *      * **         
    0x34, 0x68, 0x00,         //   * **     * **         
    0x24, 0x6C, 0x00,         //   *  *    ** **         
    0x64, 0x64, 0x00,         //   *  **   *  **         
    0x44, 0x64, 0x00,         //   *   *   *  **         
    0xC4, 0x62, 0x00,         //   *   ** *   **         
    0xC4, 0x62, 0x00,         //   *   ** *   **         
    0x84, 0x61, 0x00,         //   *    **    **         
    0x84, 0x61, 0x00,         //   *    **    **         
    0x1E, 0xF9, 0x00,         //  ****   *  *****        
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 78
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x1E,         //  **      ****   
    0x0C, 0x0C,         //   **      **    
    0x1C, 0x0C,         //   ***     **    
    0x1C, 0x0C,         //   ***     **    
    0x2C, 0x0C,         //   ** *    **    
    0x4C, 0x0C,         //   **  *   **    
    0xCC, 0x0C,         //   **  **  **    
    0x8C, 0x0C,         //   **   *  **    
    0x0C, 0x0D,         //   **    * **    
    0x0C, 0x0F,         //   **    ****    
    0x0C, 0x0E,         //   **     ***    
    0x0C, 0x0E,         //   **     ***    
    0x1E, 0x0C,         //  ****     **    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 79
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x01,         //      ****       
    0x18, 0x03,         //    **   **      
    0x0C, 0x06,         //   **     **     
    0x04, 0x06,         //   *      **     
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x0C, 0x04,         //   **      *     
    0x0C, 0x06,         //   **     **     
    0x18, 0x03,         //    **   **      
    0xF0, 0x00,         //     ****        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 80
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x00,         //  *******        
    0x8D, 0x01,         // * **   **       
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x8C, 0x01,         //   **   **       
    0xFC, 0x00,         //   ******        
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x3E, 0x00,         //  *****          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 81
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x01,         //      ****       
    0x18, 0x03,         //    **   **      
    0x0C, 0x06,         //   **     **     
    0x04, 0x06,         //   *      **     
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x0C, 0x04,         //   **      *     
    0x0C, 0x06,         //   **     **     
    0x18, 0x03,         //    **   **      
    0xF0, 0x01,         //     *****       
    0x80, 0x01,         //        **       
    0x00, 0x12,         //          *  *   
    0x00, 0x1C,         //           ***   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 82
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x00,         //  *******        
    0x8D, 0x01,         // * **   **       
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x8C, 0x01,         //   **   **       
    0x7C, 0x00,         //   *****         
    0x4C, 0x00,         //   **  *         
    0xCC, 0x00,         //   **  **        
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0x0C, 0x03,         //   **    **      
    0x1E, 0x0E,         //  ****    ***    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 83
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x00,         //    ****         
    0xC4, 0x00,         //   *   **        
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x1E, 0x00,         //  ****           
    0x7C, 0x00,         //   *****         
    0xF0, 0x00,         //     ****        
    0xE0, 0x01,         //      ****       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x82, 0x01,         //  *     **       
    0xC6, 0x00,         //  **   **        
    0x7C, 0x00,         //   *****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 84
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x0F,         //  ***********    
    0x61, 0x08,         // *    **    *    
    0x61, 0x04,         // *    **   *     
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0xF8, 0x01,         //    ******       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 85
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1E, 0x1E,         //  ****    ****   
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x0C,         //   **      **    
    0x1C, 0x06,         //   ***    **     
    0x18, 0x06,         //    **    **     
    0xE0, 0x01,         //      ****       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 86
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1F, 0x1E,         // *****    ****   
    0x0C, 0x04,         //   **      *     
    0x0C, 0x04,         //   **      *     
    0x08, 0x04,         //    *      *     
    0x18, 0x02,         //    **    *      
    0x18, 0x02,         //    **    *      
    0x10, 0x03,         //     *   **      
    0x30, 0x01,         //     **  *       
    0x30, 0x01,         //     **  *       
    0xE0, 0x01,         //      ****       
    0xE0, 0x00,         //      ***        
    0xC0, 0x00,         //       **        
    0x40, 0x00,         //       *         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 87
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x1F, 0xE1, 0x01,         // *****   *    ****       
    0x04, 0x83, 0x00,         //   *     **     *        
    0x04, 0xC3, 0x00,         //   *     **    **        
    0x8C, 0x43, 0x00,         //   **   ***    *         
    0x8C, 0x46, 0x00,         //   **   * **   *         
    0x88, 0x44, 0x00,         //    *   *  *   *         
    0xC8, 0x44, 0x00,         //    *  **  *   *         
    0x58, 0x6C, 0x00,         //    ** *   ** **         
    0x58, 0x28, 0x00,         //    ** *    * *          
    0x78, 0x38, 0x00,         //    ****    ***          
    0x30, 0x38, 0x00,         //     **     ***          
    0x30, 0x30, 0x00,         //     **      **          
    0x30, 0x10, 0x00,         //     **      *           
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 88
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x9F, 0x0F,         // *****  *****    
    0x0C, 0x02,         //   **     *      
    0x18, 0x03,         //    **   **      
    0x18, 0x01,         //    **   *       
    0xB0, 0x00,         //     ** *        
    0xE0, 0x00,         //      ***        
    0x60, 0x00,         //      **         
    0xE0, 0x00,         //      ***        
    0x90, 0x01,         //     *  **       
    0x18, 0x03,         //    **   **      
    0x08, 0x03,         //    *    **      
    0x04, 0x06,         //   *      **     
    0x1F, 0x1F,         // *****   *****   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 89
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x07, 0x0F,         // ***     ****    
    0x04, 0x02,         //   *      *      
    0x0C, 0x03,         //   **    **      
    0x18, 0x01,         //    **   *       
    0x98, 0x01,         //    **  **       
    0xB0, 0x00,         //     ** *        
    0xE0, 0x00,         //      ***        
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0xF8, 0x01,         //    ******       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 90
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x03,         //  *********      
    0x02, 0x01,         //  *      *       
    0x82, 0x01,         //  *     **       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x0C, 0x02,         //   **     *      
    0x06, 0x02,         //  **      *      
    0xFE, 0x03,         //  *********      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 91
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x06,         //  **     
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 92
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x02, 0x00,         //  *              
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x04, 0x00,         //   *             
    0x0C, 0x00,         //   **            
    0x08, 0x00,         //    *            
    0x08, 0x00,         //    *            
    0x18, 0x00,         //    **           
    0x10, 0x00,         //     *           
    0x30, 0x00,         //     **          
    0x20, 0x00,         //      *          
    0x20, 0x00,         //      *          
    0x60, 0x00,         //      **         
    0x40, 0x00,         //       *         
    0xC0, 0x00,         //       **        
    0x80, 0x00,         //        *        
    0x80, 0x00,         //        *        
    0x80, 0x01,         //        **       
    0x00, 0x01,         //         *       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 93
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1F,         // *****   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x1F,         // *****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 94
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x70, 0x00,         //     ***         
    0x78, 0x00,         //    ****         
    0x48, 0x00,         //    *  *         
    0xC8, 0x00,         //    *  **        
    0x84, 0x00,         //   *    *        
    0x84, 0x01,         //   *    **       
    0x86, 0x01,         //  **    **       
    0x02, 0x01,         //  *      *       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 95
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 96
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x07,         // ***     
    0x04,         //   *     
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 97
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x00,         //    ****         
    0xC6, 0x00,         //  **   **        
    0xC2, 0x00,         //  *    **        
    0xC0, 0x00,         //       **        
    0xF0, 0x00,         //     ****        
    0xDC, 0x00,         //   *** **        
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xE6, 0x00,         //  **  ***        
    0xDC, 0x03,         //   *** ****      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 98
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x00,         //  **             
    0x07, 0x00,         // ***             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0xE6, 0x00,         //  **  ***        
    0x9E, 0x01,         //  ****  **       
    0x8E, 0x03,         //  ***   ***      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x01,         //  **     *       
    0x8E, 0x00,         //  ***   *        
    0x78, 0x00,         //    ****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 99
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x01,         //     *****       
    0x08, 0x01,         //    *    *       
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0C, 0x00,         //   **            
    0x0C, 0x01,         //   **    *       
    0xF0, 0x00,         //     ****        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 100
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x01,         //       ***       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xF0, 0x01,         //     *****       
    0x8C, 0x01,         //   **   **       
    0x84, 0x01,         //   *    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0xCC, 0x03,         //   **  ****      
    0xB8, 0x07,         //    *** ****     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 101
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x00,         //     ****        
    0x88, 0x01,         //    *   **       
    0x04, 0x01,         //   *     *       
    0x06, 0x01,         //  **     *       
    0xFE, 0x03,         //  *********      
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0C, 0x00,         //   **            
    0x0C, 0x01,         //   **    *       
    0xF0, 0x00,         //     ****        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 102
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x00,         //      ***        
    0x90, 0x01,         //     *  **       
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x7E, 0x00,         //  ******         
    0x0D, 0x00,         // * **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x3E, 0x00,         //  *****          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 103
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x03,         //    **** **      
    0xCC, 0x00,         //   **  **        
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0xCC, 0x00,         //   **  **        
    0x78, 0x00,         //    ****         
    0x08, 0x00,         //    *            
    0x1C, 0x00,         //   ***           
    0xF8, 0x01,         //    ******       
    0x06, 0x07,         //  **     ***     
    0x03, 0x06,         // **       **     
    0x03, 0x06,         // **       **     
    0x06, 0x03,         //  **     **      
    0xFC, 0x00,         //   ******        
    0x00, 0x00,         //                 

/***********************************
 * Character - 104
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x0C, 0x00,         //   **            
    0x0E, 0x00,         //  ***            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xCC, 0x01,         //   **  ***       
    0x2C, 0x03,         //   ** *  **      
    0x1C, 0x03,         //   ***   **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x9E, 0x07,         //  ****  ****     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 105
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0E,         //  ***    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 106
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x30,         //     **  
    0x30,         //     **  
    0x00,         //         
    0x00,         //         
    0x30,         //     **  
    0x38,         //    ***  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x10,         //     *   
    0x08,         //    *    
    0x07,         // ***     
    0x00,         //         

/***********************************
 * Character - 107
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x0C, 0x00,         //   **            
    0x0E, 0x00,         //  ***            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x8C, 0x07,         //   **   ****     
    0x8C, 0x01,         //   **   **       
    0x4C, 0x00,         //   **  *         
    0x2C, 0x00,         //   ** *          
    0x3C, 0x00,         //   ****          
    0x6C, 0x00,         //   ** **         
    0xCC, 0x00,         //   **  **        
    0xCC, 0x00,         //   **  **        
    0x8C, 0x01,         //   **   **       
    0x1E, 0x07,         //  ****   ***     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 108
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0E,         //  ***    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x3F,         // ******  
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 109
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0xCE, 0x71, 0x00,         //  ***  ***   ***         
    0x2C, 0xCB, 0x00,         //   ** *  ** *  **        
    0x1C, 0xC7, 0x00,         //   ***   ***   **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x0C, 0xC3, 0x00,         //   **    **    **        
    0x9E, 0xE7, 0x01,         //  ****  ****  ****       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 110
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xCC, 0x01,         //   **  ***       
    0x2E, 0x03,         //  *** *  **      
    0x1C, 0x03,         //   ***   **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x9E, 0x07,         //  ****  ****     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 111
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x00,         //     ****        
    0x8C, 0x01,         //   **   **       
    0x84, 0x03,         //   *    ***      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x06, 0x03,         //  **     **      
    0x0E, 0x01,         //  ***    *       
    0x8C, 0x01,         //   **   **       
    0x78, 0x00,         //    ****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 112
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xCE, 0x01,         //  ***  ***       
    0xBC, 0x01,         //   **** **       
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x01,         //   **    *       
    0x9C, 0x01,         //   ***  **       
    0xEC, 0x00,         //   ** ***        
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x3E, 0x00,         //  *****          
    0x00, 0x00,         //                 

/***********************************
 * Character - 113
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x70, 0x01,         //     *** *       
    0x88, 0x01,         //    *   **       
    0x84, 0x01,         //   *    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x86, 0x01,         //  **    **       
    0x4C, 0x01,         //   **  * *       
    0xB8, 0x01,         //    *** **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xE0, 0x03,         //      *****      
    0x00, 0x00,         //                 

/***********************************
 * Character - 114
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0xCC,         //   **  **
    0xAE,         //  *** * *
    0x9C,         //   ***  *
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 115
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x26,         //  **  *  
    0x06,         //  **     
    0x0E,         //  ***    
    0x3C,         //   ****  
    0x78,         //    **** 
    0x60,         //      ** 
    0x62,         //  *   ** 
    0x62,         //  *   ** 
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 116
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x0C,         //   **    
    0x0C,         //   **    
    0xFE,         //  *******
    0x0D,         // * **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x4C,         //   **  * 
    0xB8,         //    *** *
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 117
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x8C, 0x01,         //   **   **       
    0xCE, 0x01,         //  ***  ***       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x01,         //   **   **       
    0xCC, 0x05,         //   **  *** *     
    0xB8, 0x03,         //    *** ***      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 118
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x8F, 0x03,         // ****   ***      
    0x06, 0x01,         //  **     *       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x00,         //   **   *        
    0x88, 0x00,         //    *   *        
    0x58, 0x00,         //    ** *         
    0x58, 0x00,         //    ** *         
    0x50, 0x00,         //     * *         
    0x30, 0x00,         //     **          
    0x20, 0x00,         //      *          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 119
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x8F, 0x78,         // ****   *   **** 
    0x86, 0x11,         //  **    **   *   
    0x84, 0x11,         //   *    **   *   
    0x44, 0x11,         //   *   * *   *   
    0x4C, 0x13,         //   **  * **  *   
    0x48, 0x0B,         //    *  * ** *    
    0x28, 0x0A,         //    * *   * *    
    0x38, 0x0E,         //    ***   ***    
    0x30, 0x06,         //     **   **     
    0x10, 0x04,         //     *     *     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 120
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xDF, 0x03,         // ***** ****      
    0x8C, 0x01,         //   **   **       
    0x88, 0x00,         //    *   *        
    0x58, 0x00,         //    ** *         
    0x30, 0x00,         //     **          
    0x70, 0x00,         //     ***         
    0xC8, 0x00,         //    *  **        
    0x8C, 0x00,         //   **   *        
    0x84, 0x01,         //   *    **       
    0xCF, 0x03,         // ****  ****      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 121
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x8F, 0x03,         // ****   ***      
    0x06, 0x01,         //  **     *       
    0x8C, 0x01,         //   **   **       
    0x8C, 0x00,         //   **   *        
    0x88, 0x00,         //    *   *        
    0x58, 0x00,         //    ** *         
    0x58, 0x00,         //    ** *         
    0x50, 0x00,         //     * *         
    0x30, 0x00,         //     **          
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x10, 0x00,         //     *           
    0x18, 0x00,         //    **           
    0x0F, 0x00,         // ****            
    0x07, 0x00,         // ***             
    0x00, 0x00,         //                 

/***********************************
 * Character - 122
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x00,         //  *******        
    0xC2, 0x00,         //  *    **        
    0x62, 0x00,         //  *   **         
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x0C, 0x01,         //   **    *       
    0x86, 0x00,         //  **    *        
    0xFE, 0x00,         //  *******        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 123
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x40,         //       * 
    0x30,         //     **  
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x38,         //    ***  
    0x30,         //     **  
    0x30,         //     **  
    0x10,         //     *   
    0x0C,         //   **    
    0x30,         //     **  
    0x30,         //     **  
    0x30,         //     **  
    0x38,         //    ***  
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x30,         //     **  
    0x60,         //      ** 
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 124
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 125
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x06,         //  **     
    0x0C,         //   **    
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x0C,         //   **    
    0x0C,         //   **    
    0x30,         //     **  
    0x08,         //    *    
    0x0C,         //   **    
    0x0C,         //   **    
    0x1C,         //   ***   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x0C,         //   **    
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 126
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1C, 0x02,         //   ***    *      
    0x3C, 0x01,         //   ****  *       
    0xF2, 0x01,         //  *  *****       
    0xE1, 0x00,         // *    ***        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

};

/*********************************
 * TTF Font File Structure
 * Label: Font35
 * Description:  Height: 35 pixels, 1 bit per pixel, Range: ' ' to '~'
 ***********************************/

extern const char __Font35[] __attribute__((aligned(2)));

const FONT_FLASH Font35 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__Font35
};

const char __Font35[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x00,           // Font information:  1 bit per pixel, Characters zero degress rotation
    0x20, 0x00,     // First Character
    0x7E, 0x00,     // Last Character
    0x23, 0x00,     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
    0x06,              // width of the glyph
    0x84, 0x01, 0x00,       // Character - 32, offset (0x00000184)
    0x08,              // width of the glyph
    0xA7, 0x01, 0x00,       // Character - 33, offset (0x000001A7)
    0x0C,              // width of the glyph
    0xCA, 0x01, 0x00,       // Character - 34, offset (0x000001CA)
    0x0E,              // width of the glyph
    0x10, 0x02, 0x00,       // Character - 35, offset (0x00000210)
    0x0D,              // width of the glyph
    0x56, 0x02, 0x00,       // Character - 36, offset (0x00000256)
    0x14,              // width of the glyph
    0x9C, 0x02, 0x00,       // Character - 37, offset (0x0000029C)
    0x14,              // width of the glyph
    0x05, 0x03, 0x00,       // Character - 38, offset (0x00000305)
    0x07,              // width of the glyph
    0x6E, 0x03, 0x00,       // Character - 39, offset (0x0000036E)
    0x09,              // width of the glyph
    0x91, 0x03, 0x00,       // Character - 40, offset (0x00000391)
    0x09,              // width of the glyph
    0xD7, 0x03, 0x00,       // Character - 41, offset (0x000003D7)
    0x0D,              // width of the glyph
    0x1D, 0x04, 0x00,       // Character - 42, offset (0x0000041D)
    0x0C,              // width of the glyph
    0x63, 0x04, 0x00,       // Character - 43, offset (0x00000463)
    0x07,              // width of the glyph
    0xA9, 0x04, 0x00,       // Character - 44, offset (0x000004A9)
    0x0A,              // width of the glyph
    0xCC, 0x04, 0x00,       // Character - 45, offset (0x000004CC)
    0x07,              // width of the glyph
    0x12, 0x05, 0x00,       // Character - 46, offset (0x00000512)
    0x0E,              // width of the glyph
    0x35, 0x05, 0x00,       // Character - 47, offset (0x00000535)
    0x0E,              // width of the glyph
    0x7B, 0x05, 0x00,       // Character - 48, offset (0x0000057B)
    0x0E,              // width of the glyph
    0xC1, 0x05, 0x00,       // Character - 49, offset (0x000005C1)
    0x0E,              // width of the glyph
    0x07, 0x06, 0x00,       // Character - 50, offset (0x00000607)
    0x0E,              // width of the glyph
    0x4D, 0x06, 0x00,       // Character - 51, offset (0x0000064D)
    0x0D,              // width of the glyph
    0x93, 0x06, 0x00,       // Character - 52, offset (0x00000693)
    0x0E,              // width of the glyph
    0xD9, 0x06, 0x00,       // Character - 53, offset (0x000006D9)
    0x0E,              // width of the glyph
    0x1F, 0x07, 0x00,       // Character - 54, offset (0x0000071F)
    0x0E,              // width of the glyph
    0x65, 0x07, 0x00,       // Character - 55, offset (0x00000765)
    0x0D,              // width of the glyph
    0xAB, 0x07, 0x00,       // Character - 56, offset (0x000007AB)
    0x0E,              // width of the glyph
    0xF1, 0x07, 0x00,       // Character - 57, offset (0x000007F1)
    0x07,              // width of the glyph
    0x37, 0x08, 0x00,       // Character - 58, offset (0x00000837)
    0x07,              // width of the glyph
    0x5A, 0x08, 0x00,       // Character - 59, offset (0x0000085A)
    0x0D,              // width of the glyph
    0x7D, 0x08, 0x00,       // Character - 60, offset (0x0000087D)
    0x0D,              // width of the glyph
    0xC3, 0x08, 0x00,       // Character - 61, offset (0x000008C3)
    0x0D,              // width of the glyph
    0x09, 0x09, 0x00,       // Character - 62, offset (0x00000909)
    0x0C,              // width of the glyph
    0x4F, 0x09, 0x00,       // Character - 63, offset (0x0000094F)
    0x18,              // width of the glyph
    0x95, 0x09, 0x00,       // Character - 64, offset (0x00000995)
    0x11,              // width of the glyph
    0xFE, 0x09, 0x00,       // Character - 65, offset (0x000009FE)
    0x10,              // width of the glyph
    0x67, 0x0A, 0x00,       // Character - 66, offset (0x00000A67)
    0x10,              // width of the glyph
    0xAD, 0x0A, 0x00,       // Character - 67, offset (0x00000AAD)
    0x11,              // width of the glyph
    0xF3, 0x0A, 0x00,       // Character - 68, offset (0x00000AF3)
    0x0E,              // width of the glyph
    0x5C, 0x0B, 0x00,       // Character - 69, offset (0x00000B5C)
    0x0E,              // width of the glyph
    0xA2, 0x0B, 0x00,       // Character - 70, offset (0x00000BA2)
    0x11,              // width of the glyph
    0xE8, 0x0B, 0x00,       // Character - 71, offset (0x00000BE8)
    0x13,              // width of the glyph
    0x51, 0x0C, 0x00,       // Character - 72, offset (0x00000C51)
    0x09,              // width of the glyph
    0xBA, 0x0C, 0x00,       // Character - 73, offset (0x00000CBA)
    0x0A,              // width of the glyph
    0x00, 0x0D, 0x00,       // Character - 74, offset (0x00000D00)
    0x11,              // width of the glyph
    0x46, 0x0D, 0x00,       // Character - 75, offset (0x00000D46)
    0x0E,              // width of the glyph
    0xAF, 0x0D, 0x00,       // Character - 76, offset (0x00000DAF)
    0x17,              // width of the glyph
    0xF5, 0x0D, 0x00,       // Character - 77, offset (0x00000DF5)
    0x13,              // width of the glyph
    0x5E, 0x0E, 0x00,       // Character - 78, offset (0x00000E5E)
    0x11,              // width of the glyph
    0xC7, 0x0E, 0x00,       // Character - 79, offset (0x00000EC7)
    0x0F,              // width of the glyph
    0x30, 0x0F, 0x00,       // Character - 80, offset (0x00000F30)
    0x12,              // width of the glyph
    0x76, 0x0F, 0x00,       // Character - 81, offset (0x00000F76)
    0x10,              // width of the glyph
    0xDF, 0x0F, 0x00,       // Character - 82, offset (0x00000FDF)
    0x0E,              // width of the glyph
    0x25, 0x10, 0x00,       // Character - 83, offset (0x00001025)
    0x10,              // width of the glyph
    0x6B, 0x10, 0x00,       // Character - 84, offset (0x0000106B)
    0x13,              // width of the glyph
    0xB1, 0x10, 0x00,       // Character - 85, offset (0x000010B1)
    0x13,              // width of the glyph
    0x1A, 0x11, 0x00,       // Character - 86, offset (0x0000111A)
    0x19,              // width of the glyph
    0x83, 0x11, 0x00,       // Character - 87, offset (0x00001183)
    0x12,              // width of the glyph
    0x0F, 0x12, 0x00,       // Character - 88, offset (0x0000120F)
    0x11,              // width of the glyph
    0x78, 0x12, 0x00,       // Character - 89, offset (0x00001278)
    0x0F,              // width of the glyph
    0xE1, 0x12, 0x00,       // Character - 90, offset (0x000012E1)
    0x09,              // width of the glyph
    0x27, 0x13, 0x00,       // Character - 91, offset (0x00001327)
    0x0E,              // width of the glyph
    0x6D, 0x13, 0x00,       // Character - 92, offset (0x0000136D)
    0x09,              // width of the glyph
    0xB3, 0x13, 0x00,       // Character - 93, offset (0x000013B3)
    0x0E,              // width of the glyph
    0xF9, 0x13, 0x00,       // Character - 94, offset (0x000013F9)
    0x0E,              // width of the glyph
    0x3F, 0x14, 0x00,       // Character - 95, offset (0x0000143F)
    0x09,              // width of the glyph
    0x85, 0x14, 0x00,       // Character - 96, offset (0x00001485)
    0x0D,              // width of the glyph
    0xCB, 0x14, 0x00,       // Character - 97, offset (0x000014CB)
    0x0F,              // width of the glyph
    0x11, 0x15, 0x00,       // Character - 98, offset (0x00001511)
    0x0D,              // width of the glyph
    0x57, 0x15, 0x00,       // Character - 99, offset (0x00001557)
    0x0F,              // width of the glyph
    0x9D, 0x15, 0x00,       // Character - 100, offset (0x0000159D)
    0x0D,              // width of the glyph
    0xE3, 0x15, 0x00,       // Character - 101, offset (0x000015E3)
    0x0C,              // width of the glyph
    0x29, 0x16, 0x00,       // Character - 102, offset (0x00001629)
    0x0E,              // width of the glyph
    0x6F, 0x16, 0x00,       // Character - 103, offset (0x0000166F)
    0x10,              // width of the glyph
    0xB5, 0x16, 0x00,       // Character - 104, offset (0x000016B5)
    0x08,              // width of the glyph
    0xFB, 0x16, 0x00,       // Character - 105, offset (0x000016FB)
    0x08,              // width of the glyph
    0x1E, 0x17, 0x00,       // Character - 106, offset (0x0000171E)
    0x0F,              // width of the glyph
    0x41, 0x17, 0x00,       // Character - 107, offset (0x00001741)
    0x08,              // width of the glyph
    0x87, 0x17, 0x00,       // Character - 108, offset (0x00001787)
    0x17,              // width of the glyph
    0xAA, 0x17, 0x00,       // Character - 109, offset (0x000017AA)
    0x10,              // width of the glyph
    0x13, 0x18, 0x00,       // Character - 110, offset (0x00001813)
    0x0F,              // width of the glyph
    0x59, 0x18, 0x00,       // Character - 111, offset (0x00001859)
    0x0F,              // width of the glyph
    0x9F, 0x18, 0x00,       // Character - 112, offset (0x0000189F)
    0x0F,              // width of the glyph
    0xE5, 0x18, 0x00,       // Character - 113, offset (0x000018E5)
    0x0B,              // width of the glyph
    0x2B, 0x19, 0x00,       // Character - 114, offset (0x0000192B)
    0x0B,              // width of the glyph
    0x71, 0x19, 0x00,       // Character - 115, offset (0x00001971)
    0x0A,              // width of the glyph
    0xB7, 0x19, 0x00,       // Character - 116, offset (0x000019B7)
    0x0F,              // width of the glyph
    0xFD, 0x19, 0x00,       // Character - 117, offset (0x000019FD)
    0x0E,              // width of the glyph
    0x43, 0x1A, 0x00,       // Character - 118, offset (0x00001A43)
    0x14,              // width of the glyph
    0x89, 0x1A, 0x00,       // Character - 119, offset (0x00001A89)
    0x0F,              // width of the glyph
    0xF2, 0x1A, 0x00,       // Character - 120, offset (0x00001AF2)
    0x0F,              // width of the glyph
    0x38, 0x1B, 0x00,       // Character - 121, offset (0x00001B38)
    0x0D,              // width of the glyph
    0x7E, 0x1B, 0x00,       // Character - 122, offset (0x00001B7E)
    0x0A,              // width of the glyph
    0xC4, 0x1B, 0x00,       // Character - 123, offset (0x00001BC4)
    0x07,              // width of the glyph
    0x0A, 0x1C, 0x00,       // Character - 124, offset (0x00001C0A)
    0x0A,              // width of the glyph
    0x2D, 0x1C, 0x00,       // Character - 125, offset (0x00001C2D)
    0x0E,              // width of the glyph
    0x73, 0x1C, 0x00,       // Character - 126, offset (0x00001C73)
/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 32
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 33
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x10,         //     *   
    0x1C,         //   ***   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 34
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x18, 0x03,         //    **   **      
    0x9C, 0x03,         //   ***  ***      
    0x9C, 0x03,         //   ***  ***      
    0x18, 0x03,         //    **   **      
    0x18, 0x03,         //    **   **      
    0x18, 0x03,         //    **   **      
    0x18, 0x03,         //    **   **      
    0x08, 0x03,         //    *    **      
    0x08, 0x01,         //    *    *       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 35
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x18,         //        *   **   
    0x80, 0x08,         //        *   *    
    0xC0, 0x0C,         //       **  **    
    0xC0, 0x0C,         //       **  **    
    0x40, 0x0C,         //       *   **    
    0xF8, 0x3F,         //    ***********  
    0x60, 0x06,         //      **  **     
    0x20, 0x06,         //      *   **     
    0x30, 0x02,         //     **   *      
    0x30, 0x03,         //     **  **      
    0xFE, 0x0F,         //  ***********    
    0x18, 0x01,         //    **   *       
    0x98, 0x01,         //    **  **       
    0x88, 0x01,         //    *   **       
    0x88, 0x00,         //    *   *        
    0x8C, 0x00,         //   **   *        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 36
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xF0, 0x07,         //     *******     
    0xCC, 0x0E,         //   **  ** ***    
    0xC4, 0x04,         //   *   **  *     
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xDE, 0x00,         //  **** **        
    0xFC, 0x00,         //   ******        
    0xF8, 0x03,         //    *******      
    0xE0, 0x07,         //      ******     
    0xC0, 0x0F,         //       ******    
    0xC0, 0x0E,         //       ** ***    
    0xC0, 0x0C,         //       **  **    
    0xC0, 0x0C,         //       **  **    
    0xC2, 0x0C,         //  *    **  **    
    0xC6, 0x04,         //  **   **  *     
    0xCE, 0x06,         //  ***  ** **     
    0xFC, 0x01,         //   *******       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 37
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x80, 0x01,         //                **       
    0x78, 0xC0, 0x00,         //    ****       **        
    0xCC, 0xC0, 0x00,         //   **  **      **        
    0x86, 0x61, 0x00,         //  **    **    **         
    0x86, 0x31, 0x00,         //  **    **   **          
    0x86, 0x39, 0x00,         //  **    **  ***          
    0x86, 0x19, 0x00,         //  **    **  **           
    0x86, 0x0D, 0x00,         //  **    ** **            
    0xCC, 0x06, 0x00,         //   **  ** **             
    0x78, 0xE6, 0x01,         //    ****  **  ****       
    0x00, 0x33, 0x03,         //         **  **  **      
    0x80, 0x19, 0x06,         //        **  **    **     
    0xC0, 0x19, 0x06,         //       ***  **    **     
    0xC0, 0x18, 0x06,         //       **   **    **     
    0x60, 0x18, 0x06,         //      **    **    **     
    0x30, 0x18, 0x06,         //     **     **    **     
    0x30, 0x30, 0x03,         //     **      **  **      
    0x18, 0xE0, 0x01,         //    **        ****       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 38
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x80, 0x07, 0x00,         //        ****             
    0x60, 0x0E, 0x00,         //      **  ***            
    0x20, 0x0C, 0x00,         //      *    **            
    0x30, 0x0C, 0x00,         //     **    **            
    0x30, 0x0C, 0x00,         //     **    **            
    0x30, 0x06, 0x00,         //     **   **             
    0x30, 0x07, 0x00,         //     **  ***             
    0xF0, 0x01, 0x00,         //     *****               
    0xE0, 0x00, 0x00,         //      ***                
    0xF0, 0xF0, 0x07,         //     ****    *******     
    0xD8, 0xE9, 0x02,         //    ** ***  * *** *      
    0xCC, 0xC1, 0x00,         //   **  ***     **        
    0x8C, 0xC3, 0x00,         //   **   ***    **        
    0x06, 0xC7, 0x00,         //  **     ***   **        
    0x06, 0x4F, 0x00,         //  **     ****  *         
    0x06, 0x7E, 0x00,         //  **      ******         
    0x06, 0x3C, 0x00,         //  **       ****          
    0x0C, 0xF8, 0x00,         //   **       *****        
    0x1C, 0xEC, 0x07,         //   ***     ** ******     
    0xF0, 0x83, 0x03,         //     ******     ***      
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 39
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 40
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x00,         //        *        
    0xC0, 0x01,         //       ***       
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x1C, 0x00,         //   ***           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x60, 0x00,         //      **         
    0xC0, 0x00,         //       **        
    0x80, 0x01,         //        **       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 41
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x02, 0x00,         //  *              
    0x07, 0x00,         // ***             
    0x0C, 0x00,         //   **            
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x70, 0x00,         //     ***         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x20, 0x00,         //      *          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x03, 0x00,         // **              
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 42
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x42, 0x04,         //  *    *   *     
    0x4E, 0x0E,         //  ***  *  ***    
    0x5C, 0x07,         //   *** * ***     
    0xF0, 0x01,         //     *****       
    0xE0, 0x01,         //      ****       
    0x5C, 0x07,         //   *** * ***     
    0x4E, 0x0E,         //  ***  *  ***    
    0x42, 0x04,         //  *    *   *     
    0x40, 0x00,         //       *         
    0x60, 0x00,         //      **         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 43
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0xFE, 0x07,         //  **********     
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 44
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x1E,         //  ****   
    0x1C,         //   ***   
    0x18,         //    **   
    0x18,         //    **   
    0x08,         //    *    
    0x0C,         //   **    
    0x04,         //   *     
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 45
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x01,         //  ********       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 46
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 47
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x18,         //            **   
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x07,         //         ***     
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x80, 0x03,         //        ***      
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0E, 0x00,         //  ***            
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 48
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x01,         //      ****       
    0x10, 0x07,         //     *   ***     
    0x08, 0x0E,         //    *     ***    
    0x0C, 0x0C,         //   **      **    
    0x04, 0x0C,         //   *       **    
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x0C, 0x08,         //   **       *    
    0x0C, 0x0C,         //   **      **    
    0x1C, 0x04,         //   ***     *     
    0x18, 0x02,         //    **    *      
    0xE0, 0x01,         //      ****       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 49
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x00,         //        *        
    0xF0, 0x00,         //     ****        
    0xFC, 0x00,         //   ******        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xE0, 0x01,         //      ****       
    0xFC, 0x0F,         //   **********    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 50
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x03,         //       ****      
    0x30, 0x06,         //     **   **     
    0x18, 0x0C,         //    **     **    
    0x1C, 0x0C,         //   ***     **    
    0x04, 0x0C,         //   *       **    
    0x00, 0x0C,         //           **    
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x03,         //         **      
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x30, 0x08,         //     **     *    
    0x18, 0x08,         //    **      *    
    0x1C, 0x08,         //   ***      *    
    0xFC, 0x0F,         //   **********    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 51
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x01,         //      ****       
    0x18, 0x03,         //    **   **      
    0x0C, 0x06,         //   **     **     
    0x0C, 0x06,         //   **     **     
    0x00, 0x06,         //          **     
    0x00, 0x02,         //          *      
    0x80, 0x01,         //        **       
    0xE0, 0x01,         //      ****       
    0x80, 0x07,         //        ****     
    0x00, 0x06,         //          **     
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x04, 0x06,         //   *      **     
    0x0C, 0x07,         //   **    ***     
    0xF8, 0x01,         //    ******       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 52
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x02,         //          *      
    0x80, 0x03,         //        ***      
    0x80, 0x03,         //        ***      
    0xC0, 0x03,         //       ****      
    0x60, 0x03,         //      ** **      
    0x60, 0x03,         //      ** **      
    0x30, 0x03,         //     **  **      
    0x10, 0x03,         //     *   **      
    0x18, 0x03,         //    **   **      
    0x0C, 0x03,         //   **    **      
    0x0C, 0x03,         //   **    **      
    0x06, 0x03,         //  **     **      
    0xFF, 0x0F,         // ************    
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0xE0, 0x0F,         //      *******    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 53
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF8, 0x0F,         //    *********    
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x08, 0x00,         //    *            
    0xF8, 0x01,         //    ******       
    0x0C, 0x07,         //   **    ***     
    0x00, 0x06,         //          **     
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x04, 0x06,         //   *      **     
    0x0C, 0x03,         //   **    **      
    0xF8, 0x01,         //    ******       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 54
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x06,         //          **     
    0x80, 0x01,         //        **       
    0xE0, 0x00,         //      ***        
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xCC, 0x03,         //   **  ****      
    0x3C, 0x0E,         //   ****   ***    
    0x0C, 0x0C,         //   **      **    
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x18, 0x08,         //    **      *    
    0x18, 0x0C,         //    **     **    
    0x30, 0x04,         //     **    *     
    0xE0, 0x03,         //      *****      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 55
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x1F,         //   ***********   
    0x04, 0x0C,         //   *       **    
    0x02, 0x0C,         //  *        **    
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 56
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x01,         //     *****       
    0x0C, 0x03,         //   **    **      
    0x06, 0x06,         //  **      **     
    0x06, 0x06,         //  **      **     
    0x06, 0x06,         //  **      **     
    0x0E, 0x03,         //  ***    **      
    0xBC, 0x01,         //   **** **       
    0xF0, 0x01,         //     *****       
    0xF0, 0x03,         //     ******      
    0x08, 0x07,         //    *    ***     
    0x0C, 0x0E,         //   **     ***    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x0E, 0x04,         //  ***      *     
    0x1C, 0x02,         //   ***    *      
    0xF0, 0x01,         //     *****       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 57
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x03,         //      *****      
    0x18, 0x06,         //    **    **     
    0x0C, 0x0C,         //   **      **    
    0x04, 0x0C,         //   *       **    
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x0C, 0x18,         //   **       **   
    0x1C, 0x1E,         //   ***    ****   
    0xF0, 0x19,         //     *****  **   
    0x00, 0x18,         //            **   
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x06,         //          **     
    0x00, 0x07,         //         ***     
    0x80, 0x03,         //        ***      
    0xE0, 0x00,         //      ***        
    0x38, 0x00,         //    ***          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 58
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 59
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1C,         //   ***   
    0x1C,         //   ***   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x1E,         //  ****   
    0x1C,         //   ***   
    0x18,         //    **   
    0x18,         //    **   
    0x08,         //    *    
    0x0C,         //   **    
    0x04,         //   *     
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 60
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x0C,         //           **    
    0x80, 0x0F,         //        *****    
    0xE0, 0x01,         //      ****       
    0x7C, 0x00,         //   *****         
    0x0E, 0x00,         //  ***            
    0x3E, 0x00,         //  *****          
    0xF0, 0x01,         //     *****       
    0x80, 0x07,         //        ****     
    0x00, 0x0E,         //          ***    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 61
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x0F,         //  ***********    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x0F,         //  ***********    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 62
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x00,         //  **             
    0x3E, 0x00,         //  *****          
    0xF0, 0x01,         //     *****       
    0x80, 0x0F,         //        *****    
    0x00, 0x0E,         //          ***    
    0xC0, 0x07,         //       *****     
    0xF8, 0x00,         //    *****        
    0x1E, 0x00,         //  ****           
    0x06, 0x00,         //  **             
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 63
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x01,         //     *****       
    0x0C, 0x03,         //   **    **      
    0x06, 0x06,         //  **      **     
    0x06, 0x06,         //  **      **     
    0x06, 0x06,         //  **      **     
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x03,         //         **      
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xE0, 0x00,         //      ***        
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x20, 0x00,         //      *          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x60, 0x00,         //      **         
    0x70, 0x00,         //     ***         
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 64
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0xFC, 0x01,         //           *******       
    0x00, 0x83, 0x07,         //         **     ****     
    0xC0, 0x00, 0x0E,         //       **         ***    
    0x20, 0x00, 0x1C,         //      *            ***   
    0x10, 0x00, 0x38,         //     *              ***  
    0x18, 0x00, 0x30,         //    **               **  
    0x08, 0xBC, 0x30,         //    *      **** *    **  
    0x0C, 0xE6, 0x70,         //   **     **  ***    *** 
    0x04, 0xC3, 0x60,         //   *     **    **     ** 
    0x06, 0xC1, 0x60,         //  **     *     **     ** 
    0x86, 0xC1, 0x60,         //  **    **     **     ** 
    0x86, 0xC1, 0x60,         //  **    **     **     ** 
    0x86, 0xC1, 0x60,         //  **    **     **     ** 
    0x86, 0xC1, 0x60,         //  **    **     **     ** 
    0x86, 0xC1, 0x20,         //  **    **     **     *  
    0x8E, 0xC1, 0x30,         //  ***   **     **    **  
    0x0C, 0xC3, 0x10,         //   **    **    **    *   
    0x0C, 0xF7, 0x09,         //   **    *** *****  *    
    0x18, 0x8E, 0x07,         //    **    ***   ****     
    0x38, 0x00, 0x00,         //    ***                  
    0x70, 0x00, 0x00,         //     ***                 
    0xE0, 0x00, 0x18,         //      ***           **   
    0xC0, 0x03, 0x0F,         //       ****      ****    
    0x00, 0xFE, 0x01,         //          ********       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 65
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x01, 0x00,         //         *               
    0x80, 0x03, 0x00,         //        ***              
    0x80, 0x03, 0x00,         //        ***              
    0x80, 0x03, 0x00,         //        ***              
    0xC0, 0x06, 0x00,         //       ** **             
    0xC0, 0x06, 0x00,         //       ** **             
    0x40, 0x0E, 0x00,         //       *  ***            
    0x60, 0x0C, 0x00,         //      **   **            
    0x60, 0x0C, 0x00,         //      **   **            
    0x20, 0x1C, 0x00,         //      *    ***           
    0x30, 0x18, 0x00,         //     **     **           
    0xF0, 0x1F, 0x00,         //     *********           
    0x10, 0x38, 0x00,         //     *      ***          
    0x18, 0x30, 0x00,         //    **       **          
    0x18, 0x30, 0x00,         //    **       **          
    0x08, 0x70, 0x00,         //    *        ***         
    0x0C, 0x60, 0x00,         //   **         **         
    0x3F, 0xF8, 0x01,         // ******     ******       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 66
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x03,         //   ********      
    0x1A, 0x0E,         //  * **    ***    
    0x18, 0x18,         //    **      **   
    0x18, 0x18,         //    **      **   
    0x18, 0x18,         //    **      **   
    0x18, 0x18,         //    **      **   
    0x18, 0x0C,         //    **     **    
    0x18, 0x06,         //    **    **     
    0xF8, 0x07,         //    ********     
    0x18, 0x1C,         //    **     ***   
    0x18, 0x18,         //    **      **   
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x18,         //    **      **   
    0x18, 0x0C,         //    **     **    
    0xFE, 0x07,         //  **********     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 67
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x1F,         //        ******   
    0x60, 0x38,         //      **    ***  
    0x18, 0x00,         //    **           
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x04, 0x00,         //   *             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0E, 0x00,         //  ***            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x18, 0x20,         //    **        *  
    0x70, 0x18,         //     ***    **   
    0xC0, 0x07,         //       *****     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 68
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0xFC, 0x07, 0x00,         //   *********             
    0x1A, 0x1C, 0x00,         //  * **     ***           
    0x18, 0x38, 0x00,         //    **      ***          
    0x18, 0x70, 0x00,         //    **       ***         
    0x18, 0x60, 0x00,         //    **        **         
    0x18, 0xE0, 0x00,         //    **        ***        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0x60, 0x00,         //    **        **         
    0x18, 0x60, 0x00,         //    **        **         
    0x18, 0x30, 0x00,         //    **       **          
    0x18, 0x30, 0x00,         //    **       **          
    0x18, 0x1C, 0x00,         //    **     ***           
    0xFE, 0x07, 0x00,         //  **********             
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 69
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x1F,         //  ************   
    0x18, 0x08,         //    **      *    
    0x18, 0x08,         //    **      *    
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xF8, 0x07,         //    ********     
    0x18, 0x02,         //    **    *      
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x10,         //    **       *   
    0x18, 0x10,         //    **       *   
    0xFE, 0x1F,         //  ************   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 70
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x1F,         //  ************   
    0x18, 0x18,         //    **      **   
    0x18, 0x08,         //    **      *    
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xF8, 0x07,         //    ********     
    0x18, 0x02,         //    **    *      
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 71
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x80, 0x3F, 0x00,         //        *******          
    0x60, 0x70, 0x00,         //      **     ***         
    0x10, 0x00, 0x00,         //     *                   
    0x08, 0x00, 0x00,         //    *                    
    0x0C, 0x00, 0x00,         //   **                    
    0x0C, 0x00, 0x00,         //   **                    
    0x06, 0x00, 0x00,         //  **                     
    0x06, 0x00, 0x00,         //  **                     
    0x06, 0x00, 0x00,         //  **                     
    0x06, 0x00, 0x00,         //  **                     
    0x06, 0xFC, 0x00,         //  **       ******        
    0x06, 0x60, 0x00,         //  **          **         
    0x0E, 0x60, 0x00,         //  ***         **         
    0x0C, 0x60, 0x00,         //   **         **         
    0x1C, 0x60, 0x00,         //   ***        **         
    0x18, 0x60, 0x00,         //    **        **         
    0x70, 0x60, 0x00,         //     ***      **         
    0xC0, 0x1F, 0x00,         //       *******           
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 72
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x7E, 0xF0, 0x03,         //  ******     ******      
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0xF8, 0xFF, 0x00,         //    *************        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x7E, 0xF0, 0x03,         //  ******     ******      
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 73
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7E, 0x00,         //  ******         
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 74
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF8, 0x03,         //    *******      
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x40, 0x00,         //       *         
    0x60, 0x00,         //      **         
    0x22, 0x00,         //  *   *          
    0x1F, 0x00,         // *****           
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 75
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x7E, 0xFC, 0x00,         //  ******   ******        
    0x18, 0x18, 0x00,         //    **      **           
    0x18, 0x0C, 0x00,         //    **     **            
    0x18, 0x0E, 0x00,         //    **    ***            
    0x18, 0x06, 0x00,         //    **    **             
    0x18, 0x03, 0x00,         //    **   **              
    0x98, 0x01, 0x00,         //    **  **               
    0xD8, 0x00, 0x00,         //    ** **                
    0x78, 0x00, 0x00,         //    ****                 
    0xD8, 0x00, 0x00,         //    ** **                
    0x98, 0x01, 0x00,         //    **  **               
    0x98, 0x03, 0x00,         //    **  ***              
    0x18, 0x07, 0x00,         //    **   ***             
    0x18, 0x0E, 0x00,         //    **    ***            
    0x18, 0x1C, 0x00,         //    **     ***           
    0x18, 0x18, 0x00,         //    **      **           
    0x18, 0x78, 0x00,         //    **      ****         
    0x7E, 0xF0, 0x01,         //  ******     *****       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 76
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7E, 0x00,         //  ******         
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x10,         //    **       *   
    0x18, 0x10,         //    **       *   
    0xFE, 0x1F,         //  ************   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 77
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x3E, 0x00, 0x3E,         //  *****           *****  
    0x38, 0x00, 0x0E,         //    ***           ***    
    0x78, 0x00, 0x0F,         //    ****         ****    
    0x78, 0x00, 0x0F,         //    ****         ****    
    0x78, 0x00, 0x0D,         //    ****         * **    
    0xD8, 0x80, 0x0D,         //    ** **       ** **    
    0xD8, 0x80, 0x0C,         //    ** **       *  **    
    0xD8, 0xC1, 0x0C,         //    ** ***     **  **    
    0x98, 0xC1, 0x0C,         //    **  **     **  **    
    0x98, 0x43, 0x0C,         //    **  ***    *   **    
    0x18, 0x63, 0x0C,         //    **   **   **   **    
    0x18, 0x23, 0x0C,         //    **   **   *    **    
    0x18, 0x36, 0x0C,         //    **    ** **    **    
    0x18, 0x36, 0x0C,         //    **    ** **    **    
    0x18, 0x1E, 0x0C,         //    **    ****     **    
    0x08, 0x1C, 0x0C,         //    *      ***     **    
    0x08, 0x0C, 0x0C,         //    *      **      **    
    0x7E, 0x08, 0x3F,         //  ******    *    ******  
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 78
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x1E, 0xF0, 0x03,         //  ****       ******      
    0x18, 0xC0, 0x00,         //    **         **        
    0x38, 0xC0, 0x00,         //    ***        **        
    0x78, 0xC0, 0x00,         //    ****       **        
    0xD8, 0xC0, 0x00,         //    ** **      **        
    0xD8, 0xC0, 0x00,         //    ** **      **        
    0x98, 0xC1, 0x00,         //    **  **     **        
    0x18, 0xC3, 0x00,         //    **   **    **        
    0x18, 0xC3, 0x00,         //    **   **    **        
    0x18, 0xC6, 0x00,         //    **    **   **        
    0x18, 0xCE, 0x00,         //    **    ***  **        
    0x18, 0xCC, 0x00,         //    **     **  **        
    0x18, 0xD8, 0x00,         //    **      ** **        
    0x18, 0xF8, 0x00,         //    **      *****        
    0x18, 0xF0, 0x00,         //    **       ****        
    0x18, 0xE0, 0x00,         //    **        ***        
    0x18, 0xE0, 0x00,         //    **        ***        
    0x7E, 0xC0, 0x00,         //  ******       **        
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 79
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0xC0, 0x07, 0x00,         //       *****             
    0x20, 0x18, 0x00,         //      *     **           
    0x10, 0x30, 0x00,         //     *       **          
    0x08, 0x60, 0x00,         //    *         **         
    0x0C, 0x60, 0x00,         //   **         **         
    0x04, 0xE0, 0x00,         //   *          ***        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x0E, 0x40, 0x00,         //  ***          *         
    0x0C, 0x60, 0x00,         //   **         **         
    0x1C, 0x20, 0x00,         //   ***        *          
    0x18, 0x10, 0x00,         //    **       *           
    0x30, 0x08, 0x00,         //     **     *            
    0xC0, 0x07, 0x00,         //       *****             
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 80
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x07,         //   *********     
    0x1A, 0x1C,         //  * **     ***   
    0x18, 0x18,         //    **      **   
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x18,         //    **      **   
    0x18, 0x0C,         //    **     **    
    0xD8, 0x07,         //    ** *****     
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 81
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0xC0, 0x07, 0x00,         //       *****             
    0x20, 0x18, 0x00,         //      *     **           
    0x10, 0x30, 0x00,         //     *       **          
    0x08, 0x60, 0x00,         //    *         **         
    0x0C, 0x60, 0x00,         //   **         **         
    0x04, 0xE0, 0x00,         //   *          ***        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x06, 0xC0, 0x00,         //  **           **        
    0x0E, 0x40, 0x00,         //  ***          *         
    0x0C, 0x60, 0x00,         //   **         **         
    0x1C, 0x20, 0x00,         //   ***        *          
    0x18, 0x30, 0x00,         //    **       **          
    0x30, 0x18, 0x00,         //     **     **           
    0xC0, 0x07, 0x00,         //       *****             
    0x00, 0x0C, 0x00,         //           **            
    0x00, 0x38, 0x02,         //            ***   *      
    0x00, 0xE0, 0x01,         //              ****       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 82
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x03,         //   ********      
    0x1A, 0x0E,         //  * **    ***    
    0x18, 0x1C,         //    **     ***   
    0x18, 0x18,         //    **      **   
    0x18, 0x18,         //    **      **   
    0x18, 0x18,         //    **      **   
    0x18, 0x0C,         //    **     **    
    0x18, 0x06,         //    **    **     
    0xF8, 0x03,         //    *******      
    0x98, 0x01,         //    **  **       
    0x98, 0x03,         //    **  ***      
    0x18, 0x03,         //    **   **      
    0x18, 0x06,         //    **    **     
    0x18, 0x0E,         //    **    ***    
    0x18, 0x0C,         //    **     **    
    0x18, 0x1C,         //    **     ***   
    0x18, 0x38,         //    **      ***  
    0x7E, 0xF8,         //  ******    *****
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 83
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x0F,         //      *******    
    0x18, 0x0E,         //    **    ***    
    0x08, 0x04,         //    *      *     
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x3C, 0x00,         //   ****          
    0x7C, 0x00,         //   *****         
    0xF8, 0x01,         //    ******       
    0xE0, 0x07,         //      ******     
    0xC0, 0x0F,         //       ******    
    0x00, 0x1E,         //          ****   
    0x00, 0x1C,         //           ***   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x04, 0x08,         //   *        *    
    0x0C, 0x0C,         //   **      **    
    0x1C, 0x06,         //   ***    **     
    0xF8, 0x01,         //    ******       
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 84
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x7F,         //  ************** 
    0x82, 0x41,         //  *     **     * 
    0x81, 0x41,         // *      **     * 
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xE0, 0x07,         //      ******     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 85
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x7E, 0xF0, 0x03,         //  ******     ******      
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x30, 0x60, 0x00,         //     **       **         
    0x30, 0x60, 0x00,         //     **       **         
    0x60, 0x30, 0x00,         //      **     **          
    0x80, 0x0F, 0x00,         //        *****            
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 86
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x3F, 0xF0, 0x03,         // ******      ******      
    0x1C, 0xC0, 0x00,         //   ***         **        
    0x18, 0xC0, 0x00,         //    **         **        
    0x18, 0x40, 0x00,         //    **         *         
    0x38, 0x60, 0x00,         //    ***       **         
    0x30, 0x60, 0x00,         //     **       **         
    0x70, 0x20, 0x00,         //     ***      *          
    0x60, 0x30, 0x00,         //      **     **          
    0x60, 0x30, 0x00,         //      **     **          
    0xE0, 0x10, 0x00,         //      ***    *           
    0xC0, 0x18, 0x00,         //       **   **           
    0xC0, 0x18, 0x00,         //       **   **           
    0xC0, 0x0D, 0x00,         //       *** **            
    0x80, 0x0D, 0x00,         //        ** **            
    0x80, 0x07, 0x00,         //        ****             
    0x00, 0x07, 0x00,         //         ***             
    0x00, 0x07, 0x00,         //         ***             
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 87
 ***********************************/
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x3F, 0x10, 0xFC, 0x00,         // ******      *     ******        
    0x1C, 0x18, 0x30, 0x00,         //   ***      **       **          
    0x1C, 0x18, 0x30, 0x00,         //   ***      **       **          
    0x18, 0x38, 0x30, 0x00,         //    **      ***      **          
    0x18, 0x3C, 0x10, 0x00,         //    **     ****      *           
    0x18, 0x7C, 0x18, 0x00,         //    **     *****    **           
    0x18, 0x64, 0x18, 0x00,         //    **     *  **    **           
    0x30, 0x66, 0x18, 0x00,         //     **   **  **    **           
    0x30, 0xC6, 0x08, 0x00,         //     **   **   **   *            
    0x30, 0xC2, 0x08, 0x00,         //     **   *    **   *            
    0x30, 0xC3, 0x0C, 0x00,         //     **  **    **  **            
    0x70, 0x83, 0x0D, 0x00,         //     *** **     ** **            
    0x60, 0x81, 0x0D, 0x00,         //      ** *      ** **            
    0xE0, 0x81, 0x05, 0x00,         //      ****      ** *             
    0xE0, 0x01, 0x07, 0x00,         //      ****       ***             
    0xE0, 0x00, 0x07, 0x00,         //      ***        ***             
    0xC0, 0x00, 0x07, 0x00,         //       **        ***             
    0x40, 0x00, 0x02, 0x00,         //       *          *              
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 
    0x00, 0x00, 0x00, 0x00,         //                                 

/***********************************
 * Character - 88
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x7E, 0xFC, 0x01,         //  ******   *******       
    0x1C, 0x70, 0x00,         //   ***       ***         
    0x38, 0x30, 0x00,         //    ***      **          
    0x30, 0x18, 0x00,         //     **     **           
    0x70, 0x18, 0x00,         //     ***    **           
    0xE0, 0x0C, 0x00,         //      ***  **            
    0xC0, 0x07, 0x00,         //       *****             
    0x80, 0x07, 0x00,         //        ****             
    0x80, 0x03, 0x00,         //        ***              
    0x80, 0x07, 0x00,         //        ****             
    0xC0, 0x06, 0x00,         //       ** **             
    0xC0, 0x0E, 0x00,         //       ** ***            
    0x60, 0x1C, 0x00,         //      **   ***           
    0x60, 0x18, 0x00,         //      **    **           
    0x30, 0x30, 0x00,         //     **      **          
    0x18, 0x70, 0x00,         //    **       ***         
    0x1C, 0xE0, 0x00,         //   ***        ***        
    0x7F, 0xF8, 0x01,         // *******    ******       
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 89
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x1E, 0xF8, 0x01,         //  ****      ******       
    0x18, 0x60, 0x00,         //    **        **         
    0x30, 0x30, 0x00,         //     **      **          
    0x70, 0x30, 0x00,         //     ***     **          
    0x60, 0x18, 0x00,         //      **    **           
    0xE0, 0x18, 0x00,         //      ***   **           
    0xC0, 0x0C, 0x00,         //       **  **            
    0x80, 0x0D, 0x00,         //        ** **            
    0x80, 0x07, 0x00,         //        ****             
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0x00, 0x03, 0x00,         //         **              
    0xC0, 0x0F, 0x00,         //       ******            
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 90
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x3F,         //   ************  
    0x0C, 0x18,         //   **       **   
    0x04, 0x1C,         //   *       ***   
    0x04, 0x0E,         //   *      ***    
    0x00, 0x0E,         //          ***    
    0x00, 0x07,         //         ***     
    0x00, 0x03,         //         **      
    0x80, 0x03,         //        ***      
    0xC0, 0x01,         //       ***       
    0xC0, 0x00,         //       **        
    0xE0, 0x00,         //      ***        
    0x70, 0x00,         //     ***         
    0x70, 0x00,         //     ***         
    0x38, 0x00,         //    ***          
    0x18, 0x20,         //    **        *  
    0x1C, 0x20,         //   ***        *  
    0x0E, 0x30,         //  ***        **  
    0xFE, 0x3F,         //  *************  
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 91
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x00,         //   ******        
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xFC, 0x00,         //   ******        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 92
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x00, 0x03,         //         **      
    0x00, 0x03,         //         **      
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x06,         //          **     
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x0C,         //           **    
    0x00, 0x18,         //            **   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 93
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7E, 0x00,         //  ******         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 94
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x00,         //        *        
    0xC0, 0x00,         //       **        
    0xC0, 0x01,         //       ***       
    0xE0, 0x01,         //      ****       
    0xA0, 0x03,         //      * ***      
    0x30, 0x03,         //     **  **      
    0x30, 0x03,         //     **  **      
    0x10, 0x07,         //     *   ***     
    0x18, 0x06,         //    **    **     
    0x18, 0x0E,         //    **    ***    
    0x08, 0x0C,         //    *      **    
    0x0C, 0x0C,         //   **      **    
    0x04, 0x1C,         //   *       ***   
    0x06, 0x08,         //  **        *    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 95
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFE, 0x1F,         //  ************   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 96
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x06, 0x00,         //  **             
    0x0F, 0x00,         // ****            
    0x0C, 0x00,         //   **            
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0x20, 0x00,         //      *          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 97
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x03,         //      *****      
    0x18, 0x06,         //    **    **     
    0x0C, 0x06,         //   **     **     
    0x04, 0x06,         //   *      **     
    0x00, 0x06,         //          **     
    0xC0, 0x07,         //       *****     
    0xF8, 0x07,         //    ********     
    0x1C, 0x06,         //   ***    **     
    0x0E, 0x06,         //  ***     **     
    0x06, 0x06,         //  **      **     
    0x06, 0x06,         //  **      **     
    0x86, 0x07,         //  **    ****     
    0x7C, 0x1E,         //   *****  ****   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 98
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x0C, 0x00,         //   **            
    0x0F, 0x00,         // ****            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x8C, 0x07,         //   **   ****     
    0x6C, 0x1C,         //   ** **   ***   
    0x1C, 0x18,         //   ***      **   
    0x1C, 0x38,         //   ***      ***  
    0x0C, 0x30,         //   **        **  
    0x0C, 0x30,         //   **        **  
    0x0C, 0x30,         //   **        **  
    0x0C, 0x30,         //   **        **  
    0x0C, 0x30,         //   **        **  
    0x0C, 0x10,         //   **        *   
    0x0C, 0x08,         //   **       *    
    0x38, 0x04,         //    ***    *     
    0xE0, 0x03,         //      *****      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 99
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x07,         //      ******     
    0x10, 0x06,         //     *    **     
    0x08, 0x04,         //    *      *     
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0E, 0x00,         //  ***            
    0x0C, 0x04,         //   **      *     
    0x18, 0x0C,         //    **     **    
    0xF0, 0x03,         //     ******      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 100
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x18,         //            **   
    0x00, 0x1E,         //          ****   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0xC0, 0x1F,         //       *******   
    0x30, 0x1C,         //     **    ***   
    0x08, 0x18,         //    *       **   
    0x0C, 0x18,         //   **       **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x1C,         //   **      ***   
    0x18, 0x7A,         //    **    * **** 
    0xF0, 0x19,         //     *****  **   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 101
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x03,         //      *****      
    0x18, 0x07,         //    **   ***     
    0x0C, 0x06,         //   **     **     
    0x04, 0x0E,         //   *      ***    
    0x06, 0x0C,         //  **       **    
    0xFE, 0x0F,         //  ***********    
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x06, 0x00,         //  **             
    0x0E, 0x00,         //  ***            
    0x0C, 0x08,         //   **       *    
    0x18, 0x04,         //    **     *     
    0xF0, 0x03,         //     ******      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 102
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x07,         //        ****     
    0xC0, 0x0F,         //       ******    
    0x20, 0x06,         //      *   **     
    0x30, 0x00,         //     **          
    0x10, 0x00,         //     *           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xFE, 0x01,         //  ********       
    0x98, 0x00,         //    **  *        
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0xFE, 0x00,         //  *******        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 103
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x31,         //     *****   **  
    0x08, 0x3F,         //    *    ******  
    0x04, 0x0E,         //   *      ***    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x06, 0x0C,         //  **       **    
    0x0E, 0x04,         //  ***      *     
    0x1C, 0x02,         //   ***    *      
    0xF8, 0x01,         //    ******       
    0x38, 0x00,         //    ***          
    0x1C, 0x00,         //   ***           
    0xFC, 0x00,         //   ******        
    0xF0, 0x0F,         //     ********    
    0x9C, 0x3F,         //   ***  *******  
    0x06, 0x38,         //  **        ***  
    0x03, 0x30,         // **          **  
    0x03, 0x30,         // **          **  
    0x07, 0x18,         // ***        **   
    0x0E, 0x0C,         //  ***      **    
    0xF8, 0x03,         //    *******      
    0x00, 0x00,         //                 

/***********************************
 * Character - 104
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x18, 0x00,         //    **           
    0x1E, 0x00,         //  ****           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x1E,         //    **    ****   
    0x98, 0x31,         //    **  **   **  
    0x58, 0x30,         //    ** *     **  
    0x38, 0x30,         //    ***      **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x7E, 0xFC,         //  ******   ******
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 105
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1E,         //  ****   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x7E,         //  ****** 
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 106
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0xC0,         //       **
    0xF0,         //     ****
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0xC0,         //       **
    0x40,         //       * 
    0x60,         //      ** 
    0x22,         //  *   *  
    0x1F,         // *****   
    0x00,         //         

/***********************************
 * Character - 107
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x18, 0x00,         //    **           
    0x1E, 0x00,         //  ****           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x3E,         //    **    *****  
    0x18, 0x0C,         //    **     **    
    0x18, 0x07,         //    **   ***     
    0x98, 0x01,         //    **  **       
    0xD8, 0x00,         //    ** **        
    0x78, 0x00,         //    ****         
    0xD8, 0x00,         //    ** **        
    0x98, 0x01,         //    **  **       
    0x98, 0x03,         //    **  ***      
    0x18, 0x07,         //    **   ***     
    0x18, 0x0E,         //    **    ***    
    0x18, 0x1C,         //    **     ***   
    0x7E, 0x78,         //  ******    **** 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 108
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x1E,         //  ****   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x7E,         //  ****** 
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 109
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x1C, 0x0F, 0x0F,         //   ***   ****    ****    
    0x9A, 0x98, 0x18,         //  * **  *   **  *   **   
    0x58, 0x58, 0x18,         //    ** *    ** *    **   
    0x38, 0x38, 0x18,         //    ***     ***     **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x18, 0x18, 0x18,         //    **      **      **   
    0x7E, 0x7E, 0x7E,         //  ******  ******  ****** 
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 110
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1C, 0x1E,         //   ***    ****   
    0x9A, 0x31,         //  * **  **   **  
    0x58, 0x30,         //    ** *     **  
    0x38, 0x30,         //    ***      **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x7E, 0xFC,         //  ******   ******
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 111
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xE0, 0x03,         //      *****      
    0x10, 0x0E,         //     *    ***    
    0x08, 0x1C,         //    *      ***   
    0x04, 0x18,         //   *        **   
    0x06, 0x30,         //  **         **  
    0x06, 0x30,         //  **         **  
    0x06, 0x30,         //  **         **  
    0x06, 0x30,         //  **         **  
    0x06, 0x30,         //  **         **  
    0x0C, 0x10,         //   **        *   
    0x1C, 0x08,         //   ***      *    
    0x38, 0x04,         //    ***    *     
    0xE0, 0x03,         //      *****      
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 112
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x1E, 0x0F,         //  ****   ****    
    0xD8, 0x1C,         //    ** **  ***   
    0x38, 0x18,         //    ***     **   
    0x38, 0x38,         //    ***     ***  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x30,         //    **       **  
    0x18, 0x10,         //    **       *   
    0x18, 0x18,         //    **      **   
    0x78, 0x0C,         //    ****   **    
    0xD8, 0x03,         //    ** ****      
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 

/***********************************
 * Character - 113
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC0, 0x13,         //       ****  *   
    0x30, 0x1C,         //     **    ***   
    0x08, 0x18,         //    *       **   
    0x0C, 0x18,         //   **       **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x06, 0x18,         //  **        **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x1C,         //   **      ***   
    0x18, 0x1A,         //    **    * **   
    0xF0, 0x19,         //     *****  **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x18,         //            **   
    0x00, 0x7E,         //          ****** 
    0x00, 0x00,         //                 

/***********************************
 * Character - 114
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x98, 0x07,         //    **  ****     
    0xDE, 0x07,         //  **** *****     
    0x58, 0x06,         //    ** *  **     
    0x38, 0x04,         //    ***    *     
    0x38, 0x00,         //    ***          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x7E, 0x00,         //  ******         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 115
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF8, 0x01,         //    ******       
    0x84, 0x01,         //   *    **       
    0x06, 0x01,         //  **     *       
    0x0E, 0x00,         //  ***            
    0x1E, 0x00,         //  ****           
    0x7C, 0x00,         //   *****         
    0xF8, 0x01,         //    ******       
    0xE0, 0x03,         //      *****      
    0x80, 0x03,         //        ***      
    0x02, 0x03,         //  *      **      
    0x02, 0x03,         //  *      **      
    0x86, 0x01,         //  **    **       
    0x7C, 0x00,         //   *****         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 116
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x08, 0x00,         //    *            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0xFF, 0x01,         // *********       
    0x8C, 0x00,         //   **   *        
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x00,         //   **            
    0x0C, 0x01,         //   **    *       
    0xF8, 0x00,         //    *****        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 117
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x0C, 0x18,         //   **       **   
    0x0F, 0x1E,         // ****     ****   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x18,         //   **       **   
    0x0C, 0x1C,         //   **      ***   
    0x18, 0x7A,         //    **    * **** 
    0xF0, 0x19,         //     *****  **   
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 118
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x3F, 0x3E,         // ******   *****  
    0x0C, 0x08,         //   **       *    
    0x1C, 0x08,         //   ***      *    
    0x18, 0x0C,         //    **     **    
    0x18, 0x04,         //    **     *     
    0x38, 0x06,         //    ***   **     
    0x30, 0x06,         //     **   **     
    0x70, 0x02,         //     ***  *      
    0x60, 0x03,         //      ** **      
    0x60, 0x01,         //      ** *       
    0xC0, 0x01,         //       ***       
    0xC0, 0x01,         //       ***       
    0xC0, 0x00,         //       **        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 119
 ***********************************/
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x3F, 0x04, 0x0F,         // ******    *     ****    
    0x0C, 0x0C, 0x06,         //   **      **     **     
    0x0C, 0x0E, 0x02,         //   **     ***     *      
    0x0C, 0x0E, 0x02,         //   **     ***     *      
    0x18, 0x1A, 0x03,         //    **    * **   **      
    0x18, 0x1B, 0x03,         //    **   ** **   **      
    0x18, 0x19, 0x01,         //    **   *  **   *       
    0x30, 0x31, 0x01,         //     **  *   **  *       
    0xB0, 0xB1, 0x01,         //     ** **   ** **       
    0xB0, 0xF0, 0x00,         //     ** *    ****        
    0xE0, 0xE0, 0x00,         //      ***     ***        
    0xE0, 0xE0, 0x00,         //      ***     ***        
    0x60, 0x40, 0x00,         //      **       *         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         
    0x00, 0x00, 0x00,         //                         

/***********************************
 * Character - 120
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x3F, 0x3E,         // ******   *****  
    0x1C, 0x0C,         //   ***     **    
    0x38, 0x06,         //    ***   **     
    0x30, 0x02,         //     **   *      
    0x60, 0x03,         //      ** **      
    0xE0, 0x01,         //      ****       
    0xC0, 0x01,         //       ***       
    0xE0, 0x03,         //      *****      
    0x20, 0x03,         //      *  **      
    0x10, 0x06,         //     *    **     
    0x18, 0x0E,         //    **    ***    
    0x0C, 0x1C,         //   **      ***   
    0x3F, 0x3E,         // ******   *****  
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 121
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7E, 0x7C,         //  ******   ***** 
    0x18, 0x10,         //    **       *   
    0x38, 0x10,         //    ***      *   
    0x30, 0x18,         //     **     **   
    0x30, 0x08,         //     **     *    
    0x70, 0x0C,         //     ***   **    
    0x60, 0x0C,         //      **   **    
    0x60, 0x04,         //      **   *     
    0xC0, 0x06,         //       ** **     
    0xC0, 0x02,         //       ** *      
    0xC0, 0x03,         //       ****      
    0x80, 0x03,         //        ***      
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xC0, 0x00,         //       **        
    0x62, 0x00,         //  *   **         
    0x3E, 0x00,         //  *****          
    0x1F, 0x00,         // *****           
    0x00, 0x00,         //                 

/***********************************
 * Character - 122
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xFC, 0x0F,         //   **********    
    0x04, 0x06,         //   *      **     
    0x04, 0x03,         //   *     **      
    0x80, 0x03,         //        ***      
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0xE0, 0x00,         //      ***        
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x38, 0x00,         //    ***          
    0x1C, 0x08,         //   ***      *    
    0x0C, 0x0C,         //   **      **    
    0xFE, 0x0F,         //  ***********    
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 123
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x80, 0x01,         //        **       
    0xC0, 0x00,         //       **        
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x70, 0x00,         //     ***         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x30, 0x00,         //     **          
    0x1C, 0x00,         //   ***           
    0x30, 0x00,         //     **          
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x60, 0x00,         //      **         
    0x70, 0x00,         //     ***         
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x60, 0x00,         //      **         
    0x40, 0x00,         //       *         
    0x80, 0x00,         //        *        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 124
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 125
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x04, 0x00,         //   *             
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x38, 0x00,         //    ***          
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x30, 0x00,         //     **          
    0xE0, 0x00,         //      ***        
    0x30, 0x00,         //     **          
    0x10, 0x00,         //     *           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x18, 0x00,         //    **           
    0x38, 0x00,         //    ***          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x30, 0x00,         //     **          
    0x18, 0x00,         //    **           
    0x0C, 0x00,         //   **            
    0x06, 0x00,         //  **             
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 126
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x78, 0x10,         //    ****     *   
    0xFC, 0x19,         //   *******  **   
    0xC6, 0x0F,         //  **   ******    
    0x02, 0x07,         //  *      ***     
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

};

/*********************************
 * TTF Font File Structure
 * Label: Font35_Antialiased
 * Description:  Height: 35 pixels, 2 bits per pixel, Range: 'A' to 'T'
 ***********************************/

extern const char __Font35_Antialiased[] __attribute__((aligned(2)));

const FONT_FLASH Font35_Antialiased =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__Font35_Antialiased
};

const char __Font35_Antialiased[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x04,           // Font information:  2 bits per pixel, Characters zero degress rotation
    0x20, 0x00,     // First Character
    0x27, 0x00,     // Last Character
    0x23, 0x00,     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
    0x11,              // width of the glyph
    0x28, 0x00, 0x00,       // Character - 65, offset (0x00000028)
    0x11,              // width of the glyph
    0xD7, 0x00, 0x00,       // Character - 68, offset (0x000000D7)
    0x0E,              // width of the glyph
    0x86, 0x01, 0x00,       // Character - 69, offset (0x00000186)
    0x09,              // width of the glyph
    0x12, 0x02, 0x00,       // Character - 73, offset (0x00000212)
    0x0E,              // width of the glyph
    0x7B, 0x02, 0x00,       // Character - 76, offset (0x0000027B)
    0x13,              // width of the glyph
    0x07, 0x03, 0x00,       // Character - 78, offset (0x00000307)
    0x0E,              // width of the glyph
    0xB6, 0x03, 0x00,       // Character - 83, offset (0x000003B6)
    0x10,              // width of the glyph
    0x42, 0x04, 0x00,       // Character - 84, offset (0x00000442)
/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 65
 ***********************************/
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x40, 0x06, 0x00, 0x00,         //        .*.          
    0x00, 0x80, 0x0B, 0x00, 0x00,         //        *X*          
    0x00, 0xD0, 0x1F, 0x00, 0x00,         //       .XXX.         
    0x00, 0xD0, 0x1F, 0x00, 0x00,         //       .XXX.         
    0x00, 0xE0, 0x2E, 0x00, 0x00,         //       *X*X*         
    0x00, 0xB4, 0x7D, 0x00, 0x00,         //      .X*.XX.        
    0x00, 0x74, 0x78, 0x00, 0x00,         //      .X. *X.        
    0x00, 0x78, 0xB4, 0x00, 0x00,         //      *X. .X*        
    0x00, 0x2D, 0xF4, 0x01, 0x00,         //     .X*  .XX.       
    0x00, 0x1D, 0xE0, 0x02, 0x00,         //     .X.   *X*       
    0x00, 0x1E, 0xD0, 0x06, 0x00,         //     *X.   .X*.      
    0x40, 0xFF, 0xFF, 0x07, 0x00,         //    .XXXXXXXXX.      
    0x40, 0x07, 0x80, 0x0B, 0x00,         //    .X.     *X*      
    0x80, 0x02, 0x40, 0x1F, 0x00,         //    **      .XX.     
    0xD0, 0x02, 0x40, 0x1E, 0x00,         //   .X*      .*X.     
    0xD0, 0x01, 0x00, 0x2E, 0x00,         //   .X.       *X*     
    0xA4, 0x00, 0x00, 0x7D, 0x00,         //  .**        .XX.    
    0xFA, 0x0A, 0x80, 0xBE, 0x02,         // **XX**     **XX**   
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     

/***********************************
 * Character - 68
 ***********************************/
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0xA5, 0xEA, 0x6B, 0x00, 0x00,         // ..*****XX**.        
    0xD9, 0x03, 0xE5, 0x06, 0x00,         // .*.XX   ..*X*.      
    0xC0, 0x03, 0x80, 0x1B, 0x00,         //    XX      *X*.     
    0xC0, 0x03, 0x00, 0x2E, 0x00,         //    XX       *X*     
    0xC0, 0x03, 0x00, 0x79, 0x00,         //    XX       .*X.    
    0xC0, 0x03, 0x00, 0xB8, 0x00,         //    XX        *X*    
    0xC0, 0x03, 0x00, 0xB4, 0x00,         //    XX        .X*    
    0xC0, 0x03, 0x00, 0xF4, 0x00,         //    XX        .XX    
    0xC0, 0x03, 0x00, 0xF0, 0x00,         //    XX         XX    
    0xC0, 0x03, 0x00, 0xF0, 0x00,         //    XX         XX    
    0xC0, 0x03, 0x00, 0xB4, 0x00,         //    XX        .X*    
    0xC0, 0x03, 0x00, 0xB4, 0x00,         //    XX        .X*    
    0xC0, 0x03, 0x00, 0x78, 0x00,         //    XX        *X.    
    0xC0, 0x03, 0x00, 0x69, 0x00,         //    XX       .**.    
    0xC0, 0x03, 0x00, 0x1E, 0x00,         //    XX       *X.     
    0xC0, 0x03, 0x40, 0x0B, 0x00,         //    XX      .X*      
    0xD0, 0x07, 0xE4, 0x01, 0x00,         //   .XX.   .*X.       
    0xF9, 0xBF, 0x6B, 0x00, 0x00,         // .*XXXXX*X**.        
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     

/***********************************
 * Character - 69
 ***********************************/
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0xF9, 0xFF, 0xFF, 0x01,         // .*XXXXXXXXXX.   
    0xD0, 0x03, 0xD0, 0x01,         //   .XX     .X.   
    0xC0, 0x03, 0x80, 0x01,         //    XX      *.   
    0xC0, 0x03, 0xC0, 0x00,         //    XX      X    
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0xFF, 0x2F, 0x00,         //    XXXXXXX*     
    0xC0, 0x03, 0x19, 0x00,         //    XX   .*.     
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x05,         //    XX       ..  
    0xC0, 0x03, 0x00, 0x06,         //    XX       *.  
    0xD0, 0x17, 0x50, 0x07,         //   .XX..   ..X.  
    0xF9, 0xFF, 0xFF, 0x07,         // .*XXXXXXXXXXX.  
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 

/***********************************
 * Character - 73
 ***********************************/
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0xF9, 0x2F, 0x00,         // .*XXXX*     
    0xD0, 0x07, 0x00,         //   .XX.      
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xC0, 0x03, 0x00,         //    XX       
    0xD0, 0x07, 0x00,         //   .XX.      
    0xF9, 0x2F, 0x00,         // .*XXXX*     
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             
    0x00, 0x00, 0x00,         //             

/***********************************
 * Character - 76
 ***********************************/
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0xF9, 0x2F, 0x00, 0x00,         // .*XXXX*         
    0xD0, 0x07, 0x00, 0x00,         //   .XX.          
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x00,         //    XX           
    0xC0, 0x03, 0x00, 0x05,         //    XX       ..  
    0xC0, 0x03, 0x00, 0x06,         //    XX       *.  
    0xD0, 0x17, 0x50, 0x07,         //   .XX..   ..X.  
    0xF9, 0xFF, 0xFF, 0x02,         // .*XXXXXXXXXX*   
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 

/***********************************
 * Character - 78
 ***********************************/
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0xF9, 0x02, 0x40, 0xFE, 0x0B,         // .*XX*      .*XXXX*  
    0xD0, 0x07, 0x00, 0xF4, 0x01,         //   .XX.       .XX.   
    0xC0, 0x1F, 0x00, 0xF0, 0x00,         //    XXX.       XX    
    0xC0, 0x6F, 0x00, 0xF0, 0x00,         //    XXX*.      XX    
    0xC0, 0xB7, 0x00, 0xF0, 0x00,         //    XX.X*      XX    
    0xC0, 0xE3, 0x01, 0xF0, 0x00,         //    XX *X.     XX    
    0xC0, 0xD3, 0x06, 0xF0, 0x00,         //    XX .X*.    XX    
    0xC0, 0x43, 0x0B, 0xF0, 0x00,         //    XX  .X*    XX    
    0xC0, 0x03, 0x1E, 0xF0, 0x00,         //    XX   *X.   XX    
    0xC0, 0x03, 0x6D, 0xF0, 0x00,         //    XX   .X*.  XX    
    0xC0, 0x03, 0xB4, 0xF0, 0x00,         //    XX    .X*  XX    
    0xC0, 0x03, 0xE4, 0xF1, 0x00,         //    XX    .*X. XX    
    0xC0, 0x03, 0xD0, 0xF7, 0x00,         //    XX     .XX.XX    
    0xC0, 0x03, 0x40, 0xFB, 0x00,         //    XX      .X*XX    
    0xC0, 0x03, 0x40, 0xFE, 0x00,         //    XX      .*XXX    
    0xC0, 0x03, 0x00, 0xFD, 0x00,         //    XX       .XXX    
    0xD0, 0x07, 0x00, 0xF4, 0x00,         //   .XX.       .XX    
    0xF9, 0x6F, 0x00, 0xE4, 0x00,         // .*XXXX*.     .*X    
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     
    0x00, 0x00, 0x00, 0x00, 0x00,         //                     

/***********************************
 * Character - 83
 ***********************************/
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0xE9, 0x6B, 0x01,         //     .**XX**..   
    0x80, 0x06, 0xB9, 0x00,         //    **.  .*X*    
    0xD0, 0x01, 0x50, 0x00,         //   .X.     ..    
    0xE0, 0x01, 0x00, 0x00,         //   *X.           
    0xF0, 0x01, 0x00, 0x00,         //   XX.           
    0xE0, 0x1B, 0x00, 0x00,         //   *XX*.         
    0xE0, 0x6F, 0x01, 0x00,         //   *XXX*..       
    0x90, 0xFF, 0x16, 0x00,         //   .*XXXX*..     
    0x40, 0xFE, 0x6F, 0x00,         //    .*XXXXX*.    
    0x00, 0xA4, 0xBF, 0x01,         //      .**XXX*.   
    0x00, 0x40, 0xFD, 0x02,         //        ..XXX*   
    0x00, 0x00, 0xE4, 0x03,         //          .*XX   
    0x00, 0x00, 0xD0, 0x03,         //           .XX   
    0x30, 0x00, 0xD0, 0x02,         //   X       .X*   
    0x60, 0x00, 0xD0, 0x01,         //   *.      .X.   
    0xB0, 0x00, 0xA0, 0x01,         //   X*      **.   
    0xF0, 0x06, 0x69, 0x00,         //   XX*.  .**.    
    0x90, 0xBE, 0x16, 0x00,         //   .**XX**..     
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 

/***********************************
 * Character - 84
 ***********************************/
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0xFD, 0xFF, 0xFF, 0x7F,         // .XXXXXXXXXXXXXX.
    0x19, 0xC0, 0x03, 0x74,         // .*.    XX    .X.
    0x05, 0xC0, 0x03, 0x60,         // ..     XX     *.
    0x05, 0xC0, 0x03, 0x30,         // ..     XX     X 
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xC0, 0x03, 0x00,         //        XX       
    0x00, 0xD0, 0x07, 0x00,         //       .XX.      
    0x00, 0xF9, 0x6F, 0x00,         //     .*XXXX*.    
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 
    0x00, 0x00, 0x00, 0x00,         //                 

};

