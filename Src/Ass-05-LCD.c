/*        $Id: Ass-05-LCD.c 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

// Draw the bitmap using DMA
HAL_StatusTypeDef BSP_LCD_DrawBitmapDMA (uint32_t Image)
{
  ili9325_SetCursor (IMAGE_X_OFFSET, IMAGE_Y_OFFSET);
  LCD_IO_WriteReg (LCD_REG_34);
  HAL_DMA_Start(&hdma_memtomem_dma2_stream1, Image, (uint32_t)&LCD_RAM, 57600);
  return HAL_DMA_PollForTransfer(&hdma_memtomem_dma2_stream1, HAL_DMA_FULL_TRANSFER, 1000);  

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

