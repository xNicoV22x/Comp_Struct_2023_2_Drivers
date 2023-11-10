/*
 * keyboard.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Nicolas
 */

#include "keyboard.h"
#include <stdio.h>

//uint8_t keypad_handler(void)
//{
//	static uint32_t last_pressed_tick = 0;
//	uint8_t key_pressed = 0xFF;
//
//	if((key_event == 0xFF) || (last_pressed_tick + 100) >= HAL_GetTick())
//	{
//		return key_pressed;
//	}
//	last_pressed_tick = HAL_GetTick();
//
//	uint16_t column_1 = (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin);
//	uint16_t column_2 = (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin);
//	uint16_t column_3 = (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin);
//	uint16_t column_4 = (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin);
//	printf("Keys: %x, %x, %x, %x\r\n",
//			column_1, column_2, column_3, column_4);
//
//	switch(key_event)
//	{
//	case COLUMN_1_Pin:
//		ROW_1_GPIO_Port->BSRR = ROW_1_Pin;	//Turn on row 1
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BRR = ROW_4_Pin;	//Turn off row 4
//		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) key_pressed = 0x01;
//
//		ROW_1_GPIO_Port->BRR = ROW_1_Pin;	//Turn off row 1
//		ROW_2_GPIO_Port->BSRR = ROW_2_Pin;	//Turn on row 2
//		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) key_pressed = 0x04;
//
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BSRR = ROW_3_Pin;	//Turn on row 3
//		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) key_pressed = 0x07;
//
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BSRR = ROW_4_Pin;	//Turn on row 4
//		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) key_pressed = 0x0E;
//
//	case COLUMN_2_Pin:
//		ROW_1_GPIO_Port->BSRR = ROW_1_Pin;	//Turn on row 1
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BRR = ROW_4_Pin;	//Turn off row 4
//		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) key_pressed = 0x02;
//
//		ROW_1_GPIO_Port->BRR = ROW_1_Pin;	//Turn off row 1
//		ROW_2_GPIO_Port->BSRR = ROW_2_Pin;	//Turn on row 2
//		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) key_pressed = 0x05;
//
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BSRR = ROW_3_Pin;	//Turn on row 3
//		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) key_pressed = 0x08;
//
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BSRR = ROW_4_Pin;	//Turn on row 4
//		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) key_pressed = 0x00;
//
//	case COLUMN_3_Pin:
//		ROW_1_GPIO_Port->BSRR = ROW_1_Pin;	//Turn on row 1
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BRR = ROW_4_Pin;	//Turn off row 4
//		if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) key_pressed = 0x03;
//
//		ROW_1_GPIO_Port->BRR = ROW_1_Pin;	//Turn off row 1
//		ROW_2_GPIO_Port->BSRR = ROW_2_Pin;	//Turn on row 2
//		if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) key_pressed = 0x06;
//
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BSRR = ROW_3_Pin;	//Turn on row 3
//		if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) key_pressed = 0x09;
//
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BSRR = ROW_4_Pin;	//Turn on row 4
//		if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) key_pressed = 0x0F;
//
//	case COLUMN_4_Pin:
//		ROW_1_GPIO_Port->BSRR = ROW_1_Pin;	//Turn on row 1
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BRR = ROW_4_Pin;	//Turn off row 4
//		if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) key_pressed = 0x0A;
//
//		ROW_1_GPIO_Port->BRR = ROW_1_Pin;	//Turn off row 1
//		ROW_2_GPIO_Port->BSRR = ROW_2_Pin;	//Turn on row 2
//		if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) key_pressed = 0x0B;
//
//		ROW_2_GPIO_Port->BRR = ROW_2_Pin;	//Turn off row 2
//		ROW_3_GPIO_Port->BSRR = ROW_3_Pin;	//Turn on row 3
//		if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) key_pressed = 0x0C;
//
//		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	//Turn off row 3
//		ROW_4_GPIO_Port->BSRR = ROW_4_Pin;	//Turn on row 4
//		if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) key_pressed = 0x0D;
//
//	default:
//		break;
//	}
//	ROW_1_GPIO_Port->BSRR = ROW_1_Pin;	//Again Turn on row 1
//	ROW_2_GPIO_Port->BSRR = ROW_2_Pin;	//Again Turn on row 2
//	ROW_3_GPIO_Port->BSRR = ROW_3_Pin;	//Again Turn on row 3
//	ROW_4_GPIO_Port->BSRR = ROW_4_Pin;	//Again Turn on row 4
//
//	printf("Key Pressed: %x\r\n", key_pressed);
//	key_event = 0xFF;
//	return key_pressed;
//}


