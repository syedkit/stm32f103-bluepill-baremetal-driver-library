/******************************************************************************
 * @file    gpio.c
 * @brief   GPIO Driver Source File
 *
 * @author  S.I. SYED ARSHAD
 ******************************************************************************/

#include "gpio.h"

/******************************************************************************
 * @brief   Initializes the selected GPIO pin
 * @param   Handle : Pointer to GPIO handle
 * @return  None
 ******************************************************************************/
void GPIO_Init(GPIO_Handle_t *Handle)
{

    GPIO_TypeDef *GPIOPort = Handle->GPIOPort;
   if (GPIOPort == GPIOA)
{
    RCC->APB2ENR |= (1 << 2);
}
else if (GPIOPort == GPIOB)
{
    RCC->APB2ENR |= (1 << 3);
}
else if (GPIOPort == GPIOC)
{
    RCC->APB2ENR |= (1 << 4);
}
else if (GPIOPort == GPIOD)
{
    RCC->APB2ENR |= (1 << 5);
}
else if (GPIOPort == GPIOE)
{
    RCC->APB2ENR |= (1 << 6);
}



uint32_t configValue = 0;

/* Prepare the 4-bit GPIO configuration value */
if (Handle->PinConfig.PinMode == GPIO_MODE_OUTPUT)
{
    configValue = (Handle->PinConfig.PinConfiguration << 2) |
                  Handle->PinConfig.PinSpeed;
}
else
{
    configValue = (Handle->PinConfig.PinConfiguration << 2);
}

/* Configure CRL (Pins 0 - 7) */
if (Handle->PinConfig.PinNumber < 8)
{
    uint8_t bitPosition = Handle->PinConfig.PinNumber * 4;

    /* Clear existing configuration */
    GPIOPort->CRL &= ~(0x0FU << bitPosition);

    /* Write new configuration */
    GPIOPort->CRL |= (configValue << bitPosition);
}

/* Configure CRH (Pins 8 - 15) */
else
{
    uint8_t bitPosition = (Handle->PinConfig.PinNumber - 8) * 4;

    /* Clear existing configuration */
    GPIOPort->CRH &= ~(0x0FU << bitPosition);

    /* Write new configuration */
    GPIOPort->CRH |= (configValue << bitPosition);
}

}


/******************************************************************************
 * @brief   Reset GPIO peripheral
 * @param   GPIOPort : Pointer to GPIO Port
 * @return  None
 ******************************************************************************/
/******************************************************************************
 * @brief   Reset GPIO peripheral
 * @param   GPIOPort : Pointer to GPIO Port
 * @return  None
 ******************************************************************************/
void GPIO_Reset(GPIO_TypeDef *GPIOPort)
{
    if (GPIOPort == GPIOA)
    {
        GPIOA_RESET();
    }
    else if (GPIOPort == GPIOB)
    {
        GPIOB_RESET();
    }
    else if (GPIOPort == GPIOC)
    {
        GPIOC_RESET();
    }
    else if (GPIOPort == GPIOD)
    {
        GPIOD_RESET();
    }
    else if (GPIOPort == GPIOE)
    {
        GPIOE_RESET();
    }
}


/******************************************************************************
 * @brief   Read GPIO Input Pin
 * @param   GPIOPort  : Pointer to GPIO Port
 * @param   PinNumber : GPIO Pin Number
 * @return  0 or 1
 ******************************************************************************/
uint8_t GPIO_ReadInputPin(GPIO_TypeDef *GPIOPort,
                          uint8_t PinNumber)
{
    uint8_t pinState;

    pinState = (GPIOPort->IDR >> PinNumber) & 0x01U;

    return pinState;
}

/******************************************************************************
 * @brief   Read GPIO Input Port
 * @param   GPIOPort : Pointer to GPIO Port
 * @return  16-bit Port Value
 ******************************************************************************/
uint16_t GPIO_ReadInputPort(GPIO_TypeDef *GPIOPort)
{
    return (uint16_t)(GPIOPort->IDR);
}

/******************************************************************************
 * @brief   Write GPIO Output Pin
 * @param   GPIOPort  : Pointer to GPIO Port
 * @param   PinNumber : GPIO Pin Number
 * @param   Value     : 0 = LOW, 1 = HIGH
 * @return  None
 ******************************************************************************/
void GPIO_WriteOutputPin(GPIO_TypeDef *GPIOPort,
                         uint8_t PinNumber,
                         uint8_t Value)
{
    if (Value)
    {
        GPIOPort->BSRR = (1U << PinNumber);
    }
    else
    {
        GPIOPort->BSRR = (1U << (PinNumber + 16));
    }
}

/******************************************************************************
 * @brief   Write GPIO Output Port
 * @param   GPIOPort : Pointer to GPIO Port
 * @param   Value    : 16-bit Output Value
 * @return  None
 ******************************************************************************/
void GPIO_WriteOutputPort(GPIO_TypeDef *GPIOPort,
                          uint16_t Value)
{
    GPIOPort->ODR = Value;
}


/******************************************************************************
 * @brief   Toggle GPIO Output Pin
 ******************************************************************************/
void GPIO_ToggleOutputPin(GPIO_TypeDef *GPIOPort,
                          uint8_t PinNumber)
{
    GPIOPort->ODR ^= (1U << PinNumber);
}
