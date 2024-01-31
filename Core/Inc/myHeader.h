/*
 * myHeader.h
 *
 *  Created on: Nov 6, 2020
 *      Author: NGUYEN VAN HIEP
 */
#ifndef INC_MYHEADER_H_
#define INC_MYHEADER_H_

#include "main.h"

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdarg.h"

#include "myDefine.h"
#include "common.h"
#include "timer.h"
#include "OUTPUT_ctrl_interface.h"
#include "lcd_i2c.h"
#include "button.h"
#include "flash.h"
#include "interrupt.h"
#include "init_MCU.h"
#include "hc595.h"
#include "test_bus.h"


/***** get information extern from main.c **********/
extern I2C_HandleTypeDef hi2c1;
extern IWDG_HandleTypeDef hiwdg;

#endif /* INC_MYHEADER_H_ */
