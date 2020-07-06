/*        $Id: Ass-05.c 1912 2019-06-03 17:55:30Z Peter $
 *  $Revision: 1912 $
 *      $Date: 2019-06-04 03:55:30 +1000 (Tue, 04 Jun 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

int
UserInterface_main (void)
{

  // Welcome
  // printf("\014");
  printf ("\n");
  printf ("%s\n", ASS_STRING);
  printf ("%s\n", VER_STRING);
#ifdef STM32F407xx
  printf ("Running on STM32 platform\n");
#else
  printf ("Running on WINNT platform\n");
#endif

#ifdef STM32F407xx
  // Initialize and turn on LCD and calibrate the touch panel
  BSP_LCD_Init ();
  BSP_LCD_DisplayOn ();
  printf("Please calibrate touch panel (touch cross hairs)\n");
  BSP_TP_Init ();

  // Display welcome message
  BSP_LCD_Clear (LCD_COLOR_WHITE);
  BSP_LCD_SetFont (&Font12);
  BSP_LCD_SetTextColor (LCD_COLOR_BLACK);
  BSP_LCD_DisplayStringAtLine (0, (uint8_t*) ASS_STRING);
  BSP_LCD_DisplayStringAtLine (1, (uint8_t*) VER_STRING);
#endif

#ifdef DO_QUESTION_1
  // Touch panel input
  printf("-> Question 1\n");
#ifdef STM32F407xx
  Touch();
#else
  printf ("-> No code implemented for WINNT at the moment.\n");
#endif
#endif

#ifdef DO_QUESTION_2
  // LCD output
  printf("-> Question 2\n");
#ifdef STM32F407xx
LCD();
#else
  printf ("-> No code implemented for WINNT at the moment.\n");
#endif
#endif

#ifdef DO_QUESTION_3
  // Serial interface
  printf("-> Question 3\n");
#ifdef STM32F407xx
Serial();
#else
  printf ("-> No code implemented for WINNT at the moment.\n");
#endif
#endif

#ifdef DO_QUESTION_4
  // Application
  printf("-> Question 4\n");
#ifdef STM32F407xx
All();
#else
  printf ("-> No code implemented for WINNT at the moment.\n");
#endif
#endif

  // Sign off message
  printf ("Done.\n");
  return 0;

}
