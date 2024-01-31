#include "myHeader.h"
/**
 * @brief  SYSTICK callback - 1ms.
 * @retval None
 */
void HAL_SYSTICK_Callback(void)
{
	static uint8_t tx10;

	// 10ms
	if (++tx10 >= 10)
	{
		tx10 = 0;
		timer_periodic_poll();
		OUTPUT_periodic_poll();
	}
}
