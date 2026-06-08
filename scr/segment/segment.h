#ifndef SEGMENT_H_
#define SEGMENT_H_
#include <avr/io.h>
#include <stdint.h>

void SEG_Init(void);
void SEG_DisplayNumber(uint16_t num);


#endif /* SEGMENT_H_ */