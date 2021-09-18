#ifndef KPD_CONFIG_H

#define KPD_CONFIG_H

#define KPD_PORT      PORTC
//definition for row pins

#define KPD_ROW0_PIN  PIN0

#define KPD_ROW1_PIN  PIN1

#define KPD_ROW2_PIN  PIN2

#define KPD_ROW3_PIN  PIN3
//definition for colo pins

#define KPD_COL0_PIN  PIN4

#define KPD_COL1_PIN  PIN5

#define KPD_COL2_PIN  PIN6

#define KPD_COL3_PIN  PIN7

#define COLUMNS_NUM    4//columns in arr

#define ROWS_NUM       4//rows in arr

#define no_pressed_key  0xFF

#define KPD_ARR_VALUE  {{0,1,2,3},{4,5,6,7},{8,9,37,38},{39,40,41,42}}//*=42IN ASCII

#endif