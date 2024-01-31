#include "hc595.h"

void shift_595_Byte(uint8_t byte){
    for(uint8_t i=8; i>0; i--)
    {
        if (byte&(1<<(i-1)))
        	HC595_DATA(1);
        else
        	HC595_DATA(0);
        HC595_SCK(0);
        HC595_SCK(1);
    }
    HC595_LATCH(0);
    HC595_LATCH(1);
}

void shift_595_Word(uint32_t word){
    for(uint8_t i=32; i>0; i--)
    {
        if (word&(1<<(i-1)))
        	HC595_DATA(1);
        else
        	HC595_DATA(0);
        HC595_SCK(0);
        HC595_SCK(1);
    }
    HC595_LATCH(0);
    HC595_LATCH(1);
}

void shift_595_Dword(uint64_t dword){
    for(uint8_t i=64; i>0; i--)
    {
        if (dword&(1<<(i-1)))
        	HC595_DATA(1);
        else
        	HC595_DATA(0);
        HC595_SCK(0);
        HC595_SCK(1);
    }
    HC595_LATCH(0);
    HC595_LATCH(1);
}

void shift_595_array(uint8_t byteArray[HC595_USED_NUM])
{
	for(uint8_t i = HC595_USED_NUM; i >0; i--)
	{
		for(uint8_t k=8; k>0; k--)
		{
			if(byteArray[i-1] & (1<<(k-1)))
				HC595_DATA(1);
			else
				HC595_DATA(0);

			HC595_SCK(0);
			HC595_SCK(1);
		}
	}
	HC595_LATCH(0);
    HC595_LATCH(1);
}

void test_595(uint8_t logic){
	uint8_t i;
	uint8_t testByte;
	uint32_t testWord;
	uint64_t testDword;
	uint8_t testArray[HC595_USED_NUM];

	//set as Logic all
	if(logic){
		testByte = 0;
		testWord = 0;
		testDword = 0;
		for(i=0; i<HC595_USED_NUM; i++) testArray[i]=0;
	}
	else
	{
		testByte = 0xFF;
		testWord = 0xFFFFFFFF;
		testDword = 0xFFFFFFFFFFFFFFF;
		for(i=0; i<HC595_USED_NUM; i++) testArray[i]=0xFF;
	}

	//check byte
	for(i=0; i<8; i++){
		wbi(testByte,i,logic);
		shift_595_Byte(testByte);
		delay_ms(1000);
	}

	//check testWord
	for(i=0; i<32;i++){
		wbi(testWord,i,logic?0:1);
		shift_595_Word(testWord);
		delay_ms(1000);
	}

	//check test Double Word
	for(i=0; i<32;i++){
		wbi(testDword,i,logic?0:1);
		shift_595_Dword(testDword);
		delay_ms(1000);
	}

	//check test Array
	for(uint8_t k=0;k<HC595_USED_NUM;k++){
		for(i=0;i<8;i++){
			wbi(testArray[k],i,logic);
			shift_595_array(testArray);
		}
	}
}
