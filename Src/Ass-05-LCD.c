/*        $Id: Ass-05-LCD.c 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

// Draw the bitmap using DMA
HAL_StatusTypeDef
BSP_LCD_DrawBitmapDMA (uint32_t Image)
{

  // while (1)
  {
    BSP_LCD_SetTextColor (LCD_COLOR_RED);
    BSP_LCD_FillRect (0, 60, 320, 180);
    HAL_Delay (TOGGLE_DELAY);
    BSP_LCD_SetTextColor (LCD_COLOR_BLUE);
    BSP_LCD_FillRect (0, 60, 320, 180);
    HAL_Delay (TOGGLE_DELAY);
    BSP_LCD_SetTextColor (LCD_COLOR_GREEN);
    BSP_LCD_FillRect (0, 60, 320, 180);
    HAL_Delay (TOGGLE_DELAY);
    HAL_GPIO_TogglePin (LD3_GPIO_Port, LD3_Pin);
  }

  return HAL_OK;
}

void
LCD (void)
{

  HAL_StatusTypeDef status;

  printf ("Question 2 LCD Display:\n");
  BSP_LCD_DisplayStringAtLine (2, (uint8_t*) "Question 2 LCD Display");

  // Display the bitmap
  if ((status = BSP_LCD_DrawBitmapDMA ((uint32_t) Image)) != HAL_OK)
  {
    printf ("ERROR: BSP_LCD_DrawBitmapDMA() returned %d\n", status);
  }
}

