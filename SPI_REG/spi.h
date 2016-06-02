#include "stm32f10x.h"



extern uint8_t SpiRxBuffer[6];

void SpiInit(void);
void CS_LOW(void);
void CS_HIGH(void);
uint8_t SpiTransmit(uint8_t data, uint8_t count);
