#ifndef __HCSR04_H__
#define __HCSR04_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define HCSR04_Front_TRIG_HIGH HAL_GPIO_WritePin(HCSR04_Front_TRIG_GPIO_Port,HCSR04_Front_TRIG_Pin,GPIO_PIN_SET)
#define HCSR04_Front_TRIG_LOW  HAL_GPIO_WritePin(HCSR04_Front_TRIG_GPIO_Port,HCSR04_Front_TRIG_Pin,GPIO_PIN_RESET)
#define HCSR04_Front_ECHO	HAL_GPIO_ReadPin(HCSR04_Front_ECHO_GPIO_Port,HCSR04_Front_ECHO_Pin)

#define HCSR04_Back_TRIG_HIGH HAL_GPIO_WritePin(HCSR04_Back_TRIG_GPIO_Port,HCSR04_Back_TRIG_Pin,GPIO_PIN_SET)
#define HCSR04_Back_TRIG_LOW  HAL_GPIO_WritePin(HCSR04_Back_TRIG_GPIO_Port,HCSR04_Back_TRIG_Pin,GPIO_PIN_RESET)
#define HCSR04_Back_ECHO	HAL_GPIO_ReadPin(HCSR04_Back_ECHO_GPIO_Port,HCSR04_Back_ECHO_Pin)

#define HCSR04_Left_TRIG_HIGH HAL_GPIO_WritePin(HCSR04_Left_TRIG_GPIO_Port,HCSR04_Left_TRIG_Pin,GPIO_PIN_SET)
#define HCSR04_Left_TRIG_LOW  HAL_GPIO_WritePin(HCSR04_Left_TRIG_GPIO_Port,HCSR04_Left_TRIG_Pin,GPIO_PIN_RESET)
#define HCSR04_Left_ECHO	HAL_GPIO_ReadPin(HCSR04_Left_ECHO_GPIO_Port,HCSR04_Left_ECHO_Pin)

#define HCSR04_Right_TRIG_HIGH HAL_GPIO_WritePin(HCSR04_Right_TRIG_GPIO_Port,HCSR04_Right_TRIG_Pin,GPIO_PIN_SET)
#define HCSR04_Right_TRIG_LOW  HAL_GPIO_WritePin(HCSR04_Right_TRIG_GPIO_Port,HCSR04_Right_TRIG_Pin,GPIO_PIN_RESET)
#define HCSR04_Right_ECHO	HAL_GPIO_ReadPin(HCSR04_Right_ECHO_GPIO_Port,HCSR04_Right_ECHO_Pin)

void HCSR04_Front_StartTrigStart(void);
void HCSR04_Front_TimerFunc(uint8_t mode);
float HCSR04_Front_GetDistance_Single(void);
float HCSR04_Front_GetDistance_Repeatedly(uint8_t cnt);

void HCSR04_Back_StartTrigStart(void);
void HCSR04_Back_TimerFunc(uint8_t mode);
float HCSR04_Back_GetDistance_Single(void);
float HCSR04_Back_GetDistance_Repeatedly(uint8_t cnt);

void HCSR04_Left_StartTrigStart(void);
void HCSR04_Left_TimerFunc(uint8_t mode);
float HCSR04_Left_GetDistance_Single(void);
float HCSR04_Left_GetDistance_Repeatedly(uint8_t cnt);

void HCSR04_Right_StartTrigStart(void);
void HCSR04_Right_TimerFunc(uint8_t mode);
float HCSR04_Right_GetDistance_Single(void);
float HCSR04_Right_GetDistance_Repeatedly(uint8_t cnt);

#endif
