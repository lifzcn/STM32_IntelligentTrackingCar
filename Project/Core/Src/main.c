/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "hcsr04.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	float frontDistanceValue = 0;
	float backDistanceValue = 0;
	float leftDistanceValue = 0;
	float rightDistanceValue = 0;
	uint8_t distanceLimitValue = 10;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		frontDistanceValue = HCSR04_Front_GetDistance_Repeatedly(5);
		backDistanceValue = HCSR04_Back_GetDistance_Repeatedly(5);
		leftDistanceValue = HCSR04_Left_GetDistance_Repeatedly(5);
		rightDistanceValue = HCSR04_Right_GetDistance_Repeatedly(5);
		if(frontDistanceValue>=distanceLimitValue && backDistanceValue>=distanceLimitValue && leftDistanceValue>=distanceLimitValue && rightDistanceValue>=distanceLimitValue)
		{
			HAL_GPIO_WritePin(Front_IN1_GPIO_Port, Front_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Front_IN2_GPIO_Port, Front_IN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Back_IN1_GPIO_Port, Back_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Back_IN2_GPIO_Port, Back_IN2_Pin, GPIO_PIN_RESET);
		}
		else
		{
			if(HAL_GPIO_ReadPin(InfraredSensor_3_GPIO_Port, InfraredSensor_3_Pin) == GPIO_PIN_RESET)
			{
				HAL_GPIO_WritePin(Front_IN1_GPIO_Port, Front_IN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Front_IN2_GPIO_Port, Front_IN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Back_IN1_GPIO_Port, Back_IN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Back_IN2_GPIO_Port, Back_IN2_Pin, GPIO_PIN_SET);
			}
			else if(HAL_GPIO_ReadPin(InfraredSensor_1_GPIO_Port, InfraredSensor_1_Pin) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(InfraredSensor_2_GPIO_Port, InfraredSensor_2_Pin) == GPIO_PIN_RESET)
			{
				HAL_GPIO_WritePin(Front_IN1_GPIO_Port, Front_IN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Front_IN2_GPIO_Port, Front_IN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Back_IN1_GPIO_Port, Back_IN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Back_IN2_GPIO_Port, Back_IN2_Pin, GPIO_PIN_SET);
			}
			else if(HAL_GPIO_ReadPin(InfraredSensor_4_GPIO_Port, InfraredSensor_4_Pin) == GPIO_PIN_RESET || HAL_GPIO_ReadPin(InfraredSensor_5_GPIO_Port, InfraredSensor_5_Pin) == GPIO_PIN_RESET)
			{
				HAL_GPIO_WritePin(Front_IN1_GPIO_Port, Front_IN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Front_IN2_GPIO_Port, Front_IN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Back_IN1_GPIO_Port, Back_IN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Back_IN2_GPIO_Port, Back_IN2_Pin, GPIO_PIN_RESET);
			}
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
