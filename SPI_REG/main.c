#include "stm32f10x.h"
#include "mystuff.h"
#include "fxas21002c.h"
#include "spi.h"
volatile uint16_t time;

//#define CS_LOW (GPIOA->BSRR = GPIO_BSRR_BR4)
//#define CS_HIGH (GPIOA->BSRR = GPIO_BSRR_BS4)

//void SysTick_Handler();
void Blink(uint16_t test);
volatile uint32_t delay;
uint32_t test;
uint16_t buf;

void GpioInit(void);

int main()
{
	GpioInit();
	SpiInit();

	
while(1){


	CS_LOW();
	SpiTransmit(FXAS21002C_H_WHO_AM_I, 1);
	buf = SpiTransmit(0xFF, 6);
	CS_HIGH();
	for(delay = 1000000; delay; delay--){};

	}
}

void GpioInit(void){
	GpioConfig(GPIOC, GPIO_Pin_13, gpio_mode_output_PP_2MHz);
	GpioConfig(GPIOA, GPIO_Pin_0, gpio_mode_input_floating);
	
}



void Blink(uint16_t test)
{
	while(time != 0);
}

 
