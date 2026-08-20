#include "servo.h"
#include <util/delay.h>

// 서보 위치
#define SERVO_CLOSE 125
#define SERVO_OPEN  500

static SERVO_STATE state = SERVO_IDLE;
static uint16_t servoPos = SERVO_CLOSE;

// 초기화
void Servo_Init(void)
{
	DDRB |= (1 << PB5);

	// Timer1 PWM
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);

	ICR1 = 4999;
	OCR1A = servoPos;
}

// 동작 시작 (버튼 눌렀을 때 호출)
void Servo_Start(void)
{
	if(state == SERVO_IDLE)
	{
		state = SERVO_OPENING;
	}
}

// 상태 업데이트 (계속 호출해야 함)
void Servo_Update(void)
{
	switch(state)
	{
		case SERVO_IDLE:
		break;

		case SERVO_OPENING:
		servoPos += 1;
		if(servoPos >= SERVO_OPEN)
		{
			servoPos = SERVO_OPEN;
			state = SERVO_WAIT;
		}
		OCR1A = servoPos;
		_delay_ms(30);
		break;

		case SERVO_WAIT:
		_delay_ms(1500);
		state = SERVO_CLOSING;
		break;

		case SERVO_CLOSING:
		servoPos -= 1;
		if(servoPos <= SERVO_CLOSE)
		{
			servoPos = SERVO_CLOSE;
			state = SERVO_IDLE;
		}
		OCR1A = servoPos;
		_delay_ms(30);
		break;
	}
}
void HandleServo(int count)
{
	static int prev = -1;

	if(count != prev)
	{
		Servo_Start();
		prev = count;
	}
}