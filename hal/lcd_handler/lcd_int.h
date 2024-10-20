#ifndef HAL_LCD_HANDLER_LCD_INT_H_
#define HAL_LCD_HANDLER_LCD_INT_H_

/*
 * macros to be used in port_id param
 */
#define PORT_A (uint8_t)0
#define PORT_B (uint8_t)1
#define PORT_C (uint8_t)2
#define PORT_D (uint8_t)3

/*
 * macros to be used with pin_no param
 */
#define PIN_0 (uint8_t)0
#define PIN_1 (uint8_t)1
#define PIN_2 (uint8_t)2
#define PIN_3 (uint8_t)3
#define PIN_4 (uint8_t)4
#define PIN_5 (uint8_t)5
#define PIN_6 (uint8_t)6
#define PIN_7 (uint8_t)7

void LCD_vidInit(void);
void LCD_vidDisplayString(uint8_t * string);
void LCD_vidNewLine();
void LCD_vidDisplayStringLeftShift(uint8_t* string);
void LCD_vidDisplayStringRightShift(uint8_t* string);
void LCD_vidClearDisplay();
void LCD_vidGoTo(uint8_t x,uint8_t y);
void LCD_vidSetCursor(uint8_t x,uint8_t y);
void LCD_vidWriteInteger(uint16_ number);

// very bad
#endif
