#include "stm32f10x.h"
#include "mystuff.h"
//#include <string.h>
//#include <stdlib.h>
volatile uint16_t time;

//void SysTick_Handler();
void Blink(uint16_t test);
volatile uint32_t delay;
uint32_t test;
uint32_t adc_read;


int main()
{
	/* Enable clock for PORTC */ 
	
	RCC->APB2ENR = (RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_ADC1EN);
	GpioConfig(GPIOC, GPIO_Pin_13, gpio_mode_output_PP_2MHz);
	//GpioConfig(GPIOC, GPIO_Pin_13, gpio_mode_output_PP_2MHz);
	GpioConfig(GPIOA, GPIO_Pin_0, gpio_mode_input_analog);
	/*Wake up ADC */ 
	ADC1->CR2 = ADC_CR2_ADON|ADC_CR2_JEXTTRIG|ADC_CR2_JEXTSEL_0|ADC_CR2_JEXTSEL_1|ADC_CR2_JEXTSEL_2;
	// select mode: JSWSTART to start conversion
	//JSWSTART to start conversion
	//ADC1->JSQR = ADC_JSQR_JSQ4_4
	for(delay = 100000; delay; delay--);
	/* Select channel 0 */ 
	//ADC1->SQR3 = 0;
	
	SysTick_Config(8000000*0.5);
	
		
while(1){
	GPIOC->BSRR = GPIO_BSRR_BS13; // stan wysoki
	for(delay = 1000000; delay; delay--){};
	GPIOC->BSRR = GPIO_BSRR_BR13; // stan niski
			/* Start conversion */ 
	//ADC1->CR2 = ADC_CR2_JSWSTART|ADC_CR2_SWSTART;
	//ADC1->CR2 = ADC_CR2_ADON;
			/* Wait for result */ 
//	while(!(ADC1->SR & ADC_SR_JEOC))
//		adc_read = ADC1->DR;
	for(delay = 1000000; delay; delay--){};
	}
}


//void SysTick_Handler()
//{
//	if(time)
//		time--;
//}

void SysTick_Handler(void){
	
	//BITBAND(GPIOC->ODR, GPIO_ODR_ODR13) = 1;
	//varSetBit(GPIOC->ODR, GPIO_ODR_ODR13);
		
}

void Blink(uint16_t test)
{
	while(time != 0);
}




 
