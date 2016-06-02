#include "stm32f10x.h"
#include "mystuff.h"

//uint16_t ctz(uint16_t pin){
//	uint16_t var;
//	while(pin>>=1) ++var;
//	return var;
//}

//void GpioConfig(GPIO_TypeDef * const port, uint16_t pin, GpioMode_t mode){
//	//new_var = pin while(new_var>>=1) ++pin;
//	uint32_t volatile * cr_reg;
//	uint32_t cr_val;
//	pin = ctz(pin)*4;
//	cr_reg = &port->CRL;
//	
//	if (pin > 28){
//		pin -= 32;
//		cr_reg = &port->CRH;
//	}
//	
//	cr_val = *cr_reg;
//	cr_val &= ~((uint32_t)(0x0f << pin));
//	cr_val |= (uint32_t)(mode << pin);
//	*cr_reg = cr_val;
//}


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
