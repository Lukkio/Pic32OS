//const XCHAR AntialisedText[] = {   0x0020, 0x0025, 0x0027, 0x0023, 0x0020, 0x0024, 0x0023, 0x0020, 0x0026, 0x0022, 0x0021, 0x0000    };    //Antialised text

extern const char __DroidSans_12[] __attribute__((aligned(2)));

const FONT_FLASH DroidSans_12 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__DroidSans_12
};

const char __DroidSans_12[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x04,           // Font information:  2 bits per pixel, Characters zero degress rotation
    0x20, 0x00,     // First Character
    0x7E, 0x00,     // Last Character
    0x0F, 0x00     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
, 0x03              // width of the glyph
, 0x84, 0x01, 0x00       // Character - 32, offset (0x00000184)
, 0x03              // width of the glyph
, 0x93, 0x01, 0x00       // Character - 33, offset (0x00000193)
, 0x05              // width of the glyph
, 0xA2, 0x01, 0x00       // Character - 34, offset (0x000001A2)
, 0x08              // width of the glyph
, 0xC0, 0x01, 0x00       // Character - 35, offset (0x000001C0)
, 0x07              // width of the glyph
, 0xDE, 0x01, 0x00       // Character - 36, offset (0x000001DE)
, 0x0A              // width of the glyph
, 0xFC, 0x01, 0x00       // Character - 37, offset (0x000001FC)
, 0x08              // width of the glyph
, 0x29, 0x02, 0x00       // Character - 38, offset (0x00000229)
, 0x03              // width of the glyph
, 0x47, 0x02, 0x00       // Character - 39, offset (0x00000247)
, 0x04              // width of the glyph
, 0x56, 0x02, 0x00       // Character - 40, offset (0x00000256)
, 0x04              // width of the glyph
, 0x65, 0x02, 0x00       // Character - 41, offset (0x00000265)
, 0x07              // width of the glyph
, 0x74, 0x02, 0x00       // Character - 42, offset (0x00000274)
, 0x07              // width of the glyph
, 0x92, 0x02, 0x00       // Character - 43, offset (0x00000292)
, 0x03              // width of the glyph
, 0xB0, 0x02, 0x00       // Character - 44, offset (0x000002B0)
, 0x04              // width of the glyph
, 0xBF, 0x02, 0x00       // Character - 45, offset (0x000002BF)
, 0x03              // width of the glyph
, 0xCE, 0x02, 0x00       // Character - 46, offset (0x000002CE)
, 0x04              // width of the glyph
, 0xDD, 0x02, 0x00       // Character - 47, offset (0x000002DD)
, 0x07              // width of the glyph
, 0xEC, 0x02, 0x00       // Character - 48, offset (0x000002EC)
, 0x07              // width of the glyph
, 0x0A, 0x03, 0x00       // Character - 49, offset (0x0000030A)
, 0x07              // width of the glyph
, 0x28, 0x03, 0x00       // Character - 50, offset (0x00000328)
, 0x07              // width of the glyph
, 0x46, 0x03, 0x00       // Character - 51, offset (0x00000346)
, 0x07              // width of the glyph
, 0x64, 0x03, 0x00       // Character - 52, offset (0x00000364)
, 0x07              // width of the glyph
, 0x82, 0x03, 0x00       // Character - 53, offset (0x00000382)
, 0x07              // width of the glyph
, 0xA0, 0x03, 0x00       // Character - 54, offset (0x000003A0)
, 0x07              // width of the glyph
, 0xBE, 0x03, 0x00       // Character - 55, offset (0x000003BE)
, 0x07              // width of the glyph
, 0xDC, 0x03, 0x00       // Character - 56, offset (0x000003DC)
, 0x07              // width of the glyph
, 0xFA, 0x03, 0x00       // Character - 57, offset (0x000003FA)
, 0x03              // width of the glyph
, 0x18, 0x04, 0x00       // Character - 58, offset (0x00000418)
, 0x03              // width of the glyph
, 0x27, 0x04, 0x00       // Character - 59, offset (0x00000427)
, 0x07              // width of the glyph
, 0x36, 0x04, 0x00       // Character - 60, offset (0x00000436)
, 0x07              // width of the glyph
, 0x54, 0x04, 0x00       // Character - 61, offset (0x00000454)
, 0x07              // width of the glyph
, 0x72, 0x04, 0x00       // Character - 62, offset (0x00000472)
, 0x05              // width of the glyph
, 0x90, 0x04, 0x00       // Character - 63, offset (0x00000490)
, 0x0A              // width of the glyph
, 0xAE, 0x04, 0x00       // Character - 64, offset (0x000004AE)
, 0x07              // width of the glyph
, 0xDB, 0x04, 0x00       // Character - 65, offset (0x000004DB)
, 0x07              // width of the glyph
, 0xF9, 0x04, 0x00       // Character - 66, offset (0x000004F9)
, 0x07              // width of the glyph
, 0x17, 0x05, 0x00       // Character - 67, offset (0x00000517)
, 0x08              // width of the glyph
, 0x35, 0x05, 0x00       // Character - 68, offset (0x00000535)
, 0x06              // width of the glyph
, 0x53, 0x05, 0x00       // Character - 69, offset (0x00000553)
, 0x06              // width of the glyph
, 0x71, 0x05, 0x00       // Character - 70, offset (0x00000571)
, 0x08              // width of the glyph
, 0x8F, 0x05, 0x00       // Character - 71, offset (0x0000058F)
, 0x08              // width of the glyph
, 0xAD, 0x05, 0x00       // Character - 72, offset (0x000005AD)
, 0x04              // width of the glyph
, 0xCB, 0x05, 0x00       // Character - 73, offset (0x000005CB)
, 0x03              // width of the glyph
, 0xDA, 0x05, 0x00       // Character - 74, offset (0x000005DA)
, 0x07              // width of the glyph
, 0xE9, 0x05, 0x00       // Character - 75, offset (0x000005E9)
, 0x06              // width of the glyph
, 0x07, 0x06, 0x00       // Character - 76, offset (0x00000607)
, 0x0B              // width of the glyph
, 0x25, 0x06, 0x00       // Character - 77, offset (0x00000625)
, 0x09              // width of the glyph
, 0x52, 0x06, 0x00       // Character - 78, offset (0x00000652)
, 0x09              // width of the glyph
, 0x7F, 0x06, 0x00       // Character - 79, offset (0x0000067F)
, 0x07              // width of the glyph
, 0xAC, 0x06, 0x00       // Character - 80, offset (0x000006AC)
, 0x09              // width of the glyph
, 0xCA, 0x06, 0x00       // Character - 81, offset (0x000006CA)
, 0x07              // width of the glyph
, 0xF7, 0x06, 0x00       // Character - 82, offset (0x000006F7)
, 0x07              // width of the glyph
, 0x15, 0x07, 0x00       // Character - 83, offset (0x00000715)
, 0x07              // width of the glyph
, 0x33, 0x07, 0x00       // Character - 84, offset (0x00000733)
, 0x08              // width of the glyph
, 0x51, 0x07, 0x00       // Character - 85, offset (0x00000751)
, 0x07              // width of the glyph
, 0x6F, 0x07, 0x00       // Character - 86, offset (0x0000076F)
, 0x0B              // width of the glyph
, 0x8D, 0x07, 0x00       // Character - 87, offset (0x0000078D)
, 0x07              // width of the glyph
, 0xBA, 0x07, 0x00       // Character - 88, offset (0x000007BA)
, 0x07              // width of the glyph
, 0xD8, 0x07, 0x00       // Character - 89, offset (0x000007D8)
, 0x07              // width of the glyph
, 0xF6, 0x07, 0x00       // Character - 90, offset (0x000007F6)
, 0x04              // width of the glyph
, 0x14, 0x08, 0x00       // Character - 91, offset (0x00000814)
, 0x04              // width of the glyph
, 0x23, 0x08, 0x00       // Character - 92, offset (0x00000823)
, 0x04              // width of the glyph
, 0x32, 0x08, 0x00       // Character - 93, offset (0x00000832)
, 0x06              // width of the glyph
, 0x41, 0x08, 0x00       // Character - 94, offset (0x00000841)
, 0x05              // width of the glyph
, 0x5F, 0x08, 0x00       // Character - 95, offset (0x0000085F)
, 0x07              // width of the glyph
, 0x7D, 0x08, 0x00       // Character - 96, offset (0x0000087D)
, 0x07              // width of the glyph
, 0x9B, 0x08, 0x00       // Character - 97, offset (0x0000089B)
, 0x07              // width of the glyph
, 0xB9, 0x08, 0x00       // Character - 98, offset (0x000008B9)
, 0x06              // width of the glyph
, 0xD7, 0x08, 0x00       // Character - 99, offset (0x000008D7)
, 0x07              // width of the glyph
, 0xF5, 0x08, 0x00       // Character - 100, offset (0x000008F5)
, 0x07              // width of the glyph
, 0x13, 0x09, 0x00       // Character - 101, offset (0x00000913)
, 0x04              // width of the glyph
, 0x31, 0x09, 0x00       // Character - 102, offset (0x00000931)
, 0x06              // width of the glyph
, 0x40, 0x09, 0x00       // Character - 103, offset (0x00000940)
, 0x07              // width of the glyph
, 0x5E, 0x09, 0x00       // Character - 104, offset (0x0000095E)
, 0x03              // width of the glyph
, 0x7C, 0x09, 0x00       // Character - 105, offset (0x0000097C)
, 0x03              // width of the glyph
, 0x8B, 0x09, 0x00       // Character - 106, offset (0x0000098B)
, 0x06              // width of the glyph
, 0x9A, 0x09, 0x00       // Character - 107, offset (0x0000099A)
, 0x03              // width of the glyph
, 0xB8, 0x09, 0x00       // Character - 108, offset (0x000009B8)
, 0x0B              // width of the glyph
, 0xC7, 0x09, 0x00       // Character - 109, offset (0x000009C7)
, 0x07              // width of the glyph
, 0xF4, 0x09, 0x00       // Character - 110, offset (0x000009F4)
, 0x07              // width of the glyph
, 0x12, 0x0A, 0x00       // Character - 111, offset (0x00000A12)
, 0x07              // width of the glyph
, 0x30, 0x0A, 0x00       // Character - 112, offset (0x00000A30)
, 0x07              // width of the glyph
, 0x4E, 0x0A, 0x00       // Character - 113, offset (0x00000A4E)
, 0x04              // width of the glyph
, 0x6C, 0x0A, 0x00       // Character - 114, offset (0x00000A6C)
, 0x06              // width of the glyph
, 0x7B, 0x0A, 0x00       // Character - 115, offset (0x00000A7B)
, 0x04              // width of the glyph
, 0x99, 0x0A, 0x00       // Character - 116, offset (0x00000A99)
, 0x07              // width of the glyph
, 0xA8, 0x0A, 0x00       // Character - 117, offset (0x00000AA8)
, 0x05              // width of the glyph
, 0xC6, 0x0A, 0x00       // Character - 118, offset (0x00000AC6)
, 0x09              // width of the glyph
, 0xE4, 0x0A, 0x00       // Character - 119, offset (0x00000AE4)
, 0x06              // width of the glyph
, 0x11, 0x0B, 0x00       // Character - 120, offset (0x00000B11)
, 0x05              // width of the glyph
, 0x2F, 0x0B, 0x00       // Character - 121, offset (0x00000B2F)
, 0x06              // width of the glyph
, 0x4D, 0x0B, 0x00       // Character - 122, offset (0x00000B4D)
, 0x04              // width of the glyph
, 0x6B, 0x0B, 0x00       // Character - 123, offset (0x00000B6B)
, 0x07              // width of the glyph
, 0x7A, 0x0B, 0x00       // Character - 124, offset (0x00000B7A)
, 0x04              // width of the glyph
, 0x98, 0x0B, 0x00       // Character - 125, offset (0x00000B98)
, 0x07              // width of the glyph
, 0xA7, 0x0B, 0x00       // Character - 126, offset (0x00000BA7)

/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 32
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 33
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x0C        //  X  
, 0x0C        //  X  
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 34
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xDC, 0x01        //  X.X.   
, 0xDC, 0x01        //  X.X.   
, 0xCC, 0x00        //  X X    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 35
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x34        //   .X .X 
, 0xA0, 0x24        //   ** .* 
, 0xFF, 0xFF        // XXXXXXXX
, 0x30, 0x1C        //   X  X. 
, 0x34, 0x0C        //  .X  X  
, 0xFF, 0xFF        // XXXXXXXX
, 0x18, 0x09        //  *. .*  
, 0x1C, 0x06        //  X. *.  
, 0x0C, 0x07        //  X  X.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 36
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xC0, 0x00        //    X    
, 0xF4, 0x0B        //  .XXX*  
, 0xDC, 0x05        //  X.X..  
, 0xDC, 0x00        //  X.X    
, 0xF4, 0x01        //  .XX.   
, 0xD0, 0x0B        //   .XX*  
, 0xC0, 0x0D        //    X.X  
, 0xCC, 0x0D        //  X X.X  
, 0xFC, 0x07        //  XXXX.  
, 0xC0, 0x00        //    X    
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 37
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x7D, 0x74, 0x00        // .XX. .X.    
, 0xD7, 0x28, 0x00        // X..X **     
, 0xC3, 0x1D, 0x00        // X  X.X.     
, 0xD7, 0x0A, 0x00        // X..X**      
, 0x7D, 0xF7, 0x01        // .XX.X.XX.   
, 0x80, 0x5E, 0x03        //    **X..X   
, 0xD0, 0x0D, 0x03        //   .X.X  X   
, 0xA0, 0x5C, 0x03        //   ** X..X   
, 0x74, 0xF4, 0x01        //  .X. .XX.   
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 38
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x0B        //   .XX*  
, 0x70, 0x0D        //   X..X  
, 0x70, 0x0D        //   X..X  
, 0xE0, 0x07        //   *XX.  
, 0xF4, 0x02        //  .XX*   
, 0x6C, 0xD7        //  X*.X..X
, 0x1C, 0x7D        //  X. .XX.
, 0x1C, 0x7D        //  X. .XX.
, 0xF4, 0xB7        //  .XXX.X*
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 39
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x0C        //  X  
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 40
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xE0        //   *X
, 0x74        //  .X.
, 0x38        //  *X 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x38        //  *X 
, 0x74        //  .X.
, 0xA0        //   **
, 0x00        //     

/***********************************
 * Character - 41
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x0B        // X*  
, 0x1D        // .X. 
, 0x28        //  ** 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x28        //  ** 
, 0x1D        // .X. 
, 0x0A        // **  
, 0x00        //     

/***********************************
 * Character - 42
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xC0, 0x00        //    X    
, 0xD5, 0x15        // ...X... 
, 0xFD, 0x1F        // .XXXXX. 
, 0xB0, 0x03        //   X*X   
, 0x34, 0x07        //  .X X.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 43
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xFD, 0x1F        // .XXXXX. 
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 44
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x0D        // .X  
, 0x0A        // **  
, 0x07        // X.  
, 0x00        //     

/***********************************
 * Character - 45
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x3F        // XXX 
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 46
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x1D        // .X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 47
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xD0        //   .X
, 0xA0        //   **
, 0x70        //   X.
, 0x34        //  .X 
, 0x28        //  ** 
, 0x1D        // .X. 
, 0x0D        // .X  
, 0x07        // X.  
, 0x07        // X.  
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 48
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x28, 0x0A        //  ** **  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x0C, 0x0C        //  X   X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x28, 0x0A        //  ** **  
, 0xF4, 0x07        //  .XXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 49
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xE4, 0x00        //  .*X    
, 0xD8, 0x00        //  *.X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 50
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x18, 0x0D        //  *. .X  
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  
, 0x40, 0x07        //    .X.  
, 0xC0, 0x02        //    X*   
, 0xA0, 0x00        //   **    
, 0x38, 0x00        //  *X     
, 0xFC, 0x1F        //  XXXXX. 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 51
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF8, 0x07        //  *XXX.  
, 0x14, 0x0D        //  .. .X  
, 0x00, 0x0D        //     .X  
, 0x40, 0x0A        //    .**  
, 0xF0, 0x07        //   XXX.  
, 0x00, 0x0E        //     *X  
, 0x00, 0x0D        //     .X  
, 0x0C, 0x0E        //  X  *X  
, 0xFC, 0x07        //  XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 52
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x80, 0x03        //    *X   
, 0xD0, 0x03        //   .XX   
, 0x70, 0x03        //   X.X   
, 0x34, 0x03        //  .X X   
, 0x1D, 0x03        // .X. X   
, 0x06, 0x03        // *.  X   
, 0xFF, 0x0F        // XXXXXX  
, 0x00, 0x03        //     X   
, 0x00, 0x03        //     X   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 53
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xFC, 0x07        //  XXXX.  
, 0x40, 0x0E        //    .*X  
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  
, 0x0C, 0x0A        //  X  **  
, 0xFC, 0x07        //  XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 54
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x07        //   .XX.  
, 0x74, 0x00        //  .X.    
, 0x1C, 0x00        //  X.     
, 0xEC, 0x07        //  X*XX.  
, 0x2C, 0x0D        //  X* .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x28, 0x0E        //  ** *X  
, 0xF4, 0x07        //  .XXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 55
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x0D        //     .X  
, 0x00, 0x07        //     X.  
, 0x40, 0x07        //    .X.  
, 0x80, 0x02        //    **   
, 0xC0, 0x01        //    X.   
, 0xD0, 0x00        //   .X    
, 0xB0, 0x00        //   X*    
, 0x74, 0x00        //  .X.    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 56
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x78, 0x0B        //  *X.X*  
, 0xF4, 0x07        //  .XXX.  
, 0x2C, 0x0E        //  X* *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0xF4, 0x07        //  .XXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 57
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x2C, 0x0A        //  X* **  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xF4, 0x0E        //  .XX*X  
, 0x00, 0x0D        //     .X  
, 0x40, 0x07        //    .X.  
, 0xF4, 0x01        //  .XX.   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 58
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x1D        // .X. 
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x1D        // .X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 59
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x1D        // .X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x0D        // .X  
, 0x0A        // **  
, 0x07        // X.  
, 0x00        //     

/***********************************
 * Character - 60
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x0D        //     .X  
, 0xE4, 0x06        //  .*X*.  
, 0x2C, 0x00        //  X*     
, 0xE4, 0x06        //  .*X*.  
, 0x40, 0x0D        //    ..X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 61
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x00        //         
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 62
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0xE4, 0x06        //  .*X*.  
, 0x00, 0x0E        //     *X  
, 0xE4, 0x06        //  .*X*.  
, 0x5C, 0x00        //  X..    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 63
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x7E, 0x00        // *XX.    
, 0xD3, 0x00        // X .X    
, 0xD0, 0x00        //   .X    
, 0xB0, 0x00        //   X*    
, 0x38, 0x00        //  *X     
, 0x1C, 0x00        //  X.     
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 64
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x90, 0x7F, 0x00        //   .*XXX.    
, 0x70, 0xD0, 0x01        //   X.  .X.   
, 0x68, 0x7F, 0x02        //  **.XXX.*   
, 0xDC, 0x71, 0x03        //  X.X. X.X   
, 0xCC, 0x31, 0x03        //  X X. X X   
, 0xCC, 0x30, 0x03        //  X X  X X   
, 0xCC, 0x75, 0x03        //  X X..X.X   
, 0x5C, 0xEB, 0x01        //  X..X**X.   
, 0x74, 0x30, 0x00        //  .X.  X     
, 0xD0, 0x3F, 0x00        //   .XXXX     
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 65
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x01        //   .X.   
, 0xA0, 0x02        //   ***   
, 0x70, 0x03        //   X.X   
, 0x34, 0x07        //  .X X.  
, 0x18, 0x09        //  *. .*  
, 0xFD, 0x1F        // .XXXXX. 
, 0x0D, 0x1C        // .X   X. 
, 0x07, 0x34        // X.   .X 
, 0x07, 0x34        // X.   .X 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 66
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xFC, 0x07        //  XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 67
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x3F        //   .XXXX 
, 0x74, 0x14        //  .X. .. 
, 0x2C, 0x00        //  X*     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x2C, 0x00        //  X*     
, 0x74, 0x30        //  .X.  X 
, 0xD0, 0x3F        //   .XXXX 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 68
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x1D        //  X. .X. 
, 0x1C, 0x38        //  X.  *X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x38        //  X.  *X 
, 0x1C, 0x1D        //  X. .X. 
, 0xFC, 0x07        //  XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 69
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x03        //  XXXX   
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xFC, 0x03        //  XXXX   
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xFC, 0x03        //  XXXX   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 70
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x0F        //  XXXXX  
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xFC, 0x0F        //  XXXXX  
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 71
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xD0, 0x2F        //   .XXX* 
, 0x74, 0x14        //  .X. .. 
, 0x2C, 0x00        //  X*     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x3F        //  X. XXX 
, 0x1C, 0x34        //  X.  .X 
, 0x2C, 0x34        //  X*  .X 
, 0x74, 0x34        //  .X. .X 
, 0xD0, 0x3F        //   .XXXX 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 72
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0xFC, 0x3F        //  XXXXXX 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 73
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x7F        // XXX.
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x7F        // XXX.
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 74
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x30        //   X 
, 0x34        //  .X 
, 0x1F        // XX. 
, 0x00        //     

/***********************************
 * Character - 75
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x38        //  X.  *X 
, 0x1C, 0x1D        //  X. .X. 
, 0x5C, 0x07        //  X..X.  
, 0xDC, 0x01        //  X.X.   
, 0xEC, 0x01        //  X*X.   
, 0x5C, 0x07        //  X..X.  
, 0x1C, 0x0A        //  X. **  
, 0x1C, 0x1D        //  X. .X. 
, 0x1C, 0x34        //  X.  .X 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 76
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 77
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x3C, 0x00, 0x0F        //  XX     XX  
, 0x7C, 0x40, 0x0E        //  XX.   .*X  
, 0x9C, 0x80, 0x0D        //  X.*   *.X  
, 0xDC, 0xC0, 0x0D        //  X.X   X.X  
, 0x9C, 0x91, 0x0D        //  X.*. .*.X  
, 0x5C, 0x73, 0x0D        //  X..X X..X  
, 0x1C, 0x37, 0x0D        //  X. X.X .X  
, 0x1C, 0x1E, 0x0D        //  X. *X. .X  
, 0x1C, 0x1D, 0x0D        //  X. .X. .X  
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 78
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x3C, 0xD0, 0x00        //  XX   .X    
, 0x7C, 0xD0, 0x00        //  XX.  .X    
, 0xDC, 0xD0, 0x00        //  X.X  .X    
, 0x9C, 0xD2, 0x00        //  X.** .X    
, 0x5C, 0xD7, 0x00        //  X..X..X    
, 0x1C, 0xDA, 0x00        //  X. **.X    
, 0x1C, 0xDC, 0x00        //  X.  X.X    
, 0x1C, 0xF4, 0x00        //  X.  .XX    
, 0x1C, 0xF0, 0x00        //  X.   XX    
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 79
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0xD0, 0x1F, 0x00        //   .XXX.     
, 0x74, 0x74, 0x00        //  .X. .X.    
, 0x2C, 0xE0, 0x00        //  X*   *X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x2C, 0xE0, 0x00        //  X*   *X    
, 0x74, 0x74, 0x00        //  .X. .X.    
, 0xD0, 0x1F, 0x00        //   .XXX.     
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 80
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0A        //  X. **  
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 81
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0xD0, 0x1F, 0x00        //   .XXX.     
, 0x74, 0x74, 0x00        //  .X. .X.    
, 0x2C, 0xE0, 0x00        //  X*   *X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x1C, 0xD0, 0x00        //  X.   .X    
, 0x2C, 0xE0, 0x00        //  X*   *X    
, 0x74, 0x74, 0x00        //  .X. .X.    
, 0xD0, 0x1F, 0x00        //   .XXX.     
, 0x00, 0x2C, 0x00        //      X*     
, 0x00, 0x74, 0x00        //      .X.    
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 82
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x07        //  XXXX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xFC, 0x07        //  XXXX.  
, 0x5C, 0x03        //  X..X   
, 0x1C, 0x07        //  X. X.  
, 0x1C, 0x0A        //  X. **  
, 0x1C, 0x1D        //  X. .X. 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 83
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x0B        //  .XXX*  
, 0x2C, 0x05        //  X* ..  
, 0x1C, 0x00        //  X.     
, 0x7C, 0x00        //  XX.    
, 0xE4, 0x07        //  .*XX.  
, 0x40, 0x0F        //    .XX  
, 0x00, 0x0D        //     .X  
, 0x05, 0x0E        // ..  *X  
, 0xFD, 0x07        // .XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 84
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFF, 0x3F        // XXXXXXX 
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 85
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x1C, 0x34        //  X.  .X 
, 0x38, 0x2C        //  *X  X* 
, 0xE4, 0x1B        //  .*XX*. 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 86
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x07, 0x34        // X.   .X 
, 0x0B, 0x34        // X*   .X 
, 0x0D, 0x1C        // .X   X. 
, 0x1D, 0x1D        // .X. .X. 
, 0x1C, 0x0D        //  X. .X  
, 0x34, 0x07        //  .X X.  
, 0x74, 0x03        //  .X.X   
, 0xA0, 0x02        //   ***   
, 0xD0, 0x01        //   .X.   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 87
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x07, 0x1D, 0x34        // X.  .X.  .X 
, 0x07, 0x2A, 0x34        // X.  ***  .X 
, 0x0B, 0x37, 0x38        // X*  X.X  *X 
, 0x4E, 0x73, 0x1C        // *X .X X. X. 
, 0x8D, 0xA2, 0x1C        // .X ** ** X. 
, 0xDC, 0xD1, 0x0D        //  X.X. .X.X  
, 0xDC, 0xC0, 0x0D        //  X.X   X.X  
, 0xB8, 0x80, 0x0B        //  *X*   *X*  
, 0x74, 0x40, 0x07        //  .X.   .X.  
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 88
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x07, 0x34        // X.   .X 
, 0x1D, 0x1D        // .X. .X. 
, 0x78, 0x0B        //  *X.X*  
, 0xF0, 0x03        //   XXX   
, 0xD0, 0x01        //   .X.   
, 0xB4, 0x07        //  .X*X.  
, 0x28, 0x0A        //  ** **  
, 0x1D, 0x1D        // .X. .X. 
, 0x07, 0x34        // X.   .X 
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 89
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x07, 0x34        // X.   .X 
, 0x0D, 0x2C        // .X   X* 
, 0x1C, 0x0D        //  X. .X  
, 0x34, 0x07        //  .X X.  
, 0xE0, 0x03        //   *XX   
, 0xD0, 0x01        //   .X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0xC0, 0x01        //    X.   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 90
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x0A        //     **  
, 0x40, 0x07        //    .X.  
, 0x80, 0x02        //    **   
, 0xD0, 0x01        //   .X.   
, 0xA0, 0x00        //   **    
, 0x74, 0x00        //  .X.    
, 0x28, 0x00        //  **     
, 0xFC, 0x0F        //  XXXXX  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 91
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xFC        //  XXX
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0xFC        //  XXX
, 0x00        //     

/***********************************
 * Character - 92
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x07        // X.  
, 0x07        // X.  
, 0x0D        // .X  
, 0x1D        // .X. 
, 0x28        //  ** 
, 0x34        //  .X 
, 0x70        //   X.
, 0xA0        //   **
, 0xD0        //   .X
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 93
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x3F        // XXX 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x34        //  .X 
, 0x3F        // XXX 
, 0x00        //     

/***********************************
 * Character - 94
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xA0, 0x00        //   **    
, 0xF4, 0x01        //  .XX.   
, 0x58, 0x03        //  *..X   
, 0x0D, 0x07        // .X  X.  
, 0x07, 0x0D        // X.  .X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 95
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xFF, 0x03        // XXXXX   
, 0x00, 0x00        //         

/***********************************
 * Character - 96
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x70, 0x00        //   X.    
, 0xD0, 0x00        //   .X    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 97
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF8, 0x07        //  *XXX.  
, 0x14, 0x0D        //  .. .X  
, 0xF4, 0x0F        //  .XXXX  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xF8, 0x0E        //  *XX*X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 98
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xEC, 0x07        //  X*XX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x2C, 0x0E        //  X* *X  
, 0xEC, 0x07        //  X*XX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 99
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x03        //  .XXX   
, 0x2C, 0x03        //  X* X   
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x2C, 0x03        //  X* X   
, 0xF4, 0x03        //  .XXX   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 100
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  
, 0xF4, 0x0E        //  .XX*X  
, 0x2C, 0x0E        //  X* *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x2C, 0x0D        //  X* .X  
, 0xF4, 0x0E        //  .XX*X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 101
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x1C, 0x0D        //  X. .X  
, 0xFC, 0x0F        //  XXXXX  
, 0x1C, 0x00        //  X.     
, 0x2C, 0x0C        //  X*  X  
, 0xF4, 0x0B        //  .XXX*  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 102
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xF8        //  *XX
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x3E        // *XX 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 103
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x0F        //  .XXXX  
, 0x5C, 0x03        //  X..X   
, 0x5C, 0x03        //  X..X   
, 0xF4, 0x02        //  .XX*   
, 0x70, 0x00        //   X.    
, 0xF4, 0x0B        //  .XXX*  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0xF8, 0x07        //  *XXX.  

/***********************************
 * Character - 104
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0xEC, 0x0B        //  X*XX*  
, 0x2C, 0x0D        //  X* .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 105
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 106
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1D        // .X. 
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1D        // .X. 
, 0x0B        // X*  

/***********************************
 * Character - 107
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x0A        //  X. **  
, 0x9C, 0x02        //  X.**   
, 0xEC, 0x00        //  X*X    
, 0xDC, 0x01        //  X.X.   
, 0x5C, 0x07        //  X..X.  
, 0x1C, 0x0D        //  X. .X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 108
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 109
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0xEC, 0xEB, 0x0B        //  X*XX**XX*  
, 0x2C, 0x2D, 0x0D        //  X* .X* .X  
, 0x1C, 0x1C, 0x0D        //  X.  X. .X  
, 0x1C, 0x1C, 0x0D        //  X.  X. .X  
, 0x1C, 0x1C, 0x0D        //  X.  X. .X  
, 0x1C, 0x1C, 0x0D        //  X.  X. .X  
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 110
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xEC, 0x0B        //  X*XX*  
, 0x2C, 0x0D        //  X* .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 111
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x07        //  .XXX.  
, 0x2C, 0x0E        //  X* *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x2C, 0x0E        //  X* *X  
, 0xF4, 0x07        //  .XXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 112
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xEC, 0x07        //  X*XX.  
, 0x1C, 0x0E        //  X. *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x2C, 0x0E        //  X* *X  
, 0xEC, 0x07        //  X*XX.  
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     
, 0x1C, 0x00        //  X.     

/***********************************
 * Character - 113
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF4, 0x0E        //  .XX*X  
, 0x2C, 0x0E        //  X* *X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x2C, 0x0D        //  X* .X  
, 0xF4, 0x0E        //  .XX*X  
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  
, 0x00, 0x0D        //     .X  

/***********************************
 * Character - 114
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xEC        //  X*X
, 0x2C        //  X* 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 115
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF8, 0x02        //  *XX*   
, 0x1C, 0x03        //  X. X   
, 0x78, 0x00        //  *X.    
, 0xD0, 0x03        //   .XX   
, 0x45, 0x03        // .. .X   
, 0xFD, 0x02        // .XXX*   
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 116
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x14        //  .. 
, 0x1C        //  X. 
, 0xFE        // *XXX
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0x1C        //  X. 
, 0xF8        //  *XX
, 0x00        //     
, 0x00        //     
, 0x00        //     

/***********************************
 * Character - 117
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0D        //  X. .X  
, 0x1C, 0x0E        //  X. *X  
, 0xF8, 0x0E        //  *XX*X  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 118
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x47, 0x03        // X. .X   
, 0x47, 0x03        // X. .X   
, 0xCD, 0x01        // .X X.   
, 0xDD, 0x01        // .X.X.   
, 0xA8, 0x00        //  ***    
, 0x74, 0x00        //  .X.    
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 119
 ***********************************/
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x47, 0x47, 0x03        // X. .X. .X   
, 0x87, 0x4B, 0x03        // X. *X* .X   
, 0xCD, 0xCD, 0x01        // .X X.X X.   
, 0xDD, 0xDC, 0x01        // .X.X X.X.   
, 0xB8, 0xB8, 0x00        //  *X* *X*    
, 0x74, 0x74, 0x00        //  .X. .X.    
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             
, 0x00, 0x00, 0x00        //             

/***********************************
 * Character - 120
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x5D, 0x07        // .X..X.  
, 0xA8, 0x02        //  ****   
, 0xF4, 0x01        //  .XX.   
, 0xF4, 0x01        //  .XX.   
, 0xA8, 0x02        //  ****   
, 0x5D, 0x07        // .X..X.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 121
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x47, 0x03        // X. .X   
, 0x47, 0x03        // X. .X   
, 0xCD, 0x01        // .X X.   
, 0xDD, 0x01        // .X.X.   
, 0xB8, 0x00        //  *X*    
, 0x74, 0x00        //  .X.    
, 0x34, 0x00        //  .X     
, 0x28, 0x00        //  **     
, 0x1F, 0x00        // XX.     

/***********************************
 * Character - 122
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xF8, 0x03        //  *XXX   
, 0x80, 0x03        //    *X   
, 0xD0, 0x01        //   .X.   
, 0x74, 0x00        //  .X.    
, 0x28, 0x00        //  **     
, 0xFC, 0x07        //  XXXX.  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         

/***********************************
 * Character - 123
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0xE0        //   *X
, 0x70        //   X.
, 0x70        //   X.
, 0x70        //   X.
, 0x35        // ..X 
, 0x1F        // XX. 
, 0x34        //  .X 
, 0x70        //   X.
, 0x70        //   X.
, 0x70        //   X.
, 0xE0        //   *X
, 0x00        //     

/***********************************
 * Character - 124
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    
, 0xC0, 0x00        //    X    

/***********************************
 * Character - 125
 ***********************************/
, 0x00        //     
, 0x00        //     
, 0x00        //     
, 0x0B        // X*  
, 0x0D        // .X  
, 0x0D        // .X  
, 0x0D        // .X  
, 0x5C        //  X..
, 0xF4        //  .XX
, 0x1C        //  X. 
, 0x0D        // .X  
, 0x0D        // .X  
, 0x0D        // .X  
, 0x0B        // X*  
, 0x00        //     

/***********************************
 * Character - 126
 ***********************************/
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0xBC, 0x05        //  XX*..  
, 0x94, 0x0F        //  ..*XX  
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //         
, 0x00, 0x00        //    
};     