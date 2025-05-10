#include "stm32f4xx_hal.h"
#include "main.h"
#include <string.h>


#define TRUE 1
#define FALSE 0









//PRIVATE FUNCTION DEFINITIONS
void SystemClockConfig();
void UART2_Init();
void Error_Handler();





UART_HandleTypeDef huart2;

char *DATA = "Application is running\r\n";
uint8_t data_buffer[100];
uint8_t rcvd_data;
uint32_t count = 0;
uint8_t reception_complete = FALSE;


int main(void)
{
	HAL_Init();
	SystemClockConfig();

	UART2_Init();


	uint32_t DATALEN = strlen(DATA);

	if(HAL_UART_Transmit(&huart2,(uint8_t*)DATA,DATALEN,HAL_MAX_DELAY) != HAL_OK)
	{
		Error_Handler();
	}


	// INTERRUPT BASED RECEIVE
	while(reception_complete != TRUE)
	{
	HAL_UART_Receive_IT(&huart2,&rcvd_data,1);
	}

	while(1);
	return 0;

}



void SystemClockConfig()
{

}
void Error_Handler()
{
	while(1);
}

void UART2_Init()
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		//ERROR
		Error_Handler();
	}

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(rcvd_data == '\r')
	{
		reception_complete = TRUE;
		data_buffer[count++]='\r';
		HAL_UART_Transmit(&huart2,data_buffer,count,HAL_MAX_DELAY);
	}
	else
	{
		data_buffer[count++] = rcvd_data;
	}

}
