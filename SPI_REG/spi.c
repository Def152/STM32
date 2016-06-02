#include "stm32f10x.h"
#include "mystuff.h"
#include "spi.h"


uint8_t SpiRxBuffer[6] = {1, 2, 3, 4 ,5, 6};

void SpiInit(void){
	/* Enable clock */ 
	RCC->APB2ENR = (RCC_APB2ENR_SPI1EN|RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPCEN);
	
	GpioConfig(GPIOA, GPIO_Pin_4, gpio_mode_output_PP_10MHz); 		/* GPIO */
	GpioConfig(GPIOA, GPIO_Pin_5, gpio_mode_alternate_PP_10MHz); 	/* SCK */
	GpioConfig(GPIOA, GPIO_Pin_6, gpio_mode_input_pull); 					/* MISO */
	GpioConfig(GPIOA, GPIO_Pin_7, gpio_mode_alternate_PP_10MHz); 	/* MOSI */
	CS_HIGH();
	
	/* software CS pin, enable spi, master mode*/
	SPI1->CR1 = SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_SPE | SPI_CR1_MSTR | SPI_CR1_BR_0 |SPI_CR1_BR_1;
}

uint8_t SpiTransmit(uint8_t data, uint8_t count){
	for(uint8_t i = 0; i < count; i++){
		while( !(SPI1->SR & SPI_SR_TXE) ); // is transmit reg empty
		SPI1->DR = data;
		while( !(SPI1->SR & SPI_SR_RXNE) );
		SpiRxBuffer[i] = SPI1->DR;
	}
		return *SpiRxBuffer;
}

__inline void CS_LOW(void){ 
	GPIOA->BSRR = GPIO_BSRR_BR4;
}
__inline void CS_HIGH(void){
	while(SPI1->SR & SPI_SR_BSY);
	GPIOA->BSRR = GPIO_BSRR_BS4;
}
