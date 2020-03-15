#include "lcd.h"
#include <stdint.h>

void LCD_init() //microcontroller initialization aiming to LCD "USING FULL PINS OF PORT B"
{
//	Port_Init(PORTB); //Port B init
	//Port_SetPinDirection(PORTB, 0xFF, PORT_PIN_OUT);

	/* Configure the control pins(E,RS,RW) as output pins */
	//Port_Init(PORTA);
	//Port_SetPinDirection(PORTA, 0xE0, PORT_PIN_OUT);

	
	LCD_SendCommand(TWO_LINE_LCD_Eight_BIT_MODE); //2 lines with 5x7 characters

	LCD_SendCommand(CURSOR_OFF); //Cursor off

	LCD_SendCommand(CLEAR_COMMAND); //clear screen
}


/* TO CLEAR THE SCREEN*/
void LCD_ClearScreen(void)
{
	LCD_SendCommand(CLEAR_COMMAND);
}



void LCD_SendCommand(uint8_t com) //sending command function through port F pins(0,1,2), 0-->RS, 1-->RW, 2-->E
{
	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	delayMS(1);

	SET_BIT(LCD_CTRL_PORT, E);
	delayMS(1);

	LCD_DATA_PORT = com; //sending command to lcd
	delayMS(1);

	CLEAR_BIT(LCD_CTRL_PORT, E); //enable "E" is low
	delayMS(1);					 //high to low delay
}



void LCD_SendData(uint8_t data) //sending data to lcd function
{
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	delayMS(1);

	SET_BIT(LCD_CTRL_PORT, E);
	delayMS(1);

	LCD_DATA_PORT = data; //sending command to lcd
	delayMS(1);

	CLEAR_BIT(LCD_CTRL_PORT, E); //enable "E" is low
	delayMS(1);					 //high to low delay
}



void LCD_ShowString(const char *Str)
{
	uint8_t i = 0;
	while (Str[i] != '\0')
	{
		LCD_SendData(Str[i]);
		i++;
	}
}
