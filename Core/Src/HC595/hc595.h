#ifndef SRC_HC595_HC595_H_
#define SRC_HC595_HC595_H_

#include "myHeader.h"

#define HC595_USED_NUM	4

#define  HC595_SCK(logic)			HAL_GPIO_WritePin(SCK_595_GPIO_Port, SCK_595_Pin, logic)
#define  HC595_DATA(logic)			HAL_GPIO_WritePin(SDA_595_GPIO_Port, SDA_595_Pin, logic)
#define  HC595_LATCH(logic)			HAL_GPIO_WritePin(LAT_595_GPIO_Port, LAT_595_Pin, logic)

void shift_595_Byte(uint8_t byte);
void shift_595_Word(uint32_t word);
void shift_595_Dword(uint64_t dword);
void shift_595_array(uint8_t byteArray[HC595_USED_NUM]);

void test_595(uint8_t logic);

#endif /* SRC_HC595_HC595_H_ */
