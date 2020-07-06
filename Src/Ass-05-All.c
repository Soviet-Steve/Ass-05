/*        $Id: Ass-05-All.c 1933 2019-06-12 21:16:57Z Peter $
 *  $Revision: 1933 $
 *      $Date: 2019-06-13 07:16:57 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

/*
 * Can generate more sample input using:
 *
 *  convert Image.jpg -resize 320x180 -flip -define bmp:subtype=RGB565 Image.bmp
 *  echo '*' > Image.hex
 *  hexdump -s 138 -v -e '16/2 "%04X " "\n"' Image.bmp >> Image.hex
 *
 */
static uint16_t DownloadImage[IMAGE_X_SIZE * IMAGE_Y_SIZE];

void
All (void)
{
  uint16_t i;
  uint16_t PixelValue;
  uint8_t n, c;
  uint32_t CountStart, CountEnd;
  HAL_StatusTypeDef status;
  uint8_t loop_count = 0;
  Coordinate display;
  float temperature;

  printf ("Question 4 All:\n");
  BSP_LCD_DisplayStringAtLine (2, (uint8_t*) "Question 4 All");

#ifdef SOLUTION
  // Initialise UART2 for receive interrupts only (no parity or error interrupts)
  SET_BIT(huart2.Instance->CR1, USART_CR1_RXNEIE);
#endif

  // Draw buttons
  BSP_LCD_SetTextColor (LCD_COLOR_BLUE);
  BSP_LCD_DrawRect (0, IMAGE_Y_OFFSET - 20 - 1, 80, 20);
  BSP_LCD_DrawRect (160 - 40, IMAGE_Y_OFFSET - 20 - 1, 80, 20);
  BSP_LCD_DrawRect (320 - 80, IMAGE_Y_OFFSET - 20 - 1, 80, 20);
  BSP_LCD_SetTextColor (LCD_COLOR_RED);
  BSP_LCD_DisplayStringAt (40, IMAGE_Y_OFFSET - 20 + 4, (uint8_t *) "LOAD",
                           CENTER_MODE);
  BSP_LCD_DisplayStringAt (160, IMAGE_Y_OFFSET - 20 + 4, (uint8_t *) "DRAW",
                           CENTER_MODE);
  BSP_LCD_DisplayStringAt (320 - 40, IMAGE_Y_OFFSET - 20 + 4,
                           (uint8_t *) "CLEAR", CENTER_MODE);

  printf ("Waiting for button press...\n");

  // Start main loop
  while (1)
  {
    // Wait for touch panel input to select key
    while (BSP_TP_GetDisplayPoint (&display) != 0)
      ;

    // Check which button pressed and do function
    if ((display.x > 0) && (display.x < 80) && (display.y > IMAGE_Y_OFFSET - 20)
        && (display.y < IMAGE_Y_OFFSET))
    {
      printf ("LOAD selected\n");

      // Receive image data via serial line
      // Tests Question 3 (interrupt driven serial interface with flow control)

      // Wait for start of image data
      printf ("Waiting for start character...\n");
      while (getchar () != '*')
        ;
      printf ("Got start character.\n");
      // Read IMAGE_X_SIZE by IMAGE_Y_SIZE 16 bit HEX pixel values
      CountStart = HAL_GetTick ();
      printf ("Reading image data (counter = %ld)...\n", CountStart);
      for (i = 0; i < IMAGE_X_SIZE * IMAGE_Y_SIZE; i++)
      {
        while ((n = scanf ("%4hx", &PixelValue)) != 1)
        {
          c = getchar ();
          printf ("Got illegal character: '%c'\n", c);
        }
        DownloadImage[i] = PixelValue;
        printf ("Got %5d: %04hx\n", i, PixelValue);
        // HAL_Delay(1); // STEPIEN: Add delay to force serial line flow control
      }
      CountEnd = HAL_GetTick ();
      printf ("Finished reading image data (counter = %ld).\n", CountEnd);
      printf ("Elasped time = %ld s.\n", (CountEnd - CountStart) / 1000);

      // Use DMA to transfer downloaded image to display
      // Tests Question 2 (DMA transfer to LCD display)

      // Display the bitmap
      if ((status = BSP_LCD_DrawBitmapDMA ((uint32_t) DownloadImage)) != HAL_OK)
      {
        printf ("ERROR: BSP_LCD_DrawBitmapDMA() returned %d\n", status);
      }
      printf ("Done.\n");
      HAL_Delay (500);
    }
    else if ((display.x > 160 - 40) && (display.x < 160 + 40)
        && (display.y > IMAGE_Y_OFFSET - 20) && (display.y < IMAGE_Y_OFFSET))
    {
      printf ("DRAW selected\n");
      printf ("Select CLEAR to end draw mode.\n");

      // Read the touch panel
      // Tests Question 1 (SPI interface)

      BSP_LCD_SetTextColor (LCD_COLOR_RED);
      // Loop while DRAW button not pressed
      while (!((display.x > 320 - 80) && (display.x < 320)
          && (display.y > IMAGE_Y_OFFSET - 20) && (display.y < IMAGE_Y_OFFSET)))
      {
        if (BSP_TP_GetDisplayPoint (&display) == 0)
        {
          if (display.y > IMAGE_Y_OFFSET + 1)
          {
            BSP_LCD_FillCircle (display.x, display.y, 2);
            temperature = BSP_TP_GetTemp ();
            printf ("x = %3d, y = %3d, temperature = %f degC\n", display.x,
                    display.y, temperature);
          }
        }
        // Delay and toggle LED
        HAL_Delay (LOOP_DELAY);
        loop_count++;
        if (loop_count > TOGGLE_DELAY)
        {
          HAL_GPIO_TogglePin (LD3_GPIO_Port, LD3_Pin);
          loop_count = 0;
        }
      }
      printf ("Done.\n");
      HAL_Delay (500);
    }
    else if ((display.x > 320 - 80) && (display.x < 320)
        && (display.y > IMAGE_Y_OFFSET - 20) && (display.y < IMAGE_Y_OFFSET))
    {
      printf ("CLEAR selected\n");
      BSP_LCD_SetTextColor (LCD_COLOR_WHITE);
      BSP_LCD_FillRect (IMAGE_X_OFFSET, IMAGE_Y_OFFSET, IMAGE_X_SIZE,
                        IMAGE_Y_SIZE);
      printf ("Done.\n");
      HAL_Delay (500);
    }
  }
}

