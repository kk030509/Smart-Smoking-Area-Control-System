#ifndef SERVO_H
#define SERVO_H
#include <avr/io.h>
// 상태 정의
typedef enum {
	SERVO_IDLE,
	SERVO_OPENING,
	SERVO_WAIT,
	SERVO_CLOSING
} SERVO_STATE;
// 함수
void Servo_Init(void);
void Servo_Start(void);
void Servo_Update(void);
void HandleServo(int count);
#endif
