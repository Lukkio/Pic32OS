#define GFX_1_BPP  0x00
#define GFX_2_BPP  0x01
#define GFX_4_BPP  0x02
#define GFX_8_BPP  0x03
#define GFX_16_BPP 0x04
typedef WORD GFX_COLOR;

#if (COLOR_DEPTH == 1)
    #define GFX_BITS_PER_PIXEL                  GFX_1_BPP
    #define GFX_COLOR_MASK                      0x0001
#elif (COLOR_DEPTH == 2)
    #define GFX_BITS_PER_PIXEL                  GFX_2_BPP
    #define GFX_COLOR_MASK                      0x0003
#elif (COLOR_DEPTH == 4)
    #define GFX_BITS_PER_PIXEL                  GFX_4_BPP
    #define GFX_COLOR_MASK                      0x000F
#elif (COLOR_DEPTH == 8)
    #define GFX_BITS_PER_PIXEL                  GFX_8_BPP
    #define GFX_COLOR_MASK                      0x00FF
#else
    #define GFX_BITS_PER_PIXEL                  GFX_16_BPP
    #define GFX_COLOR_MASK                      0xFFFF
#endif

/*********************************************************************
* Overview: Memory type enumeration to determine the source of data.
*           Used in interpreting bitmap and font from different
*           memory sources.
*
*********************************************************************/
/*typedef WORD IMAGE_MBITMAP;
typedef WORD FLASH;
typedef WORD EXTERNAL;
typedef WORD FLASH_JPEG;
typedef WORD EXTERNAL_JPEG;
typedef WORD RAM ;
typedef WORD EDS_EPMP;
typedef WORD IMAGE_JPEG;
typedef WORD COMP_NONE;
typedef WORD COMP_RLE;
typedef WORD COMP_IPU;*/

typedef enum
{
	FLASH         = 0x0000,                 // internal flash
	EXTERNAL      = 0x0001,                 // external memory
	FLASH_JPEG    = 0x0002,                 // internal flash
	EXTERNAL_JPEG = 0x0003,                 // external memory
	RAM           = 0x0004,                 // RAM
	EDS_EPMP      = 0x0005,                 // memory in EPMP, base addresses are
                                            // are set in the hardware profile

	IMAGE_MBITMAP = 0x0000,                 // data resource is type Microchip bitmap
	IMAGE_JPEG    = 0x0100,                 // data resource is type JPEG

    COMP_NONE     = 0x0000,                 // no compression
	COMP_RLE      = 0x1000,                 // compressed with RLE
	COMP_IPU      = 0x2000,                 // compressed with DEFLATE (for IPU)
} GFX_RESOURCE;

/*********************************************************************
* Overview: This structure is used to describe external memory.
*
*********************************************************************/
typedef struct
{
    GFX_RESOURCE type;                      // Resource type. Valid types are:
                                            // - EXTERNAL
                                            // - EDS_EPMP
    WORD         ID;                        // Memory ID, user defined value to differentiate
                                            // between graphics resources of the same type.
                                            // When using EDS_EPMP the following ID values are
                                            // reserved and used by the Microchip display driver
                                            //   - 0 - reserved (do not use)
                                            //   - 1 - reserved for base address of EPMP CS1
                                            //   - 2 - reserved for base address of EPMP CS2
    DWORD        address;                   // Data image address (user data, bitmap or font)
} GFX_EXTDATA;

/*********************************************************************
* Overview: Primitive lines are drawn using line type and line thickness.
*			There are 3 line styles and 2 types of line thickness.
*
*********************************************************************/

// Solid Line Style
    #define SOLID_LINE  0

// Dotted Line Style
    #define DOTTED_LINE 1

// Dashed Line Style
    #define DASHED_LINE 4

// Normal Line (thickness is 1 pixel)
    #define NORMAL_LINE 0

// Thick Line (thickness is 3 pixels)
    #define THICK_LINE  1

/*********************************************************************
* Overview: Drawing bitmaps will have two modes, normal rendering
*			and stretched rendering. Stretched rendering effectively
*			doubles the image size in the horizontal and vertical
*			direction.
*
*********************************************************************/

// Normal image stretch code
    #define IMAGE_NORMAL    1

// Stretched image stretch code
    #define IMAGE_X2    2

// Current line style
extern SHORT    _lineType;

// Current line thickness
extern BYTE     _lineThickness;

// constants used for circle/arc computation
    #define SIN45   	46341   // sin(45) * 2^16)
    #define ONEP25  	81920   // 1.25 * 2^16
// constants used to get sine(v) and cosine(v)
	#define GETSINE		0x00
	#define GETCOSINE	0x01

// Current cursor coordinates
extern SHORT    _cursorX;
extern SHORT    _cursorY;

// Font orientation
extern BYTE     _fontOrientation;

    #define ORIENT_HOR  0
    #define ORIENT_VER  1

extern BYTE     _antialiastype;
#ifdef USE_ALPHABLEND_LITE
extern GFX_COLOR    _prevAlphaColor;
#endif

/*********************************************************************
* Overview: Fonts that enables anti-aliasing can be set to use
*           opaque or translucent type of anti-aliasing.
*
*********************************************************************/

// Mid colors are calculated only once while rendering each character. This is ideal for rendering text over a constant background.
    #define ANTIALIAS_OPAQUE        0

// Mid values are calculated for every necessary pixel. This feature is useful when rendering text over an image
// or when the background is not one flat color.
    #define ANTIALIAS_TRANSLUCENT   1

/*********************************************************************
* Overview: This macro sets the data type for the strings and characters.
*			There are three types used for XCHAR and the type is selected by
*           adding one of the macros in GraphicsConfig.h.
*	<TABLE>
*    	In GraphicsConfig.h         XCHAR	                        Description
*     	##########################  #############################	##########################
*     	#define USE_MULTIBYTECHAR   #define XCHAR   unsigned short	Use multibyte characters (0-2^16 range).
*     	#define USE_UNSIGNED_XCHAR  #define XCHAR   unsigned char	Use unsigned char (0-255 range).
*     	none of the two defined     #define XCHAR   char	        Use signed char (0-127 range).
*	</TABLE>
*
*           Note: Only one of the two or none at all are defined in GraphicsConfig.h.
*                 - #define USE_MULTIBYTECHAR
*                 - #define USE_UNSIGNED_XCHAR
*                 - when none are defined, XCHAR defaults to type char.
*********************************************************************/

    #if defined (USE_MULTIBYTECHAR)

        #define XCHAR   unsigned short
        #define UXCHAR  unsigned short

    #elif defined (USE_UNSIGNED_XCHAR)

        #define XCHAR   unsigned char
        #define UXCHAR  unsigned char

    #else

        #define XCHAR   char
        #define UXCHAR  unsigned char

    #endif

// bevel drawing type (0 = full bevel, 0xF0 - top bevel only, 0x0F - bottom bevel only
extern BYTE _bevelDrawType;

	#define DRAWFULLBEVEL  	0xFF
	#define DRAWTOPBEVEL  	0xF0
	#define DRAWBOTTOMBEVEL 0x0F

    #ifdef __PIC32MX__
        // Flash data with 32bit pointers
        #define FLASH_BYTE  const BYTE
        #define FLASH_WORD  const WORD
        #define FLASH_DWORD const DWORD
    #else
        // Flash data with 24bit pointers
        #define FLASH_BYTE  __prog__ char
        #define FLASH_WORD  __prog__ short int
        #define FLASH_DWORD __prog__ unsigned long
    #endif

/*********************************************************************
* Overview: This defines the size of the buffer used by font functions
*			to retrieve font data from the external memory. The buffer
*			size can be increased to accommodate large font sizes.
*			The user must be aware of the expected glyph sizes of the
*			characters stored in the font table.
*           To modify the size used, declare this macro in the
*           GraphicsConfig.h file with the desired size.
*
********************************************************************/
//#ifndef EXTERNAL_FONT_BUFFER_SIZE
    #define EXTERNAL_FONT_BUFFER_SIZE   600
//#endif



#define GFX_COMP_MASK   0xF000
#define GFX_MEM_MASK    0x000F
/* &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */
//                         STRUCTURES FOR FONTS
/* &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */

/*********************************************************************
* Overview: Structure describing the font header.
*
*********************************************************************/
typedef struct
{
    BYTE        fontID;                     // User assigned value
    BYTE        extendedGlyphEntry : 1;     // Extended Glyph entry flag. When set font has extended glyph feature enabled.
    BYTE        res1               : 1;     // Reserved for future use  (must be set to 0)
    BYTE        bpp                : 2;     // Actual BPP = 2<sup>bpp</sup>
                                            //   - 0 - 1 BPP
                                            //   - 1 - 2 BPP
                                            //   - 2 - 4 BPP
                                            //   - 3 - 8 BPP
    BYTE        orientation        : 2;     // Orientation of the character glyphs (0,90,180,270 degrees)
                                            //   - 00 - Normal
                                            //   - 01 - Characters rotated 270 degrees clockwise
                                            //   - 10 - Characters rotated 180 degrees
                                            //   - 11 - Characters rotated 90 degrees clockwise
                                            // Note: Rendering DO NOT rotate the characters. The table contains rotated characters
                                            //       and will be rendered as is.
    BYTE        res2               : 2;     // Reserved for future use (must be set to 0).
    WORD        firstChar;                  // Character code of first character (e.g. 32).
    WORD        lastChar;                   // Character code of last character in font (e.g. 3006).
    WORD        height;                     // Font characters height in pixels.
} FONT_HEADER;

/*********************************************************************
* Overview: Structures describing the glyph entry.
*
*********************************************************************/
typedef struct
{
    BYTE        width;                      // width of the glyph
    BYTE        offsetLSB;                  // Least Significant Byte of the glyph location offset
    WORD        offsetMSB;                  // Most Significant (2) Bytes of the glyph location offset
} GLYPH_ENTRY;

typedef struct
{
    DWORD       offset;                     // Offset Order: LSW_LSB LSW_MSB MSW_MSB MSW_MSB
    WORD        cursorAdvance;              // x-value by which cursor has to advance after rendering the glyph
    WORD        glyphWidth;                 // width of the glyph
    INT16       xAdjust;                    // x-position is adjusted as per this signed number
    INT16       yAdjust;                    // y-position is adjusted as per this signed number
} GLYPH_ENTRY_EXTENDED;

/*********************************************************************
* Overview: Font data can be placed in two locations. One is in 
*			FLASH memory and the other is from external memory.
*			Definining one or both enables the support for fonts located
*			in internal flash and external memory. 
*	- USE_FONT_FLASH - Font in internal flash memory support.	
*	- USE_FONT_EXTERNAL - Font in external memory support.	
*
*********************************************************************/
    #define USE_FONT_FLASH          // Support for fonts located in internal flash
    #define USE_ANTIALIASED_FONTS   // Support for rendering anti-aliased fonts
    
//#define USE_FONT_EXTERNAL		// Support for fonts located in external memory

    #define USE_GRADIENT            // Support for rendering color gradients
/*********************************************************************
* Overview: Similar to Font data bitmaps can also be placed in 
*			two locations. One is in FLASH memory and the other is 
*			from external memory.
*			Definining one or both enables the support for bitmaps located
*			in internal flash and external memory. 
*	- USE_BITMAP_FLASH - Font in internal flash memory support.	
*	- USE_BITMAP_EXTERNAL - Font in external memory support.	
*
*********************************************************************/
    #define USE_BITMAP_FLASH        // Support for bitmaps located in internal flash
//#define USE_BITMAP_EXTERNAL		// Support for bitmaps located in external memory
#define USE_COMP_RLE            // Support for bitmaps located in internal flash

/*********************************************************************
* Overview: Internal structure for currently set font.
*
*********************************************************************/
typedef struct
{
   void         *pFont;                     // pointer to the currently set font
   FONT_HEADER  fontHeader;                 // copy of the currently set font header
#ifdef USE_ANTIALIASED_FONTS
   BYTE  antiAliasType;                     // anti-alias type set
#endif
} GFX_FONT_CURRENT;

// Current line type
SHORT   _lineType;

// Current line thickness
BYTE    _lineThickness;

// Font orientation
BYTE    _fontOrientation;

// Current cursor x-coordinates
SHORT   _cursorX;

// Current cursor y-coordinates
SHORT   _cursorY;

// information on currently set font
GFX_FONT_CURRENT currentFont;


#ifdef USE_ANTIALIASED_FONTS

    BYTE    _antialiastype;

	#ifdef USE_PALETTE

		#error "Antialiasing can not be used when Palette is enabled"

	#endif

#endif
/**************************************************************************
 * Overview: Font space section.  The fonts can be located in psv (constant)
 * or program space in PIC24/dsPIC MCUs.  This define allows for switching
 * of the pointer type used to access the font structure in memory
 * See: GraphicsConfig.h for the application define.
 ***************************************************************************/
#ifdef USE_GFX_FONT_IN_PROGRAM_SECTION
#ifndef __PIC32MX__
#define GFX_FONT_SPACE __prog__
#else
#define GFX_FONT_SPACE const
#endif
#else
#define GFX_FONT_SPACE const
#endif


/*********************************************************************
* Overview: Structure for character information when rendering the character.
*
*********************************************************************/
typedef struct 
{ 
#ifdef USE_FONT_FLASH	
    GFX_FONT_SPACE GLYPH_ENTRY             *pChTable;
    GFX_FONT_SPACE GLYPH_ENTRY_EXTENDED    *pChTableExtended;
#endif
#ifdef USE_FONT_EXTERNAL
    BYTE                    chImage[EXTERNAL_FONT_BUFFER_SIZE];
    SHORT                   chEffectiveGlyphWidth;
#endif
    BYTE                    bpp;
	SHORT                   chGlyphWidth;
    GFX_FONT_SPACE BYTE     *pChImage;
    SHORT                   xAdjust;
    SHORT                   yAdjust;
    SHORT                   xWidthAdjust;
    SHORT                   heightOvershoot;
} OUTCHAR_PARAM;

/*********************************************************************
* Overview: Structure for font stored in FLASH memory.
*
*********************************************************************/
typedef struct
{
    GFX_RESOURCE  type;                     // must be FLASH
    GFX_FONT_SPACE char    *address;                 // font image address in FLASH
} FONT_FLASH;

/*********************************************************************
* Overview: Structure for font stored in RAM memory.
*
*********************************************************************/
typedef struct
{
    GFX_RESOURCE  type;                     // must be RAM
    char          *address;                 // font image address in RAM
} FONT_RAM;

/*********************************************************************
* Overview: Structure for font stored in EXTERNAL memory space.
*           (example: External SPI or parallel Flash, EDS_EPMP)
*
*********************************************************************/
typedef GFX_EXTDATA FONT_EXTERNAL;

#define RGBConvert(red, green, blue)    (GFX_COLOR) ((((GFX_COLOR)(red) & 0xF8) << 8) | (((GFX_COLOR)(green) & 0xFC) << 3) | ((GFX_COLOR)(blue) >> 3))

#define ConvertColor50(color)  (GFX_COLOR)((color & (0b1111011111011110))>>1)
#define ConvertColor25(color)  (GFX_COLOR)((color & (0b1110011110011100))>>2)
#define ConvertColor75(color)  (GFX_COLOR)(ConvertColor50(color) + ConvertColor25(color))

/*********************************************************************
* Function: void SetFontFlash(void* pFont)
*
* PreCondition: none
*
* Input: pFont - pointer to the font image in FLASH.
*
* Output: none
*
* Side Effects: none
*
* Overview: Sets the current font located in FLASH.
*
* Note: This function has a weak attribute, the driver layer
*       may implement this same function to support driver layer
*       features.
*
********************************************************************/
void __attribute__((weak)) SetFontFlash(void *pFont)
{
#if defined (USE_FONT_FLASH)
    GFX_FONT_SPACE BYTE *src;
    BYTE *dest;
    int i;

    src = (GFX_FONT_SPACE BYTE *)((FONT_FLASH *)pFont)->address;
    dest = (BYTE *)&(currentFont.fontHeader);
    for(i = 0; i < sizeof(FONT_HEADER); i++)
    {
        *dest = *src;
        src++;
        dest++;
    }
    currentFont.pFont = pFont;
#endif
#if defined (USE_FONT_RAM)
    memcpy( &(currentFont.fontHeader), 
            (FONT_HEADER *) ((FONT_RAM *)pFont)->address, 
            sizeof(FONT_HEADER));
    currentFont.pFont = pFont;
#endif
}

/*********************************************************************
* Function: void SetFontExternal(void* pFont)
*
* PreCondition: none
*
* Input: pFont - pointer to the font image located in External Memory.
*
* Output: none
*
* Side Effects: none
*
* Overview: Sets the current font located in External Memory.
*           When using fonts in external memory, the font glyph
*           buffer size defined by EXTERNAL_FONT_BUFFER_SIZE must
*           be big enough for the character glyphs.
*
* Note: This function has a weak attribute, the driver layer
*       may implement this same function to support driver layer
*       features.
*
********************************************************************/
void __attribute__((weak)) SetFontExternal(void *pFont)
{
#if defined (USE_FONT_EXTERNAL)
    FONT_HEADER *pHeader;

    pHeader = &(currentFont.fontHeader);
    ExternalMemoryCallback(pFont, 0, sizeof(FONT_HEADER), pHeader);
    currentFont.pFont = pFont;
#endif
}

/*********************************************************************
* Function: void SetFont(void* pFont)
*
* PreCondition: none
*
* Input: pointer to the font image
*
* Output: none
*
* Side Effects: none
*
* Overview: defines current font
*
* Note: This function has a weak attribute, the driver layer
*       may implement this same function to support driver layer
*       features.
*
********************************************************************/
void __attribute__((weak)) SetFont(void *pFont)
{
    switch(*((SHORT *)pFont))
    {
        case FLASH:
        case RAM:
            SetFontFlash(pFont);
            break;
				
        case EXTERNAL:
            SetFontExternal(pFont);
            break;

        default:
            break;
    }
}

#ifdef USE_ANTIALIASED_FONTS

static GFX_COLOR   _fgcolor100;
static GFX_COLOR   _fgcolor25;
static GFX_COLOR   _fgcolor75;
static GFX_COLOR   _bgcolor100;
static GFX_COLOR   _bgcolor25;
static GFX_COLOR   _bgcolor75;


GFX_COLOR   _color;
GFX_COLOR   _chrcolor;
/*********************************************************************
* Function: static void __attribute__((always_inline)) calculateColors(void)
*
* PreCondition: _bgcolor100 and _fgcolor100 must be set
*
* Input: none
*
* Output: none
*
* Side Effects: _bgcolor25, _bgcolor75, _fgcolor25 and _fgcolor75 will be calculated
*
* Overview: calculates mid values of colors
*
* Note: Internal to this file
*
********************************************************************/

#define COLOR_DEPTH 16
static void __attribute__((always_inline)) calculateColors(void)
{
    GFX_COLOR   _fgcolor50;
    GFX_COLOR   _bgcolor50;
    
#if (COLOR_DEPTH == 16) || (COLOR_DEPTH == 24)

    _fgcolor50  = ConvertColor50(_fgcolor100);
    _fgcolor25  = ConvertColor25(_fgcolor100);
    _fgcolor75  = _fgcolor50   +  _fgcolor25;

    _bgcolor50  = ConvertColor50(_bgcolor100);
    _bgcolor25  = ConvertColor25(_bgcolor100);
    _bgcolor75  = _bgcolor50   +  _bgcolor25;

#elif ((COLOR_DEPTH == 8) || (COLOR_DEPTH == 4))
        
    _fgcolor50  = _fgcolor100 >> 1;
    _fgcolor25  = _fgcolor50  >> 1;
    _fgcolor75  = _fgcolor50  +  _fgcolor25;

    _bgcolor50  = _bgcolor100 >> 1;
    _bgcolor25  = _bgcolor50  >> 1;
    _bgcolor75  = _bgcolor50  +  _bgcolor25;

    #warning "Antialiasing at 8BPP and 4BPP is supported only for Grayscale mode"
        
#else
    
    #error "Anit-aliasing is currently supported only in 8BPP Grayscale and 16BPP, 24BPP color modes"
    
#endif
    _fgcolor25 += _bgcolor75;
    _fgcolor75 += _bgcolor25;
}

#endif //#ifdef USE_ANTIALIASED_FONTS

/*********************************************************************
* Function:  void OutCharGetInfoFlash (XCHAR ch, OUTCHAR_PARAM *pParam)
*
* PreCondition: none
*
* Input: ch - character code
*        pParam - pointer to character information structure.
*
* Output: none
*
* Side Effects: none
*
* Overview: Gathers the parameters for the specified character of the 
*           currently set font from flash memory. This is a step performed
*           before the character is rendered. 
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
void __attribute__((weak)) OutCharGetInfoFlash (XCHAR ch, OUTCHAR_PARAM *pParam)
{
#ifdef USE_FONT_FLASH

    GFX_FONT_SPACE GLYPH_ENTRY_EXTENDED    *pChTableExtended;
    GFX_FONT_SPACE GLYPH_ENTRY             *pChTable;

    // set color depth of font,
    // based on 2^bpp where bpp is the color depth setting in the FONT_HEADER
    pParam->bpp = 1 << currentFont.fontHeader.bpp;

    if(currentFont.fontHeader.extendedGlyphEntry)
    {
        pChTableExtended = (GFX_FONT_SPACE GLYPH_ENTRY_EXTENDED *) (((FONT_FLASH *)currentFont.pFont)->address + sizeof(FONT_HEADER)) + ((UXCHAR)ch - (UXCHAR)currentFont.fontHeader.firstChar);
        pParam->pChImage = (GFX_FONT_SPACE BYTE *) (((FONT_FLASH *)currentFont.pFont)->address + pChTableExtended->offset);
        pParam->chGlyphWidth = pChTableExtended->glyphWidth;
        pParam->xWidthAdjust = pChTableExtended->glyphWidth - pChTableExtended->cursorAdvance;
        pParam->xAdjust = pChTableExtended->xAdjust;
        pParam->yAdjust = pChTableExtended->yAdjust;
                    
        if(pParam->yAdjust > 0)
        {
            pParam->heightOvershoot = pParam->yAdjust;
        }
    }
    else
    {
        pChTable = (GFX_FONT_SPACE GLYPH_ENTRY *) (((FONT_FLASH *)currentFont.pFont)->address + sizeof(FONT_HEADER)) + ((UXCHAR)ch - (UXCHAR)currentFont.fontHeader.firstChar);
        pParam->pChImage = (GFX_FONT_SPACE BYTE *) (((FONT_FLASH *)currentFont.pFont)->address + ((DWORD)(pChTable->offsetMSB) << 8) + pChTable->offsetLSB);
        pParam->chGlyphWidth = pChTable->width;
    }

#endif // #ifdef USE_FONT_FLASH
    
}

/*********************************************************************
* Function:  void OutCharGetInfoExternal (XCHAR ch, OUTCHAR_PARAM *pParam)
*
* PreCondition: none
*
* Input: ch - character code
*        pParam - pointer to character information structure. 
*
* Output: none
*
* Side Effects: none
*
* Overview: Gathers the parameters for the specified character of the 
*           currently set font from external memory. This is a step performed
*           before the character is rendered. 
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
void __attribute__((weak)) OutCharGetInfoExternal(XCHAR ch, OUTCHAR_PARAM *pParam)
{
#ifdef USE_FONT_EXTERNAL

    GLYPH_ENTRY             chTable;
    GLYPH_ENTRY_EXTENDED    chTableExtended;
    WORD                    imageSize;
    DWORD_VAL               glyphOffset;

    // set color depth of font,
    // based on 2^bpp where bpp is the color depth setting in the FONT_HEADER
    pParam->bpp = 1 << currentFont.fontHeader.bpp;
       
    if(currentFont.fontHeader.extendedGlyphEntry)
    {
        ExternalMemoryCallback
        (
            currentFont.pFont,
            sizeof(FONT_HEADER) + ((UXCHAR)ch - (UXCHAR)currentFont.fontHeader.firstChar) * sizeof(GLYPH_ENTRY_EXTENDED),
            sizeof(GLYPH_ENTRY_EXTENDED),
            &chTableExtended
        );
    
        pParam->chGlyphWidth = chTableExtended.glyphWidth;
        pParam->xWidthAdjust = chTableExtended.glyphWidth - chTableExtended.cursorAdvance;
        pParam->xAdjust = chTableExtended.xAdjust;
        pParam->yAdjust = chTableExtended.yAdjust;
    
        if(pParam->yAdjust > 0)
        {
            pParam->heightOvershoot = pParam->yAdjust;
        }
                    
    }
    else
    {
        // get glyph entry
        ExternalMemoryCallback
        (
            currentFont.pFont,
            sizeof(FONT_HEADER) + ((UXCHAR)ch - (UXCHAR)currentFont.fontHeader.firstChar) * sizeof(GLYPH_ENTRY),
            sizeof(GLYPH_ENTRY),
            &chTable
        );
        pParam->chGlyphWidth = chTable.width;
    }

    // width of glyph in bytes
    imageSize = 0;
    pParam->chEffectiveGlyphWidth = pParam->chGlyphWidth * pParam->bpp;
    if(pParam->chEffectiveGlyphWidth & 0x0007)
        imageSize = 1;
    imageSize += (pParam->chEffectiveGlyphWidth >> 3);

    // glyph image size
    imageSize *= currentFont.fontHeader.height;

    if(currentFont.fontHeader.extendedGlyphEntry)
    {
        glyphOffset.Val = chTableExtended.offset;
    }
    else
    {
        // get glyph image
        glyphOffset.w[1] = (chTable.offsetMSB >> 8);
        glyphOffset.w[0] = (chTable.offsetMSB << 8) + (chTable.offsetLSB);
    }
            
    ExternalMemoryCallback(currentFont.pFont, glyphOffset.Val, imageSize, &(pParam->chImage));
    pParam->pChImage = (BYTE *) &(pParam->chImage);

#endif //#ifdef USE_FONT_EXTERNAL
}

/*********************************************************************
* Function:  void OutCharRender(XCHAR ch, OUTCHAR_PARAM *pParam)
*
* PreCondition: none
*
* Input: ch - character code
*        pParam - pointer to character information structure. 
*
* Output: none
*
* Side Effects: none
*
* Overview: Performs the actual rendering of the character using PutPixel().
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
WORD __attribute__((weak)) OutCharRender(XCHAR ch, OUTCHAR_PARAM *pParam)
{
    BYTE        temp = 0;
    BYTE        mask;
    BYTE        restoremask;
    SHORT       xCnt, yCnt, x = 0, y;
#ifdef USE_ANTIALIASED_FONTS
    BYTE        val, shift;
    GFX_COLOR   bgcolor;
#endif
    
#ifdef USE_ANTIALIASED_FONTS
    if(pParam->bpp == 1)
    {
        restoremask = 0x01;
    }
    else
    {
        if(pParam->bpp == 2)
        {
            restoremask = 0x03;
        }
        else
        {
            return -1; // BPP > 2 are not yet supported
        }
        
        bgcolor = GetPixel(GetX(), GetY() + (currentFont.fontHeader.height >> 1));
        
        if((_fgcolor100 != GetColor()) || (_bgcolor100 != bgcolor))
        {
            _fgcolor100 = GetColor();
            _bgcolor100 = bgcolor;
            calculateColors();
        }
    }
#else
    restoremask = 0x01;
#endif
    
    if(_fontOrientation == ORIENT_HOR)
    {
        y = GetY() + pParam->yAdjust;
        for(yCnt = 0; yCnt < currentFont.fontHeader.height + pParam->heightOvershoot; yCnt++)
        {
            x = GetX() + pParam->xAdjust;
            mask = 0;

#ifdef USE_ANTIALIASED_FONTS
            shift = 0;
#endif

            for(xCnt = 0; xCnt < pParam->chGlyphWidth; xCnt++)
            {
                if(mask == 0)
                {
                    temp = *(pParam->pChImage)++;
                    mask = restoremask;

#ifdef USE_ANTIALIASED_FONTS
                    shift = 0;
#endif
                }

#ifdef USE_ANTIALIASED_FONTS
                if(pParam->bpp == 1)                
                {
                    if(temp & mask)
                    {
                        PutPixel(x, y);
                    }
                }
                else
                {
                    val = (temp & mask) >> shift;
                    if(val)
                    {
                        if(GFX_Font_GetAntiAliasType() == ANTIALIAS_TRANSLUCENT)
                        {
                            bgcolor = GetPixel(x, y);
                            if(_bgcolor100 != bgcolor)
                            {
                                _bgcolor100 = bgcolor;
                                calculateColors();
                            }
                        }

                        switch(val)
                        {
                            case 1:     SetColor(_fgcolor25);
                                        break;
                                        
                            case 2:     SetColor(_fgcolor75);
                                        break;
                                        
                            case 3:     SetColor(_fgcolor100);
                        }
                        
                        PutPixel(x, y);
                    }
                }

                mask  <<=  pParam->bpp;
                shift  +=  pParam->bpp;
#else
                if(temp & mask)
                {
                    PutPixel(x, y);
                }
                
                mask <<= 1;
#endif
                x++;
            }
            y++;
        }

        // move cursor
        _cursorX = x - pParam->xAdjust - pParam->xWidthAdjust;
    }
    else    // If extended glyph is used, then vertical alignment may not be rendered properly and hence users must position the texts properly
    {
        y = GetX() + pParam->xAdjust;
        for(yCnt = 0; yCnt < currentFont.fontHeader.height + pParam->heightOvershoot; yCnt++)
        {
            x = GetY() + pParam->yAdjust;
            mask = 0; 

#ifdef USE_ANTIALIASED_FONTS
            shift = 0;
#endif

            for(xCnt = 0; xCnt < pParam->chGlyphWidth; xCnt++)
            {
                if(mask == 0)
                {
                    temp = *(pParam->pChImage)++;
                    mask = restoremask; 

#ifdef USE_ANTIALIASED_FONTS
                    shift = 0;
#endif
                }

#ifdef USE_ANTIALIASED_FONTS
                if(pParam->bpp == 1)                
                {
                    if(temp & mask)
                    {
                        PutPixel(y, x);
                    }
                }
                else
                {
                    val = (temp & mask) >> shift;
                    if(val)
                    {
                        if(GFX_Font_GetAntiAliasType() == ANTIALIAS_TRANSLUCENT)
                        {
                            bgcolor = GetPixel(x, y);
                            if(_bgcolor100 != bgcolor)
                            {
                                _bgcolor100 = bgcolor;
                                calculateColors();
                            }
                        }
                        switch(val)
                        {
                            case 1: SetColor(_fgcolor25);
                                    break;
                                        
                            case 2: SetColor(_fgcolor75);
                                    break;
                                        
                            case 3: SetColor(_fgcolor100);
                        }
                        PutPixel(y, x);
                    }
                }

                mask  <<=  pParam->bpp;
                shift  +=  pParam->bpp;
#else
                if(temp & mask)
                {
                    PutPixel(y, x);
                }
                mask  <<=  1;
#endif
                x--;
            }
            y++;
        }

        // move cursor
        _cursorY = x - pParam->xAdjust;
    }

    // restore color
#ifdef USE_ANTIALIASED_FONTS
    if(pParam->bpp > 1)
    {
        SetColor(_fgcolor100);
    }
#endif
    return (1);

}

/*********************************************************************
* Function: WORD OutChar(XCHAR ch)
*
* PreCondition: none
*
* Input: character code
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the character is not yet completely drawn.
*         - Returns 1 when the character is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: outputs a character
*
* Note: none
*
********************************************************************/
WORD __attribute__((weak)) OutChar(XCHAR ch)
{
    static OUTCHAR_PARAM OutCharParam;

    // initialize variables
#ifdef USE_FONT_EXTERNAL	
    OutCharParam.pChImage = NULL;
#endif
    OutCharParam.xAdjust = 0;
    OutCharParam.yAdjust = 0;
    OutCharParam.xWidthAdjust = 0;
    OutCharParam.heightOvershoot = 0;

    // check for error conditions (a return value of 0xFFFF means error)
    if((UXCHAR)ch < (UXCHAR)currentFont.fontHeader.firstChar)
        return (-1);
    if((UXCHAR)ch > (UXCHAR)currentFont.fontHeader.lastChar)
        return (-1);
#ifndef USE_ANTIALIASED_FONTS
    if(currentFont.fontHeader.bpp > 1)
        return (-1);
#endif

#ifndef USE_NONBLOCKING_CONFIG
    while(IsDeviceBusy() != 0) Nop();
#else
    if(IsDeviceBusy() != 0)
        return (0);
#endif

    switch(*((SHORT *)currentFont.pFont))
    {

        case FLASH:
            OutCharGetInfoFlash(ch, &OutCharParam); 
            break;

        case EXTERNAL:
            OutCharGetInfoExternal(ch, &OutCharParam);
            break;
        
        default:
            return 1;
    }    
    
    return (OutCharRender(ch, &OutCharParam));
}

/*********************************************************************
* Function: WORD OutText(XCHAR* textString)
*
* PreCondition: none
*
* Input: textString - pointer to text string
*
* Output: non-zero if drawing done (used for NON-BLOCKING configuration)
*
* Side Effects: none
*
* Overview: outputs text from current position
*
* Note: none
*
********************************************************************/
WORD __attribute__((weak)) OutText(XCHAR *textString)
{
    #ifndef USE_NONBLOCKING_CONFIG

    XCHAR   ch;
    while((UXCHAR)15 < (UXCHAR)(ch = *textString++))
        while(OutChar(ch) == 0);
    return (1);

    #else

    XCHAR       ch;
    static WORD counter = 0;

    while((UXCHAR)(ch = *(textString + counter)) > (UXCHAR)15)
    {
        if(OutChar(ch) == 0)
            return (0);
        counter++;
    }

    counter = 0;
    return (1);
    #endif
}

/*********************************************************************
* Function: WORD OutTextXY(SHORT x, SHORT y, XCHAR* textString)
*
* PreCondition: none
*
* Input: x,y - starting coordinates, textString - pointer to text string
*
* Output: non-zero if drawing done (used for NON-BLOCKING configuration)
*
* Side Effects: none
*
* Overview: outputs text from x,y position
*
* Note: none
*
********************************************************************/
WORD __attribute__((weak)) OutTextXY(SHORT x, SHORT y, XCHAR *textString)
{
    #ifndef USE_NONBLOCKING_CONFIG
    MoveTo(x, y);
    OutText(textString);
    return (1);

    #else

    static BYTE start = 1;

    if(start)
    {
        MoveTo(x, y);
        start = 0;
    }

    if(OutText(textString) == 0)
    {
        return (0);
    }
    else
    {
        start = 1;
        return (1);
    }

    #endif
}

/*********************************************************************
* Function: SHORT GetTextWidthRam(XCHAR* textString, void* pFont)
*
* PreCondition: none
*
* Input: textString - pointer to the text string,
*        pFont - pointer to the font in RAM
*
* Output: text width in pixels
*
* Side Effects: none
*
* Overview: returns text width for the font
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
SHORT __attribute__((weak)) GetTextWidthRam(XCHAR* textString, void* pFont)
{
#if defined (USE_FONT_RAM)
    GLYPH_ENTRY *pChTable = NULL;
    GLYPH_ENTRY_EXTENDED *pChTableExtended = NULL;
    FONT_HEADER *pHeader;

    SHORT       textWidth;
    XCHAR       ch;
    XCHAR       fontFirstChar;
    XCHAR       fontLastChar;

    pHeader = (FONT_HEADER *) ((FONT_RAM *)pFont)->address;
    fontFirstChar = pHeader->firstChar;
    fontLastChar = pHeader->lastChar;
    if(pHeader->extendedGlyphEntry)
    {
        pChTableExtended = (GLYPH_ENTRY_EXTENDED *) (pHeader + 1);
    }
    else
    {
        pChTable = (GLYPH_ENTRY *) (pHeader + 1);
    }    
    textWidth = 0;
    while((UXCHAR)15 < (UXCHAR)(ch = *textString++))
    {
        if((UXCHAR)ch < (UXCHAR)fontFirstChar)
            continue;
        if((UXCHAR)ch > (UXCHAR)fontLastChar)
            continue;
        if(pHeader->extendedGlyphEntry)
        {
            textWidth += (pChTableExtended + ((UXCHAR)ch - (UXCHAR)fontFirstChar))->cursorAdvance;
        }
        else
        {
            textWidth += (pChTable + ((UXCHAR)ch - (UXCHAR)fontFirstChar))->width;
        }
    }
    return textWidth;

#else
    return 0;
#endif //#if defined (USE_FONT_RAM) 
}

/*********************************************************************
* Function: SHORT GetTextWidthFlash(XCHAR* textString, void* pFont)
*
* PreCondition: none
*
* Input: textString - pointer to the text string,
*        pFont - pointer to the font in flash memory
*
* Output: text width in pixels
*
* Side Effects: none
*
* Overview: returns text width for the font
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
SHORT __attribute__((weak)) GetTextWidthFlash(XCHAR* textString, void* pFont)
{
#if defined (USE_FONT_FLASH) 
    GFX_FONT_SPACE GLYPH_ENTRY *pChTable = NULL;
    GFX_FONT_SPACE GLYPH_ENTRY_EXTENDED *pChTableExtended = NULL;
    GFX_FONT_SPACE FONT_HEADER *pHeader;

    SHORT       textWidth;
    XCHAR       ch;
    XCHAR       fontFirstChar;
    XCHAR       fontLastChar;

    pHeader = (GFX_FONT_SPACE FONT_HEADER *) ((FONT_FLASH *)pFont)->address;
    fontFirstChar = pHeader->firstChar;
    fontLastChar = pHeader->lastChar;
    if(pHeader->extendedGlyphEntry)
    {
        pChTableExtended = (GFX_FONT_SPACE GLYPH_ENTRY_EXTENDED *) (pHeader + 1);
    }
    else
    {
        pChTable = (GFX_FONT_SPACE GLYPH_ENTRY *) (pHeader + 1);
    }    
    textWidth = 0;
    while((UXCHAR)15 < (UXCHAR)(ch = *textString++))
    {
        if((UXCHAR)ch < (UXCHAR)fontFirstChar)
            continue;
        if((UXCHAR)ch > (UXCHAR)fontLastChar)
            continue;
        if(pHeader->extendedGlyphEntry)
        {
            textWidth += (pChTableExtended + ((UXCHAR)ch - (UXCHAR)fontFirstChar))->cursorAdvance;
        }
        else
        {
            textWidth += (pChTable + ((UXCHAR)ch - (UXCHAR)fontFirstChar))->width;
        }
    }

    return (textWidth);

#else
    return 0;
#endif //#if defined (USE_FONT_FLASH) 

}

/*********************************************************************
* Function: SHORT GetTextWidthExternal(XCHAR* textString, void* pFont)
*
* PreCondition: none
*
* Input: textString - pointer to the text string,
*        pFont - pointer to the font in external memory
*
* Output: text width in pixels
*
* Side Effects: none
*
* Overview: returns text width for the font
*
* Note: Application should not call this function. This function is for 
*       versatility of implementing hardware accelerated text rendering
*       only.
*
********************************************************************/
SHORT __attribute__((weak)) GetTextWidthExternal(XCHAR* textString, void* pFont)
{

#ifdef USE_FONT_EXTERNAL
    GLYPH_ENTRY chTable;
    GLYPH_ENTRY_EXTENDED chTableExtended;
    FONT_HEADER header;

    SHORT       textWidth;
    XCHAR       ch;
    XCHAR       fontFirstChar;
    XCHAR       fontLastChar;


    ExternalMemoryCallback(pFont, 0, sizeof(FONT_HEADER), &header);
    fontFirstChar = header.firstChar;
    fontLastChar = header.lastChar;
    textWidth = 0;
    while((UXCHAR)15 < (UXCHAR)(ch = *textString++))
    {
        if((UXCHAR)ch < (UXCHAR)fontFirstChar)
            continue;
        if((UXCHAR)ch > (UXCHAR)fontLastChar)
            continue;
        if(header.extendedGlyphEntry)
        {
            ExternalMemoryCallback
            (
                pFont,
                sizeof(FONT_HEADER) + sizeof(GLYPH_ENTRY_EXTENDED) * ((UXCHAR)ch - (UXCHAR)fontFirstChar),
                sizeof(GLYPH_ENTRY_EXTENDED),
                &chTableExtended
            );
            textWidth += chTableExtended.cursorAdvance;
        }
        else
        {
            ExternalMemoryCallback
            (
                pFont,
                sizeof(FONT_HEADER) + sizeof(GLYPH_ENTRY) * ((UXCHAR)ch - (UXCHAR)fontFirstChar),
                sizeof(GLYPH_ENTRY),
                &chTable
            );
            textWidth += chTable.width;
        }
    }

    return (textWidth);
#else
    return 0;
#endif //#ifdef USE_FONT_EXTERNAL
}

/*********************************************************************
* Function: SHORT GetTextWidth(XCHAR* textString, void* pFont)
*
* PreCondition: none
*
* Input: textString - pointer to the text string,
*        pFont - pointer to the font
*
* Output: text width in pixels
*
* Side Effects: none
*
* Overview: returns text width for the font
*
* Note: none
*
********************************************************************/
SHORT __attribute__((weak)) GetTextWidth(XCHAR *textString, void *pFont)
{
    switch(*((SHORT *)pFont))
    {
        case RAM:
            return GetTextWidthRam(textString, pFont);
                	    
        case FLASH:
            return GetTextWidthFlash(textString, pFont);

        case EXTERNAL:
            return GetTextWidthExternal(textString, pFont);
            
        default:
            return (0);
    }
}


/*********************************************************************
* Function: SHORT GetTextHeight(void* pFont)
*
* PreCondition: none
*
* Input: pointer to the font
*
* Output: character height in pixels
*
* Side Effects: none
*
* Overview: returns characters height for the font
*
* Note: none
*
********************************************************************/
SHORT __attribute__((weak)) GetTextHeight(void *pFont)
{
#ifdef USE_FONT_EXTERNAL
    SHORT height;
#endif

    // if the current set font is the same just return with 
    // the already set value in currentFont
    if (pFont == currentFont.pFont)
        return currentFont.fontHeader.height;
    else
    {
        switch(*((SHORT *)pFont))
        {
#ifdef USE_FONT_RAM
            case RAM:
                return ((FONT_HEADER *) ((FONT_RAM *)pFont)->address)->height;
#endif
                    
#ifdef USE_FONT_FLASH
            case FLASH:
                return ((GFX_FONT_SPACE FONT_HEADER *) ((FONT_FLASH *)pFont)->address)->height;
#endif
                    
#ifdef USE_FONT_EXTERNAL
            case EXTERNAL:
                ExternalMemoryCallback(pFont, sizeof(FONT_HEADER) - 2, 2, &height);
                return (height);
#endif
    
            default:
                return (0);
        }
    }
}