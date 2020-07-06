/*        $Id: Ass-05-Lib.c 1870 2019-05-19 17:22:47Z Peter $
 *  $Revision: 1870 $
 *      $Date: 2019-05-20 03:22:47 +1000 (Mon, 20 May 2019) $
 *    $Author: Peter $
 */

#include "Ass-05.h"

//
// PLACE YOUR COMMON CODE HERE 
//

// STEPIEN: Added two touch panel functions to make the interface more
//          consistent with the LCD BSP.

#ifdef STM32F407xx
uint8_t
BSP_TP_Init (void)
{
  // Initialise the interface and calibrate
  TP_Init (); // This is an empty function since done by STM32CubeMX
  TouchPanel_Calibrate ();

  return 0;
}

uint8_t
BSP_TP_GetDisplayPoint (Coordinate *pDisplay)
{
  Coordinate *pScreen;

  pScreen = Read_Ads7846 ();
  if (pScreen == NULL)
  {
    return 1; // Error reading the touch panel
  }
  if (getDisplayPoint (pDisplay, pScreen, &matrix) == DISABLE)
  {
    return 1; // Error in LCD
  }
  return 0;
}
#endif
