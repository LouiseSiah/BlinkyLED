#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO_TypeDef *port)
{
	GPIO_InitTypeDef GpioInfo;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	int *ptr = (int *) 0x40021800;
	ptr[0] = 0x14000000;				//MODE.pin14 = output
	ptr[1] = 0;							//OTYPE.pin14 = push-pull
	ptr[2] = 0x28000000;				//OSPeED.pin14 = high speed

	int *ptrB = (int *) 0x40020400;
	ptrB[0] = 0x04000000;				//MODE.pin14 = output
	ptrB[1] = 0;							//OTYPE.pin14 = push-pull
	ptrB[2] = 0x08000000;				//OSPeED.pin14 = high speed

//	GpioInfo.Pin = pinNum;
//	GpioInfo.Mode = direction;
//	GpioInfo.Speed = GPIO_SPEED_MEDIUM;
//	GpioInfo.Pull = GPIO_NOPULL;

//	HAL_GPIO_Init(port, &GpioInfo);

}

void writeOne(int pinNum, GPIO_TypeDef *port)
{
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
}

void writeZero(int pinNum, GPIO_TypeDef *port)
{
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_RESET);
}
