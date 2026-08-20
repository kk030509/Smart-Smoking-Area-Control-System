#include "segment.h"
#include <util/delay.h>
// 숫자 패턴 (공통 캐소드 기준)
uint8_t segData[] = {
	0x3F, // 0 0011 1111 
	0x06, // 1 0000 0110
	0x5B, // 2 0101 1011
	0x4F, // 3 0010 1111
	0x66, // 4 0110 0110
	0x6D, // 5 0110 1101
	0x7D, // 6 0111 1101
	0x07, // 7 0000 0111
	0x7F, // 8 0111 1111
	0x6F  // 9 0110 1111
};
// 문자 (F, U, L)
#define SEG_F 0x71 //0111 0001
#define SEG_U 0x3E //0011 1110
#define SEG_L 0x38 //0011 1000
void SEG_Init(void)
{
	DDRC = 0xFF; // 세그먼트 데이터
	DDRA = 0x0F; // 자리 선택 (A0~A3)
}

// 한 자리 출력
void SEG_Output(uint8_t digit, uint8_t data)
{
	PORTA = ~(1 << digit); // 자리 선택 (active low 가정)
	PORTC = data;
	_delay_ms(2);
}

// 숫자 출력
void SEG_DisplayNumber(uint16_t num)
{
	uint8_t d[4];

	if(num <= 5)
	{
		d[0] = (num / 1000) % 10;
		d[1] = (num / 100) % 10;
		d[2] = (num / 10) % 10;
		d[3] = num % 10;

		if(num<10)
		{
			SEG_Output(0,0x00);
			SEG_Output(1,0x00);
			SEG_Output(2, 0x00);
			SEG_Output(3,segData[d[3]]);
		}
		else
		{
			SEG_Output(0,0x00);
			SEG_Output(1,0x00);
			SEG_Output(2,segData[d[2]]);
			SEG_Output(3,segData[d[3]]);
		}
	}
	else
	{
		// FULL 표시
		SEG_Output(0, SEG_F);
		SEG_Output(1, SEG_U);
		SEG_Output(2, SEG_L);
		SEG_Output(3, SEG_L);
	}
}