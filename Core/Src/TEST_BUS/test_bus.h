#ifndef SRC_TEST_BUS_TEST_BUS_H_
#define SRC_TEST_BUS_TEST_BUS_H_

//BUZZER
#define BUZ_ON 					HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, 1)
#define BUZ_OFF 				HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, 0)
#define BUZ_TOG 				HAL_GPIO_TogglePin(BUZ_GPIO_Port, BUZ_Pin)
#define BUZ_STT 				HAL_GPIO_ReadPin(BUZ_GPIO_Port, BUZ_Pin)

#define _TEST_TOOL_FOR_AF3_BUS	1
//#define _TEST_TOOL_FOR_AF3_SWT	2

typedef struct{
	char str_row0[17];
	char str_row1[17];
}Display_t;

typedef enum{
	_STATE_NONE,
	_STATE_TEST,
	_STATE_FINISHED
}TestState_t;

typedef enum{
	_MODE_AF3,
	_MODE_DUAL,
	_MODE_AF2,
	_MODE_MAS,
	_MODE_SWT,
	_MODE_LAN
}TestMode_t;

typedef union{
	uint8_t	SDA_out[4];
	uint32_t all;
}ManagerLineOut_t;


typedef struct {
	TestMode_t mode;
	TestState_t	state;
}testBus_t;

void test_bus_init();
void test_bus_loop();

#endif /* SRC_TEST_BUS_TEST_BUS_H_ */
