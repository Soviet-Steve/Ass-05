/*        $Id: Ass-05.h 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

// Common include file for all modules
#ifndef ASS_05_H_
#define ASS_05_H_

// Assignment and version strings
#define ASS_STRING "ELEC2720-2019s1 Assignment 5"
#define VER_STRING "Ver: 04 $Rev: 1938 $"

// Standard includes

#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#include "openx07v_c_lcd.h"
#include "ili9325.h"
#include "touch_panel.h"
#include "gpio.h"
#include "dma.h"
#include "adc.h"
#include "spi.h"
#include "lcd.h"
#include "usart.h"
#else
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Delay function that can have zero delay

#define MY_HAL_Delay(x) ((x)==0 ? : HAL_Delay(x))

// Questions to be completed

#define DO_QUESTION_1
// #define DO_QUESTION_2
// #define DO_QUESTION_3
// #define DO_QUESTION_4

// Parameters

#define LOOP_DELAY         1 // Period of loops (ms)
#define TOGGLE_DELAY     100 // Period before toggling heartbeat LED (xLOOP_DELAY)

// STEPIEN: Define flow control characters

#define CTRLQ 17
#define CTRLS 19

// STEPIEN: Assume horizontal display 320x240 and image size below
// STEPIEN: The following defines the size and location of images for Question 3 and 4,
//          which use the complete width of the screen.
// STEPIEN: Note that is is possible to define a window in the display to write

#define IMAGE_X_SIZE 320
#define IMAGE_Y_SIZE 180

#define IMAGE_X_OFFSET 0
#define IMAGE_Y_OFFSET 60

// Assignment main function

extern int
UserInterface_main (void);

extern void
Touch ();

extern void
LCD ();

extern void
Serial ();

extern void
All ();


// Assignment solutions used in Question 4

extern float
BSP_TP_GetTemp ();

extern HAL_StatusTypeDef
BSP_LCD_DrawBitmapDMA (uint32_t Image);


// Library functions
#ifdef STM32F407xx
extern uint8_t
BSP_TP_Init (void);
extern uint8_t
BSP_TP_GetDisplayPoint (Coordinate *pDisplay);
#endif

// Image to display on LCD
extern const uint32_t Image[];

#endif /* ASS_05_H_ */
