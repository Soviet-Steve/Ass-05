/*        $Id: Ass-05-Serial.c 1938 2019-06-12 21:29:03Z Peter $
 *  $Revision: 1938 $
 *      $Date: 2019-06-13 07:29:03 +1000 (Thu, 13 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

#define BUFFER_SIZE 16

uint8_t RxChar;
uint8_t TxChar;

// STEPIEN: Rewrite _read() and _write() to use non-blocking functions
//          The code originally contained in syscalls.c

void UART2_Receive(UART_HandleTypeDef *huart)
{
  RxChar = (uint8_t)(huart->Instance->DR & (uint16_t)0x00FF);
  
  // CODE TO BE WRITTEN
}

void UART2_Transmit(UART_HandleTypeDef *huart)
{
  huart->Instance->DR = (uint8_t)(TxChar & (uint8_t)0x00FF);
  CLEAR_BIT(huart->Instance->CR1, USART_CR1_TXEIE);
  // CODE TO BE WRITTEN
}

// STEPIEN: ISR for USART2
void UART2_ISR(UART_HandleTypeDef *huart)
{
  HAL_NVIC_DisableIRQ(USART2_IRQn);

  uint32_t isrflags   = READ_REG(huart->Instance->SR);
  uint32_t cr1its     = READ_REG(huart->Instance->CR1);

  if(((isrflags & USART_SR_RXNE) != RESET) && ((cr1its & USART_CR1_RXNEIE) != RESET))
  {
    UART2_Receive(huart);
  }

  if(((isrflags & USART_SR_TXE) != RESET) && ((cr1its & USART_CR1_TXEIE) != RESET))
  {
    UART2_Transmit(huart);
  }

  HAL_NVIC_EnableIRQ(USART2_IRQn);
}

int _read (int file, char *ptr, int len)
{
  HAL_UART_Receive(&huart2, (uint8_t *)(ptr), 1, HAL_MAX_DELAY);
  return 1;
}

int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart2, (uint8_t *)(ptr), len, HAL_MAX_DELAY);
  return len;
}

void
Serial (void)
{
  uint8_t i,j,c;

  printf ("Question 3 Serial:\n");
  BSP_LCD_DisplayStringAtLine (2, (uint8_t*) "Question 3 Serial");

  // Initialise UART2 for receive interrupts only (no parity or error interrupts)
  SET_BIT(huart2.Instance->CR1, USART_CR1_RXNEIE);

  HAL_Delay(2000);
  while (1)
  {
    /*
    for (i=0;i<20;i++)
    {
      for (j=0;j<60;j++)
      {
        printf("%c", 'A'+i);
      }
      printf("\n");
    }
    */
    SET_BIT(huart2.Instance->CR1, USART_CR1_TXEIE);
    printf("Press a key: \r");
    fflush(stdout);
    c=getchar();
    if (c < ' ')
    {
      printf("Press a key: Got ASCII %3d        \r", c);
    }
    else
    {
      printf("Press a key: Got ASCII %3d '%c'\r", c, c);
    }
  }
}
