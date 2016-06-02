#ifndef __MYSTUFF_H
#define __MYSTUFF_H


#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */


/*
+=============================================================================+
| global definitions
+=============================================================================+
*/

#define BITBAND_SRAM_REF   					0x20000000
#define BITBAND_SRAM_BASE  					0x22000000

#define BITBAND_PERIPH_REF   				0x40000000
#define BITBAND_PERIPH_BASE  				0x42000000

/*
+=============================================================================+
| strange variables
+=============================================================================+
*/

#define bitband_t *(volatile unsigned long*)

/*
+=============================================================================+
| macros
+=============================================================================+
*/

#define BITBAND_SRAM(address, bit)			(BITBAND_SRAM_BASE + (((unsigned long)address) - BITBAND_SRAM_REF) * 32 + (bit) * 4)
#define BITBAND_PERIPH(address, bit)		(BITBAND_PERIPH_BASE + (((unsigned long)address) - BITBAND_PERIPH_REF) * 32 + (bit) * 4)
#define BITBAND(address, bit)				( \
	(((unsigned long)address) >= 0x20000000) && (((unsigned long)address) <= 0x200FFFFF) ? BITBAND_SRAM(address, bit) : \
	(((unsigned long)address) >= 0x40000000) && (((unsigned long)address) <= 0x400FFFFF) ? BITBAND_PERIPH(address, bit) : \
	0 /* fail */ \
	)

// old-style deprecated aliases
	
#define m_BITBAND_SRAM(address, bit)		BITBAND_SRAM(address, bit)
#define m_BITBAND_PERIPH(address, bit)		BITBAND_PERIPH(address, bit)

/******************************************************************************
* END OF FILE
******************************************************************************/
// bitband 2

#define RAM_BASE       0x20000000
#define RAM_BB_BASE    0x22000000
#define Var_ResetBit_BB(VarAddr, BitNumber)  (*(volatile unsigned int *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) < < 5) | ((BitNumber) << 2)) = 0)
#define Var_SetBit_BB(VarAddr, BitNumber)    (*(volatile unsigned int *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 1)
#define Var_GetBit_BB(VarAddr, BitNumber)    (*(volatile unsigned int *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)))

#define varSetBit(var,bit) (Var_SetBit_BB((unsigned int)&var,bit)) 
#define varGetBit(var,bit) (Var_GetBit_BB((unsigned int)&var,bit))
#define varResetBit(var,bit) (Var_ResetBit_BB((unsigned int)&var,bit)) 	
	

typedef enum GpioMode{
/* Push-Pull */
gpio_mode_output_PP_2MHz = 2,
gpio_mode_output_PP_10MHz = 1,
gpio_mode_output_PP_50MHz = 3,
/* Open-Drain */
gpio_mode_output_OD_2MHz = 6,
gpio_mode_output_OD_10MHz = 5,
gpio_mode_output_OD_50MHz = 7,
/* Push-Pull */
gpio_mode_alternate_PP_2MHz = 10,
gpio_mode_alternate_PP_10MHz = 9,
gpio_mode_alternate_PP_50MHz = 11,
/* Open-Drain */
gpio_mode_alternate_OD_2MHz = 14,
gpio_mode_alternate_OD_10MHz = 13,
gpio_mode_alternate_OD_50MHz = 15,
/* Analog input (ADC) */
gpio_mode_input_analog = 0,
/* Floating digital input. */
gpio_mode_input_floating = 4,
/* Digital input with pull-up/down (depending on the ODR reg.). */
gpio_mode_input_pull = 8
} GpioMode_t;



void GpioConfig(GPIO_TypeDef * const port, uint16_t pin, GpioMode_t mode);
uint16_t ctz(uint16_t pin);
#endif /*__MYSTUFF_H */
