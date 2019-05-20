#ifndef __stepmotor_h
#define __stepmotor_h

#include "stm32f10x.h"
#include "delay_tim4.h"

#define FULL_STEP									1
#define HALF_STEP									2
#define QUARTER_STEP							4
#define EIGHTH_STEP								8
#define SIXTEENTH_STEP						16

typedef enum
{
	CW = 0,
	CCW = 1
} Direction;

typedef enum
{
	true = 0,
	false = 1
} Status;

void stepmotor_init(void);
void set_resolution(uint8_t resolution);
void set_direction(Direction dir);
void set_step(uint32_t number, Direction direction, uint16_t speed, uint32_t *current_position);
void set_start_position(void);

#endif
