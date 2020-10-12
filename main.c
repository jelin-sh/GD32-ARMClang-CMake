#include "gd32f30x.h"

#define LED0_GPIO_PORT GPIOD
#define LED0_GPIO_PIN  GPIO_PIN_2

/**
 * @addtogroup BSP
*/
void LED_Init(void)
{
    rcu_periph_clock_enable(RCU_GPIOD);
    gpio_init(LED0_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_10MHZ, LED0_GPIO_PIN);
}

void LED_On(void)
{
    gpio_bit_set(LED0_GPIO_PORT, LED0_GPIO_PIN);
}

void LED_Off(void)
{
    gpio_bit_reset(LED0_GPIO_PORT, LED0_GPIO_PIN);
}

/**
 * @endgroup
*/

void Delay()
{
    for (uint8_t i = 0; i < 0xff; i++) {
        for (uint32_t j = 0; j < 0xffff; j++) {
            asm("nop");
        }
    }
}

/**
 * @brief 程序入口函数
*/
int main()
{
    LED_Init();
    LED_On();
    while (1) {
        Delay();
        LED_On();
        Delay();
        LED_Off();
    }
}
