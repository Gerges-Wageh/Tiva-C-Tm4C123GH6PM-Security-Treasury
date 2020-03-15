#ifndef LCD_H
#define LCD_H

//#include "PORT.h"
#include "tm4c123gh6pm.h"
#include "common_macros.h"
#include "delay.h"


/* -------- LCD HardWare Pins -------- */

/* put RS->4 RW->5 E->6*/
#define RS 4
#define RW 5
#define E 6

/* PUT CTRL->A , DATA->B*/
#define LCD_CTRL_PORT GPIO_PORTA_DATA_R
#define LCD_DATA_PORT GPIO_PORTB_DATA_R

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

#define RETURN_CURSOR 			0x02
#define SHIFT_CURSOR_RIGHT 		0x06
#define SHIFT_CURSOR_LEFT		0x04
#define DISPLAY_OFF_CURSOR_OFF          0x08
#define DISPLAY_BLINK_CURSOR_ON	        0x0F
#define FUNC_SET_8BIT_1LINE             0x30
#define CURSOR_BEGIN_SECOND_LINE	0xC0


/*  -------- LCD Functions Prototypes -------- */

void delayMS(uint32_t n);
void LCD_SendCommand(uint8_t com);
void LCD_SendData(uint8_t data);
void LCD_init(void);
void LCD_ClearScreen(void);
void LCD_ShowString(const char *Str);


#endif /* LCD_H */