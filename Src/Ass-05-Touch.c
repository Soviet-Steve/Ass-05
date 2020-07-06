/*        $Id: Ass-05-Touch.c 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

// Get temperature in degrees
// Note that ads7846/tsc2046/ad7873 have temperature sensors
float
BSP_TP_GetTemp ()
{
  HAL_StatusTypeDef status;

  float temperature = 0;

  return temperature;
}

void
Touch (void)
{
  Coordinate display;
  float temperature;
  uint8_t loop_count=0;

  printf ("Question 1 Touch Panel:\n");
  BSP_LCD_DisplayStringAtLine (2, (uint8_t*) "Question 1 Touch Panel");

  // Print touched location and draw a filled circle
  BSP_LCD_SetTextColor (LCD_COLOR_RED);
  while (1)
  {
    if (BSP_TP_GetDisplayPoint (&display) == 0)
    {
      if (display.y > IMAGE_Y_OFFSET+1)
      {
        BSP_LCD_FillCircle (display.x, display.y, 2);
        temperature = BSP_TP_GetTemp ();
        printf ("x = %3d, y = %3d, temperature = %f degC\n", display.x, display.y,
                temperature);
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
}
