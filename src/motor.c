#define F_CPU 16000000UL
#include "motor.h"
#include <util/delay.h>
// PWM 초기화 (Timer0 사용)
static int prev_count = 0;
void Motor_Init(void)
{
	DDRB |= (1 << PB4);  // OC0 핀 (보드에 따라 다름)
	// Fast PWM
	TCCR0 |= (1 << WGM00) | (1 << WGM01);
	TCCR0 |= (1 << COM01); // non-inverting
	TCCR0 |= (1 << CS01)|(1<<CS00); 
	OCR0 = 0; // 초기 정지
}
// 속도 설정
void Motor_SetSpeed(uint8_t level)
{

	switch(level)
	{
		case 0: OCR0 = 0; break;    // 정지
		case 1: OCR0 = 40; break;   // 1단
		case 2: OCR0 = 60; break;  // 2단
		case 3: OCR0 = 255; break;  // 3단
	}
	
}

// count 기반 자동 설정
void Motor_UpdateByCount(int count)
{
	if(count == 0)
	{
		Motor_SetSpeed(0);
	}
	else if(count <= 1)
	{
		 if(prev_count == 0 && count > 0)
		 {
			 Motor_SetSpeed(3);   // 부스트
			 _delay_ms(50);       // 100ms 정도 (환경에 맞게 조절)
		 }
		Motor_SetSpeed(1);
	}
	else if(count <= 2)
	{
		Motor_SetSpeed(2);
	}
	else
	{
		Motor_SetSpeed(3);
	}
	prev_count = count;
}