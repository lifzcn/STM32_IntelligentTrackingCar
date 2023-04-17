#include "hcsr04.h"
#include "main.h"
#include "tim.h"

void HCSR04_Front_StartTrigStart(void)
{
	HCSR04_Front_TRIG_HIGH;
	HAL_Delay_us(20);
	HCSR04_Front_TRIG_LOW;
}

void HCSR04_Front_TimerFunc(uint8_t mode)
{
	if(mode)
	{
		__HAL_TIM_SetCounter(&htim1,0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_Front_GetDistance_Single(void)
{
	HCSR04_Front_StartTrigStart();
  while(!HCSR04_Front_ECHO);
  HCSR04_Front_TimerFunc(1);
  while(HCSR04_Front_ECHO);
  HCSR04_Front_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1))/58.0;
}

float HCSR04_Front_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
  for(int i =0;i<cnt;i++)
  {
		sum+=HCSR04_Front_GetDistance_Single();
  }
	return sum/cnt;
}

void HCSR04_Back_StartTrigStart(void)
{
	HCSR04_Back_TRIG_HIGH;
	HAL_Delay_us(20);
	HCSR04_Back_TRIG_LOW;
}

void HCSR04_Back_TimerFunc(uint8_t mode)
{
	if(mode)
	{
		__HAL_TIM_SetCounter(&htim1,0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_Back_GetDistance_Single(void)
{
	HCSR04_Back_StartTrigStart();
  while(!HCSR04_Back_ECHO);
  HCSR04_Back_TimerFunc(1);
  while(HCSR04_Back_ECHO);
  HCSR04_Back_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1))/58.0;
}

float HCSR04_Back_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
  for(int i =0;i<cnt;i++)
  {
		sum+=HCSR04_Back_GetDistance_Single();
  }
	return sum/cnt;
}

void HCSR04_Left_StartTrigStart(void)
{
	HCSR04_Left_TRIG_HIGH;
	HAL_Delay_us(20);
	HCSR04_Left_TRIG_LOW;
}

void HCSR04_Left_TimerFunc(uint8_t mode)
{
	if(mode)
	{
		__HAL_TIM_SetCounter(&htim1,0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_Left_GetDistance_Single(void)
{
	HCSR04_Left_StartTrigStart();
  while(!HCSR04_Left_ECHO);
  HCSR04_Left_TimerFunc(1);
  while(HCSR04_Left_ECHO);
  HCSR04_Left_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1))/58.0;
}

float HCSR04_Left_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
  for(int i =0;i<cnt;i++)
  {
		sum+=HCSR04_Left_GetDistance_Single();
  }
	return sum/cnt;
}

void HCSR04_Right_StartTrigStart(void)
{
	HCSR04_Right_TRIG_HIGH;
	HAL_Delay_us(20);
	HCSR04_Right_TRIG_LOW;
}

void HCSR04_Right_TimerFunc(uint8_t mode)
{
	if(mode)
	{
		__HAL_TIM_SetCounter(&htim1,0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_Right_GetDistance_Single(void)
{
	HCSR04_Right_StartTrigStart();
  while(!HCSR04_Right_ECHO);
  HCSR04_Right_TimerFunc(1);
  while(HCSR04_Right_ECHO);
  HCSR04_Right_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1))/58.0;
}

float HCSR04_Right_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
  for(int i =0;i<cnt;i++)
  {
		sum+=HCSR04_Right_GetDistance_Single();
  }
	return sum/cnt;
}
