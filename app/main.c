#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "Gpio.h"
//#include <stdint.h>

//void configurePin(GPIO_TypeDef *port, uint32_t pinNumber)
//{
//	GPIO_InitTypeDef gpio;
//	gpio.Pin = GPIO_PIN_13;
//	gpio.Mode = GPIO_MODE_OUTPUT_PP;
//	gpio.Speed = GPIO_SPEED_MEDIUM;
//	HAL_GPIO_Init(port, &gpio);
//
//}
void delay(uint32_t delayCount)
{
	while(delayCount != 0)
		delayCount--;
}

int main(void)
{
//	int a = 4;
//	double d = 5.6789123;

//	d = d * a + 1.987654321;

	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTG);
	configurePin(GPIO_OUTPUT, PIN_14, GPIOG);
	configurePin(GPIO_OUTPUT, PIN_13, GPIOB);
	configurePin(GPIO_OUTPUT, PIN_5, GPIOC);

    while(1)
    {
    	delay(200000);
    	writeOne(GPIO_PIN_13, GPIOG);
    	delay(200000);
    	writeZero(GPIO_PIN_13, GPIOG);
    	delay(200000);
    	writeOne(GPIO_PIN_14, GPIOG);
    	delay(200000);
    	writeZero(GPIO_PIN_14, GPIOG);
    	delay(200000);
    	writeOne(GPIO_PIN_13, GPIOB);
    	delay(200000);
    	writeZero(GPIO_PIN_13, GPIOB);
    	delay(200000);
    	writeZero(GPIO_PIN_5, GPIOC);
    	delay(200000);
    	writeOne(GPIO_PIN_5, GPIOC);

    }
//    	turnOnLED(PORTG, LED3);
//    	turnOffLED(PORTG, LED3);
//    	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
}
