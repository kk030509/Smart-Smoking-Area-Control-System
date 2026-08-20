#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>
#include <stdint.h>

enum {PUSHED, RELEASED};

enum {
	NO_ACT,
	ACT_PUSH,
	ACT_RELEASE
};

typedef struct {
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	volatile uint8_t *port;
	uint8_t btnPin;
	uint8_t prevState;
} BUTTON;

void Button_Init(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, volatile uint8_t *port, uint8_t pinNum);
uint8_t Button_GetState(BUTTON *button);

#endif