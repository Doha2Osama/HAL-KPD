/*file name:KPD_program.c
layer:HAL
author: DohaOsama
date: 23 Aug 2021
version 1.0
*/

#include "../../LIB/BIT_MATH.h"

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"

#include "KPD_private.h"

#include "KPD_config.h"

#include <util/delay.h>

void KPD_voidInit(void)//intiation function
{
	//set the rows pins to be input pulled up
	 DIO_voidSetPinDirection(KPD_PORT,KPD_ROW0_PIN,INPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_ROW1_PIN,INPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_ROW2_PIN,INPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_ROW3_PIN,INPUT);
	 //turn on the pullup resistor
	 DIO_voidSetPinValue(KPD_PORT,KPD_ROW0_PIN,PULLUP);
	 DIO_voidSetPinValue(KPD_PORT,KPD_ROW1_PIN,PULLUP);
	 DIO_voidSetPinValue(KPD_PORT,KPD_ROW2_PIN,PULLUP);
	 DIO_voidSetPinValue(KPD_PORT,KPD_ROW3_PIN,PULLUP);
	 //set the column pins to be output high
	 DIO_voidSetPinDirection(KPD_PORT,KPD_COL0_PIN,OUTPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_COL1_PIN,OUTPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_COL2_PIN,OUTPUT);
	 DIO_voidSetPinDirection(KPD_PORT,KPD_COL3_PIN,OUTPUT);
	 //make the output COLUMN PINS high
	  DIO_voidSetPinValue(KPD_PORT,KPD_COL0_PIN,HIGH);
	 DIO_voidSetPinValue(KPD_PORT,KPD_COL1_PIN,HIGH);
	 DIO_voidSetPinValue(KPD_PORT,KPD_COL2_PIN,HIGH);
	 DIO_voidSetPinValue(KPD_PORT,KPD_COL3_PIN,HIGH);
} 
u8 KPD_u8GetPassedKey(void)//return the pin 
{
	u8 Local_u8ColumnsCounter;
	u8 Local_u8RowsCounter;
	u8 Local_u8PinState;
	u8 Local_u8PressedKey=no_pressed_key;
	u8 Local_u8ColumnsArray[COLUMNS_NUM]={ KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN };///array of colums to be config. to any port else
	u8 Local_u8RowsArray[ROWS_NUM]={ KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN };///array of rowss to be config. to any port else
	u8 Local_u8KPDARRAY[ROWS_NUM][COLUMNS_NUM]=KPD_ARR_VALUE;
	for(Local_u8ColumnsCounter=0;Local_u8ColumnsCounter<COLUMNS_NUM;Local_u8ColumnsCounter++)
	{
		//active the column
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColumnsArray[Local_u8ColumnsCounter],LOW);
		for(Local_u8RowsCounter=LOW;Local_u8RowsCounter<ROWS_NUM;Local_u8RowsCounter++)//LOW =0
		{
			Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArray[Local_u8RowsCounter]);
			if(Local_u8PinState==LOW)
			{
				Local_u8PressedKey=Local_u8KPDARRAY[Local_u8RowsCounter][Local_u8ColumnsCounter];
				while(Local_u8PinState==LOW)
				{
					Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArray[Local_u8RowsCounter]);
					return Local_u8PressedKey;
					
				}
			}
		}
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColumnsArray[Local_u8ColumnsCounter],HIGH);
	}
	return Local_u8PressedKey;
}