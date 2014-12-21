
// A/D rewuired values
#define	CHX 	0x90
#define	CHY 	0xd0
#define LCD_Height 240
#define LCD_Width 320
#define LCD_Height2 240
#define LCD_Width2 320

#define PORTRAIT        0
#define LANDSCAPE       1
//Empyrical data

#define MEDIAN          20

void TP_Init(void);
void TP_GetAdXY(uint16_t *x, uint16_t *y);
void TP_GetAVGAdXY(uint32_t *x, uint32_t *y);
void TP_GetMedianAdXY(uint32_t *x, uint32_t *y);
int median(uint32_t x[]);

