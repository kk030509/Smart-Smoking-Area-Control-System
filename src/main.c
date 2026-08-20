#define F_CPU 16000000UL
#include <avr/io.h>
#include "button.h"
#include "segment.h"
#include "servo.h"
#include "motor.h"
int main()
{
	SEG_Init();
	BUTTON btnUp, btnDown;
	Button_Init(&btnUp, &DDRG, &PING, &PORTG, 0);
	Button_Init(&btnDown, &DDRG, &PING, &PORTG, 1);
	Servo_Init();
	Motor_Init();

	int count = 0;
	while(1)
	{
		// UP버튼 -> 카운트 증가
		if(Button_GetState(&btnUp) == ACT_RELEASE)
		{
			count++;
		}

		// DOWN버튼 -> 카운트 감소
		if(Button_GetState(&btnDown) == ACT_RELEASE)
		{
			if(count > 0) 
			count--;
		}
		
		SEG_DisplayNumber(count);
		HandleServo(count);
		Servo_Update();
		Motor_UpdateByCount(count);
	}
} 
