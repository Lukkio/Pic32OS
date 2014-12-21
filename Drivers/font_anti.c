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
// Mid colors are calculated only once while rendering each character. This is ideal for rendering text over a constant background.
    #define ANTIALIAS_OPAQUE        0

// Mid values are calculated for every necessary pixel. This feature is useful when rendering text over an image 
// or when the background is not one flat color.
    #define ANTIALIAS_TRANSLUCENT   1
    #define USE_GRADIENT            // Support for rendering color gradients
#define COLOR_DEPTH 16
#define GFX_FONT_SPACE const
#define XCHAR   char
#define UXCHAR  unsigned char
    #define USE_NONBLOCKING_CONFIG  // Comment this line to use blocking configuration
#define ORIENT_HOR  0
    #define ORIENT_VER  1
#define ORIENT_VER2 2
	
	// Font orientation
BYTE    _fontOrientation;

    #define GetFontOrientation()    _fontOrientation
    #define SetFontOrientation(orient)  _fontOrientation = orient;
// Current cursor x-coordinates
SHORT   _cursorX;

// Current cursor y-coordinates
SHORT   _cursorY;



	#ifdef USE_ANTIALIASED_FONTS

    BYTE    _antialiastype;
	#endif





/*********************************************************************
* Macros:  GetX()
*
* Overview: This macro returns the current graphic cursor x-coordinate.
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
    #define GetX()  _cursorX

/*********************************************************************
* Macros:  GetX()
*
* Overview: This macro returns the current graphic cursor y-coordinate.
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
    #define GetY()  _cursorY
/*********************************************************************
* Macro: GFX_Font_GetAntiAliasType()
*
* Overview: Returns the font anti-alias type.
*
* PreCondition: Compiler switch USE_ANTIALIASED_FONTS must be enabled
*
* Input: none
*
* Output: Return the current font anti-alias type.
*        - ANTIALIAS_TRANSLUCENT - (or 1) when font anti-alias is type translucent
*        - ANTIALIAS_OPAQUE - (or 0) when font anti-alias is type opaque
*
********************************************************************/
    #ifdef USE_ANTIALIASED_FONTS
        #define GFX_Font_GetAntiAliasType()  _antialiastype
    #else
        #define GFX_Font_GetAntiAliasType()
    #endif

        #ifdef USE_ANTIALIASED_FONTS
        #define GFX_Font_SetAntiAliasType(transparency)  _antialiastype = transparency;
    #else
        #define GFX_Font_SetAntiAliasType(transparency)
    #endif
	


typedef WORD GFX_COLOR; 

static GFX_COLOR   _fgcolor100;
static GFX_COLOR   _fgcolor25;
static GFX_COLOR   _fgcolor75;
static GFX_COLOR   _bgcolor100;
static GFX_COLOR   _bgcolor25;
static GFX_COLOR   _bgcolor75;
GFX_COLOR   _color;


#define GetColor() _color
#define SetColor(color) _color = (color)
#if (COLOR_DEPTH == 16)

    #ifndef RGBConvert
		/*********************************************************************
		* Macros:  RGBConvert(red, green, blue)
		*
		* Overview: This macro converts the color data to the selected 
		*           COLOR_DEPTH. This macro is only valid when COLOR_DEPTH is 8, 16, or 24.
		*
		*	<TABLE>
		*    	COLOR_DEPTH            Conversion
		*     	##################     ############
		*     	8                      8-8-8 to 3-3-2 conversion
		*     	16                     8-8-8 to to 5-6-5 conversion
		*     	24                     8-8-8 to 8-8-8 conversion or no conversion						 
		*	</TABLE>
		*
		* PreCondition: none
		*
		* Input: red - red component of the color.
		*        green - green component of the color.
		*        blue - blue component of the color.
		*
		* Output: none
		*
		* Side Effects: none
		*
		********************************************************************/	
        #define RGBConvert(red, green, blue)    (GFX_COLOR) ((((GFX_COLOR)(red) & 0xF8) << 8) | (((GFX_COLOR)(green) & 0xFC) << 3) | ((GFX_COLOR)(blue) >> 3))                                               
    #endif

   #define ConvertColor50(color)  (GFX_COLOR)((color & (0b1111011111011110))>>1)
   #define ConvertColor25(color)  (GFX_COLOR)((color & (0b1110011110011100))>>2)
   #define ConvertColor75(color)  (GFX_COLOR)(ConvertColor50(color) + ConvertColor25(color))
   
#ifdef USE_ANTIALIASED_FONTS

    BYTE    _antialiastype;

	#ifdef USE_PALETTE

		#error "Antialiasing can not be used when Palette is enabled"

	#endif

#endif
#endif

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

// information on currently set font
GFX_FONT_CURRENT currentFont;

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
* Overview: Memory type enumeration to determine the source of data.
*           Used in interpreting bitmap and font from different 
*           memory sources.
*
*********************************************************************/
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
* Overview: Structure for font stored in FLASH memory.
*
*********************************************************************/
typedef struct
{
    GFX_RESOURCE  type;                     // must be FLASH
    GFX_FONT_SPACE char    *address;                 // font image address in FLASH
} FONT_FLASH;

extern const FONT_FLASH     Font35_Antialiased;
extern  const XCHAR          AntialisedText[];

/*********************************************************************
* Macros:  MoveTo(x,y)
*
* Overview: This macro moves the graphic cursor to new x,y position.
*
* PreCondition: none
*
* Input: x - Specifies the new x position of the graphic cursor.
*        y - Specifies the new y position of the graphic cursor.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
    #define MoveTo(x, y) \
    _cursorX = x;        \
    _cursorY = y;

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
           // SetFontExternal(pFont);
            break;

        default:
            break;
    }
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
//            return GetTextWidthRam(textString, pFont);
                	    
        case FLASH:
            return GetTextWidthFlash(textString, pFont);

        case EXTERNAL:
        //    return GetTextWidthExternal(textString, pFont);
            
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
        ///sostituito con il driver compatibile
        ///bgcolor = GetPixel(GetX(), GetY() + (currentFont.fontHeader.height >> 1));
        bgcolor = SSD1289_ReadData(GetX(), GetY() + (currentFont.fontHeader.height >> 1));
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
                        //PutPixel(x, y);
                        LCD_Pixel(x, y, _color);
                    }
                }
                else
                {
                    val = (temp & mask) >> shift;
                    if(val)
                    {
                        if(GFX_Font_GetAntiAliasType() == ANTIALIAS_TRANSLUCENT)
                        {
                            bgcolor = SSD1289_ReadData(x, y);
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

                        //PutPixel(x, y);
                        LCD_Pixel(x, y, _color);
                    }
                }

                mask  <<=  pParam->bpp;
                shift  +=  pParam->bpp;
#else
                if(temp & mask)
                {
                    //PutPixel(x, y);
                    LCD_Pixel(y, x, _color);
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
    if(_fontOrientation == ORIENT_VER)    // If extended glyph is used, then vertical alignment may not be rendered properly and hence users must position the texts properly
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
                        //PutPixel(y, x);
                        LCD_Pixel(y, x, _color);
                    }
                }
                else
                {
                    val = (temp & mask) >> shift;
                    if(val)
                    {
                        if(GFX_Font_GetAntiAliasType() == ANTIALIAS_TRANSLUCENT)
                        {
                            bgcolor = SSD1289_ReadData(x, y);

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
						//Sostituito con driver compatibile
                        //PutPixel(y, x);
			LCD_Pixel(y, x, _color);
                    }
                }

                mask  <<=  pParam->bpp;
                shift  +=  pParam->bpp;
#else
                if(temp & mask)
                {
                    //PutPixel(y, x);
                    LCD_Pixel(y, x, _color);
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

    if(_fontOrientation == ORIENT_VER2)
    {
        y = GetX() + pParam->yAdjust;
        for(yCnt = 0; yCnt < currentFont.fontHeader.height + pParam->heightOvershoot; yCnt++)
        {
            x = GetY() + pParam->xAdjust;
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
                        //PutPixel(x, y);
                        LCD_Pixel(y, x, _color);
                    }
                }
                else
                {
                    val = (temp & mask) >> shift;
                    if(val)
                    {
                        if(GFX_Font_GetAntiAliasType() == ANTIALIAS_TRANSLUCENT)
                        {
                            bgcolor = SSD1289_ReadData(y, x);
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

                        //PutPixel(x, y);
                        LCD_Pixel(y, x, _color);
                    }
                }

                mask  <<=  pParam->bpp;
                shift  +=  pParam->bpp;
#else
                if(temp & mask)
                {
                    //PutPixel(x, y);
                    LCD_Pixel(y, x, _color);
                }

                mask <<= 1;
#endif
                x++;
            }
            y--;
        }

        // move cursor
        _cursorY = x - pParam->xAdjust - pParam->xWidthAdjust;
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
    //if(IsDeviceBusy() != 0)
       // return (0);
#endif

    switch(*((SHORT *)currentFont.pFont))
    {

        case FLASH:
            OutCharGetInfoFlash(ch, &OutCharParam);
            break;

        case EXTERNAL:
            //OutCharGetInfoExternal(ch, &OutCharParam);
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
        if(_fontOrientation==2) {MoveTo((239-y), x);}///switch per assegnare il punto di partenza in alto a sinistra!!
        else {MoveTo(x, y);}
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








	
