/******************************************************************************
 * @file    main.c
 * @brief   LED Blink Example using GPIO Driver
 *
 * @author  S.I. SYED ARSHAD
 ******************************************************************************/

#include "gpio.h"

/* Simple Software Delay */
static void Delay(void)
{
    for (volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    GPIO_Handle_t LED;

    /* Select GPIO Port */
    LED.GPIOPort = GPIOC;

    /* Configure PC13 */
    LED.PinConfig.PinNumber = GPIO_PIN_13;
    LED.PinConfig.PinMode = GPIO_MODE_OUTPUT;
    LED.PinConfig.PinConfiguration = GPIO_CONFIG_PUSH_PULL;
    LED.PinConfig.PinSpeed = GPIO_SPEED_2MHZ;

    /* Initialize GPIO */
    GPIO_Init(&LED);

    while (1)
    {
        GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_13);
        Delay();
    }
}
