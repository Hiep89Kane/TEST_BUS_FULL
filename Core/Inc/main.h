/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IN40_Pin GPIO_PIN_11
#define IN40_GPIO_Port GPIOC
#define IN39_Pin GPIO_PIN_12
#define IN39_GPIO_Port GPIOC
#define IN42_Pin GPIO_PIN_13
#define IN42_GPIO_Port GPIOC
#define IN41_Pin GPIO_PIN_14
#define IN41_GPIO_Port GPIOC
#define BUTTON_Pin GPIO_PIN_15
#define BUTTON_GPIO_Port GPIOC
#define BUZ_Pin GPIO_PIN_1
#define BUZ_GPIO_Port GPIOC
#define IN1_Pin GPIO_PIN_2
#define IN1_GPIO_Port GPIOC
#define IN2_Pin GPIO_PIN_3
#define IN2_GPIO_Port GPIOC
#define IN8_Pin GPIO_PIN_0
#define IN8_GPIO_Port GPIOA
#define IN7_Pin GPIO_PIN_1
#define IN7_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_2
#define IN4_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_3
#define IN3_GPIO_Port GPIOA
#define IN6_Pin GPIO_PIN_4
#define IN6_GPIO_Port GPIOA
#define IN5_Pin GPIO_PIN_5
#define IN5_GPIO_Port GPIOA
#define IN10_Pin GPIO_PIN_6
#define IN10_GPIO_Port GPIOA
#define IN9_Pin GPIO_PIN_7
#define IN9_GPIO_Port GPIOA
#define IN32_Pin GPIO_PIN_4
#define IN32_GPIO_Port GPIOC
#define IN31_Pin GPIO_PIN_5
#define IN31_GPIO_Port GPIOC
#define IN30_Pin GPIO_PIN_0
#define IN30_GPIO_Port GPIOB
#define IN29_Pin GPIO_PIN_1
#define IN29_GPIO_Port GPIOB
#define IN28_Pin GPIO_PIN_2
#define IN28_GPIO_Port GPIOB
#define IN27_Pin GPIO_PIN_10
#define IN27_GPIO_Port GPIOB
#define IN26_Pin GPIO_PIN_11
#define IN26_GPIO_Port GPIOB
#define IN25_Pin GPIO_PIN_12
#define IN25_GPIO_Port GPIOB
#define IN24_Pin GPIO_PIN_13
#define IN24_GPIO_Port GPIOB
#define IN23_Pin GPIO_PIN_14
#define IN23_GPIO_Port GPIOB
#define IN12_Pin GPIO_PIN_15
#define IN12_GPIO_Port GPIOB
#define IN22_Pin GPIO_PIN_8
#define IN22_GPIO_Port GPIOA
#define IN21_Pin GPIO_PIN_9
#define IN21_GPIO_Port GPIOA
#define IN16_Pin GPIO_PIN_6
#define IN16_GPIO_Port GPIOC
#define IN11_Pin GPIO_PIN_7
#define IN11_GPIO_Port GPIOC
#define IN15_Pin GPIO_PIN_8
#define IN15_GPIO_Port GPIOD
#define IN14_Pin GPIO_PIN_9
#define IN14_GPIO_Port GPIOD
#define IN13_Pin GPIO_PIN_10
#define IN13_GPIO_Port GPIOA
#define IN17_Pin GPIO_PIN_11
#define IN17_GPIO_Port GPIOA
#define IN18_Pin GPIO_PIN_12
#define IN18_GPIO_Port GPIOA
#define IN19_Pin GPIO_PIN_15
#define IN19_GPIO_Port GPIOA
#define IN20_Pin GPIO_PIN_8
#define IN20_GPIO_Port GPIOC
#define IN34_Pin GPIO_PIN_9
#define IN34_GPIO_Port GPIOC
#define IN33_Pin GPIO_PIN_0
#define IN33_GPIO_Port GPIOD
#define IN36_Pin GPIO_PIN_1
#define IN36_GPIO_Port GPIOD
#define IN35_Pin GPIO_PIN_2
#define IN35_GPIO_Port GPIOD
#define IN43_Pin GPIO_PIN_3
#define IN43_GPIO_Port GPIOD
#define IN44_Pin GPIO_PIN_4
#define IN44_GPIO_Port GPIOD
#define IN45_Pin GPIO_PIN_5
#define IN45_GPIO_Port GPIOD
#define IN46_Pin GPIO_PIN_6
#define IN46_GPIO_Port GPIOD
#define SCK_595_Pin GPIO_PIN_3
#define SCK_595_GPIO_Port GPIOB
#define LAT_595_Pin GPIO_PIN_4
#define LAT_595_GPIO_Port GPIOB
#define SDA_595_Pin GPIO_PIN_5
#define SDA_595_GPIO_Port GPIOB
#define IN37_Pin GPIO_PIN_6
#define IN37_GPIO_Port GPIOB
#define IN38_Pin GPIO_PIN_7
#define IN38_GPIO_Port GPIOB
#define PNP4_Pin GPIO_PIN_10
#define PNP4_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */
#define I_BT0	HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
