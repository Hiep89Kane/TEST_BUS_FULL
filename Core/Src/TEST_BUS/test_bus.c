#include "myHeader.h"

#define _DISPLAYMAX 1
#define _STRING_BUFFER_SIZE 17

#define _NUM_OUT_WIRE 33
#define _NUM_IN_WIRE 46
#define _NUM_IN_WIRE_CHECK 4

typedef uint8_t (*pReadPin)(void);
typedef void (*pWritePin)(uint8_t logic);

uint8_t BusRulesToCheckArr[_NUM_OUT_WIRE][_NUM_IN_WIRE_CHECK];

testBus_t TOOL;
ManagerLineOut_t Out595;
ManagerLineOut_t ErrorsReport;
TIMER_vitual_t timer_debug,_timer_ShowLCD;
OUTPUT_struct_t _BUZZER;
//LCD
char str1[_STRING_BUFFER_SIZE];
char str2[_STRING_BUFFER_SIZE];
Display_t displayLCD[_DISPLAYMAX];

#define APP_BUTTON_NUM	1
uint8_t BTN0_Stt() {return (uint8_t)(!I_BT0);}
button_t BUTTON_arr[APP_BUTTON_NUM];

//function for all buttons
void BUZ_BaseCtrl(uint8_t ON_OFF);
void allButtons_init();
void allButtonsHandle();
void button0_callBackHandle(button_functionCb_t typeFunction, button_typeArg_t agr);

//function check for AF3 lines
void test_EachLine(uint8_t pAF3RuleArr[_NUM_OUT_WIRE][_NUM_IN_WIRE_CHECK], ManagerLineOut_t *pResult);
void test_bus_AF3All();
void update_LCDScreen();

uint64_t getAllPinStt();
uint8_t input_00(void);
uint8_t input_01(void);
uint8_t input_02(void);
uint8_t input_03(void);
uint8_t input_04(void);
uint8_t input_05(void);
uint8_t input_06(void);
uint8_t input_07(void);
uint8_t input_08(void);
uint8_t input_09(void);
uint8_t input_10(void);
uint8_t input_11(void);
uint8_t input_12(void);
uint8_t input_13(void);
uint8_t input_14(void);
uint8_t input_15(void);
uint8_t input_16(void);
uint8_t input_17(void);
uint8_t input_18(void);
uint8_t input_19(void);
uint8_t input_20(void);
uint8_t input_21(void);
uint8_t input_22(void);
uint8_t input_23(void);
uint8_t input_24(void);
uint8_t input_25(void);
uint8_t input_26(void);
uint8_t input_27(void);
uint8_t input_28(void);
uint8_t input_29(void);
uint8_t input_30(void);
uint8_t input_31(void);
uint8_t input_32(void);
uint8_t input_33(void);
uint8_t input_34(void);
uint8_t input_35(void);
uint8_t input_36(void);
uint8_t input_37(void);
uint8_t input_38(void);
uint8_t input_39(void);
uint8_t input_40(void);
uint8_t input_41(void);
uint8_t input_42(void);
uint8_t input_43(void);
uint8_t input_44(void);
uint8_t input_45(void);
void output_00(uint8_t logic);
void output_01(uint8_t logic);
void output_02(uint8_t logic);
void output_03(uint8_t logic);
void output_04(uint8_t logic);
void output_05(uint8_t logic);
void output_06(uint8_t logic);
void output_07(uint8_t logic);
void output_08(uint8_t logic);
void output_09(uint8_t logic);
void output_10(uint8_t logic);
void output_11(uint8_t logic);
void output_12(uint8_t logic);
void output_13(uint8_t logic);
void output_14(uint8_t logic);
void output_15(uint8_t logic);
void output_16(uint8_t logic);
void output_17(uint8_t logic);
void output_18(uint8_t logic);
void output_19(uint8_t logic);
void output_20(uint8_t logic);
void output_21(uint8_t logic);
void output_22(uint8_t logic);
void output_23(uint8_t logic);
void output_24(uint8_t logic);
void output_25(uint8_t logic);
void output_26(uint8_t logic);
void output_27(uint8_t logic);
void output_28(uint8_t logic);
void output_29(uint8_t logic);
void output_30(uint8_t logic);
void output_31(uint8_t logic);
void output_32(uint8_t logic);

// INPUT
uint8_t input_00(void) { return 1;}
uint8_t input_01(void) { return HAL_GPIO_ReadPin(IN1_GPIO_Port, IN1_Pin); }
uint8_t input_02(void) { return HAL_GPIO_ReadPin(IN2_GPIO_Port, IN2_Pin); }
uint8_t input_03(void) { return HAL_GPIO_ReadPin(IN3_GPIO_Port, IN3_Pin); }
uint8_t input_04(void) { return HAL_GPIO_ReadPin(IN4_GPIO_Port, IN4_Pin); }
uint8_t input_05(void) { return HAL_GPIO_ReadPin(IN5_GPIO_Port, IN5_Pin); }
uint8_t input_06(void) { return HAL_GPIO_ReadPin(IN6_GPIO_Port, IN6_Pin); }
uint8_t input_07(void) { return HAL_GPIO_ReadPin(IN7_GPIO_Port, IN7_Pin); }
uint8_t input_08(void) { return HAL_GPIO_ReadPin(IN8_GPIO_Port, IN8_Pin); }

uint8_t input_09(void) { return HAL_GPIO_ReadPin(IN9_GPIO_Port, IN9_Pin); }
uint8_t input_10(void) { return HAL_GPIO_ReadPin(IN10_GPIO_Port, IN10_Pin); }
uint8_t input_11(void) { return HAL_GPIO_ReadPin(IN11_GPIO_Port, IN11_Pin); }
uint8_t input_12(void) { return HAL_GPIO_ReadPin(IN12_GPIO_Port, IN12_Pin); }
uint8_t input_13(void) { return HAL_GPIO_ReadPin(IN13_GPIO_Port, IN13_Pin); }
uint8_t input_14(void) { return HAL_GPIO_ReadPin(IN14_GPIO_Port, IN14_Pin); }
uint8_t input_15(void) { return HAL_GPIO_ReadPin(IN15_GPIO_Port, IN15_Pin); }
uint8_t input_16(void) { return HAL_GPIO_ReadPin(IN16_GPIO_Port, IN16_Pin); }

uint8_t input_17(void) { return HAL_GPIO_ReadPin(IN17_GPIO_Port, IN17_Pin); }
uint8_t input_18(void) { return HAL_GPIO_ReadPin(IN18_GPIO_Port, IN18_Pin); }
uint8_t input_19(void) { return HAL_GPIO_ReadPin(IN19_GPIO_Port, IN19_Pin); }
uint8_t input_20(void) { return HAL_GPIO_ReadPin(IN20_GPIO_Port, IN20_Pin); }
uint8_t input_21(void) { return HAL_GPIO_ReadPin(IN21_GPIO_Port, IN21_Pin); }
uint8_t input_22(void) { return HAL_GPIO_ReadPin(IN22_GPIO_Port, IN22_Pin); }
uint8_t input_23(void) { return HAL_GPIO_ReadPin(IN23_GPIO_Port, IN23_Pin); }
uint8_t input_24(void) { return HAL_GPIO_ReadPin(IN24_GPIO_Port, IN24_Pin); }

uint8_t input_25(void) { return HAL_GPIO_ReadPin(IN25_GPIO_Port, IN25_Pin); }
uint8_t input_26(void) { return HAL_GPIO_ReadPin(IN26_GPIO_Port, IN26_Pin); }
uint8_t input_27(void) { return HAL_GPIO_ReadPin(IN27_GPIO_Port, IN27_Pin); }
uint8_t input_28(void) { return HAL_GPIO_ReadPin(IN28_GPIO_Port, IN28_Pin); }
uint8_t input_29(void) { return HAL_GPIO_ReadPin(IN29_GPIO_Port, IN29_Pin); }
uint8_t input_30(void) { return HAL_GPIO_ReadPin(IN30_GPIO_Port, IN30_Pin); }
uint8_t input_31(void) { return HAL_GPIO_ReadPin(IN31_GPIO_Port, IN31_Pin); }
uint8_t input_32(void) { return HAL_GPIO_ReadPin(IN32_GPIO_Port, IN32_Pin); }

uint8_t input_33(void) { return HAL_GPIO_ReadPin(IN33_GPIO_Port, IN33_Pin); }
uint8_t input_34(void) { return HAL_GPIO_ReadPin(IN34_GPIO_Port, IN34_Pin); }
uint8_t input_35(void) { return HAL_GPIO_ReadPin(IN35_GPIO_Port, IN35_Pin); }
uint8_t input_36(void) { return HAL_GPIO_ReadPin(IN36_GPIO_Port, IN36_Pin); }
uint8_t input_37(void) { return HAL_GPIO_ReadPin(IN37_GPIO_Port, IN37_Pin); }
uint8_t input_38(void) { return HAL_GPIO_ReadPin(IN38_GPIO_Port, IN38_Pin); }
uint8_t input_39(void) { return HAL_GPIO_ReadPin(IN39_GPIO_Port, IN39_Pin); }
uint8_t input_40(void) { return HAL_GPIO_ReadPin(IN40_GPIO_Port, IN40_Pin); }

uint8_t input_41(void) { return HAL_GPIO_ReadPin(IN41_GPIO_Port, IN41_Pin); }
uint8_t input_42(void) { return HAL_GPIO_ReadPin(IN42_GPIO_Port, IN42_Pin); }
uint8_t input_43(void) { return HAL_GPIO_ReadPin(IN43_GPIO_Port, IN43_Pin); }
uint8_t input_44(void) { return HAL_GPIO_ReadPin(IN44_GPIO_Port, IN44_Pin); }
uint8_t input_45(void) { return HAL_GPIO_ReadPin(IN45_GPIO_Port, IN45_Pin); }

uint64_t getAllPinStt();

void output_00(uint8_t logic) { ;}
void output_01(uint8_t logic) { wbi(Out595.all,0,logic);}
void output_02(uint8_t logic) { wbi(Out595.all,1,logic);}
void output_03(uint8_t logic) { wbi(Out595.all,2,logic);}
void output_04(uint8_t logic) { wbi(Out595.all,3,logic);}
void output_05(uint8_t logic) { wbi(Out595.all,4,logic);}
void output_06(uint8_t logic) { wbi(Out595.all,5,logic);}
void output_07(uint8_t logic) { wbi(Out595.all,6,logic);}
void output_08(uint8_t logic) { wbi(Out595.all,7,logic);}
void output_09(uint8_t logic) { wbi(Out595.all,8,logic);}
void output_10(uint8_t logic) { wbi(Out595.all,9,logic);}
void output_11(uint8_t logic) { wbi(Out595.all,10,logic);}
void output_12(uint8_t logic) { wbi(Out595.all,11,logic);}
void output_13(uint8_t logic) { wbi(Out595.all,12,logic);}
void output_14(uint8_t logic) { wbi(Out595.all,13,logic);}
void output_15(uint8_t logic) { wbi(Out595.all,14,logic);}
void output_16(uint8_t logic) { wbi(Out595.all,15,logic);}
void output_17(uint8_t logic) { wbi(Out595.all,16,logic);}
void output_18(uint8_t logic) { wbi(Out595.all,17,logic);}
void output_19(uint8_t logic) { wbi(Out595.all,18,logic);}
void output_20(uint8_t logic) { wbi(Out595.all,19,logic);}
void output_21(uint8_t logic) { wbi(Out595.all,20,logic);}
void output_22(uint8_t logic) { wbi(Out595.all,21,logic);}
void output_23(uint8_t logic) { wbi(Out595.all,22,logic);}
void output_24(uint8_t logic) { wbi(Out595.all,23,logic);}
void output_25(uint8_t logic) { wbi(Out595.all,24,logic);}
void output_26(uint8_t logic) { wbi(Out595.all,25,logic);}
void output_27(uint8_t logic) { wbi(Out595.all,26,logic);}
void output_28(uint8_t logic) { wbi(Out595.all,27,logic);}
void output_29(uint8_t logic) { wbi(Out595.all,28,logic);}
void output_30(uint8_t logic) { wbi(Out595.all,29,logic);}
void output_31(uint8_t logic) { wbi(Out595.all,30,logic);}
void output_32(uint8_t logic) { wbi(Out595.all,31,logic);}

pReadPin inputArray[_NUM_IN_WIRE]= {input_00,
									input_01, input_02, input_03, input_04, input_05, input_06, input_07, input_08, input_09, input_10,
									input_11, input_12, input_13, input_14, input_15, input_16, input_17, input_18, input_19, input_20,
									input_21, input_22, input_23, input_24, input_25, input_26, input_27, input_28, input_29, input_30,
									input_31, input_32, input_33, input_34, input_35, input_36, input_37, input_38, input_39, input_40,
									input_41, input_42, input_43, input_44, input_45};

pWritePin outputArray[_NUM_OUT_WIRE]= {output_00,
							output_01, output_02, output_03, output_04, output_05, output_06, output_07, output_08, output_09, output_10,
							output_11, output_12, output_13, output_14, output_15, output_16, output_17, output_18, output_19, output_20,
							output_21, output_22, output_23, output_24, output_25, output_26, output_27, output_28, output_29, output_30,
							output_31, output_32};

const uint8_t AF3_RulesCommon[_NUM_OUT_WIRE][_NUM_IN_WIRE_CHECK]={{0,0,0,0},//no use
																	{1,1,0,0},//spot+
																	{2,2,0,0},//spot-
																	{3,28,0,0},//24v rgb
																	{4,24,0,0},//red
																	{5,22,0,0},//blue
																	{6,26,0,0},//green
																	{7,0,0,0},//7 ko sử dụng
																	{8,0,0,0},//8 ko sử dụng
																	{9,0,0,0},//9 ko sử dụng
																	{10,4,0,0},//dome
																	{11,3,0,0},//24v dome
																	{12,12,0,0},//sol ST-
																	{13,30,0,0},//Jetswt
																	{14,7,9,0},//sol AF-
																	{15,13,0,0},//signal SS1
																	{16,8,10,11},//Sol+
																	{17,14,18,0},//5v Sensor
																	{18,32,0,0},//Drainswt
																	{19,15,0,0},//logic ss1
																	{20,6,0,0},//gnd Safety
																	{21,16,20,0},//gnd Sensor
																	{22,27,0,0},//txd rs232
																	{23,21,0,0},//5v Dcs
																	{24,25,0,0},//rxd rs232
																	{25,17,0,0},//signal ss2
																	{26,19,0,0},//Logic ss2
																	{27,23,0,0},//gnd Dcs
																	{28,5,0,0},//safety swt
																	{29,0,0,0},//ko sử dụng
																	{31,0,0,0},//ko sử dụng
																	{32,0,0,0}};//ko sử dụng

const uint8_t SwtPrive_RulesCommon[_NUM_OUT_WIRE][_NUM_IN_WIRE_CHECK]={	{0,0,0,0},//no use
																		{1,0,0,0},//no use
																		{2,0,0,0},//no use
																		{3,35,0,0},// dây cam -drainswt
																		{4,36,0,0},// dây đen -drainswt
																		{5,33,0,0},//dây xanh -Jetswt
																		{6,34,0,0},//dây đen - Jetswt
																		{7,0,0,0},//no use
																		{8,0,0,0},//no use
																		{9,0,0,0},//no use
																		{10,0,0,0},//no use
																		{11,0,0,0},//no use
																		{12,0,0,0},//no use
																		{13,0,0,0},//no use
																		{14,0,0,0},//no use
																		{15,0,0,0},//no use
																		{16,0,0,0},//no use
																		{17,0,0,0},//no use
																		{18,0,0,0},//no use
																		{19,0,0,0},//no use
																		{20,0,0,0},//no use
																		{21,0,0,0},//no use
																		{22,0,0,0},//no use
																		{23,0,0,0},//no use
																		{24,0,0,0},//no use
																		{25,0,0,0},//no use
																		{26,0,0,0},//no use
																		{27,0,0,0},//no use
																		{28,0,0,0},//no use
																		{29,0,0,0},//no use
																		{31,0,0,0},//no use
																		{32,0,0,0}};//no use
//=================================================================================================
void update_LCDScreen(){
	static char str_cmp0[17],
				str_cmp1[17];
	uint8_t result1,result2;

//	// cập nhật giá trị mới
	if (!timer_expired(&_timer_ShowLCD))
		return;
	timer_restart(&_timer_ShowLCD);

	//Nếu chuỗi không thay đổi thì return
	result1 = memcmp(displayLCD[0].str_row0, str_cmp0, _STRING_BUFFER_SIZE);
	result2 = memcmp(displayLCD[0].str_row1, str_cmp1, _STRING_BUFFER_SIZE);
	if(result1 == 0 && result2==0)return;

	//Cập nhật dữ liệu mới lên LCD
	CLCD_I2C_Clear(&LCD1);
	LCD_ShowString(displayLCD[0].str_row0, 0, 0);
	LCD_ShowString(displayLCD[0].str_row1, 0, 1);

	memcpy(str_cmp0,displayLCD[0].str_row0, _STRING_BUFFER_SIZE);
	memcpy(str_cmp1,displayLCD[0].str_row1, _STRING_BUFFER_SIZE);
}

void BUZ_BaseCtrl(uint8_t ON_OFF){
	if (ON_OFF) BUZ_ON;
	else BUZ_OFF;
}
void allButtons_init(){
	//init callback button0
	BUTTON_arr[0].pinStt = &BTN0_Stt;
	BUTTON_arr[0].cb_function = &button0_callBackHandle;
}

void button0_callBackHandle(button_functionCb_t typeFunction, button_typeArg_t agr){

	switch(typeFunction){
		case _BUTTON_FUNC_EVENT:
			if(agr.event==BUTTON_ONECLICK){
				TOOL.state = _STATE_TEST;
				ErrorsReport.all = 0;
			}
			break;

		case _BUTTON_FUNC_MULCLICK:

			break;

		case _BUTTON_FUNC_HOLD:
			if(agr.holdInterval_ms == 3000){
				if(TOOL.mode == _MODE_AF3){
					TOOL.mode  = _MODE_SWT;
					memcpy(BusRulesToCheckArr, SwtPrive_RulesCommon, sizeof(SwtPrive_RulesCommon));
					OUTPUT_set_blink(&_BUZZER,2,CLOCK_SECOND/4,CLOCK_SECOND/4,0);
				}
				else if(TOOL.mode == _MODE_SWT){
					TOOL.mode  = _MODE_AF3;
					memcpy(BusRulesToCheckArr, AF3_RulesCommon, sizeof(AF3_RulesCommon));
					OUTPUT_set_blink(&_BUZZER,1,CLOCK_SECOND/4,CLOCK_SECOND/4,0);
				}
				delay_ms(1000);
				TOOL.state = _STATE_TEST;
				ErrorsReport.all = 0;
			}
			break;

		default:break;
	}

}

void allButtonsHandle(){
	for(uint8_t i=0; i < APP_BUTTON_NUM; i++){
		btn_progress_loop(&BUTTON_arr[i]);
	}
}

uint64_t getAllPinStt(){
	uint64_t result=0xFFFFFFFFFFFFFFFF;
	for(uint8_t i=0; i<_NUM_IN_WIRE; i++){
		result = DbWord_wbi(result,i,inputArray[i]());
	}

	return result;
}

void test_bus_init(){
	//init
//	HAL_I2C_Init(&hi2c1);
//	CLCD_I2C_Init(&LCD1, &hi2c1, 0x4e, 20, 4);
// 	timer_set(&_timer_ShowLCD, CLOCK_SECOND/4);
	allButtons_init();

	timer_set(&timer_debug, 2*CLOCK_SECOND);

	Out595.all = 0xFFFFFFFF;
	shift_595_array(Out595.SDA_out);
	OUTPUT_config_new_control(&_BUZZER, &BUZ_BaseCtrl);

	TOOL.mode = _MODE_AF3;
	memcpy(BusRulesToCheckArr, AF3_RulesCommon, sizeof(AF3_RulesCommon));
	TOOL.state = _STATE_NONE;

	OUTPUT_set_blink(&_BUZZER,1,CLOCK_SECOND/4,CLOCK_SECOND/4,0);

//	if(TOOL.mode == _MODE_AF3)
//		sprintf(displayLCD[0].str_row0,"Day dien AF3");
//	else if(TOOL.mode == _MODE_SWT)
//		sprintf(displayLCD[0].str_row0,"Day Switch");
//
//	sprintf(displayLCD[0].str_row1,"Nhan nut de test");
}

uint64_t inputManager;
void test_bus_loop(){

	//update_LCDScreen();
	inputManager = getAllPinStt();
	allButtonsHandle();
	test_bus_AF3All();
}

//uint64_t allInputStt , allInputStt_Cmp , allInputStt_default;
void test_EachLine(uint8_t pAF3RuleArr[_NUM_OUT_WIRE][_NUM_IN_WIRE_CHECK], ManagerLineOut_t *pResult){

	uint8_t	bit_dk1, bit_dk2, bit_dk3;
	uint64_t allInputStt , allInputStt_Cmp , allInputStt_default;

	//reset lỗi = 0
	pResult->all = 0;
	allInputStt = 0;
	allInputStt_Cmp = 0;

	//reset tat ca output ve muc cao va doc gia tri bien Input
	Out595.all = 0xFFFFFFFF;
	shift_595_Word(Out595.all);
	delay_ms(10);
	allInputStt_default = getAllPinStt();

	for(uint8_t i=1; i<_NUM_OUT_WIRE; i++){
		//reset lai tat ca output muc cao sai check xong 1 wire
		Out595.all = 0xFFFFFFFF;
		allInputStt_Cmp = allInputStt_default;

		//Lấy điều kiện so sánh của wire này
		bit_dk1 = pAF3RuleArr[i][1];
		bit_dk2 = pAF3RuleArr[i][2];
		bit_dk3 = pAF3RuleArr[i][3];
		//Nếu dk==0 thi bo qua khong check điều kiện đó
		allInputStt_Cmp = (bit_dk1) ? DbWord_cbi(allInputStt_Cmp, bit_dk1) : DbWord_sbi(allInputStt_Cmp, bit_dk1);
		allInputStt_Cmp = (bit_dk2) ? DbWord_cbi(allInputStt_Cmp, bit_dk2) : DbWord_sbi(allInputStt_Cmp, bit_dk2);
		allInputStt_Cmp = (bit_dk3) ? DbWord_cbi(allInputStt_Cmp, bit_dk3) : DbWord_sbi(allInputStt_Cmp, bit_dk3);

		//set mức thấp từng chân
		outputArray[pAF3RuleArr[i][0]](_LOW);
		shift_595_Word(Out595.all);
		delay_ms(10);
		//Đọc lại giá trị Input mới
		allInputStt = getAllPinStt();

		if(allInputStt != allInputStt_Cmp)
			sbi((pResult->all),i-1);//1 la lỗi
		else
			cbi((pResult->all),i-1);//0 la OK

//		//kiểm tra chéo dây dome
//		if(rbi(pResult->all,10-1) && rbi(pResult->all,11-1) && repeatDome==0){
//			tmp = pAF3RuleArr[10][1];
//			pAF3RuleArr[10][1] = pAF3RuleArr[11][1];
//			pAF3RuleArr[11][1] = tmp;
//			//test lai day nay
//			i = 10-1;
//			repeatDome = 1;
//		}
//
//		//kiểm tra chéo safety device
//		if(rbi(pResult->all,20-1) && rbi(pResult->all,28-1) && repeatSafety==0){
//			tmp = pAF3RuleArr[20][1];
//			pAF3RuleArr[20][1] = pAF3RuleArr[28][1];
//			pAF3RuleArr[28][1] = tmp;
//			//test lai day nay
//			i = 20-1;
//			repeatSafety = 1;
//		}
	}

}

void test_bus_AF3All(){
	static TIMER_vitual_t timer_togle_led;

	//if(TOOL.mode != _MODE_AF3) return;

	switch(TOOL.state){
		case _STATE_NONE: return;

		case _STATE_TEST:
			test_EachLine(BusRulesToCheckArr, &ErrorsReport);
			delay_ms(20);
			TOOL.state = _STATE_FINISHED;
			timer_set(&timer_togle_led, CLOCK_SECOND/2);
			break;

		case _STATE_FINISHED:
			if(ErrorsReport.all==0) {
				Out595.all = 0;
				timer_stop(&timer_togle_led);
				//sprintf(displayLCD[0].str_row1,"Day OK");
				TOOL.state = _STATE_NONE;
				OUTPUT_set_blink(&_BUZZER,1,CLOCK_SECOND/4,CLOCK_SECOND/10,0);
				return;
			}
			else {
				if(!timer_expired(&timer_togle_led))return;
				timer_restart(&timer_togle_led);
				//sprintf(displayLCD[0].str_row1,"Day Loi");

				for(uint8_t i=0; i<32; i++){
					//Nếu Line nào có lỗi thì nhấp nháy Line đó
					if(rbi(ErrorsReport.all,i)) tbi(Out595.all,i);
				}
				shift_595_Word(Out595.all);
			}
			break;
	}

}
