#include "bsp_led.h"


void led_init(void)
{
	/* enable the LEDs GPIO clock */
  rcu_periph_clock_enable(RCU_GPIOC);
	
	/* configure LED2 GPIO port */
  gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_6);
  gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);

  /* reset LED2 GPIO pin */
  gpio_bit_reset(GPIOC, GPIO_PIN_6);
}

void led_on(void)
{
	/* turn on LED2 */
  gpio_bit_set(GPIOC, GPIO_PIN_6);
}

void led_off(void)
{
	/* turn off LED2 */
  gpio_bit_reset(GPIOC, GPIO_PIN_6);
}

void led_task(void *pvParameters)
{
	while(1)
	{
		led_on();
		vTaskDelay(500);
		
		led_off();
		vTaskDelay(500);
	}
	
}

