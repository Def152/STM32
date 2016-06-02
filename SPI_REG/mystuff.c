#include "stm32f10x.h"
#include "mystuff.h"


void GpioConfig(GPIO_TypeDef * const port, uint16_t pin, GpioMode_t mode){
	uint16_t p = 0;
	uint32_t volatile * cr_reg;
	uint32_t cr_val;
	while(pin>>=1)
		p+=4;
	 pin = p;
	 cr_reg = &port->CRL;
	 if (pin > 28){
		 pin -= 32;
		 cr_reg = &port->CRH;
	 }
	 cr_val = *cr_reg;
	 cr_val &= ~((uint32_t)(0x0f << pin));
	 cr_val |= (uint32_t)(mode << pin);
	 *cr_reg = cr_val;
}
