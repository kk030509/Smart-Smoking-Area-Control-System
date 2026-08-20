#include "button.h"
#include <util/delay.h>

void Button_Init(BUTTON *button, volatile uint8_t *ddr, 
volatile uint8_t *pin, volatile uint8_t *port, uint8_t pinNum)
{
	button->ddr = ddr;
	button->pin = pin;
	button->port = port;
	button->btnPin = pinNum;
	button->prevState = RELEASED;
	*button->ddr &= ~(1 << button->btnPin);   // 입력 설정
	*button->port |= (1 << button->btnPin);   // 내부 풀업
}

uint8_t Button_GetState(BUTTON *button)
{
	uint8_t currState;
	// 눌림=0
	currState = (*button->pin & (1 << button->btnPin)) ? RELEASED : PUSHED;
	if((currState == PUSHED) && (button->prevState == RELEASED))
	{
		_delay_ms(10);
		button->prevState = PUSHED;
		return ACT_PUSH;
	}
	else if((currState == RELEASED) && (button->prevState == PUSHED))
	{
		_delay_ms(10);
		button->prevState = RELEASED;
		return ACT_RELEASE;
	}
	return NO_ACT;
}
