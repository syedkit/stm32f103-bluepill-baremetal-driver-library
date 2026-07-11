/******************************************************************************
 * @file    gpio.h
 * @brief   GPIO Driver Header File
 *
 * @author  S.I. SYED ARSHAD
 ******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include "stm32f103xx.h"


/******************************************************************************
 * GPIO Pin Definitions
 ******************************************************************************/

#define GPIO_PIN_0      0
#define GPIO_PIN_1      1
#define GPIO_PIN_2      2
#define GPIO_PIN_3      3
#define GPIO_PIN_4      4
#define GPIO_PIN_5      5
#define GPIO_PIN_6      6
#define GPIO_PIN_7      7
#define GPIO_PIN_8      8
#define GPIO_PIN_9      9
#define GPIO_PIN_10     10
#define GPIO_PIN_11     11
#define GPIO_PIN_12     12
#define GPIO_PIN_13     13
#define GPIO_PIN_14     14
#define GPIO_PIN_15     15

/******************************************************************************
 * GPIO Pin Modes
 ******************************************************************************/
#define GPIO_MODE_INPUT              0
#define GPIO_MODE_OUTPUT             1

/******************************************************************************
 * GPIO Pin Configurations
 ******************************************************************************/
#define GPIO_CONFIG_ANALOG           0
#define GPIO_CONFIG_FLOATING         1
#define GPIO_CONFIG_PULL             2
#define GPIO_CONFIG_PUSH_PULL        0
#define GPIO_CONFIG_OPEN_DRAIN       1
#define GPIO_CONFIG_AF_PUSH_PULL     2
#define GPIO_CONFIG_AF_OPEN_DRAIN    3

/******************************************************************************
 * GPIO Output Speeds
 ******************************************************************************/
#define GPIO_SPEED_10MHZ             1
#define GPIO_SPEED_2MHZ              2
#define GPIO_SPEED_50MHZ             3

/******************************************************************************
 * GPIO Pin Configuration Structure
 ******************************************************************************/

typedef struct
{
    uint8_t PinNumber;
    uint8_t PinMode;
    uint8_t PinConfiguration;
    uint8_t PinSpeed;

} GPIO_PinConfig_t;


typedef struct
{
    GPIO_TypeDef    *GPIOPort;
    GPIO_PinConfig_t PinConfig;

} GPIO_Handle_t;


/******************************************************************************
 * GPIO Driver APIs
 ******************************************************************************/

void GPIO_Init(GPIO_Handle_t *Handle);


/******************************************************************************
 * GPIO Driver APIs
 ******************************************************************************/

/* GPIO Configuration */
void GPIO_Init(GPIO_Handle_t *Handle);
void GPIO_Reset(GPIO_TypeDef *GPIOPort);

/* GPIO Input */
uint8_t GPIO_ReadInputPin(GPIO_TypeDef *GPIOPort,
                          uint8_t PinNumber);

uint16_t GPIO_ReadInputPort(GPIO_TypeDef *GPIOPort);

/* GPIO Output */
void GPIO_WriteOutputPin(GPIO_TypeDef *GPIOPort,
                         uint8_t PinNumber,
                         uint8_t Value);

void GPIO_WriteOutputPort(GPIO_TypeDef *GPIOPort,
                          uint16_t Value);

void GPIO_ToggleOutputPin(GPIO_TypeDef *GPIOPort,
                          uint8_t PinNumber);



#endif /* GPIO_H */
