/*        $Id: Ass-05-Touch.c 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"
#include "touch_panel.h"

#define TEMPERTURE_COMMAND 0x10
#define ADC_CONVERSERSION 3.3/4096

// Get temperature in degrees
// Note that ads7846/tsc2046/ad7873 have temperature sensors
float
BSP_TP_GetTemp ()
{
  HAL_StatusTypeDef status;
  /*
   * Step one set touchscreen adc addresses to a0 a1 a2 = 0 0 0 
   * V = -2.1mV/C + 547.5mV
   * C = -2.1mV/(V - 547mV)
   */

  float temperature;
  const uint8_t inTempTempComand = TEMPERTURE_COMMAND;
  HAL_SPI_Transmit(&hspi2, &inTempTempComand,1,1000);
  uint8_t outbuf[2] = {0,0}; // STEPIEN: Data to write to ensure it is not a command.
  uint8_t buf[2];
  HAL_SPI_TransmitReceive(&hspi2,outbuf,buf,2,1000);
  //uint32_t value = (uint16_t)((buf[0] << 8) + buf[1]) >> 4; // STEPIEN: Was 3 It is 12 bit ADC
  // WR_CMD(TEMPERTURE_COMMAND);
  temperature = -2.1 / ((((float)((uint16_t)((buf[0] << 8) + buf[1]) >> 4) * ADC_CONVERSERSION) / 1000) - 547);
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
    /* // Busy Code
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == SET){
      HAL_Delay(1);
      continue;
    }
    */
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
