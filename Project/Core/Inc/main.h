/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Front_IN1_Pin GPIO_PIN_1
#define Front_IN1_GPIO_Port GPIOA
#define Front_IN3_Pin GPIO_PIN_2
#define Front_IN3_GPIO_Port GPIOA
#define HCSR04_Front_TRIG_Pin GPIO_PIN_3
#define HCSR04_Front_TRIG_GPIO_Port GPIOA
#define HCSR04_Front_ECHO_Pin GPIO_PIN_4
#define HCSR04_Front_ECHO_GPIO_Port GPIOA
#define HCSR04_Back_TRIG_Pin GPIO_PIN_5
#define HCSR04_Back_TRIG_GPIO_Port GPIOA
#define HCSR04_Back_ECHO_Pin GPIO_PIN_6
#define HCSR04_Back_ECHO_GPIO_Port GPIOA
#define HCSR04_Left_TRIG_Pin GPIO_PIN_7
#define HCSR04_Left_TRIG_GPIO_Port GPIOA
#define HCSR04_Left_ECHO_Pin GPIO_PIN_0
#define HCSR04_Left_ECHO_GPIO_Port GPIOB
#define HCSR04_Right_TRIG_Pin GPIO_PIN_1
#define HCSR04_Right_TRIG_GPIO_Port GPIOB
#define HCSR04_Right_ECHO_Pin GPIO_PIN_2
#define HCSR04_Right_ECHO_GPIO_Port GPIOB
#define Front_IN2_Pin GPIO_PIN_10
#define Front_IN2_GPIO_Port GPIOB
#define Front_IN4_Pin GPIO_PIN_11
#define Front_IN4_GPIO_Port GPIOB
#define Back_IN1_Pin GPIO_PIN_12
#define Back_IN1_GPIO_Port GPIOB
#define Back_IN3_Pin GPIO_PIN_13
#define Back_IN3_GPIO_Port GPIOB
#define Back_IN2_Pin GPIO_PIN_14
#define Back_IN2_GPIO_Port GPIOB
#define Back_IN4_Pin GPIO_PIN_15
#define Back_IN4_GPIO_Port GPIOB
#define InfraredSensor_1_Pin GPIO_PIN_3
#define InfraredSensor_1_GPIO_Port GPIOB
#define InfraredSensor_2_Pin GPIO_PIN_4
#define InfraredSensor_2_GPIO_Port GPIOB
#define InfraredSensor_3_Pin GPIO_PIN_5
#define InfraredSensor_3_GPIO_Port GPIOB
#define InfraredSensor_4_Pin GPIO_PIN_6
#define InfraredSensor_4_GPIO_Port GPIOB
#define InfraredSensor_5_Pin GPIO_PIN_7
#define InfraredSensor_5_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
