#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>

void Motor_Init(void);
void Motor_SetSpeed(uint8_t level);
void Motor_UpdateByCount(int count);

#endif