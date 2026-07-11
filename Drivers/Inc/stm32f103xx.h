/******************************************************************************
 * @file    stm32f103xx.h
 * @brief   Common device header for STM32F103C8T6 (Blue Pill)
 *
 * @author  S.I. SYED ARSHAD
 * @version 1.0.0
 * @date    July 2026
 *
 * @target  STM32F103C8T6 (Blue Pill)
 * @toolchain GNU Arm Embedded Toolchain
 *
 * Copyright (c) 2026 S.I. SYED ARSHAD
 ******************************************************************************/

#ifndef STM32F103XX_H
#define STM32F103XX_H
#include <stdint.h>

//Memory Base Address

#define FLASH_BASE     0x08000000UL
#define SRAM_BASE      0x20000000UL
#define PERIPH_BASE    0x40000000UL

// Bus Base Addresses

#define APB1PERIPH_BASE    PERIPH_BASE
#define APB2PERIPH_BASE    (PERIPH_BASE + 0x10000UL)
#define AHBPERIPH_BASE     (PERIPH_BASE + 0x20000UL)

// APB2 Peripheral Base Addresses

#define AFIO_BASE       (APB2PERIPH_BASE + 0x0000UL)
#define EXTI_BASE       (APB2PERIPH_BASE + 0x0400UL)
#define GPIOA_BASE      (APB2PERIPH_BASE + 0x0800UL)
#define GPIOB_BASE      (APB2PERIPH_BASE + 0x0C00UL)
#define GPIOC_BASE      (APB2PERIPH_BASE + 0x1000UL)
#define GPIOD_BASE      (APB2PERIPH_BASE + 0x1400UL)
#define GPIOE_BASE      (APB2PERIPH_BASE + 0x1800UL)
#define RCC_BASE        (AHBPERIPH_BASE  + 0x1000UL)



/******************************************************************************
 * GPIO Register Definition Structure
 ******************************************************************************/

typedef struct
{
    volatile uint32_t CRL;    // Configuration Register Low          Offset: 0x00 
    volatile uint32_t CRH;    // Configuration Register High         Offset: 0x04 
    volatile uint32_t IDR;    // Input Data Register                 Offset: 0x08 
    volatile uint32_t ODR;    // Output Data Register                Offset: 0x0C 
    volatile uint32_t BSRR;   // Bit Set/Reset Register              Offset: 0x10 
    volatile uint32_t BRR;    // Bit Reset Register                  Offset: 0x14 
    volatile uint32_t LCKR;   // Configuration Lock Register         Offset: 0x18 
} GPIO_TypeDef;

/******************************************************************************
 * GPIO Peripheral Definitions
 ******************************************************************************/

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)





/******************************************************************************
 * RCC Register Definition Structure
 ******************************************************************************/

typedef struct
{
    volatile uint32_t CR;          /* Offset: 0x00 */
    volatile uint32_t CFGR;        /* Offset: 0x04 */
    volatile uint32_t CIR;         /* Offset: 0x08 */
    volatile uint32_t APB2RSTR;    /* Offset: 0x0C */
    volatile uint32_t APB1RSTR;    /* Offset: 0x10 */
    volatile uint32_t AHBENR;      /* Offset: 0x14 */
    volatile uint32_t APB2ENR;     /* Offset: 0x18 */
    volatile uint32_t APB1ENR;     /* Offset: 0x1C */
    volatile uint32_t BDCR;        /* Offset: 0x20 */
    volatile uint32_t CSR;         /* Offset: 0x24 */
} RCC_TypeDef;


/******************************************************************************
 * RCC Peripheral Definition
 ******************************************************************************/

#define RCC ((RCC_TypeDef *)RCC_BASE)




/******************************************************************************
 * GPIO Reset Macros
 ******************************************************************************/

#define GPIOA_RESET()   (RCC->APB2RSTR |=  (1U << 2), RCC->APB2RSTR &= ~(1U << 2))
#define GPIOB_RESET()   (RCC->APB2RSTR |=  (1U << 3), RCC->APB2RSTR &= ~(1U << 3))
#define GPIOC_RESET()   (RCC->APB2RSTR |=  (1U << 4), RCC->APB2RSTR &= ~(1U << 4))
#define GPIOD_RESET()   (RCC->APB2RSTR |=  (1U << 5), RCC->APB2RSTR &= ~(1U << 5))
#define GPIOE_RESET()   (RCC->APB2RSTR |=  (1U << 6), RCC->APB2RSTR &= ~(1U << 6))



#endif /* STM32F103XX_H */
